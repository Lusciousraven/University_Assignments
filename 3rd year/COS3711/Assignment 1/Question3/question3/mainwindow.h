#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include "MusicModel.h"
//#include "RatingDelegate.h"

class MusicModel;
class QLineEdit;
class QPushButton;
class QDoubleSpinBox;
class QSpinBox;
class QTableView;
class QGridLayout;

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void addCD();
    void enableButton();
    void deleteCD();

private:
    void setupGui();

    QLineEdit *m_composerEdit;
    QLineEdit *m_albumEdit;
    QDoubleSpinBox *m_replacementCostSpinBox;
    QSpinBox *m_ratingSpinBox;
    QPushButton *m_addButton;
    QPushButton *m_deleteButton;
    QTableView *m_tableView;
    MusicModel *m_model;
};

#endif // MAINWINDOW_H
