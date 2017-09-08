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
    }
};

#endif // FIELD_H
