#include "gameengine.h"

Direction GameEngine::moveDirection(int x, int y)
{
    bool checkUp, ckeckRight, checkDown, checkLeft = false;

    if (x > 0)
    {
        checkLeft = true;
    }
    if (y > 0)
    {
        checkDown = true;
    }
    if (x < 3)
    {
        checkRight = true;
    }
    if (y < 3)
    {
        checkUp = true;
    }
    if (checkUp)
    {
        if (field[x][y+1] == 0) return UP;
    }
    if (checkRight)
    {
        if (field[x+1][y] == 0) return RIGHT;
    }
    if (checkDown)
    {
        if (field[x][y-1] == 0) return DOWN;
    }
    if (checkLeft)
    {
        if (field[x-1][y] == 0) return LEFT;
    }
}

GameEngine::GameEngine()
{

}

void GameEngine::move(int x, int y)
{
    assert(x >= 0 && y >=0 && x < 4 && y < 4);

    if (gameRunnig)
    {
        switch (moveDirection(x, y))
        {
            case Direction::UP:    {field[x][y+1] = field[x][y]; field[x][y] = 0; break;}
            case Direction::RIGHT: {field[x+1][y] = field[x][y]; field[x][y] = 0; break;}
            case Direction::DOWN:  {field[x][y-1] = field[x][y]; field[x][y] = 0; break;}
            case Direction::LEFT:  {field[x-1][y] = field[x][y]; field[x][y] = 0; break;}
        }
        gameRunning = isGameOver();
    }
}
