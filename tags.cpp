#include "tags.h"
#include <QRandomGenerator>

Tags::Tags()
{
    startGame();
}

void Tags::startGame()
{
    int num = 0;
    QRandomGenerator *rnd = QRandomGenerator::global();
        for (auto i = 0; i < 4; i++)
            for (auto j = 0; j < 4; j++)
            {
               table[i][j] = (rnd->bounded(16));
               while(!cmp(table[i][j],num))
               {
               table[i][j] = (rnd->bounded(16));

               }
                copyTable[i][j] = table[i][j];
                num++;
            }
    while(isFinished());
}

void Tags::restartGame()
{
    for (auto i = 0; i < 4; i++)
        for (auto j = 0; j < 4; j++)
            table[i][j] = copyTable[i][j];
}

bool Tags::isFinished()
{
    int num = 0;
    for (auto i = 0; i < 4; i++)
        for (auto j = 0; j < 4; j++)
        {
           if((i==3 && j==1 && table[i][j] == 14) || (i==3 && j==2 && table[i][j] == 13))
               continue;
            if (table[i][j] != num )
            return false;
            num++;
         }
    return true;
}

bool Tags::reCalc(int r, int c)
{
 if(c >= 1)
 {
    if(table[r][c-1] == 15)
    {
        int a = table[r][c];
        table[r][c] =  table[r][c-1];
        table[r][c-1] = a;
        return true;
    }

 }
if(c <= 2)
 {
    if(table[r][c+1] == 15)
    {
        int a = table[r][c];
        table[r][c] =  table[r][c+1];
        table[r][c+1] = a;
        return true;
    }

 }
 if(r >= 1)
 {
    if(table[r-1][c] == 15)
    {
        int a = table[r][c];
        table[r][c] =  table[r-1][c];
        table[r-1][c] = a;
        return true;
    }

 }
 if(r <= 2)
 {
    if(table[r+1][c] == 15)
    {
        int a = table[r][c];
        table[r][c] =  table[r+1][c];
        table[r+1][c] = a;
        return true;
    }

 }
  return false;
}

int Tags::getItem(int i, int j) const
{
    return table[i][j];
}

bool Tags::cmp(int w, int e)
{
    int num = 0;
    for (auto i = 0; i < 4; i++)
{
        for (auto j = 0; j < 4; j++)
        {
            if(num == e)
                break;
            num++;
            if (table[i][j] == w)
                return false;
        }
    if(num == e)
        break;
    }
    return true;
}
