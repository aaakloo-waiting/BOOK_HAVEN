#include "customer_login_panel.h"
#include "ui_customer_login_panel.h"

Customer_login_panel::Customer_login_panel(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Customer_login_panel)
{
    ui->setupUi(this);
}

Customer_login_panel::~Customer_login_panel()
{
    delete ui;
}

void Customer_login_panel::on_pushButton_4_clicked()
{
    this->close();
}


void Customer_login_panel::on_customer_login_to_reg_clicked()
{
    ptr_customer_registration_panel = new customer_registration_panel();
    ptr_customer_registration_panel->show();
    this->close();
}

