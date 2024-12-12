#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <QVector>
#include "PrimeFinder.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private slots:
    void startFindingPrimes();
    void handlePrimesFound(const QList<int>& primes);
    void closeEvent(QCloseEvent* event) override;

private:
    QLineEdit* startEdit;
    QLineEdit* endEdit;
    QLineEdit* threadsEdit;
    QPushButton* startButton;
    QWidget* centralWidget;
    QVBoxLayout* layout;
    QVector<PrimeFinder*> primeFinders;
    QVector<QTextEdit*> resultDisplays;

    void cleanUpThreads();
};

#endif // MAINWINDOW_H
