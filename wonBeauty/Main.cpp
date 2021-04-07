#include "intro.h"
int main(void) {
    init();
    while (1) {

        gotoxy(40, 4);

        cout << "Beauty" << endl;

        int menuCode = -1;

        menuCode=mainMenu();

        system("cls");

        if (menuCode == 0)
            login("");

        else if (menuCode == 1)
            join(" ");

        else if (menuCode == 2)
            manager();
    }
}
int mainMenu() {
    int x = 40;
    int y = 12;
    gotoxy(x - 2, y);
    cout << "> 로그인";
    gotoxy(x, y + 1);
    cout << "회원가입";
    gotoxy(x, y + 2);
    cout << "관리자";
    int n = -1;

    while (1) {
        n = keyControl();
        switch (n) {
        case UP: {
            if (y > 12) {
                gotoxy(x - 2, y);
                cout << " ";
                gotoxy(x - 2, --y);
                cout << ">";
            }
            break;
        }
        case DOWN: {
            if (y < 14) {
                gotoxy(x - 2, y);
                cout << " ";
                gotoxy(x - 2, ++y);
                cout << ">";
            }
            break;
        }
        case SUBMIT: {
            return y - 12;
        }
        }
    }
}
void init() {
    system("mode con: cols=90 lines=25 | title Beauty_shop");

    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO ConsoleCursor;
    ConsoleCursor.bVisible = 0;
    ConsoleCursor.dwSize = 1;
    SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);

}