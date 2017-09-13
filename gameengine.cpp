#include "gameengine.h"


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
        emit victory();
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
//    int numberToMove = m_field.m_field[_x][_y];
    int newX = _x, newY = _y;
    if (m_gameRunning)
    {
        switch (moveDirection(_x, _y))
        {
            case UP:
            {
                m_field.m_field[_x][_y+1] = m_field.m_field[_x][_y];
                m_field.m_field[_x][_y]   = 0;
                ++newY;
                break;
            }
            case RIGHT:
            {
                m_field.m_field[_x+1][_y] = m_field.m_field[_x][_y];
                m_field.m_field[_x][_y]   = 0;
                ++newX;
                break;
            }
            case DOWN:
            {
                m_field.m_field[_x][_y-1] = m_field.m_field[_x][_y];
                m_field.m_field[_x][_y]   = 0;
                --newY;
                break;
            }
            case LEFT:
            {
                m_field.m_field[_x-1][_y] = m_field.m_field[_x][_y];
                m_field.m_field[_x][_y]   = 0;
                --newX;
                break;
            }

        default: break;
        }
        if (_x != newX || _y != newY)
        {
            emit moveTile(_x+4*_y, newX+4*newY);
        }
        m_gameRunning = isGameRunning();
    }
}

void GameEngine::shuffle()
{
    if (!m_gameRunning)
    {
        m_gameRunning = true;
    }
    QVector<QVector<int> > initVector = {{1,5,9,13},
                                         {2,6,10,14},
                                         {3,7,11,15},
                                         {4,8,12,0}};
    m_field.m_field = initVector;
    emit setData();

    int  counter = 0,
         zeroX   = 3,
         zeroY   = 3,
         direction;

    bool checkUp    = false,
         checkRight = false,
         checkDown  = false,
         checkLeft  = false,
         validNum;
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
                emit moveTile(zeroX+4*(zeroY-1), zeroX+4*zeroY);
                break;
            }
            case RIGHT:
            {
                initVector[zeroX][zeroY]   = initVector[zeroX+1][zeroY];
                initVector[zeroX+1][zeroY] = 0;
                ++zeroX;
                emit moveTile((zeroX-1)+4*zeroY, zeroX+4*zeroY);
                break;
            }
            case DOWN:
            {
                initVector[zeroX][zeroY]   = initVector[zeroX][zeroY-1];
                initVector[zeroX][zeroY-1] = 0;
                --zeroY;
                emit moveTile(zeroX+4*(zeroY+1), zeroX+4*zeroY);
                break;
            }
            case LEFT:
            {
                initVector[zeroX][zeroY]   = initVector[zeroX-1][zeroY];
                initVector[zeroX-1][zeroY] = 0;
                --zeroX;
                emit moveTile((zeroX+1)+4*zeroY, zeroX+4*zeroY);
                break;
            }
        }
        ++counter;
    }
    m_field.m_field = initVector;
}

int GameEngine::getFieldValue(int _row, int _column) const
{
    if ((_row < m_field.m_field.size())
            && (_column < m_field.m_field[0].size()))
    {
        return m_field.m_field[_row][_column];
    }
    else
    {
        return -1;
    }
}

unsigned int GameEngine::getRowCount() const
{
    return m_field.m_field.size();
}

unsigned int GameEngine::getColumnCount() const
{
    return m_field.m_field[0].size();
}

