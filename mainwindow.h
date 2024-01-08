#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "viewer_panel.h" //include .h file of the ui class
// viewer, customer login, customer reg all access
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    Viewer_panel *ptr_viewer_panel; // pointer to an object of the ui class
    customer_registration_panel *ptr_customer_registration_panel;
};
#endif // MAINWINDOW_H
