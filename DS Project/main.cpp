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
	 

	while (bool x = true) {
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

		cin >> choice;

		switch (choice) {
			case 1:
				//User::sendMessage();
				break;
			case 2:
				//User::undoMessage();
				break;
			case 3:
				//User::addContact(int c);
				break;
			case 4:
				//User::rmContact(int c);
				break;
			case 5:
				//User::viewContacts(User u);
				break;
			case 6:
				//User::searchContacts(User u);
				break;
			case 7:
				//User::viewSentMsgs();
				break;
			case 8:
				//User::viewReceivedMsgs(int id);
				break;
			case 9:
				//User::addFavMsg();
				break;
			case 10:
				//User::rmFavMsg();
				break;
			case 11:
				//User::viewFavMsgs();
				break;
			case 12:
				x = false;
				break;

		}
	}


	//return 0;
}