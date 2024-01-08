#include "customer_registration_panel.h"
#include "ui_customer_registration_panel.h"

customer_registration_panel::customer_registration_panel(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::customer_registration_panel)
{
    ui->setupUi(this);
}

customer_registration_panel::~customer_registration_panel()
{
    delete ui;
}
