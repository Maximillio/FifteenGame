#include "gameengine.h"

void GameEngine::render()
{
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
    shuffle();
}

void GameEngine::move(int _x, int _y)
{
    assert(_x >= 0 && _y >= 0 && _x < 4 && _y < 4);
    int numberToMove = field.field[_x][_y];
    int newX = _x, newY = _y;
    if (gameRunning)
    {
        switch (moveDirection(_x, _y))
        {
            case UP:
            {
                field.field[_x][_y+1] = field.field[_x][_y];
                field.field[_x][_y] = 0;
                ++newY;
                break;
            }
            case RIGHT:
            {
                field.field[_x+1][_y] = field.field[_x][_y];
                field.field[_x][_y] = 0;
                ++newX;
                break;
            }
            case DOWN:
            {
                field.field[_x][_y-1] = field.field[_x][_y];
                field.field[_x][_y] = 0;
                --newY;
                break;
            }
            case LEFT:
            {
                field.field[_x-1][_y] = field.field[_x][_y];
                field.field[_x][_y] = 0;
                --newX;
                break;
            }
        default: break;
        }
        if ((_x != newX) || (_y != newY))
        {
            emit moveTile(newX, newY, numberToMove);
        }
        gameRunning = isGameRunning();
    }
}

void GameEngine::shuffle()
{
    vector<vector<int> > initVector = {{0,4,8,12},
                                       {1,5,9,13},
                                       {2,6,10,14},
                                       {3,7,11,15}};
    int counter = 0;
    int zeroX = 0, zeroY = 0;
    bool checkUp = false, checkRight = false, checkDown = false, checkLeft = false;
    bool validNum;
    int direction;
    srand(std::time(0));
    while (counter < SHUFFLE_LIMIT)
    {
        checkUp    = false;
        checkRight = false;
        checkDown  = false;
        checkLeft  = false;
        if (zeroY < 3)
        {
            checkUp = true;
        }
        if (zeroX < 3)
        {
            checkRight = true;
        }
        if (zeroY > 0)
        {
            checkDown = true;
        }
        if (zeroX > 0)
        {
            checkLeft = true;
        }

        validNum = false;
        while (!validNum)
        {
            direction = rand() % 4 + 1;
            switch(direction)
            {
                case UP:
                {
                    if (checkUp)
                    {
                        validNum = true;
                    }
                    break;
                }
                case RIGHT:
                {
                    if (checkRight)
                    {
                        validNum = true;
                    }
                    break;
                }
                case DOWN:
                {
                    if (checkDown)
                    {
                        validNum = true;
                    }
                    break;
                }
                case LEFT:
                {
                    if (checkLeft)
                    {
                        validNum = true;
                    }
                    break;
                }
            }

        }
        switch (direction)
        {
            case UP:
            {
                initVector[zeroX][zeroY] = initVector[zeroX][zeroY+1];
                initVector[zeroX][zeroY+1] = 0;
                ++zeroY;
                break;
            }
            case RIGHT:
            {
                initVector[zeroX][zeroY] = initVector[zeroX+1][zeroY];
                initVector[zeroX+1][zeroY] = 0;
                ++zeroX;
                break;
            }
            case DOWN:
            {
                initVector[zeroX][zeroY] = initVector[zeroX][zeroY-1];
                initVector[zeroX][zeroY-1] = 0;
                --zeroY;
                break;
            }
            case LEFT:
            {
                initVector[zeroX][zeroY] = initVector[zeroX-1][zeroY];
                initVector[zeroX-1][zeroY] = 0;
                --zeroX;
                break;
            }
        }
        ++counter;
    }
    field.field = initVector;
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
        {
            emit moveTile(i,j, field.field[i][j]);
        }
}

void GameEngine::initRender()
{
    render();
}
