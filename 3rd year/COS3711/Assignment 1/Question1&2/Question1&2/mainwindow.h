#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "reviewdata.h"
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QDateEdit>
#include <QCheckBox>
#include <QMetaObject>

class MainWindow : public QWidget
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    QString getSoftwareName() const;
    QDate getReviewDate() const;
    bool isRecommended() const;
    ~MainWindow();


private slots:
    void addReview();
    void displayReviews();
    void displayReviewDetails(); //For question2

private:
    QLabel *titleLabel;
    QLabel *softwareNameLabel;
    QLineEdit *softwareNameLineEdit;
    QLabel *reviewDateLabel;
    QDateEdit *reviewDateEdit;
    QLabel *recommendationLabel;
    QCheckBox *recommendationCheckBox;
    QPushButton *addReviewButton;
    QPushButton *displayReviewsButton;
    QVector<ReviewData> reviewDataList; //Container to store several reviews
    QPushButton *displayReviewDetailsButton;

};

#endif // MAINWINDOW_H
