#include "intro.h";
void joinmenu();
boolean pwCheck(string pw, string pwch);
boolean idCheck(string id);

void join(string s) {
    while (1) {
        gotoxy(33, 0);
        cout << s << endl;
        gotoxy(40, 2);
        cout << "회원가입" << endl;
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
    cout << "\t\t\t\t이름 : ";
    cin >> name;

    cout << endl << endl;
    cout << "\t\t\t\t전화번호 : ";
    cin >> ph;

    cout << endl << endl;
    cout << "\t\t\t\tID : ";
    cin >> id;

    cout << endl << endl;
    cout << "\t\t\t\t비밀번호 : ";
    cin >> pw;

    cout << endl << endl;
    cout << "\t\t\t\t비밀번호 확인 : ";
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
                join("중복된 아이디입니다.");

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
        join("비밀번호를 다시 확인해 주세요");
        return false;
    }

}