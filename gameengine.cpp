#include "gameengine.h"

void GameEngine::render()
{
    emit clear();
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            if (field.field[i][j] != 0)
                emit draw(i, j, field.field[i][j]);
        }
    }
}

Direction GameEngine::moveDirection(int _x, int _y)
{
    bool checkUp = false, checkRight = false, checkDown = false, checkLeft = false;

    if (_x > 0)
    {
        checkLeft = true;
    }
    if (_y > 0)
    {
        checkDown = true;
    }
    if (_x < 3)
    {
        checkRight = true;
    }
    if (_y < 3)
    {
        checkUp = true;
    }
    if (checkUp)
    {
        if (field.field[_x][_y+1] == 0) return UP;
    }
    if (checkRight)
    {
        if (field.field[_x+1][_y] == 0) return RIGHT;
    }
    if (checkDown)
    {
        if (field.field[_x][_y-1] == 0) return DOWN;
    }
    if (checkLeft)
    {
        if (field.field[_x-1][_y] == 0) return LEFT;
    }
    return NONE;
}

bool GameEngine::isGameRunning()
{
    static vector<vector<int> > winConditionFirst = {{0,4,8,12},
                                                     {1,5,9,13},
                                                     {2,6,10,14},
                                                     {3,7,11,15}};
    static vector<vector<int> > winConditionSecond = {{1,5,9,13},
                                                      {2,6,10,14},
                                                      {3,7,11,15},
                                                      {4,8,12,0}};
    if ((field.field == winConditionFirst) || (field.field == winConditionSecond))
    {
        emit displayWinMessage();
        return false;
    }
    else
    {
        return true;
    }
}

GameEngine::GameEngine()
{

}

void GameEngine::move(int _x, int _y)
{
    assert(_x >= 0 && _y >= 0 && _x < 4 && _y < 4);

    if (gameRunning)
    {
        switch (moveDirection(_x, _y))
        {
            case UP:
            {
                field.field[_x][_y+1] = field.field[_x][_y];
                field.field[_x][_y] = 0;
                break;
            }
            case RIGHT:
            {
                field.field[_x+1][_y] = field.field[_x][_y];
                field.field[_x][_y] = 0;
                break;
            }
            case DOWN:
            {
                field.field[_x][_y-1] = field.field[_x][_y];
                field.field[_x][_y] = 0;
                break;
            }
            case LEFT:
            {
                field.field[_x-1][_y] = field.field[_x][_y];
                field.field[_x][_y] = 0;
                break;
            }
        default: break;
        }
        render();
        gameRunning = isGameRunning();
    }
}

void GameEngine::initRender()
{
    render();
}
