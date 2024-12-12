// mainwindow.h
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>

class QTextEdit;
class QPushButton;
class QTextDocument;

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void openFile();
    void highlightNumbersAndEmails();

private:
    QTextEdit *m_textEdit;
    QPushButton *m_openFileButton;
    QTextDocument *m_textDocument;
};
#endif // MAINWINDOW_H
