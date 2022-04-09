#ifndef TAGS_H
#define TAGS_H


class Tags
{
public:
    Tags();
    void startGame();
    void restartGame();
    bool isFinished();
    bool reCalc(int r, int c);
    int getItem(int i, int j) const;
private:
    int table [4][4];
    int copyTable [4][4];
    bool cmp(int w, int e);
};

#endif // TAGS_H
