#include "gamemodel.h"

GameModel::GameModel() {
    assert(&m_gameEngine);
    QObject::connect(&m_gameEngine, SIGNAL(moveTile(int, int)), this, SLOT(moveGridTile(int, int)));
    QObject::connect(&m_gameEngine, SIGNAL(setData()), this, SLOT(setData()));
    QObject::connect(&m_gameEngine, SIGNAL(victory()), this, SLOT(onVictory()));
}

int GameModel::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return m_gameEngine.getRowCount() * m_gameEngine.getColumnCount();
}

QVariant GameModel::data(const QModelIndex &index, int role) const {
    if (role == Qt::UserRole + 1) {
        return m_gameEngine.getFieldValue(index.row()%4, index.row()/4);
    }
    else {
        return QVariant();
    }
}

QHash<int, QByteArray> GameModel::roleNames() const {
    QHash<int, QByteArray> role;
    role[Qt::UserRole + 1] = "number";
    return role;
}

void GameModel::moveTile(int _index) {
    m_gameEngine.move(_index % 4, _index / 4);
}

void GameModel::shuffle() {
    m_gameEngine.shuffle();
}

void GameModel::moveGridTile(int _index, int _newIndex) {
    if (_index != _newIndex) {
        int indexDiff = _index - _newIndex;

        if (indexDiff == 1) {
            beginMoveRows(QModelIndex(), _index, _index, QModelIndex(), _newIndex);
            endMoveRows();
            return;
        }
        if (indexDiff == -1) {
            beginMoveRows(QModelIndex(), _newIndex, _newIndex, QModelIndex(), _index);
            endMoveRows();
            return;
        }
        if (indexDiff >=  2) {
            beginMoveRows(QModelIndex(), _newIndex, _newIndex, QModelIndex(), _index);
            endMoveRows();
            beginMoveRows(QModelIndex(), _index, _index, QModelIndex(), _newIndex);
            endMoveRows();
            return;
        }
        if (indexDiff <= -2) {
            beginMoveRows(QModelIndex(), _index, _index, QModelIndex(), _newIndex);
            endMoveRows();
            beginMoveRows(QModelIndex(), _newIndex , _newIndex, QModelIndex(), _index);
            endMoveRows();
            return;
        }
    }
}

void GameModel::setData() {
    emit dataChanged(this->index(0),this->index(15));
}

void GameModel::onVictory(){
    emit victory();
}

