#ifndef GameModel_H
#define GameModel_H

#include <QAbstractTableModel>
#include <gameengine.h>

class GameModel : public QAbstractListModel
{
    Q_OBJECT
public:
    GameModel();
    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QHash<int, QByteArray> roleNames() const;
signals:
    void victory();
public slots:
    void moveTile(int _index);
    void shuffle();
private slots:
    void moveGridTile(int _index, int _newIndex);
    void setData();
    void onVictory();
private:
    GameEngine m_gameEngine;
};

#endif // GameModel_H
