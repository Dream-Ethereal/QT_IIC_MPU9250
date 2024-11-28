#ifndef __IIC_CONNECTION_H__
#define __IIC_CONNECTION_H__

typedef struct stIICConnection IICConnection;

#ifndef CAPI
#ifdef __cplusplus
#define CAPI extern "C"
#else
#if defined(_MSC_VER) && defined(DLL)
#define CAPI __declspec(dllexport)
#else // _MSC_VER
#define CAPI
#endif 
#endif
#endif

typedef enum enIIC_Endian {
	Endian_Big = 0,
	Endian_Little = 1,
}IIC_Endian;

CAPI int IICConnection_Init();

CAPI void IICConnection_Deinit();

CAPI IICConnection* IICConnection_Create(IIC_Endian endian, int addrLen, unsigned char i2c_addr);

CAPI void IICConnection_Destroy(IICConnection* conn);

CAPI int IICConnection_Read(IICConnection* conn, unsigned int addr, int length, unsigned char* buff);

CAPI int IICConnection_Write(IICConnection* conn, unsigned int addr, int length, unsigned char* buff);

#endif // !__IIC_CONNECTION_H__
