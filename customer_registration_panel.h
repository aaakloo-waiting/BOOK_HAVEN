#ifndef CUSTOMER_REGISTRATION_PANEL_H
#define CUSTOMER_REGISTRATION_PANEL_H

#include <QDialog>

namespace Ui {
class customer_registration_panel;
}

class customer_registration_panel : public QDialog
{
    Q_OBJECT

public:
    explicit customer_registration_panel(QWidget *parent = nullptr);
    ~customer_registration_panel();

private:
    Ui::customer_registration_panel *ui;
};

#endif // CUSTOMER_REGISTRATION_PANEL_H
