#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <QObject>
#include <QVariant>
#include <assert.h>
#include <field.h>

enum Direction {NONE = 0, UP = 1, RIGHT = 2, DOWN = 3, LEFT = 4};

class GameEngine : public QObject
{
    Q_OBJECT
private:
    Field field;
    bool gameRunning = true;

    void render();

    Direction moveDirection(int _x, int _y);
    bool isGameRunning();
public:
    GameEngine();

public slots:
    void move(int _x, int _y);
    void initRender();
signals:
    void draw(QVariant _x, QVariant _y, QVariant _number);
    void clear();
};

#endif // GAMEENGINE_H
