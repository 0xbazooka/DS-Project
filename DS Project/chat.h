#pragma once
#include <iostream>
#include <list>
#include<stack>
#include<queue>
#include<fstream>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

class Message {

	int id;
	int senderID;
	int recipientID;
	string content;
	
public:
	void setID(int id) {
		this->id = id;
	}
	void setSenderID(int senderID) {
		this->senderID = senderID;
	}
	void setRecipientID(int recipientID) {
		this->recipientID = recipientID;
	}
	void setContent(string content) {
		this->content = content;
	}

	int getID(){
		return id;
	}
	int getSenderID() {
		return senderID;
	}
	int getRecipientID() {
		return recipientID;
	}
	string getContent() {
		return content;
	}

	Message();
	Message(int id, int senderID, int recipientID, string content);
	~Message();
	/*void addFavMsg(Message m);
	* void rmFavMsg(Message m);
	*/
};

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

	User();
	User(int id, string username, string password);
	~User();

	//Setters
	void setId(int id);
	void setUsername(string username);
	void setPassword(string password);
	/*void setContacts(set<int> contacts);
	void setSentMessages(stack<Message> sentMessages);
	void setReceivedMessages(unordered_map<int, vector<Message>> receivedMessages);
	void setFavMessages(queue<Message> favMessages);*/

	//Getters
	int getId();
	string getUsername();
	string getPassword();

	// the functions
	void Register();
	void Login();
	void sendMessage(int idOfReceived, string message);
	void undoMessage();
	void addContact(int userID);
	void rmContact(int contactID);
	void viewContacts(); //sorted by no. of msgs
	bool searchContacts(int id);
	void viewSentMsgs();
	void viewMessagesFromContact(int contactId); //from a specific contact
	void addFavMsg(queue<Message>& favMessages); //view messages needed
	void rmFavMsg(queue<Message>& favMessages); //rm oldest fav msg
	void viewFavMsgs(queue<Message> fav);

};


