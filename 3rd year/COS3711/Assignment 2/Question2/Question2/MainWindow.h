#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QTableWidget>
#include <QDateEdit>
#include <QFileDialog>
#include "RegistrationList.h"
#include "registrationlistwriter.h"

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void addRegistration();
    void updateTable();
    void saveRegistrationList();

private:
    QLineEdit *m_nameEdit;
    QLineEdit *m_affiliationEdit;
    QLineEdit *m_emailEdit;
    QDateEdit *m_bookingDateEdit;
    QLineEdit *m_typeEdit;
    QPushButton *m_addButton;
    QPushButton *m_saveButton;
    QTableWidget *m_tableWidget;
    RegistrationList *m_registrationList;

    void setupUi();
};

#endif // MAINWINDOW_H
