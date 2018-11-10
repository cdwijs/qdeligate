#include "deligate.h"

QWidget *Deligate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QStyledItemDelegate::createEditor(parent,option,index);
}
