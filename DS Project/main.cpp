//main.cpp
#include<iostream>
#include<fstream>
#include"chat.h"
#include<cstdlib>
//#include "Source.h"

using namespace std;

int main() {


	int choice;
	vector <User> users;

	cout << "to login press 1\nto register press 2\n";
	cin >> choice;
	switch (choice) {
	case 1:User.Login();
		break;
	case 2:User.Register();
		break;
	}
	 

	while (true) {
		cout << "Choose one of the following options:" << endl;
		cout << "1. send a message " << endl;
		cout << "2. undo a sent message" << endl;
		cout << "3. add a new contact" << endl;
		cout << "4. remove a contact" << endl;
		cout << "5. view all contacts" << endl; //sorted by no. of msgs
		cout << "6. search for a contact" << endl;
		cout << "7. view all the messages you sent" << endl;
		cout << "8. view your received messages" << endl;
		cout << "9. add a message to favourites " << endl;
		cout << "10. rm the oldest fav msg"<< endl;
		cout << "11. view your fav messages " << endl;
		cout << "12. exit " << endl;


		switch (choice) {
			case 1:
				//User::sendMessage();
				break;
			case 2:

				break;
			case 3:

				break;

		}
	}


	//return 0;
}