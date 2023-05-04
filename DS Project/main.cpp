//main.cpp
#include<iostream>
#include<fstream>
#include"chat.h"
#include<cstdlib>
//#include "Source.h"

using namespace std;

int main() {

	//LOGIN AND REGISTER FIRST
	int choice;
	//int currentUserIndex = -1;
	vector <User*> users;
	User user;
	cout << "to login press 1\nto register press 2\n";
	cin >> choice;
	switch (choice) {
	case 1:user.Login();

		break;
	case 2:user.Register();
		break;
	}
	 
	//CHOOSING A FUNCTION AFTER LOGGING IN
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

		//declaring needed variables in the switch case
		string msg; //error when inside the switch
		int id;
		int idOfRecepient;

		switch (choice) {
			case 1:

				cout << "Enter the id of the user you want to send the message: " << endl;
				cin >> idOfRecepient;
				cout << "Enter your message:";
				cin >> msg;
				user.sendMessage(idOfRecepient, msg);
				break;

			case 2:
				user.undoMessage();
				//cout << "deleted your last sent msg successfully." << endl;
				break;

			case 3:
				cout << " what is the id of the user you want to add?" << endl;
				cin >> id;
				user.addContact(id);
				break;

			case 4:
				cout << " what's the contact's id you want to remove" << endl;
				cin >> id;
				user.rmContact(id);
				break;

			case 5:
				user.viewContacts();
				break;

			case 6:
				cout << "Enter the id of contact you want to search for:" << endl;
				cin >> id;
				user.searchContacts(id);
				break;

			case 7:
				user.viewSentMsgs();
				break;

			case 8:
				cout << "which contact's messages you want to see? " << endl;
				cin >> id;
				user.viewReceivedMsgs(id);
				break;

			case 9:
				user.addFavMsg();////
				break;

			case 10:
				user.rmFavMsg();
				break;

			case 11:
				user.viewFavMsgs();
				break;

			case 12:
				x = false;
				break;

		}
	}


	//return 0;
}