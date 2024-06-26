#include "editmember.h"
#include "ui_editmember.h"
#include "digitallibrary.h"
#include <QSqlRecord>
#include <QSqlField>
#include <QTableView>
#include <QMessageBox>
#include <QRegularExpression>
#include <QRegularExpressionValidator>
#include <QDebug>

editMember::editMember(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editMember)
{
    ui->setupUi(this);
    this->setWindowTitle("Edit Member Info");
    setValidator();
}

editMember::~editMember()
{
    delete ui;
}

void editMember::on_searchMemberBtn_clicked()
{
    //get the content of the Line edit
    QString ID = ui->ID->text();
    QString firstName;
    QString lastName;
    QString phone;
    QString mail;
    QString gender;

    //call the mail Database
    digitalLibrary lib;
    auto db = lib.db;

    //Define the query
    auto query = QSqlQuery(db);
    QString searchID = {"SELECT * FROM accounts WHERE ID = '%1'"};

    //execute the query
    if(!query.exec(searchID.arg(ID)))
        qDebug() << "Cannot select from members accounts";

    //check if the member is found
    while(query.next())
        count++;

    if(count != 1)
    {
        QMessageBox::warning(this, "Not Found", "Member account not Found");
        ui->ID->clear();
    }
    else
    {
        //Retrieve the fields identified by ID
        if(query.first())
        {
            firstName = query.value(1).toString();
            lastName = query.value(2).toString();
            phone = query.value(3).toString();
            mail = query.value(4).toString();
            gender = query.value(5).toString();
        }
    }

    //Show the fields in the corresponding line Edit
    ui->firstName->setText(firstName);
    ui->lastName->setText(lastName);
    ui->phone->setText(phone);
    ui->mail->setText(mail);
    ui->gender->setCurrentText(gender);

}

void editMember::on_editMemberBtn_clicked()
{
    //get the content of the line edits
    QString ID = ui->ID->text();
    QString firstName = ui->firstName->text();
    QString lastName = ui->lastName->text();
    QString phone = ui->phone->text();;
    QString mail = ui->mail->text();
    QString gender = ui->gender->currentText();

    //call the mail Database
    digitalLibrary lib;
    auto db = lib.db;

    //Define the query
    auto query = QSqlQuery(db);
    QString searchID = {"UPDATE members SET firstName = '"+firstName+"',"
                        "lastName = '"+lastName+"', phone = '"+phone+"',"
                        "email = '"+mail+"', gender = '"+gender+"'"
                        " WHERE ID = '"+ID+"'"};
    if(!ID.isEmpty())
    {
        if(count == 1)
        {
            //execute the query
            if(!query.exec(searchID))
                qDebug() << "Cannot update members";
            else
                QMessageBox::information(this, "SUCCESS", "Member updated successfully");
        }
        else
            QMessageBox::warning(this, "Warning", "Search member");
    }
    else
        QMessageBox::warning(this, "Warning", "Insert ID");
}

void editMember::setValidator(){

    //Validator for ID
    QRegularExpression ID("[0-9]{1000}");
    QRegularExpressionValidator *valID = new QRegularExpressionValidator(ID, this);
    ui->ID->setValidator(valID);

    //regx for name
    QRegularExpression Name("^[A-Za-z]{7,29}$");
    QRegularExpressionValidator *valName = new QRegularExpressionValidator(Name, this);
    ui->firstName->setValidator(valName);
    ui->lastName->setValidator(valName);

    //Validator for phone number
    QRegularExpression phone("[0-9]{11}");
    QRegularExpressionValidator *valPhone = new QRegularExpressionValidator(phone, this);
    ui->phone->setValidator(valPhone);

    //Validator for email
    QRegularExpression email("^[a-zA-Z0-9_.-]+@[a-zA-Z0-9.-]+$");
    QRegularExpressionValidator *valMail = new QRegularExpressionValidator(email, this);
    ui->mail->setValidator(valMail);
}

