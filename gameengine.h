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

public slots:
    void move(int _x, int _y);
    void shuffle();
    void initRender();
signals:
    void draw(QVariant _x, QVariant _y, QVariant _number);
    void moveTile(QVariant _x, QVariant _y, QVariant _number);
    void clearMessage();
    void displayWinMessage();
private:
    Field m_field;
    bool  m_gameRunning = true;
private:
    void render();
    Direction moveDirection(int _x, int _y);
    bool isGameRunning();
};

#endif // GAMEENGINE_H
