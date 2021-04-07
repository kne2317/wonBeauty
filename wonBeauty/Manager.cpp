#include "intro.h";

string managerCode = "123456789";
static string user_name, user_id, user_bt,user_major,user_ph;
static double user_rate;

int managerMenu();
void Mjoin(string s);
void Mlogin(string s);
void joinMm();
void loginMm();
boolean idCheckm(string idx);
boolean pwCheckm(string pw, string pwch);
boolean loginCHm(string id, string pw);

void manager() {
    while (1) {

        gotoxy(40, 4);

        cout << "관리자" << endl;

        int menuCode = managerMenu();

        system("cls");

        if (menuCode == 0)
            Mlogin("");

        else if (menuCode == 1)
            Mjoin(" ");

        else if (menuCode == 2)
            main();
    }
}
int managerMenu() {
    int x = 40;
    int y = 12;

    gotoxy(x - 2, y);
    cout << "> 로그인";
    gotoxy(x, y + 1);
    cout << "회원가입";
    gotoxy(x, y + 2);
    cout << "back";

    while (1) {
        int n = keyControl();
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
            int k = y - 12;
            return k;
        }
        }
    }
}
void Mjoin(string s) {
    while (1) {
        gotoxy(33, 0);
        cout << s << endl;
        gotoxy(40, 2);
        cout << "관리자 가입" << endl;
        joinMm();
        system("cls");
    }
}

void joinMm() {
    string name;
    string ph;
    string id;
    string pw;
    string pwch;
    string codeM;
    string major;
    boolean business_trip;
    double rate;

    cout << endl << endl;

    cout << "\t\t\t\t관리자 코드 : ";
    cin >> codeM;

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

    if (codeM.compare(managerCode) == 0) {
        if (idCheckm(id) == false) {
            if (pwCheckm(pw, pwch) == true) {
                system("cls");

                cout << endl << endl << endl << endl;

                cout << "\t\t\t\t분야 ex)헤어/메이크업 : ";
                cin >> major;

                cout << endl << endl << endl << endl;

                cout << "\t\t\t\t출장가능 (true or false) : ";
                cin >> business_trip;

                ofstream fout("manager_info.txt", ios::app);
                fout << id << "\t" << pw << "\t" << name << "\t" << ph << "\t" <<major<< "\t"<<business_trip<<"\t"<<0<<endl;
                main();
            }
        }
    }
    else {
        system("cls");
        Mjoin("관리자 코드를 다시 확인해 주세요.");
    }

}
void loginMm() {
    string id;
    string pw;

    cout << endl << endl << endl << endl << endl;
    cout << "\t\t\t\tID : ";
    cin >> id;

    cout << endl << endl << endl << endl;
    cout << "\t\t\t\tPW : ";
    cin >> pw;

    if (loginCHm(id, pw) == true) {
        chooseM();
    }
}

void Mlogin(string s) {
    while (1) {
        gotoxy(30, 2);
        cout << s << endl;
        gotoxy(40, 5);
        cout << "관리자 로그인" << endl;
        loginMm();
    }
}
boolean idCheckm(string idx) {
    ifstream fin;
    int offset;
    string line;
    fin.open("manager_info.txt");

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
                Mjoin("중복된 아이디입니다.");
                return true;
            }
        }
    }
    return false;
}
boolean pwCheckm(string pw, string pwch) {
    if (pw == pwch)
        return true;
    else {
        system("cls");
        Mjoin("비밀번호를 다시 확인해 주세요");
        return false;
    }

}
boolean loginCHm(string idx, string pwx) {
    ifstream fin;
    int offset;
    string line;
    fin.open("manager_info.txt");

    string name,ph,id,pw,bt,major;
    double rate;

    vector<string> uid;
    vector<string> upw;
    vector<string> uname;
    vector<string>uph;
    vector<string>ubt;
    vector<string> umajor;
    vector<double>urate;

    while (fin >> id >> pw >> name >> ph>>major>>bt>>rate) {
        uid.push_back(id);
        upw.push_back(pw);
        uname.push_back(name);
        uph.push_back(ph);
        umajor.push_back(major);
        ubt.push_back(bt);
        urate.push_back(rate);
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
                    user_major = umajor[i];
                    user_bt = ubt[i];
                    user_rate = urate[i];
                    Artist::name = user_name;
                    Artist::id = user_id;
                    Artist::bt = user_bt;
                    Artist::rate = user_rate;
                    Artist::major = user_major;
                    Artist::ph = user_ph;
                    return true;
                }
            }
        }
    }
    if (ch == true)
        return true;
    else {
        system("cls");
        Mlogin("아이디와 비밀번호를 다시 확인해 주세요");
        return false;
    }

}