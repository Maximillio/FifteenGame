#ifndef FIELD_H
#define FIELD_H

#include <vector>
#include <random>
#include <ctime>

using namespace std;

struct Field
{
    vector<vector<int> > field;
    Field()
    {
        vector<int> temp (4);
        for (int i = 0; i < 4; ++i)
        {
            field.push_back(temp);
        }
        initField();
    }
    void initField()
    {
        vector<int> initVector;
        int counter = 0;
        int temp;
        srand(std::time(0));
        while (counter != 16)
        {
            temp = rand() % 16;
            if (find(initVector.begin(), initVector.end(), temp) == initVector.end())
            {
                initVector.push_back(temp);
                ++counter;
            }
        }
        for (int i = 0; i < 16; ++i)
        {
            field[i%4][i/4] = initVector[i];
        }
    }
};

#endif // FIELD_H
