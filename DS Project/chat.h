#pragma once
#include <iostream>
#include <list>
#include<stack>
#include<queue>
#include<fstream>
#include <set>
#include <unordered_map>
#include <vector>
//#include <map>

using namespace std;

class User {
	int id;
	string username;
	string password;
	set<int> contacts; //set 3shan rm (logn) msh (n)
	stack<Message> sentMessages;
	unordered_map<int, vector<Message>> receivedMessages;//unordered_map 3shan a7san fel data el so8ayara
	queue<Message> favMessages;

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
	void sendMessage(int idOfReceived, string message);
	void undoMessage();
	void addContact(int c);
	void rmContact(int c);
	void viewContacts(User u); //sorted by no. of msgs
	bool searchContacts(User u);
	void viewSentMsgs();
	void viewReceivedMsgs(int id); //from a specific contact
	void addFavMsg(); //WHATS THE PARAMETER
	void rmFavMsg(); //rm oldest fav msg
	void viewFavMsgs();

};

class Message {
	int id;
	int senderID;
	int receiverID;
	string content;
};


//class Contact {
//	int id;
//	vector<message>* messages; //view recieved msgs
//	int msgcount; //sort by no. of msgs
//};