#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    file = new QFile("data.txt");
    out = new QTextStream(file);

    msgbox = new QMessageBox(this);

    flag_ax = flag_ay = flag_az = true;
    flag_gx = flag_gy = flag_gz = false;
    flag_mx = flag_my = flag_mz = false;

    // 创建QwtPlot实例和曲线对象
    ui->qwtPlot->setCanvasBackground(Qt::white);

    curve_ax = new QwtPlotCurve( "ACCX" );
    curve_ax->setRenderHint( QwtPlotItem::RenderAntialiased );
    curve_ax->setLegendAttribute( QwtPlotCurve::LegendShowLine, true );
    curve_ax->setPen( QPen( Qt::red ) );
    curve_ax->attach( ui->qwtPlot );
    curve_ax->setVisible( flag_ax );

    curve_ay = new QwtPlotCurve( "ACCY" );
    curve_ay->setRenderHint( QwtPlotItem::RenderAntialiased );
    curve_ay->setLegendAttribute( QwtPlotCurve::LegendShowLine, true );
    curve_ay->setPen( QPen( Qt::black ) );
    curve_ay->attach( ui->qwtPlot );
    curve_ay->setVisible( flag_ay );

    curve_az = new QwtPlotCurve( "ACCZ" );
    curve_az->setRenderHint( QwtPlotItem::RenderAntialiased );
    curve_az->setLegendAttribute( QwtPlotCurve::LegendShowLine, true );
    curve_az->setPen( QPen( Qt::green ) );
    curve_az->attach( ui->qwtPlot );
    curve_az->setVisible( flag_az );

    curve_gx = new QwtPlotCurve( "GYROX" );
    curve_gx->setRenderHint( QwtPlotItem::RenderAntialiased );
    curve_gx->setLegendAttribute( QwtPlotCurve::LegendShowLine, true );
    curve_gx->setPen( QPen( Qt::blue ) );
    curve_gx->attach( ui->qwtPlot );
    curve_gx->setVisible( flag_gx );

    curve_gy = new QwtPlotCurve( "GYROY" );
    curve_gy->setRenderHint( QwtPlotItem::RenderAntialiased );
    curve_gy->setLegendAttribute( QwtPlotCurve::LegendShowLine, true );
    curve_gy->setPen( QPen( Qt::yellow ) );
    curve_gy->attach( ui->qwtPlot );
    curve_gy->setVisible( flag_gy );

    curve_gz = new QwtPlotCurve( "GYROZ" );
    curve_gz->setRenderHint( QwtPlotItem::RenderAntialiased );
    curve_gz->setLegendAttribute( QwtPlotCurve::LegendShowLine, true );
    curve_gz->setPen( QPen( Qt::gray ) );
    curve_gz->attach( ui->qwtPlot );
    curve_gz->setVisible( flag_gz );

    curve_mx = new QwtPlotCurve( "MAGX" );
    curve_mx->setRenderHint( QwtPlotItem::RenderAntialiased );
    curve_mx->setLegendAttribute( QwtPlotCurve::LegendShowLine, true );
    curve_mx->setPen( QPen( Qt::cyan ) );
    curve_mx->attach( ui->qwtPlot );
    curve_mx->setVisible( flag_mx );

    curve_my = new QwtPlotCurve( "MAGY" );
    curve_my->setRenderHint( QwtPlotItem::RenderAntialiased );
    curve_my->setLegendAttribute( QwtPlotCurve::LegendShowLine, true );
    curve_my->setPen( QPen( Qt::magenta ) );
    curve_my->attach( ui->qwtPlot );
    curve_my->setVisible( flag_my );

    curve_mz = new QwtPlotCurve( "MAGZ" );
    curve_mz->setRenderHint( QwtPlotItem::RenderAntialiased );
    curve_mz->setLegendAttribute( QwtPlotCurve::LegendShowLine, true );
    curve_mz->setPen( QPen( Qt::darkYellow ) );
    curve_mz->attach( ui->qwtPlot );
    curve_mz->setVisible( flag_mz );

    ui->qwtPlot->setAxisTitle( QwtPlot::yLeft, "Values" );
    ui->qwtPlot->enableAxis(QwtPlot::xBottom,false);    // 底部y轴
    ui->qwtPlot->setAxisScale(QwtPlot::yLeft, -50, 50);

    QwtPlotGrid *grid = new QwtPlotGrid();
    grid->enableX( true );//设置网格线
    grid->enableY( true );
    grid->setMajorPen( Qt::black, 0, Qt::DotLine );
    grid->attach(ui->qwtPlot);

    QwtLegend* legend = new QwtLegend;
    legend->setDefaultItemMode(QwtLegendData::Clickable);
    ui->qwtPlot->insertLegend(legend, QwtPlot::BottomLegend);
    QObject::connect(legend, SIGNAL(clicked(const QVariant &, int)), SLOT(legendClicked(const QVariant &)));

    //MPU9250初始化
    MPU9250_init();

    //结束保存按钮初始不可见
    ui->pushButton_end->setDisabled(true);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateSensorData);
    timer->start(5);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete IIC_Connection_MPU9250;
    delete IIC_Connection_AK8963;
    delete timer;
}


