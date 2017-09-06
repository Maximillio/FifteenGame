#ifndef FIELD_H
#define FIELD_H

#include <vector>

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
};

#endif // FIELD_H
