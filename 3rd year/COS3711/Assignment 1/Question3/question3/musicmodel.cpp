#include "MusicModel.h"
#include <QBrush>

MusicModel::MusicModel(QObject *parent)
    : QStandardItemModel(parent)
{
    // Set up column headers
    setColumnCount(4);
    setHorizontalHeaderLabels({"Composer", "Album Name", "Replacement Value", "Rating"});

    // Connect signal for updating row color on edit
    connect(this, &MusicModel::dataChanged, this, &MusicModel::updateRowColorOnEdit);
}

void MusicModel::addCD(const QString &composer, const QString &albumName, double replacementValue, int rating)
{
    // Create new row items
    QList<QStandardItem *> rowItems;
    rowItems << new QStandardItem(composer)
             << new QStandardItem(albumName)
             << new QStandardItem(QString::number(replacementValue, 'f', 2))
             << new QStandardItem(QString::number(rating));

    // Append the new row to the model
    appendRow(rowItems);

    // Update row color based on replacement value
    updateRowColor(rowCount() - 1);
}

void MusicModel::updateRowColor(int row)
{
    // Get the replacement value from the model
    double replacementValue = item(row, 2)->text().toDouble();

    // Define brush color based on replacement value
    QBrush brush(replacementValue >= 200 ? Qt::red : Qt::white);

    // Apply brush color to all columns in the row
    for (int col = 0; col < columnCount(); ++col) {
        item(row, col)->setBackground(brush);
    }
}

void MusicModel::updateRowColorOnEdit(const QModelIndex &index)
{
    // Check if the edited index is in the replacement value column
    if (index.column() == 2) {
        // Update row color based on edited replacement value
        updateRowColor(index.row());
    }
}

