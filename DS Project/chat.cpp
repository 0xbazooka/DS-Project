//chat.cpp
#include "chat.h"
using namespace std;

string User::getUsername()
{
	return username;
}

string User::getPassword()
{
	return password;
}

int User::getId()
{
	return id;
}

void User::Login()
{
	// DECLARATION
	dataToRead.open("Userdata.txt");
	dataToWrite.open("Userdata.txt", ios::app);
	fid = 0;
	bool flag = false;
	bool flag2 = false;

	// ENTER DATA
	cout << "Enter your Username: ";
	cin >> username;
	cout << "Enter your password: ";
	cin >> password;

	// TO COMPARE DATA
	while (dataToRead >> fname >> fpassword >> fid) {
		if (fname == username && fpassword == password)
		{
			cout << "Logged IN";
			flag = true;
			dataToRead.close();
			dataToWrite.close();
			break;
		}
	}
	if (flag == false) {
		dataToRead.clear();
		dataToRead.seekg(0, ios::beg);
		while (dataToRead >> fname >> fpassword >> fid) {
			if (fname == username || fpassword == password) {
				cout << "Either username or password is wrong";
				flag2 = true;
				dataToRead.close();
				dataToWrite.close();
				break;
			}
		}
		if (flag2 == false)
		{
			dataToRead.close();
			dataToWrite.close();
			cout << "You don't have account PLEASE Register" << endl;
			Register();
		}
	}
}

void User::Register() {


	// DECLARATION
	bool flagu, flagi;
	dataToRead.open("Userdata.txt");
	dataToWrite.open("Userdata.txt", ios::app);
	fid = 0;

	//  
	// 
	// USERNAME REGISTERATION
	// TO CHECK THAT USERNAME DIDN'T EXIST BEFORE
	do {
		flagu = true;
		cout << "Enter your username: ";
		cin >> username;
		dataToRead.clear();
		dataToRead.seekg(0, ios::beg);
		while (dataToRead >> fname >> fpassword >> fid) {
			if (getUsername() == fname)
			{
				cout << "This username is taken, Try another" << endl;
				flagu = false;
			}

		}
	} while (flagu == false);

	dataToWrite << getUsername() << " ";

	// PASSWORD REGISTERATION
	// TO CHECK PASSWORD IS AT LEAST 8 CHARACTERS
	do {
		cout << "Enter your Password IT SHOULD BE AT LEAST 8 CHARACTERS: ";
		cin >> password;
		if (password.length() < 8)
			cout << "INVALID Password\n";
	} while (password.length() < 8);
	dataToWrite << getPassword() << " ";


	// CREATE ID
	do {
		flagi = true;
		id = rand() % 1000 + 1000;
		dataToRead.clear();
		dataToRead.seekg(0, ios::beg);
		while (dataToRead >> fname >> fpassword >> fid) {
			if (fid == id)
				flagi = false;
		}
	} while (flagi == false);
	dataToWrite << getId() << endl;
	cout << "Your ID is : " << getId() << endl;
	dataToRead.close();
	dataToWrite.close();
}

void User::viewFavMsgs() {



}

////SEND/UNDO MESSAGE
//void User::sendMessage(string message) {
//	messages.push(message);
//	cout << "Message sent: " << message << endl;
//}
//
//void User::undoMessage() {
//	if (!messages.empty()) {
//		string lastMessage = messages.top();
//		messages.pop();
//		cout << "Last message undone: " << lastMessage << endl;
//	}
//	else {
//		cout << "No messages to undo" << endl;
//	}
//}
