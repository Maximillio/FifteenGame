#ifndef FIELD_H
#define FIELD_H

#include <QVector>

using namespace std;

struct Field
{
    QVector<QVector<int> > m_field;
    Field()
    {
        QVector<int> temp (4);
        for (int i = 0; i < 4; ++i)
        {
            m_field.push_back(temp);
        }
        m_field = {{1,5,9,13},
                   {2,6,10,14},
                   {3,7,11,15},
                   {4,8,12,0}};
    }
};

#endif // FIELD_H
