#include "unp.h"
#include <QApplication>
#include <QtWidgets>
#include <QString>
#include "QStringList"
#include <QtDebug>
#include <iostream>
#include <string>

QString generateUsername(QString firstN, QString lastN) {

    QString userN;
    int i = 0;


    if (lastN.length()>=4)
    {
        lastN.resize(4);
        firstN.resize(1);
        userN = lastN + firstN;
    }

    else
    {
        userN += lastN;
        i = 4 - lastN.length();
        if (firstN.length()>=(i+1))
        {
            firstN.resize(i+1);
            userN += firstN;
        }
        else userN = lastN + firstN;
        userN += QString(5-userN.size(),'0');

    }

    userN.replace(0,1,userN.at(0).toUpper());

    return userN;
}


QString generatePassword(QString fullname)
{
    QString password;
    int randomIndex;

    for( int i = 0; i<5; i++)
    {
        randomIndex = rand()% fullname.length();
        password += fullname[randomIndex];

    }

    return password;
}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString fullName, fName, lName, userName, password, str;
    QString info = QInputDialog::getText(nullptr,"Username and Password generator", "Please enter full name");

    QStringList sInfo = info.split(" ");



    if (sInfo.length()>=2)
    {
            fName = sInfo[0].toLower();
            lName = sInfo[sInfo.length()-1].toLower();
            //fullName = fName + lName;

            for (int i=0; i<sInfo.length(); i++ )
            {
            fullName+= sInfo[i];
            }

            userName = generateUsername(fName,lName);

            password = generatePassword(fullName);


            str = QString("Username is: %1\n Password is: %2").arg(userName).arg(password);
            QMessageBox::information(nullptr,"UNP",str);
    }

    else
            QMessageBox::information(nullptr,"UNP","Please enter name AND surname");

    //UNP w;
   //w.show();
    return a.exec();
}
