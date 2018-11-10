#ifndef DELIGATE_H
#define DELIGATE_H

#include <QStyledItemDelegate>

class Deligate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                             const QModelIndex &index) const override;
};

#endif // DELIGATE_H
