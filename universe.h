#ifndef _UNIVERSE_H_
#define _UNIVERSE_H_

const int angle_diff     = 5;
const int sleep_duration = 300;

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
    void Revolve(short);
    void Show();
    void Hide();
    int GetX();
    int GetY();
};

class Moon {
private:
    int r;
    int x, y;
    char initialCh;
    Earth* pEarth;

public:
    Moon(int, char, Earth*);
    void Revolve(short);
    void Show();
    void Hide();
};
#endif
