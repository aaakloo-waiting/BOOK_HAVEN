#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete ptr_viewer_panel; // destructor called to delete object pointer
}
// viewer section
void MainWindow::on_main_to_viewBookPanel_clicked()
{
    ptr_viewer_panel = new Viewer_panel(); // create view_panel pointer from main_window_ui
    ptr_viewer_panel->show(); // display function of view_panel class
    this->close();
}

// customer reg section

void MainWindow::on_main_to_customer_reg_clicked()
{
    ptr_customer_registration_panel = new customer_registration_panel();
    ptr_customer_registration_panel->show();
    this->close();
}


void MainWindow::on_main_to_customer_login_clicked()
{
    ptr_customer_login_panel = new Customer_login_panel();
    ptr_customer_login_panel->show();
    this->close();
}

