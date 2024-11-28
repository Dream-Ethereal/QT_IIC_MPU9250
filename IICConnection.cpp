#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
//#include "CH341DLL.H"
#include "IICConnection.h"

typedef HANDLE (__stdcall* CH341OpenDevice_Func)(ULONG);
typedef ULONG (__stdcall* CH341GetVersion_Func)(void);
typedef ULONG (__stdcall* CH341GetDrvVersion_Func)(void);
typedef void (__stdcall* CH341CloseDevice_Func)(ULONG);
typedef BOOL (__stdcall* CH341StreamI2C_Func)(ULONG, ULONG, PVOID, ULONG, PVOID);
typedef BOOL(__stdcall* CH341SetStream_Func)(ULONG, ULONG);

static HMODULE ch341dll_handle = NULL;
static CH341OpenDevice_Func CH341OpenDevice = NULL;
static CH341GetVersion_Func CH341GetVersion = NULL;
static CH341GetDrvVersion_Func CH341GetDrvVersion = NULL;
static CH341CloseDevice_Func CH341CloseDevice = NULL;
static CH341StreamI2C_Func CH341StreamI2C = NULL;
static CH341SetStream_Func CH341SetStream = NULL;

CAPI int IICConnection_Init()
{
	if (ch341dll_handle) return 1;

	int ok = 0;
	do
	{
#ifdef X64
        ch341dll_handle = LoadLibraryA("CH341DLLA64.DLL");
#else
        ch341dll_handle = LoadLibraryA("CH341DLL.DLL");
#endif // X64
        if (ch341dll_handle == NULL) break;

		CH341OpenDevice = (CH341OpenDevice_Func)GetProcAddress(ch341dll_handle, "CH341OpenDevice");
		if (!CH341OpenDevice) break;

		CH341GetVersion = (CH341GetVersion_Func)GetProcAddress(ch341dll_handle, "CH341GetVersion");
		if (!CH341GetVersion) break;

		CH341GetDrvVersion = (CH341GetDrvVersion_Func)GetProcAddress(ch341dll_handle, "CH341GetDrvVersion");
		if (!CH341GetDrvVersion) break;

		CH341CloseDevice = (CH341CloseDevice_Func)GetProcAddress(ch341dll_handle, "CH341CloseDevice");
		if (!CH341CloseDevice) break;

		CH341SetStream = (CH341SetStream_Func)GetProcAddress(ch341dll_handle, "CH341SetStream");
		if (!CH341SetStream) break;

		CH341StreamI2C = (CH341StreamI2C_Func)GetProcAddress(ch341dll_handle, "CH341StreamI2C");
		if (!CH341StreamI2C) break;

		ok = 1;
	} while (0);

	if (!ok) {
		IICConnection_Deinit();
	}
	return ok;
}

CAPI void IICConnection_Deinit()
{
	if (ch341dll_handle) {
		FreeLibrary(ch341dll_handle);
		ch341dll_handle = NULL;
		CH341OpenDevice = NULL;
		CH341GetVersion = NULL;
		CH341GetDrvVersion = NULL;
		CH341CloseDevice = NULL;
		CH341SetStream = NULL;
		CH341StreamI2C = NULL;
	}
}

#define IIC_DATA_LEN 512
#define	I2C_BUFFER_LEN (IIC_DATA_LEN+5)

struct stIICConnection {
	HANDLE handle;

	IIC_Endian endian;
	int addrLen;
	unsigned int maxAddr;

	unsigned char buff[I2C_BUFFER_LEN];
	unsigned char* pdata;
	unsigned char* paddr;
};

CAPI IICConnection* IICConnection_Create(IIC_Endian endian, int addrLen, unsigned char i2c_addr)
{
	IICConnection* conn = NULL;
	int ok = 0;

	do
	{
		if (!ch341dll_handle) break;

		if (addrLen <= 0 || addrLen > 4) {
			printf("Invalid addrLen(%d)\n", addrLen);
			break;
		}

		conn = (IICConnection*)malloc(sizeof(IICConnection));
		if (!conn) break;

		conn->maxAddr = (unsigned int)(((unsigned long long)1 << (addrLen * 8)) - 1);
		conn->endian = endian;
		conn->addrLen = addrLen;
		conn->buff[0] = i2c_addr;
		conn->paddr = conn->buff + 1;
		conn->pdata = conn->buff + 1 + addrLen;

		conn->handle = CH341OpenDevice(0);
		if (conn->handle == INVALID_HANDLE_VALUE)
			break;

		ULONG ver = CH341GetVersion();
		ULONG dver = CH341GetDrvVersion();
		if (dver < 0x23) break;
		if (ver == 0 || dver == 0)
			break;

        CH341SetStream(0, 0x00);

		ok = 1;
	} while (0);

	if (!ok) {
		IICConnection_Destroy(conn);
		conn = NULL;
	}

	return conn;
}

