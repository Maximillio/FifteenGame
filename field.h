#ifndef FIELD_H
#define FIELD_H

#include <vector>
#include <random>

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
    }
    void initField()
    {
        vector<int> initVector;
        vector<int>::iterator it = initVector.begin();
        int temp;
        while (it != initVector.end())
        {
            temp = rand() % 16;
            if (find(initVector.begin(), initVector.end(), temp) == initVector.end())
            {
                initVector.push_back(temp);
                ++it;
            }
        }
    }
};

#endif // FIELD_H
