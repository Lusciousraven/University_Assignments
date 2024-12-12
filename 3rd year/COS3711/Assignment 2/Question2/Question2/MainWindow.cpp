#include "MainWindow.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QHeaderView>

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent), m_registrationList(new RegistrationList(this))
{
    setupUi();
}

MainWindow::~MainWindow()
{
}

void MainWindow::setupUi()
{
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    QHBoxLayout *formLayout = new QHBoxLayout();
    m_nameEdit = new QLineEdit(this);
    m_affiliationEdit = new QLineEdit(this);
    m_emailEdit = new QLineEdit(this);
    m_bookingDateEdit = new QDateEdit(QDate::currentDate(), this);
    m_typeEdit = new QLineEdit(this);
    m_addButton = new QPushButton("Add", this);
    m_saveButton = new QPushButton("Save", this);

    formLayout->addWidget(new QLabel("Name:"));
    formLayout->addWidget(m_nameEdit);
    formLayout->addWidget(new QLabel("Affiliation:"));
    formLayout->addWidget(m_affiliationEdit);
    formLayout->addWidget(new QLabel("Email:"));
    formLayout->addWidget(m_emailEdit);
    formLayout->addWidget(new QLabel("Booking Date:"));
    formLayout->addWidget(m_bookingDateEdit);
    formLayout->addWidget(new QLabel("Type:"));
    formLayout->addWidget(m_typeEdit);
    formLayout->addWidget(m_addButton);
    formLayout->addWidget(m_saveButton);

    mainLayout->addLayout(formLayout);

    m_tableWidget = new QTableWidget(this);
    m_tableWidget->setColumnCount(5);
    m_tableWidget->setHorizontalHeaderLabels({"Name", "Affiliation", "Email", "Booking Date", "Fee"});
    m_tableWidget->horizontalHeader()->setStretchLastSection(true);

    mainLayout->addWidget(m_tableWidget);

    connect(m_addButton, &QPushButton::clicked, this, &MainWindow::addRegistration);
    connect(m_saveButton, &QPushButton::clicked, this, &MainWindow::saveRegistrationList);

    setLayout(mainLayout);
}

void MainWindow::addRegistration()
{
    QString name = m_nameEdit->text();
    QString affiliation = m_affiliationEdit->text();
    QString email = m_emailEdit->text();
    QDate bookingDate = m_bookingDateEdit->date();
    QString type = m_typeEdit->text();

    Registration *registration = nullptr;
    if (type == "Standard")
        registration = new StandardRegistration(name, affiliation, email, bookingDate);
    else if (type == "Student")
        registration = new StudentRegistration(name, affiliation, email, bookingDate);
    else if (type == "Guest")
        registration = new GuestRegistration(name, affiliation, email, bookingDate);

    if (registration)
    {
        m_registrationList->addRegistration(registration);
        updateTable();
    }
}

void MainWindow::updateTable()
{
    m_tableWidget->setRowCount(0);

    const QList<Registration*> registrations = m_registrationList->registrations();
    for (int i = 0; i < registrations.size(); ++i)
    {
        const Registration* reg = registrations.at(i);

        m_tableWidget->insertRow(i);
        m_tableWidget->setItem(i, 0, new QTableWidgetItem(reg->getAttendee()));
        m_tableWidget->setItem(i, 1, new QTableWidgetItem(reg->getAffiliation()));
        m_tableWidget->setItem(i, 2, new QTableWidgetItem(reg->getEmail()));
        m_tableWidget->setItem(i, 3, new QTableWidgetItem(reg->getBookingDate().toString()));
        m_tableWidget->setItem(i, 4, new QTableWidgetItem(QString::number(reg->registrationFee())));
    }
}

void MainWindow::saveRegistrationList()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save Registration List"), "", tr("XML Files (*.xml)"));
    if (!fileName.isEmpty())
    {
        RegistrationListWriter writer;
        if (!writer.writeToFile(fileName, m_registrationList))
        {
            // Handle error
        }
    }
}
