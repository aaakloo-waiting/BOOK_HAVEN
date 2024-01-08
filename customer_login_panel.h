#ifndef CUSTOMER_LOGIN_PANEL_H
#define CUSTOMER_LOGIN_PANEL_H

#include <QDialog>
#include "customer_registration_panel.h"
// #include "viewer_panel.h"

namespace Ui {
class Customer_login_panel;
}

class Customer_login_panel : public QDialog
{
    Q_OBJECT

public:
    explicit Customer_login_panel(QWidget *parent = nullptr);
    ~Customer_login_panel();

private slots:

    void on_pushButton_4_clicked();

    void on_customer_login_to_reg_clicked();

private:
    Ui::Customer_login_panel *ui;
    customer_registration_panel *ptr_customer_registration_panel;
    // Viewer_panel *ptr_viewer_panel;
};

#endif // CUSTOMER_LOGIN_PANEL_H
