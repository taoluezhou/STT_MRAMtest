#include "mainwindow.h"
#include "ui_mainwindow.h"

PCIE m_hPCIE;
PCIE_CONFIG m_szPcieInfo[256];
DWORD   m_dwCardNum;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("STT-MRAM测试系统");
    /***************初始化连接状态标签*****************/
    QPalette pe;
    pe.setColor(QPalette::WindowText,Qt::red);
    ui->connect_state->setPalette(pe);
    ui->connect_state->setText("未连接PCIE！");
    /***************初始化开始状态*****************/
    pe.setColor(QPalette::WindowText,Qt::gray);
    ui->led->setPalette(pe);
    /******************定时器*****************/
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(timerUpDateLabel()));
    timer->start(100);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::rebuildboard()
{
    const WORD wVendorID = 0;
    const WORD wDeviceID = 0;
    bool bSuccess;
    DWORD dwDeviceNum;
    m_dwCardNum = 0;
    bSuccess = m_hPCIE.ScanCard(wVendorID, wDeviceID, &dwDeviceNum, m_szPcieInfo);
    if (!bSuccess)
    {
       qDebug()<<"Failed to scan pcie card!";
    }
    else if (dwDeviceNum == 0)
    {
       qDebug()<<"Cannot find any desired pcie card!";
    }
    else
    {
        m_dwCardNum = dwDeviceNum;
        //int nDefaultIndex = 0;
        for (int i = 0; i < (int)dwDeviceNum; i++)
        {
            PCIE_CONFIG *p = (PCIE_CONFIG *)&m_szPcieInfo[i];
            if (p->VendorID == 0x1172 && p->DeviceID == 0xE001)
            {
            }
        }
    }
    return bSuccess;
}

bool MainWindow::connectboard()
{
    bool bSuccess;
    if (m_hPCIE.IsOpened())
        m_hPCIE.Close();
    bSuccess = m_hPCIE.Open(PCIE_VID, PCIE_DID, 0);
    if (bSuccess)
    {
        QPalette pe;
        pe.setColor(QPalette::WindowText,Qt::green);
        ui->connect_state->setPalette(pe);
        ui->connect_state->setText("连接PCIE成功！");
    }
    else
    {
        QPalette pe;
        pe.setColor(QPalette::WindowText,Qt::red);
        ui->connect_state->setPalette(pe);
        ui->connect_state->setText("未连接PCIE！");
    }
    /*译码复位标志位*/
    if (m_hPCIE.Write32(DEMO_PCIE_USER_BAR, DEMO_PCIE_IO_ADDR + 40, 2) == 0)
    {
        return 0;
    }
    return bSuccess;
}

void MainWindow::on_connect_clicked()
{
    if (!m_hPCIE.IsDriverAvailable())
    {
        qDebug()<<"Load Driver fail!";
    }
    else
    {
        rebuildboard();
        connectboard();
    }
}

