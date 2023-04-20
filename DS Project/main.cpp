//main.cpp
#include<iostream>
#include<fstream>
#include"chat.h"
#include<cstdlib>
//#include "Source.h"

using namespace std;

int main() {

	// VARIABLE DECLARATION

	int choice;
	User user;

	cout << "TO LOGIN PRESS 1\nTO REGISTER PRESS 2\n";
	cin >> choice;
	switch (choice) {
	case 1:user.Login();
		break;
	case 2:user.Register();
		break;
	}

	return 0;
}