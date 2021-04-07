#pragma once
#include <windows.h>
#include<iostream>
#include <conio.h>
#include <fstream>
#include <iomanip>
#include <vector>
#include <mysql.h>
#include"User.cpp"
#include "Artist.cpp"

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4
#define ENTER 5


void init();
void record();
int mainMenu();
int chooseMenu();
void gotoxy(int x, int y);
int main(void);
void join(string s);
void login(string s);
void manager();
int keyControl();
void choose();
void chooseM();
int chooseMenuM();
void reserve();