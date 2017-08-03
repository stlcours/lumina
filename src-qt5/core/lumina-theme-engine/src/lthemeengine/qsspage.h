#ifndef QSSPAGE_H
#define QSSPAGE_H

#include "tabpage.h"

namespace Ui {
class QSSPage;
}

class QListWidgetItem;
class QMenu;

class QSSPage : public TabPage
{
    Q_OBJECT

public:
    explicit QSSPage(QWidget *parent = 0);
    ~QSSPage();

    void writeSettings();

private slots:
    void on_qssListWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *);
    void on_createButton_clicked();
    void on_editButton_clicked();
    void on_removeButton_clicked();
    void on_renameButton_clicked();
    void on_qssListWidget_customContextMenuRequested(const QPoint &pos);

private:
    void readSettings();
    void findStyleSheets(const QStringList &paths);
    Ui::QSSPage *m_ui;
    QMenu *m_menu;
};

#endif // QSSPAGE_H
