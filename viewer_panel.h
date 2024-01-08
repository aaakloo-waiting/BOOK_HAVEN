#ifndef VIEWER_PANEL_H
#define VIEWER_PANEL_H

#include <QDialog>
#include "customer_login_panel.h"
namespace Ui {
class Viewer_panel;
}

class Viewer_panel : public QDialog
{
    Q_OBJECT

public:
    explicit Viewer_panel(QWidget *parent = nullptr);
    ~Viewer_panel();

private slots:

    void on_view_to_main_clicked();

    void on_view_to_customer_login_clicked();

private:
    Ui::Viewer_panel *ui;
    Customer_login_panel *ptr_customer_login_panel;
};

#endif // VIEWER_PANEL_H
