#include "intro.h"

int keyControl() {
    char temp = _getch();
    int t = _getch();
    if (t == 72)
        return UP;
    else if (t == 80)
        return DOWN;
    else if (t == 75)
        return LEFT;
    else if (t == 77)
        return RIGHT;
    else if (t == 13)
        return ENTER;
    if (temp == ' ') {
        return SUBMIT;
    }
}
void gotoxy(int x, int y) {
    COORD Pos; //x, y를 가지고 있는 구조체 
    Pos.X = x;
    Pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}