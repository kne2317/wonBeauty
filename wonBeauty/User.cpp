#pragma once
#include <string>
using namespace std;

class UserInfo{
public:
	static string ph;
	static string name;
	static string id;
	static int count;

public:
	UserInfo() {}
	UserInfo(string id,  string name, string ph, int count) {
		setName(name);
		setId(id);
		setPh(ph);
		setCount(count);
	}
	static void setName(string n) {
		name = n;
	}
	static void setPh(string p) {
		ph = p;
	}
	static void setCount(int c) {
		count = c;
	}
	static void setId(string i) {
		id = i;
	}
	static string getName() {
		return name;
	}
	static string getPh() {
		return ph;
	}
	static int getCount() {
		return count;
	}
	static string getId() {
		return id;
	}
};
string UserInfo::ph = "";
string UserInfo::id = "";
string UserInfo::name = "";
int UserInfo::count = 0;
