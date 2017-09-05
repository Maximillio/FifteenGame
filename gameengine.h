#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <QObject>
#include <field.h>

enum Direction {NONE = 0, UP = 1, RIGHT = 2, DOWN = 3, LEFT = 4};

class GameEngine : public QObject
{
    Q_OBJECT
private:
    Field field;
    bool gameRunning;
    Direction moveDirection(int x, int y);
    bool isGameOver();
public:
    GameEngine();
    void move(int x, int y);

};

#endif // GAMEENGINE_H
