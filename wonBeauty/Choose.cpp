#include "intro.h"

void choose() {
    while (1) {

        gotoxy(40, 4);

        int menuCode = chooseMenu();

        system("cls");

        if (menuCode == 0)
            reserve();

        else if (menuCode == 1)
            record();

        else if (menuCode == 2)
            choose();

        else if (menuCode == 3)
            choose();

        else if (menuCode == 4)
            main();
    }
}

int chooseMenu() {
    int x = 38;
    int y = 10;

    system("cls");
    gotoxy(x - 2, y);
    cout << "> �����ϱ�";
    gotoxy(x, y + 1);
    cout << "�̿� ��� ����";
    gotoxy(x, y + 2);
    cout << "�ı� �ۼ��ϱ�";
    gotoxy(x, y + 3);
    cout << "���� ���� / Ż��";
    gotoxy(x, y + 4);
    cout << "�α׾ƿ�";


    while (1) {
        int n = keyControl();
        switch (n) {
        case UP: {
            if (y > 10) {
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
            return y - 10;
        }
        }
    }
}
