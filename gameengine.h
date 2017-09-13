#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <QObject>
#include <QVariant>
#include <assert.h>
#include <random>
#include <ctime>
#include <field.h>

const int SHUFFLE_LIMIT = 1000;

enum Direction {NONE = 0, UP = 1, RIGHT = 2, DOWN = 3, LEFT = 4};

class GameEngine : public QObject
{
    Q_OBJECT
public:
    GameEngine();
    void move(int _x, int _y);
    void shuffle();
    int  getFieldValue(int _row, int _column) const;
    unsigned int getRowCount() const;
    unsigned int getColumnCount() const;
signals:
    void moveTile(int _index, int _newIndex);
    void setData();
    void victory();
private:
    Field m_field;
    bool  m_gameRunning = true;
private:
    Direction moveDirection(int _x, int _y);
    bool isGameRunning();
};

#endif // GAMEENGINE_H
