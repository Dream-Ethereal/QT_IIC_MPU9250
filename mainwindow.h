#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include <QTimer>
#include "CH341DLL.H"
#include "IICConnection.h"
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <qwt_plot_canvas.h>
#include <qwt_legend.h>
#include <qwt_plot_grid.h>
#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include <QDialog>

#define u8 unsigned char
#define u16 unsigned short
#define u32 unsigned int

#define SIMPLE_NUMS 400

#define MPU9250_ADDR          0X68
#define MPU6500_ID				0X73

#define AK8963_ADDR				0X0C
#define AK8963_ID				0X48

#define MPU_PWR_MGMT1_REG		0X6B	//电源管理寄存器1
#define MPU_PWR_MGMT2_REG		0X6C	//电源管理寄存器2
#define MPU_GYRO_CFG_REG		0X1B	//陀螺仪配置寄存器
#define MPU_ACCEL_CFG_REG		0X1C	//加速度计配置寄存器
#define MPU_ACCEL_CFG2_REG		0X1D	//加速度计配置寄存器2
#define MPU_SAMPLE_RATE_REG		0X19	//采样频率分频器
#define MPU_CFG_REG				0X1A	//配置寄存器
#define MPU_INT_EN_REG			0X38	//中断使能寄存器
#define MPU_USER_CTRL_REG		0X6A	//用户控制寄存器
#define MPU_FIFO_EN_REG			0X23	//FIFO使能寄存器
#define MPU_INTBP_CFG_REG		0X37	//中断/旁路设置寄存器
#define MPU_DEVICE_ID_REG		0X75	//器件ID寄存器
#define MAG_WIA					0x00	//AK8963的器件ID寄存器地址
#define MAG_CNTL1          	  	0X0A
#define MPU_TEMP_OUTH_REG		0X41	//温度值高八位寄存器
#define MPU_TEMP_OUTL_REG		0X42	//温度值低8位寄存器
#define MPU_GYRO_XOUTH_REG		0X43	//陀螺仪值,X轴高8位寄存器
#define MPU_GYRO_XOUTL_REG		0X44	//陀螺仪值,X轴低8位寄存器
#define MPU_GYRO_YOUTH_REG		0X45	//陀螺仪值,Y轴高8位寄存器
#define MPU_GYRO_YOUTL_REG		0X46	//陀螺仪值,Y轴低8位寄存器
#define MPU_GYRO_ZOUTH_REG		0X47	//陀螺仪值,Z轴高8位寄存器
#define MPU_GYRO_ZOUTL_REG		0X48	//陀螺仪值,Z轴低8位寄存器
#define MPU_ACCEL_XOUTH_REG		0X3B	//加速度值,X轴高8位寄存器
#define MPU_ACCEL_XOUTL_REG		0X3C	//加速度值,X轴低8位寄存器
#define MPU_ACCEL_YOUTH_REG		0X3D	//加速度值,Y轴高8位寄存器
#define MPU_ACCEL_YOUTL_REG		0X3E	//加速度值,Y轴低8位寄存器
#define MPU_ACCEL_ZOUTH_REG		0X3F	//加速度值,Z轴高8位寄存器
#define MPU_ACCEL_ZOUTL_REG		0X40	//加速度值,Z轴低8位寄存器
#define MAG_XOUT_L				0X03	//磁力计值
#define MAG_XOUT_H				0X04
#define MAG_YOUT_L				0X05
#define MAG_YOUT_H				0X06
#define MAG_ZOUT_L				0X07
#define MAG_ZOUT_H				0X08

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    IICConnection* IIC_Connection_MPU9250;
    IICConnection* IIC_Connection_AK8963;
    QFile* file;
    QTextStream* out;
    QMessageBox* msgbox;
    QwtPlotCurve *curve_ax,*curve_ay,*curve_az,*curve_gx,*curve_gy,*curve_gz,*curve_mx,*curve_my,*curve_mz; // 曲线对象
    int flag_ax,flag_ay,flag_az,flag_gx,flag_gy,flag_gz,flag_mx,flag_my,flag_mz;
    double Data1[SIMPLE_NUMS] = {0};
    double Data2[SIMPLE_NUMS] = {0};
    double Data3[SIMPLE_NUMS] = {0};
    double Data4[SIMPLE_NUMS] = {0};
    double Data5[SIMPLE_NUMS] = {0};
    double Data6[SIMPLE_NUMS] = {0};
    double Data7[SIMPLE_NUMS] = {0};
    double Data8[SIMPLE_NUMS] = {0};
    double Data9[SIMPLE_NUMS] = {0};
    int write_done = 0;
    void MPU9250_init();
    void MPU_Set_Gyro_Fsr(u8 fsr);
    void MPU_Set_Accel_Fsr(u8 fsr);
    void MPU_Set_LPF(u16 lpf);
    void MPU_Set_Rate(u16 rate);
    short MPU_Get_Temperature(void);
    u8 MPU_Get_Gyroscope(short *gx,short *gy,short *gz);
    u8 MPU_Get_Accelerometer(short *ax,short *ay,short *az);
    u8 MPU_Get_Magnetometer(short *mx,short *my,short *mz);
    void displayCurve(QwtPlotCurve *pCurve,double *pCurveData,int dataNum);

private slots:
    void updateSensorData();
    void on_pushButton_start_clicked();
    void on_pushButton_end_clicked();
    void legendClicked(const QVariant &itemInfo);
    void on_pushButton_help_clicked();
};

#endif // MAINWINDOW_H
