#include "gameengine.h"

void GameEngine::render()
{
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            if (m_field.m_field[i][j] != 0)
                emit draw(i, j, m_field.m_field[i][j]);
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
        if (m_field.m_field[_x][_y+1] == 0) return UP;
    }
    if (checkRight)
    {
        if (m_field.m_field[_x+1][_y] == 0) return RIGHT;
    }
    if (checkDown)
    {
        if (m_field.m_field[_x][_y-1] == 0) return DOWN;
    }
    if (checkLeft)
    {
        if (m_field.m_field[_x-1][_y] == 0) return LEFT;
    }
    return NONE;
}

bool GameEngine::isGameRunning()
{
    static QVector<QVector<int> > winCondition = {{1,5,9,13},
                                                      {2,6,10,14},
                                                      {3,7,11,15},
                                                      {4,8,12,0}};

    if (m_field.m_field == winCondition)
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
    int numberToMove = m_field.m_field[_x][_y];
    int newX = _x, newY = _y;
    if (m_gameRunning)
    {
        switch (moveDirection(_x, _y))
        {
            case UP:
            {
                m_field.m_field[_x][_y+1] = m_field.m_field[_x][_y];
                m_field.m_field[_x][_y] = 0;
                ++newY;
                break;
            }
            case RIGHT:
            {
                m_field.m_field[_x+1][_y] = m_field.m_field[_x][_y];
                m_field.m_field[_x][_y] = 0;
                ++newX;
                break;
            }
            case DOWN:
            {
                m_field.m_field[_x][_y-1] = m_field.m_field[_x][_y];
                m_field.m_field[_x][_y] = 0;
                --newY;
                break;
            }
            case LEFT:
            {
                m_field.m_field[_x-1][_y] = m_field.m_field[_x][_y];
                m_field.m_field[_x][_y] = 0;
                --newX;
                break;
            }
        default: break;
        }
        if ((_x != newX) || (_y != newY))
        {
            emit moveTile(newX, newY, numberToMove);
        }
        m_gameRunning = isGameRunning();
    }
}

void GameEngine::shuffle()
{
    emit clearMessage();
    if (!m_gameRunning)
    {
        m_gameRunning = true;
    }
    QVector<QVector<int> > initVector = {{1,5,9,13},
                                         {2,6,10,14},
                                         {3,7,11,15},
                                         {4,8,12,0}};
    int  counter = 0;
    int  zeroX   = 3,
         zeroY   = 3;

    bool checkUp    = false,
         checkRight = false,
         checkDown  = false,
         checkLeft  = false;
    bool validNum;
    int  direction;
    srand(std::time(0));
    while (counter < SHUFFLE_LIMIT)
    {
        checkUp    = false;
        checkRight = false;
        checkDown  = false;
        checkLeft  = false;
        if (zeroY < 3)
        {
            checkUp    = true;
        }
        if (zeroX < 3)
        {
            checkRight = true;
        }
        if (zeroY > 0)
        {
            checkDown  = true;
        }
        if (zeroX > 0)
        {
            checkLeft  = true;
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
                initVector[zeroX][zeroY]   = initVector[zeroX][zeroY+1];
                initVector[zeroX][zeroY+1] = 0;
                ++zeroY;
                break;
            }
            case RIGHT:
            {
                initVector[zeroX][zeroY]   = initVector[zeroX+1][zeroY];
                initVector[zeroX+1][zeroY] = 0;
                ++zeroX;
                break;
            }
            case DOWN:
            {
                initVector[zeroX][zeroY]   = initVector[zeroX][zeroY-1];
                initVector[zeroX][zeroY-1] = 0;
                --zeroY;
                break;
            }
            case LEFT:
            {
                initVector[zeroX][zeroY]   = initVector[zeroX-1][zeroY];
                initVector[zeroX-1][zeroY] = 0;
                --zeroX;
                break;
            }
        }
        ++counter;
    }
    m_field.m_field = initVector;
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
        {
            emit moveTile(i,j, m_field.m_field[i][j]);
        }
}

void GameEngine::initRender()
{
    render();
}
