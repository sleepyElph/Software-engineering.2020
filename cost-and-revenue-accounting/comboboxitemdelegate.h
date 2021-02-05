#ifndef COMBOBOXITEMDELEGATE_H
#define COMBOBOXITEMDELEGATE_H
#include <QStyledItemDelegate>
#include <QComboBox>

// Класс для выбора месяца в таблице:
class ComboBoxItemDelegate : public QStyledItemDelegate //унаследован от класса QStyledItemDelegate
{
    Q_OBJECT//макрос,в котором планируется описать сигналы и/или слоты

public:    
    ComboBoxItemDelegate(QObject *parent = nullptr);//Конструктор

    // Перегрузка методов класса QStyledItemDelegate
    // Метод создания выпадающего списка для выбора месяца
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override;

    // Метод для установки текущего значения в выпадающем списке
    void setEditorData(QWidget *editor, const QModelIndex &index) const override;

    // Метод для запоминания выбранного в выпадающем списке значения
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const override;

    // Обработчик событий в выпадающем списке
    bool editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index);

private slots:

    void currentIndexChanged(int index);
    void currentIndexChanged(const QString &text);

private:
    //mutable — значит "не const ни при каких обстоятельствах"
    mutable QComboBox *cb;
    mutable QModelIndex idx;

};

#endif // COMBOBOXITEMDELEGATE_H