void MainWindow::updateSensorData()
{
    short ax, ay, az;
    short gx, gy, gz;
    short mx, my, mz;
    short temp;

    MPU_Get_Accelerometer(&ax, &ay, &az);
    MPU_Get_Gyroscope(&gx, &gy, &gz);
    MPU_Get_Magnetometer(&mx, &my, &mz);
    temp = MPU_Get_Temperature();

    double temp_ = temp / 100.0;

    double a_x = ax / 1671.837;
    double a_y = ay / 1671.837;
    double a_z = az / 1671.837;
    
    double g_x = gx / 938.731;
    double g_y = gy / 938.731;
    double g_z = gz / 938.731;

    double m_x = mx / 100.0;
    double m_y = my / 100.0;
    double m_z = mz / 100.0;

    
    if(write_done)
    {
        *out << a_x << "\t\t\t" << a_y << "\t\t\t" << a_z << "\t\t\t" << g_x << "\t\t\t" << g_y << "\t\t\t" << g_z << "\t\t\t" << mx << "\t\t\t" << my << "\t\t\t" << mz << "\n";

    }

    ui->lineEdit_accx->setText(QString::number(a_x));
    ui->lineEdit_accy->setText(QString::number(a_y));
    ui->lineEdit_accz->setText(QString::number(a_z));
    ui->lineEdit_gyrx->setText(QString::number(g_x));
    ui->lineEdit_gyry->setText(QString::number(g_y));
    ui->lineEdit_gyrz->setText(QString::number(g_z));
    ui->lineEdit_cpsx->setText(QString::number(mx));
    ui->lineEdit_cpsy->setText(QString::number(my));
    ui->lineEdit_cpsz->setText(QString::number(mz));
    ui->lineEdit_temp->setText(QString::number(temp_));

    for(int i=0;i<SIMPLE_NUMS-1;i++){
        Data1[i]=Data1[i+1];
        Data2[i]=Data2[i+1];
        Data3[i]=Data3[i+1];
        Data4[i]=Data4[i+1];
        Data5[i]=Data5[i+1];
        Data6[i]=Data6[i+1];
        Data7[i]=Data7[i+1];
        Data8[i]=Data8[i+1];
        Data9[i]=Data9[i+1];
    }
    Data1[SIMPLE_NUMS-1]=a_x;
    Data2[SIMPLE_NUMS-1]=a_y;
    Data3[SIMPLE_NUMS-1]=a_z;
    Data4[SIMPLE_NUMS-1]=g_x;
    Data5[SIMPLE_NUMS-1]=g_y;
    Data6[SIMPLE_NUMS-1]=g_z;
    Data7[SIMPLE_NUMS-1]=m_x;
    Data8[SIMPLE_NUMS-1]=m_y;
    Data9[SIMPLE_NUMS-1]=m_z;

    displayCurve(curve_ax,Data1,SIMPLE_NUMS);
    displayCurve(curve_ay,Data2,SIMPLE_NUMS);
    displayCurve(curve_az,Data3,SIMPLE_NUMS);
    displayCurve(curve_gx,Data4,SIMPLE_NUMS);
    displayCurve(curve_gy,Data5,SIMPLE_NUMS);
    displayCurve(curve_gz,Data6,SIMPLE_NUMS);
    displayCurve(curve_mx,Data7,SIMPLE_NUMS);
    displayCurve(curve_my,Data8,SIMPLE_NUMS);
    displayCurve(curve_mz,Data9,SIMPLE_NUMS);


}

