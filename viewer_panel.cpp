#include "viewer_panel.h"
#include "ui_viewer_panel.h"
#include "mainwindow.h"
// #include "customer_login_panel.h"

Viewer_panel::Viewer_panel(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Viewer_panel)
{
    ui->setupUi(this);
}

Viewer_panel::~Viewer_panel()
{
    delete ui;
    delete ptr_customer_login_panel;
}

// Return to main window button
void Viewer_panel::on_view_to_main_clicked()
{
    MainWindow *main_window = new MainWindow();
    main_window->show();
    this->close();
}

// customer login button
void Viewer_panel::on_view_to_customer_login_clicked()
{
    ptr_customer_login_panel = new Customer_login_panel();
    ptr_customer_login_panel->show();
    this->close();
}

