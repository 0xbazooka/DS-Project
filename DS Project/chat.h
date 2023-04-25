#pragma once
#include <iostream>
#include <list>
#include<stack>
#include<queue>
#include<fstream>


using namespace std;

class User {
	int id;
	string username;
	string password;
	vector<int> contacts;
	stack<int> sentMessages;
	stack<int> receivedMessages;
	queue<int> favMessages;

	ifstream dataToRead;
	ofstream dataToWrite;
	// FOR SEARCHING FILES
	string fname, fpassword;
	int fid;

public:
	int getId();
	string getUsername();
	string getPassword();
	void Register();
	void Login();
	void addContact(int c);
	void rmContact(int c);
	void viewContacts(User u); //sorted by no. of msgs
	bool searchContacts(User u);

	void sendMessage(string message);
	void undoMessage();
};

class Message {
	int id;
	int senderID;
	//int recepientID;
	string content;
};


//class contact {
//	int id;
//	vector<message>* messages; //view recieved msgs
//	int msgcount; //sort by no. of msgs
//};