void MainWindow::displayCurve(QwtPlotCurve *pCurve,double *pCurveData,int dataNum)
{
    double *pCurveXData = (double*)malloc(dataNum*sizeof(double));
    for(int i=0;i<dataNum;i++){
        pCurveXData[i] = i;
    }
    pCurve->setSamples(pCurveXData,pCurveData,dataNum);
    ui->qwtPlot->setAutoReplot(true);
    ui->qwtPlot->replot();
    free(pCurveXData);
}

//图例点击可以切换显示和隐藏
void MainWindow::legendClicked(const QVariant &itemInfo)
{
    //获取曲线
    QwtPlotItem* plotItem = ui->qwtPlot->infoToItem(itemInfo);

    //根据图例选择状态，设置曲线隐藏还是显示
    if(plotItem==curve_ax) {
        plotItem->setVisible(!flag_ax);
        flag_ax = !flag_ax;
    } else if(plotItem==curve_ay) {
        plotItem->setVisible(!flag_ay);
        flag_ay = !flag_ay;
    } else if(plotItem==curve_az) {
        plotItem->setVisible(!flag_az);
        flag_az = !flag_az;
    } else if(plotItem==curve_gx) {
        plotItem->setVisible(!flag_gx);
        flag_gx = !flag_gx;
    } else if(plotItem==curve_gy) {
        plotItem->setVisible(!flag_gy);
        flag_gy = !flag_gy;
    } else if(plotItem==curve_gz) {
        plotItem->setVisible(!flag_gz);
        flag_gz = !flag_gz;
    } else if(plotItem==curve_mx) {
        plotItem->setVisible(!flag_mx);
        flag_mx = !flag_mx;
    } else if(plotItem==curve_my) {
        plotItem->setVisible(!flag_my);
        flag_my = !flag_my;
    } else if(plotItem==curve_mz) {
        plotItem->setVisible(!flag_mz);
        flag_mz = !flag_mz;
    }
}

