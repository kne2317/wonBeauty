#include "intro.h"
int reserveMenu();
void chooseArtist(string str);
void  dateReserve(string artistid,string artname, string str, string service);
void reserveResult(string artID, string day, string service, string notice,string artname);
void reserve() {
    while (1) {

        gotoxy(40, 4);

        int menuCode = reserveMenu();

        system("cls");

        if (menuCode == 0)
            chooseArtist("메이크업");

        else if (menuCode == 1)
            chooseArtist("헤어");

        else if (menuCode == 2)
            chooseArtist("네일");

        else if (menuCode == 3)
            chooseArtist("피부관리");

        else if (menuCode == 4)
            choose();
    }
}

int reserveMenu() {
    int x = 38;
    int y = 10;

    system("cls");
    gotoxy(x - 2, y);
    cout << "> 메이크업";
    gotoxy(x, y + 1);
    cout << "헤어";
    gotoxy(x, y + 2);
    cout << "네일";
    gotoxy(x, y + 3);
    cout << "피부 관리";
    gotoxy(x, y + 4);
    cout << "취소";


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
string artistID1, artistID2, artistID3, artistID4, artistID5;
string name1, name2, name3, name4, name5;
int artistMenu(string str) {
    ifstream fin;
    int offset;
    string line;
    fin.open("manager_info.txt");

    string name;
    string ph;
    string id;
    string pw;
    string major;
    string bt;
    double rate;

    vector<string> mid;
    vector<string> mpw;
    vector<string> mname;
    vector<string>mph;
    vector<string>mmajor;
    vector<string>mbt;
    vector<double>mrate;

    while (fin >> id >> pw >> name >> ph>>major>>bt>>rate) {
        if (major.find(str) != std::string::npos) {
            mid.push_back(id);
            mpw.push_back(pw);
            mname.push_back(name);
            mph.push_back(ph);
            mmajor.push_back(major);
            if (bt.compare("t")==0)mbt.push_back("출장가능");
            else  mbt.push_back("");
            mrate.push_back(rate);
        }
    }
    system("cls");

    int x = 10;
    int y = 8;

    int r = rand() % mid.size();
    if (mid.size() > 5) {
        gotoxy(x - 2, y); r = rand() % mid.size(); artistID1 = mid[r]; name1 = mname[r];
        cout << "> " << mname[r] << " 아티스트 \t" << mmajor[r] << "\t" << mrate[r] << "\t\t" << mbt[r];
        gotoxy(x, y + 2); r = rand() % mid.size(); artistID2 = mid[r]; name2 = mname[r];
        cout << mname[r] << " 아티스트 \t" << mmajor[r] << "\t" << mrate[r] << "\t\t" << mbt[r];
        gotoxy(x, y + 4); r = rand() % mid.size(); artistID3 = mid[r]; name3 = mname[r];
        cout << mname[r] << " 아티스트 \t" << mmajor[r] << "\t" << mrate[r] << "\t\t" << mbt[r];
        gotoxy(x, y + 6); r = rand() % mid.size(); artistID4 = mid[r]; name4 = mname[r];
        cout << mname[r] << " 아티스트 \t" << mmajor[r] << "\t" << mrate[r] << "\t\t" << mbt[r];
        gotoxy(x, y + 8); r = rand() % mid.size(); artistID5 = mid[r]; name5 = mname[r];
        cout << mname[r] << " 아티스트 \t" << mmajor[r] << "\t" << mrate[r] << "\t\t" << mbt[r];
    }
    else if(mid.size()==4){
        gotoxy(x - 2, y); r =0; artistID1 = mid[r]; name1 = mname[r];
        cout << "> " << mname[r] << " 아티스트 \t" << mmajor[r] << "\t" << mrate[r] << "\t\t" << mbt[r];
        gotoxy(x, y + 2); r = 1; artistID2 = mid[r]; name2 = mname[r];
        cout << mname[r] << " 아티스트 \t" << mmajor[r] << "\t" << mrate[r] << "\t\t" << mbt[r];
        gotoxy(x, y + 4); r = 2; artistID3 = mid[r]; name3 = mname[r];
        cout << mname[r] << " 아티스트 \t" << mmajor[r] << "\t" << mrate[r] << "\t\t" << mbt[r];
        gotoxy(x, y + 6); r = 3; artistID4 = mid[r]; name4 = mname[r];
        cout << mname[r] << " 아티스트 \t" << mmajor[r] << "\t" << mrate[r] << "\t\t" << mbt[r];
    }
    else if (mid.size() == 3) {
        gotoxy(x - 2, y); r = 0; artistID1 = mid[r]; name1 = mname[r];
        cout << "> " << mname[r] << " 아티스트 \t" << mmajor[r] << "\t" << mrate[r] << "\t\t" << mbt[r];
        gotoxy(x, y + 2); r = 1; artistID2 = mid[r]; name2 = mname[r];
        cout << mname[r] << " 아티스트 \t" << mmajor[r] << "\t" << mrate[r] << "\t\t" << mbt[r];
        gotoxy(x, y + 4); r = 2; artistID3 = mid[r]; name3 = mname[r];
        cout << mname[r] << " 아티스트 \t" << mmajor[r] << "\t" << mrate[r] << "\t\t" << mbt[r];
    }
    else if (mid.size() == 2) {
        gotoxy(x - 2, y); r = 0; artistID1 = mid[r]; name1 = mname[r];
        cout << "> " << mname[r] << " 아티스트 \t" << mmajor[r] << "\t" << mrate[r] << "\t\t" << mbt[r];
        gotoxy(x, y + 2); r = 1; artistID2 = mid[r]; name2 = mname[r];
        cout << mname[r] << " 아티스트 \t" << mmajor[r] << "\t" << mrate[r] << "\t\t" << mbt[r];
    }
    else if (mid.size() == 1) {
        gotoxy(x - 2, y); r = 0; artistID1 = mid[r]; name1 = mname[r];
        cout << "> " << mname[r] << " 아티스트 \t" << mmajor[r] << "\t" << mrate[r] << "\t\t" << mbt[r];
    }
    else if (mid.size() == 0) {
        gotoxy(x - 2, y); 
        cout << "> " << "이 분야에는 아티스트가 없습니다.";
    }
    
    gotoxy(x, y + 10);
    cout << "취소";


    while (1) {
        int n = keyControl();
        switch (n) {
        case UP: {
            if (y > 8) {
                gotoxy(x - 2, y);
                cout << " ";
                gotoxy(x - 2,y-2);
                y -= 2;
                cout << ">";
            }
            break;
        }
        case DOWN: {
            if (y < 18) {
                gotoxy(x - 2, y);
                cout << " ";
                gotoxy(x - 2, y+2);
                y += 2;
                cout << ">";
            }
            break;
        }
        case SUBMIT: {
            return y - 8;
        }
        }
    }
    return 0;
}


void chooseArtist(string major) {
    while (1) {
        gotoxy(40, 4);
        int menuCode = artistMenu(major);
        system("cls");
        if (menuCode == 0)
            dateReserve(artistID1,name1,"",major);
        else if (menuCode == 2)
            dateReserve(artistID2, name2, "", major);
        else if (menuCode == 4)
            dateReserve(artistID3, name3, "", major);
        else if (menuCode == 6)
            dateReserve(artistID4, name4, "", major);
        else if (menuCode == 8)
            dateReserve(artistID5, name5, "", major);
        else if (menuCode == 10)
            choose();
    }
}

void dateReserve(string artID,string artname,string str,string service) {
    string year;
    string month;
    string day;
    string time;
    string notice;

    cout <<"\t\t\t" <<str;

    cout << endl << endl << endl;;
    cout << "\t\t\t\t년도 (yyyy) : ";
    cin >> year;

    cout << endl << endl;
    cout << "\t\t\t\t월 (mm) : ";
    cin >> month;

    cout << endl << endl;
    cout << "\t\t\t\t일 (dd) : ";
    cin >> day;

    cout << endl << endl;
    cout << "\t\t\t\t시간 (hh) : ";
    cin >> time;

    cout << endl << endl;
    cout << "\t\t\t\t요청사항 : ";
    cin >> notice;

    if (year.size() != 4 || month.size() != 2 || day.size() != 2 || time.size() != 2) dateReserve(artID,artname,"형식에 맞취 작성해 주세요",service);
    else reserveResult(artID,year+month+day+time,service,notice,artname);

}

void reserveResult(string artID, string day, string service,string notice,string artname) {
    system("cls");
    cout << endl << endl << endl;;
    cout << "\t\t\t\t"<<UserInfo::name<<" 회원님"<<endl<<endl;
    cout << "\t\t\t\t" << day.substr(0,4)<<"년 "<<day.substr(4,2)<<"월 "<<day.substr(6,2)<<"일 "<<day.substr(8,2)<<"시 "<< endl << endl;

    cout << "\t\t\t\t" <<artname<<" 아티스트" << endl << endl;
    
    string ch="";
    cout << "\t\t\t\t" << "다음 내용이 맞습니까? (y/n)";
    cin >> ch;

    if (ch.compare("y") == 0) {
        ofstream fout("reserve.txt", ios::app);
        fout << UserInfo::id << "\t" << artID << "\t" <<artname << "\t"<< service << "\t" << notice << "\t" << day << endl;
        choose();
    }
    else {
        reserve();
    }

}
