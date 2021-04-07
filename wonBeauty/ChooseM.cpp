#include "intro.h"
#include <time.h>
#pragma warning(disable : 4996)
void checkReserve();
void chooseM() {
    while (1) {

        gotoxy(40, 4);

        int menuCode = chooseMenuM();

        system("cls");

        if (menuCode == 0)
            checkReserve();

        else if (menuCode == 1)
            chooseM();

        else if (menuCode == 2)
            chooseM();

        else if (menuCode == 3)
            chooseM();

        else if (menuCode == 4)
            main();
    }
}

int chooseMenuM() {
    int x = 38;
    int y = 10;

    system("cls");
    gotoxy(x - 2, y);
    cout << "> 예약 확인";
    gotoxy(x, y + 1);
    cout << "회원 정보 기록";
    gotoxy(x, y + 2);
    cout << "정보 수정 / 탈퇴";
    gotoxy(x, y + 3);
    cout << "로그아웃";


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
            if (y < 13) {
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
void checkReserve() {
    ifstream fin;
    int offset;
    fin.open("reserve.txt");

    string userid;
    string artid;
    string artname;
    string major;
    string notice;
    string date;

    vector<string> vuserid;
    vector<string> vartid;
    vector<string> vartname;
    vector<string> vmajor;
    vector<string> vnotice;
    vector<string> vdate;

    while (fin >>userid >>artid>>artname>>major >>notice>>date ) {
        if (Artist::id.compare(artid)==0) {

            time_t curTime = time(NULL);
            struct tm* pLocal = NULL;
            #if defined(_WIN32) || defined(_WIN64) 
            pLocal = localtime(&curTime);
            #else 
            localtime_r(&curTime, pLocal);
            #endif 
            if (pLocal == NULL) {return;}

            string year =date.substr(0, 4);
            string month = date.substr(4, 2);
            string day = date.substr(6, 2);
            string hour = date.substr(8, 2);

            if (stoi(year) >= (pLocal->tm_year + 1900) && stoi(month) >= (pLocal->tm_mon + 1) && stoi(day) >= (pLocal->tm_mday) && stoi(hour) > (pLocal->tm_hour)) {
                vuserid.push_back(userid);
                vartid.push_back(artid);
                vartname.push_back(artname);
                vmajor.push_back(major);
                vnotice.push_back(notice);
                vdate.push_back(date);
            }
        }
    }
    
    system("cls");

    cout << endl << endl << endl<<"\t\t\t\t"<<Artist::name<<"아티스트"<<endl << endl;;
    if (vuserid.size() < 7) {
        for (int i = 0; i < vuserid.size(); i++) {
            cout << "\t\t\t" <<vdate[i].substr(0,4)<<"년 " << vdate[i].substr(4, 2) << "월 " << vdate[i].substr(6, 2) << "일 " << vdate[i].substr(8, 2) << "시 \t" << vuserid[i]<<"\t"<<vmajor[i] << endl << endl;
        }
    }
    else {
        for (int i = 0; i < 10; i++) {
            cout << "\t\t\t" << vdate[i].substr(0, 4) << "년 " << vdate[i].substr(4, 2) << "월 " << vdate[i].substr(6, 2) << "일 " << vdate[i].substr(8, 2) << "시 \t" << vuserid[i] << "\t" << vmajor[i] << endl << endl;
        }
    }
    string ch = "";
    cout << "\t\t\t\t" << "확인 (y/n)";
    cin >> ch;

    if (ch.compare("y") == 0) {
        chooseM();
    }
    else {
        checkReserve();
    }
   

}