CAPI void IICConnection_Destroy(IICConnection* conn)
{
	if (conn) {
		
		if (conn->handle && conn->handle != INVALID_HANDLE_VALUE) {
			CH341CloseDevice(0);
			conn->handle = NULL;
		}
		free(conn);
	}
}

static void IICConnection_SetAddr(IICConnection* conn, unsigned int addr)
{
	unsigned char* paddr = (unsigned char*)(&addr);
	int i;
	
	switch (conn->endian) {
	case Endian_Big:
		for (i = 0; i < conn->addrLen; i++) {
			conn->paddr[conn->addrLen - 1 - i] = paddr[i];
		}
		break;
	case Endian_Little:
		for (i = 0; i < conn->addrLen; i++) {
			conn->paddr[i] = paddr[i];
		}
		break;
	}
}

static void IICConnection_GetBytes(IICConnection* conn, unsigned char* dst, int len)
{
	int i;
	switch (conn->endian) {
	case Endian_Big:
		for (i = 0; i < len; i += 4)
		{
			dst[i + 0] = conn->pdata[i + 3];
			dst[i + 1] = conn->pdata[i + 2];
			dst[i + 2] = conn->pdata[i + 1];
			dst[i + 3] = conn->pdata[i + 0];
		}
		break;

	case Endian_Little:
		for (i = 0; i < len; i ++)
		{
			dst[i] = conn->pdata[i];
		}
		break;
	}
}

CAPI int IICConnection_Read(IICConnection* conn, unsigned int addr, int length, unsigned char* buff)
{
	int result = 0;
//	if (length % 4 != 0) {
//		printf("IICConnection_Read: invalid length(%d)\n", length);
//		return -1;
//	}
	if (conn) {
		while (length > 0) {
            unsigned long len =  length < IIC_DATA_LEN ? length : IIC_DATA_LEN;
			IICConnection_SetAddr(conn, addr);
			if (addr + len > conn->maxAddr) {
				result = -1;
				break;
			}

			if (FALSE == CH341StreamI2C(0, conn->addrLen + 1, conn->buff, len, conn->pdata)) {
				result = -1;
				break;
			}

			IICConnection_GetBytes(conn, buff, len);
			buff += len;
			length -= len;
			addr += len;
			result += len;
		}
	}
	return result;
}

static void IICConnection_SetBytes(IICConnection* conn, const unsigned char* src, int len)
{
	int i;
	switch (conn->endian) {
	case Endian_Big:
		for (i = 0; i < len; i += 4)
		{
			conn->pdata[i + 3] = src[i + 0];
			conn->pdata[i + 2] = src[i + 1];
			conn->pdata[i + 1] = src[i + 2];
			conn->pdata[i + 0] = src[i + 3];
		}
		break;

	case Endian_Little:
		for (i = 0; i < len; i++)
		{
			conn->pdata[i] = src[i];
		}
		break;
	}
}


CAPI int IICConnection_Write(IICConnection* conn, unsigned int addr, int length, unsigned char* buff)
{
	int result = 0;
	if (conn) {
		//iic->paddr[0] = addr;
		while (length > 0) {
            unsigned long len = length < IIC_DATA_LEN ? length : IIC_DATA_LEN;
			IICConnection_SetBytes(conn, buff, len);
			IICConnection_SetAddr(conn, addr);
			if (addr + len > conn->maxAddr) {
				result = -1;
				break;
			}
			
			if (FALSE == CH341StreamI2C(0, 1 + conn->addrLen + len, conn->buff, 0, NULL)) {
				result = -1;
				break;
			}
			buff += len;
			length -= len;
			addr += len;
			result += len;
		}
	}
	return result;
}
