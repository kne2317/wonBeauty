#pragma once
#include <string>
using namespace std;

class Artist {
public:
	static string ph;
	static string name;
	static string id;
	static double rate;
	static string major;
	static string bt;
};
string Artist::ph = "";
string Artist::id = "";
string Artist::name = "";
double Artist::rate = 0;
string Artist::major="";
string Artist::bt = "";

