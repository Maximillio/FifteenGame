#include "gameengine.h"

Direction GameEngine::moveDirection(int x, int y)
{
    bool checkUp, checkRight, checkDown, checkLeft = false;

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
        if (field.field[x][y+1] == 0) return UP;
    }
    if (checkRight)
    {
        if (field.field[x+1][y] == 0) return RIGHT;
    }
    if (checkDown)
    {
        if (field.field[x][y-1] == 0) return DOWN;
    }
    if (checkLeft)
    {
        if (field.field[x-1][y] == 0) return LEFT;
    }
    return NONE;
}

bool GameEngine::isGameOver()
{
    static vector<vector<int> > winConditionFirst = {{0,1,2,3},
                                                     {4,5,6,7},
                                                     {8,9,10,11},
                                                     {12,13,14,15}};
    static vector<vector<int> > winConditionSecond = {{1,2,3,4},
                                                      {5,6,7,8},
                                                      {9,10,11,12},
                                                      {13,14,15,0}};
    if ((field.field == winConditionFirst) || (field.field == winConditionSecond))
    {
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

void GameEngine::move(int x, int y)
{
    assert(x >= 0 && y >=0 && x < 4 && y < 4);

    if (gameRunning)
    {
        switch (moveDirection(x, y))
        {
            case UP:
            {
                field.field[x][y+1]  = field.field[x][y];
                field.field[x][y] = 0;
                break;
            }
            case RIGHT:
            {
                field.field[x+1][y]  = field.field[x][y];
                field.field[x][y] = 0;
                break;
            }
            case DOWN:
            {
                field.field[x][y-1] = field.field[x][y];
                field.field[x][y] = 0;
                break;
            }
            case LEFT:
            {
                field.field[x-1][y] = field.field[x][y];
                field.field[x][y] = 0;
                break;
            }
        default: break;
        }
        gameRunning = isGameOver();
    }
}
