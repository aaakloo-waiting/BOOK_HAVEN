#include "login.h"
#include "signup.h"
#include "newpasswd.h"
#include "managebooks.h"
#include "manageauthors.h"
#include "addmember.h"
#include "editmember.h"
#include "memberslist.h"
#include "addbook.h"
#include "customer_login.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    customer_login w;
    w.show();
    return a.exec();
}
