#include "intro.h"
#include "User.cpp"

class DB_connect {
	MYSQL Conn;
	MYSQL* ConnPtr = NULL;
	MYSQL_RES* Result;
	MYSQL_ROW Row;
	int Stat;

	DB_connect() {

		mysql_init(&Conn);
		ConnPtr = mysql_real_connect(&Conn, "localhost", "root", "111111", "wonbeauty", 3306, (char*)NULL, 0);
		if (ConnPtr == NULL) {
			fprintf(stderr, "Mysql connection error ");
			return;
		}
	}
	boolean loginUser(string idx, string pwx) {
		string q = "select * from user where id='" + idx + "'";
		const char* Query = q.c_str();
		Stat = mysql_query(ConnPtr, Query);

		Result = mysql_store_result(ConnPtr);
		while ((Row = mysql_fetch_row(Result)) != NULL) {
			if (sizeof(Row) == 0) return false;
			else {
				string id = Row[0];
				string name = Row[2];
				string ph = Row[3];
				int count = (int)Row[4];
				//User *user=new User(id, name, ph,count);
				return true;
			}
		}
	}
	void close_db() {
		mysql_close(ConnPtr);
	}
};