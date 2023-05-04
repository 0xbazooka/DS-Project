#pragma once
#include <iostream>
#include <list>
#include<stack>
#include<queue>
#include<fstream>
//chat.h file
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
	void addContact(int userID);
	void rmContact(int contactID);
	void viewContacts(); //sorted by no. of msgs
	bool searchContacts(int id);
	void viewSentMsgs();
	void viewReceivedMsgs(int id); //from a specific contact
	void addFavMsg(Message m); //WHATS THE PARAMETER
	void rmFavMsg(Message m); //rm oldest fav msg
	void viewFavMsgs(queue<Message> fav);

};

class Message {
	int id;
	int senderID;
	int receiverID;
	string content;

	
};

