#include "intro.h";
#include <time.h>
#pragma warning(disable : 4996)
void record() {

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
    vector<string>check;

    while (fin >> userid >> artid >> artname >> major >> notice >> date) {
        if (UserInfo::id.compare(userid) == 0) {
            time_t curTime = time(NULL);
            struct tm* pLocal = NULL;
            #if defined(_WIN32) || defined(_WIN64) 
            pLocal = localtime(&curTime);
            #else 
            localtime_r(&curTime, pLocal);
            #endif 
            if (pLocal == NULL) { return; }
            string year = date.substr(0, 4);
            string month = date.substr(4, 2);
            string day = date.substr(6, 2);
            string hour = date.substr(8, 2);

            vuserid.push_back(userid);
            vartid.push_back(artid);
            vartname.push_back(artname);
            vmajor.push_back(major);
            vnotice.push_back(notice);
            vdate.push_back(date);
            if (stoi(year) >= (pLocal->tm_year + 1900) && stoi(month) >= (pLocal->tm_mon + 1) && stoi(day) >= (pLocal->tm_mday) && stoi(hour) > (pLocal->tm_hour)){ check.push_back("이용 예정"); }
            else { check.push_back("이용 완료"); }
        }
    }

    system("cls");

    cout << endl << endl << endl << "\t\t\t\t" << UserInfo::name << "회원님의 이용 기록입니다." << endl << endl<<endl;
    if (vuserid.size() < 7) {
        for (int i = vuserid.size()-1; i >=0; i--) {
            cout << "\t" << vdate[i].substr(0, 4) << "년 " << vdate[i].substr(4, 2) << "월 " << vdate[i].substr(6, 2) << "일 " << vdate[i].substr(8, 2) << "시 \t" << vartname[i]<<"아티스트" << "\t" << vmajor[i] <<"\t"<<check[i]<< endl << endl;
        }
    }
    else {
        for (int i = vuserid.size() - 1; i >= 0; i--) {
            cout << "\t" << vdate[i].substr(0, 4) << "년 " << vdate[i].substr(4, 2) << "월 " << vdate[i].substr(6, 2) << "일 " << vdate[i].substr(8, 2) << "시 \t" << vartname[i] << "아티스트" << "\t" << vmajor[i] << "\t" << check[i] << endl << endl;
        }
    }
    string ch = "";
    cout << "\t\t\t\t\t" << "확인 (y/n)";
    cin >> ch;

    if (ch.compare("y") == 0) {
        choose();
    }
    else {
        record();
    }
}