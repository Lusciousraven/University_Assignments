// mainwindow.cpp
#include "mainwindow.h"
#include <QTextEdit>
#include <QPushButton>
#include <QFileDialog>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QTextDocument>
#include <QTextCursor>
#include <QRegularExpression>

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    m_textEdit = new QTextEdit(this);
    m_openFileButton = new QPushButton("Open File", this);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(m_textEdit);
    layout->addWidget(m_openFileButton);

    setLayout(layout);

    connect(m_openFileButton, &QPushButton::clicked, this, &MainWindow::openFile);
}

MainWindow::~MainWindow()
{
}

void MainWindow::openFile()
{
    QString filePath = QFileDialog::getOpenFileName(this, tr("Open Text File"), "", tr("Text Files (*.txt)"));
    if (!filePath.isEmpty()) {
        QFile file(filePath);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
            return;
        }

        QTextStream in(&file);
        QString fileContent = in.readAll();
        m_textEdit->setText(fileContent);

        highlightNumbersAndEmails();
    }
}

void MainWindow::highlightNumbersAndEmails()
{
    m_textDocument = m_textEdit->document();
    QTextCursor cursor(m_textDocument);
    QTextCharFormat format;

    // Regular expression patterns
    QRegularExpression phonePattern("\\b(\\d{3}[-\\.\\s]?\\d{3}[-\\.\\s]?\\d{4})\\b");
    QRegularExpression emailPattern("\\b\\S+@\\S+\\.\\S+\\b");

    // Highlight phone numbers and email addresses
    cursor.beginEditBlock();
    cursor.movePosition(QTextCursor::Start);
    while (!cursor.isNull() && !cursor.atEnd()) {
        // Highlight email addresses
        cursor = m_textDocument->find(emailPattern, cursor);
        if (!cursor.isNull()) {
            format.setForeground(Qt::blue);
            cursor.mergeCharFormat(format);
        }

        // Highlight phone numbers
        cursor = m_textDocument->find(phonePattern, cursor);
        if (!cursor.isNull()) {
            format.setForeground(Qt::blue);
            cursor.mergeCharFormat(format);
            cursor.movePosition(QTextCursor::EndOfBlock);
        }
    }
    cursor.endEditBlock();
}