void MainWindow::MPU9250_init()
{
    unsigned char data[1];

    //初始化IIC
    IICConnection_Init();

    //创建连接
    IIC_Connection_MPU9250 = IICConnection_Create(Endian_Little, 1, MPU9250_ADDR << 1);
    IIC_Connection_AK8963 = IICConnection_Create(Endian_Little, 1, AK8963_ADDR << 1);


    //复位MPU9250
    data[0] = 0X80;
    IICConnection_Write(IIC_Connection_MPU9250, MPU_PWR_MGMT1_REG, 1, data);


    //唤醒MPU9250
    data[0] = 0X00;
    IICConnection_Write(IIC_Connection_MPU9250, MPU_PWR_MGMT1_REG, 1, data);

    //设置陀螺仪传感器，±2000dps
    MPU_Set_Gyro_Fsr(3);

    //设置加速度传感器，±2g
    MPU_Set_Accel_Fsr(0);

    //设置采样率
    MPU_Set_Rate(200);

    //关闭所有中断
    data[0] = 0X00;
    IICConnection_Write(IIC_Connection_MPU9250, MPU_INT_EN_REG, 1, data);

    //IIC主模式关闭
    data[0] = 0X00;
    IICConnection_Write(IIC_Connection_MPU9250, MPU_USER_CTRL_REG, 1, data);

    //关闭FIFO
    data[0] = 0X00;
    IICConnection_Write(IIC_Connection_MPU9250, MPU_FIFO_EN_REG, 1, data);

    //INT引脚低电平有效，开启bypass模式，可以直接读取磁力计
    data[0] = 0X82;
    IICConnection_Write(IIC_Connection_MPU9250, MPU_INTBP_CFG_REG, 1, data);

    //读取MPU6500的ID
    IICConnection_Read(IIC_Connection_MPU9250, MPU_DEVICE_ID_REG, 1, data);
    if(data[0] == MPU6500_ID)   //器件ID正确
    {
        data[0] = 0X01;
        IICConnection_Write(IIC_Connection_MPU9250, MPU_PWR_MGMT1_REG, 1, data);//设置CLKSEL,PLL X轴为参考
        data[0] = 0X00;
        IICConnection_Write(IIC_Connection_MPU9250, MPU_PWR_MGMT2_REG, 1, data);//加速度与陀螺仪都工作
        MPU_Set_Rate(50);   //设置采样率为50Hz
    }

    //读取AK8963 ID
    IICConnection_Read(IIC_Connection_AK8963, MAG_WIA, 1, data);
    if(data[0] == AK8963_ID)   //器件ID正确
    {
        data[0] = 0X11;
        IICConnection_Write(IIC_Connection_AK8963, MAG_CNTL1, 1, data);//设置AK8963为单次测量模式
    }
}

//设置陀螺仪满量程范围
//fsr:0,±250dps;1,±500dps;2,±1000dps;3,±2000dps
void MainWindow::MPU_Set_Gyro_Fsr(u8 fsr)
{
    unsigned char data[1] = {fsr << 3};
    IICConnection_Write(IIC_Connection_MPU9250, MPU_GYRO_CFG_REG, 1, data);
}

//设置MPU9250加速度传感器满量程范围
//fsr:0,±2g;1,±4g;2,±8g;3,±16g
void MainWindow::MPU_Set_Accel_Fsr(u8 fsr)
{
    unsigned char data[1] = {fsr << 3};
    IICConnection_Write(IIC_Connection_MPU9250, MPU_ACCEL_CFG_REG, 1, data);
}

//设置MPU9250的数字低通滤波器
//lpf:数字低通滤波频率(Hz)
void MainWindow::MPU_Set_LPF(u16 lpf)
{
    u8 tdata=0;
    if(lpf>=188)tdata=1;
    else if(lpf>=98)tdata=2;
    else if(lpf>=42)tdata=3;
    else if(lpf>=20)tdata=4;
    else if(lpf>=10)tdata=5;
    else tdata=6;
    unsigned char data[1] = {tdata};
    IICConnection_Write(IIC_Connection_MPU9250, MPU_CFG_REG, 1, data);
}

//设置MPU9250的采样率(假定Fs=1KHz)
//rate:4~1000(Hz)
void MainWindow::MPU_Set_Rate(u16 rate)
{
    u8 tdata;
    if(rate>1000)rate=1000;
    if(rate<4)rate=4;
    tdata=1000/rate-1;
    unsigned char data[1] = {tdata};
    IICConnection_Write(IIC_Connection_MPU9250, MPU_SAMPLE_RATE_REG, 1, data);
    MPU_Set_LPF(rate/2);	//自动设置LPF为采样率的一半
}


//得到温度值
//返回值:温度值(扩大了100倍)
short MainWindow::MPU_Get_Temperature(void)
{
    u8 buf[2];
    short raw;
    float temp;
    IICConnection_Read(IIC_Connection_MPU9250, MPU_TEMP_OUTH_REG, 2, buf);
    raw=((u16)buf[0] << 8) | buf[1];
    temp= 21 + ((double)raw)/333.87;
    return temp*100;;
}

