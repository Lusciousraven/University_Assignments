#ifndef RATINGDELEGATE_H
#define RATINGDELEGATE_H

#include <QStyledItemDelegate>
#include <QObject>

class RatingDelegate : public QStyledItemDelegate
{
public:
    RatingDelegate(QObject *parent = nullptr);
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
};

#endif // RATINGDELEGATE_H
