#ifndef _UNIVERSE_H_
#define _UNIVERSE_H_

void gotoxy(int, int);
class Sun {
private:
    int x, y;
    char initialCh;

public:
    Sun(int, int, char);
    void Show();
    void Hide();
    int GetX();
    int GetY();
};

class Earth {
private:
    int r;
    int x, y;
    char initialCh;
    Sun* pSun;

public:
    Earth(int, char, Sun*);
    void Revolve(double);
    void Show();
    void Hide();
};
#endif
