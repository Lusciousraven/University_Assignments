#ifndef UNP_H
#define UNP_H

#include <QWidget>
#include <QObject>
#include <QInputDialog>
#include <QMessageBox>


class UNP : public QWidget
{
    Q_OBJECT

public:
    UNP(QWidget *parent = nullptr);
    ~UNP();

/*private:
    QInputDialog* nameInput;
    QMessageBox* showUNP;*/
};
#endif // UNP_H
