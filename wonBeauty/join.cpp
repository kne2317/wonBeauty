#include "intro.h";
void joinmenu();
boolean pwCheck(string pw, string pwch);
boolean idCheck(string id);

void join(string s) {
    while (1) {
        gotoxy(33, 0);
        cout << s << endl;
        gotoxy(40, 2);
        cout << "ȸ������" << endl;
        joinmenu();
        system("cls");
    }

}
void joinmenu() {

    string name;
    string ph;
    string id;
    string pw;
    string pwch;

    cout << endl << endl;
    cout << "\t\t\t\t�̸� : ";
    cin >> name;

    cout << endl << endl;
    cout << "\t\t\t\t��ȭ��ȣ : ";
    cin >> ph;

    cout << endl << endl;
    cout << "\t\t\t\tID : ";
    cin >> id;

    cout << endl << endl;
    cout << "\t\t\t\t��й�ȣ : ";
    cin >> pw;

    cout << endl << endl;
    cout << "\t\t\t\t��й�ȣ Ȯ�� : ";
    cin >> pwch;

    if (idCheck(id) == false) {
        if (pwCheck(pw, pwch) == true) {
            ofstream fout("user_info.txt", ios::app);
            fout << id << "\t" << pw << "\t" << name << "\t" << ph << "\t" << 0<<endl;
            main();
        }
    }

}
boolean idCheck(string idx) {
    ifstream fin;
    int offset;
    string line;
    fin.open("user_info.txt");

    string name;
    string ph;
    string id;
    string pw;
    vector<string> user;

    while (fin >> id >> pw >> name >> ph) {
        user.push_back(id);
    }
    boolean ch = false;
    for (int i = 0; i < user.size(); i++) {
        if (ch == false) {
            if (user.at(i).compare(idx) == 0) {
                ch = true;
                system("cls");
                join("�ߺ��� ���̵��Դϴ�.");

                return true;
            }
        }
    }
    return false;
}
boolean pwCheck(string pw, string pwch) {
    if (pw == pwch)
        return true;
    else {
        system("cls");
        join("��й�ȣ�� �ٽ� Ȯ���� �ּ���");
        return false;
    }

}