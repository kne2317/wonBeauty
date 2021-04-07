#pragma once
#include "intro.h";

string user_name;
string user_id;
string user_ph;
int user_count;

boolean loginCH(string id, string pw);
void loginmenu();

void login(string s) {
    while (1) {
        gotoxy(30, 2);
        cout << s << endl;
        gotoxy(40, 5);
        cout << "로그인" << endl;
        loginmenu();
    }
}
void loginmenu() {

    string id;
    string pw;

    cout << endl << endl << endl << endl << endl;
    cout << "\t\t\t\tID : ";
    cin >> id;

    cout << endl << endl << endl << endl;
    cout << "\t\t\t\tPW : ";
    cin >> pw;

    if (loginCH(id, pw) == true) {
        choose();
        
    }
}
boolean loginCH(string idx, string pwx) {
    
    ifstream fin;
    int offset;
    string line;
    fin.open("user_info.txt");

    string name;
    string ph;
    string id;
    string pw;
    int count;

    vector<string> uid;
    vector<string> uph;
    vector<string> uname;
    vector<string> upw;
    vector<int> ucount;

    while (fin >> id >> pw >> name >> ph>>count) {
        uid.push_back(id);
        uph.push_back(ph);
        upw.push_back(pw);
        uname.push_back(name);
        ucount.push_back(count);
    }
    boolean ch = false;
    for (int i = 0; i < uid.size(); i++) {
        if (ch == false) {
            if (uid.at(i).compare(idx) == 0) {
                if (upw.at(i).compare(pwx) == 0) {
                    ch = true;
                    user_name = uname[i];
                    user_id = uid[i];
                    user_ph = uph[i];
                    user_count = ucount[i];
                    UserInfo::id = user_id;
                    UserInfo::name = user_name;
                    UserInfo::ph = user_ph;
                    UserInfo::count = user_count;
                    return true;
                }
            }
        }
    }
    if (ch == true)
        return true;
    else {
        system("cls");
        login("아이디와 비밀번호를 다시 확인해 주세요");
        return false;
    }
    
}