//得到陀螺仪值(原始值)
//gx,gy,gz:陀螺仪x,y,z轴的原始读数(带符号)
//返回值:-1,错误
//    其他,成功
u8 MainWindow::MPU_Get_Gyroscope(short *gx,short *gy,short *gz)
{
    u8 buf[6], res;
    res = IICConnection_Read(IIC_Connection_MPU9250, MPU_GYRO_XOUTH_REG, 6, buf);
    if(res != -1)
    {
        *gx=((u16)buf[0] << 8) | buf[1];
        *gy=((u16)buf[2] << 8) | buf[3];
        *gz=((u16)buf[4] << 8) | buf[5];
    }
    return res;;
}

//得到加速度值(原始值)
//ax,ay,az:加速度x,y,z轴的原始读数(带符号)
//返回值:-1,错误
//    其他,成功
u8 MainWindow::MPU_Get_Accelerometer(short *ax,short *ay,short *az)
{
    u8 buf[6], res;
    res = IICConnection_Read(IIC_Connection_MPU9250, MPU_ACCEL_XOUTH_REG, 6, buf);
    if(res != -1)
    {
        *ax=((u16)buf[0] << 8) | buf[1];
        *ay=((u16)buf[2] << 8) | buf[3];
        *az=((u16)buf[4] << 8) | buf[5];
    }
    return res;;
}

//得到磁力计值(原始值)
//mx,my,mz:磁力计x,y,z轴的原始读数(带符号)
//返回值:-1,错误
//    其他,成功
u8 MainWindow::MPU_Get_Magnetometer(short *mx,short *my,short *mz)
{
    u8 buf[6], res;
    res = IICConnection_Read(IIC_Connection_AK8963, MAG_XOUT_L, 6, buf);
    if(res != -1)
    {
        *mx=((u16)buf[1]<<8)|buf[0];
        *my=((u16)buf[3]<<8)|buf[2];
        *mz=((u16)buf[5]<<8)|buf[4];
    }
    u8 data[1] = {0X11};
    IICConnection_Write(IIC_Connection_AK8963, MAG_CNTL1, 1, data);//AK8963每次读完以后都需要重新设置为单次测量模式
    return res;
}


void MainWindow::on_pushButton_start_clicked()
{
    bool ret = file->open(QIODevice::WriteOnly|QIODevice::Truncate);
    if(ret == false){
        QMessageBox::information(this,"提示","文件打开读写失败，请检查data.txt是否正常！");
        return;
    }

    *out << "ACCX\t\tACCY\t\tACCZ\t\tGYROX\t\tGYROY\t\tGYROZ\t\tCPSX\t\tCPSY\t\tCPSZ\n";

    write_done = 1;

    ui->pushButton_start->setEnabled(false);
    ui->pushButton_end->setEnabled(true);
}

void MainWindow::on_pushButton_end_clicked()
{
    write_done = 0;
    file->close();
    ui->pushButton_start->setEnabled(true);
    ui->pushButton_end->setEnabled(false);
}

void MainWindow::on_pushButton_help_clicked()
{
    msgbox = new QMessageBox(QMessageBox::Information,"使用说明","1、初始默认显示三轴加速度计的数值，点击图表下方图例可以显示/隐藏曲线。\n\n2、图像数值和右侧数据栏的数值中，除了磁力计数值之外，其他已经经过单位转换，加速度单位为m/s²，角速度单位为rad/s\n\n3、为了图像曲线显示美观，图像对磁力计的数值进行了缩小显示，缩小倍数为100倍，请注意！右侧磁力计数据栏显示的是原始数据。",QMessageBox::Ok);
    msgbox->setModal(false);
    msgbox->setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowTitleHint | Qt::WindowStaysOnTopHint);
    msgbox->show();
}
