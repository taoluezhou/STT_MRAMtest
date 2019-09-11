#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QPalette>
#include <QTimer>
#include <QtCore/qmath.h>

#include "PCIE.h"

#define PCIE_VID                 0x1172
#define PCIE_DID                 0xE001
#define MAX_PCIE_CARD   256
#define DEMO_PCIE_USER_BAR      PCIE_BAR1
#define DEMO_PCIE_IO_ADDR       0x00
#define DEMO_PCIE_FIFO_ID       0x00
#define AUTONUM					13
#define TESTTIME				2499

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    bool rebuildboard();
    bool connectboard();
    ~MainWindow();

private slots:
    void on_connect_clicked();

    void on_begin_clicked();

    void timerUpDateLabel();

private:
    Ui::MainWindow *ui;




};

#endif // MAINWINDOW_H
