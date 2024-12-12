#ifndef MUSICMODEL_H
#define MUSICMODEL_H

#include <QStandardItemModel>

class MusicModel : public QStandardItemModel
{
    Q_OBJECT

public:
    explicit MusicModel(QObject *parent = nullptr);

    // Method to add a CD
    void addCD(const QString &composer, const QString &albumName, double replacementValue, int rating);

private:
    // Method to update the row color based on replacement value
    void updateRowColor(int row);

private slots:
    // Slot to update row color when replacement value is edited
    void updateRowColorOnEdit(const QModelIndex &index);
};

#endif // MUSICMODEL_H
