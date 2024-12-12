#include "RatingDelegate.h"
#include <QStyleOptionProgressBar>
#include <QApplication>
#include <QPainter>
#include <QRect>

RatingDelegate::RatingDelegate(QObject *parent)
    : QStyledItemDelegate(parent)
{
}

void RatingDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if (index.data().canConvert<int>()) {
        QRect bar = QRect(option.rect.topLeft(), QSize(option.rect.width() * (index.data().toInt()) / 100.0, option.rect.height()));
        painter->fillRect(option.rect, option.palette.dark());
        painter->fillRect(bar, option.palette.highlight());
    } else {
        QStyledItemDelegate::paint(painter, option, index);
    }
}