void MainWindow::on_begin_clicked()
{
    if(!(m_hPCIE.IsOpened()))
    {
        qDebug("Connect to the PCIE Port first");
        return;
    }
    uint frame=ui->input_frame->toPlainText().toInt();
    uint parameter=ui->input_information_source->toPlainText().toInt();
    double q0=ui->input_q0_prob->toPlainText().toDouble();
    double q1=ui->input_q1_prob->toPlainText().toDouble();
    uint R0AD=ui->input_R0_average_deviation->toPlainText().toInt();
    uint R0SD=ui->input_R0_standard_deviation->toPlainText().toInt();
    uint R1AD=ui->input_R1_average_deviation->toPlainText().toInt();
    uint R1SD=ui->input_R1_standard_deviation->toPlainText().toInt();

    double err_gap_0=1/(1-q0);
    double err_gap_1=1/(1-q1);

    uint ppq_eq=(qLn(1-q0+q1)-qLn(1-q0))*65536;
    qlonglong qqp=(q0/(q0+1-q1))*4294967296;
    qlonglong pqp=((1-q1)/(q0+1-q1))*4294967296;
    qlonglong ppq=((1-q0)/(1-q0+q1))*4294967296;
    qlonglong qpq=(q1/(1-q0+q1))*4294967296;
    uint var0=R0SD*R0SD;
    uint var1=R1SD*R1SD;
    uint ln_v0_div_v1=(qLn(R0SD/R1SD))*65536;
    uint ln_p0_div_q1=(qLn(1-q0+q0))*65536;
    uint ln_q0_div_p1=(qLn(q0+1-q1))*65536;

    m_hPCIE.Write32(DEMO_PCIE_USER_BAR, DEMO_PCIE_IO_ADDR+12,frame);
    m_hPCIE.Write32(DEMO_PCIE_USER_BAR, DEMO_PCIE_IO_ADDR+16,parameter);
    m_hPCIE.Write32(DEMO_PCIE_USER_BAR, DEMO_PCIE_IO_ADDR+20,R0AD);
    m_hPCIE.Write32(DEMO_PCIE_USER_BAR, DEMO_PCIE_IO_ADDR+24,R0SD);
    m_hPCIE.Write32(DEMO_PCIE_USER_BAR, DEMO_PCIE_IO_ADDR+28,R1AD);
    m_hPCIE.Write32(DEMO_PCIE_USER_BAR, DEMO_PCIE_IO_ADDR+32,R1SD);
    m_hPCIE.Write32(DEMO_PCIE_USER_BAR, DEMO_PCIE_IO_ADDR+36,err_gap_0);
    m_hPCIE.Write32(DEMO_PCIE_USER_BAR, DEMO_PCIE_IO_ADDR+40,err_gap_1);
    m_hPCIE.Write32(DEMO_PCIE_USER_BAR, DEMO_PCIE_IO_ADDR+44,ppq_eq);

    m_hPCIE.Write32(DEMO_PCIE_USER_BAR, DEMO_PCIE_IO_ADDR+48,qqp/65536);
    m_hPCIE.Write32(DEMO_PCIE_USER_BAR, DEMO_PCIE_IO_ADDR+52,qqp%65536);

    m_hPCIE.Write32(DEMO_PCIE_USER_BAR, DEMO_PCIE_IO_ADDR+56,pqp/65536);
    m_hPCIE.Write32(DEMO_PCIE_USER_BAR, DEMO_PCIE_IO_ADDR+60,pqp%65536);

    m_hPCIE.Write32(DEMO_PCIE_USER_BAR, DEMO_PCIE_IO_ADDR+64,ppq/65536);
    m_hPCIE.Write32(DEMO_PCIE_USER_BAR, DEMO_PCIE_IO_ADDR+68,ppq%65536);

    m_hPCIE.Write32(DEMO_PCIE_USER_BAR, DEMO_PCIE_IO_ADDR+72,qpq/65536);
    m_hPCIE.Write32(DEMO_PCIE_USER_BAR, DEMO_PCIE_IO_ADDR+76,qpq%65536);

    m_hPCIE.Write32(DEMO_PCIE_USER_BAR, DEMO_PCIE_IO_ADDR+80,var0);
    m_hPCIE.Write32(DEMO_PCIE_USER_BAR, DEMO_PCIE_IO_ADDR+84,var1);
    m_hPCIE.Write32(DEMO_PCIE_USER_BAR, DEMO_PCIE_IO_ADDR+88,ln_v0_div_v1);
    m_hPCIE.Write32(DEMO_PCIE_USER_BAR, DEMO_PCIE_IO_ADDR+92,ln_p0_div_q1);
    m_hPCIE.Write32(DEMO_PCIE_USER_BAR, DEMO_PCIE_IO_ADDR+96,ln_q0_div_p1);

    m_hPCIE.Write32(DEMO_PCIE_USER_BAR, DEMO_PCIE_IO_ADDR+8, 1);

    unsigned long pread;
    m_hPCIE.Read32(DEMO_PCIE_USER_BAR, DEMO_PCIE_IO_ADDR+12, &pread);
    ui->error_frame_result->setPlainText(QString::number(pread));

    m_hPCIE.Read32(DEMO_PCIE_USER_BAR, DEMO_PCIE_IO_ADDR+16, &pread);
    ui->error_rate_result->setPlainText(QString::number(pread));

}

void MainWindow::timerUpDateLabel()
{
    unsigned long pread;
    m_hPCIE.Read32(DEMO_PCIE_USER_BAR, DEMO_PCIE_IO_ADDR+8, &pread);
    if(pread==1)
    {
        QPalette pe;
        pe.setColor(QPalette::WindowText,Qt::green);
        ui->led->setPalette(pe);
    }
    else if(pread==0)
    {
        QPalette pe;
        pe.setColor(QPalette::WindowText,Qt::gray);
        ui->led->setPalette(pe);
    }
}
