#include "chat.h"

//MESSAGE CLASS 
Message::Message() {

	id = 0;
	senderID = 0;
	recipientID = 0;
	content = "";
}
Message::Message(int id, int senderID, int recipientID, string content) {

	this->id = id;
	this->senderID = senderID;
	this->recipientID = recipientID;
	this->content = content;
}
Message::~Message()
{
}




/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// USER CLASS 
User::User() {
	id = 0;
	username = "";
	password = "";
}
User::User(int id, string username, string password)
{
    	this->id = id;
		this->username = username;
		this->password = password;
}
User::~User()
{
}

// Setters
void User::setId(int id) {
	this->id = id;
}
void User::setUsername(string username) {
	this->username = username;
}
void User::setPassword(string password) {
	this->password = password;
}



// Getters
int User::getId() {
	return id;
}
string User::getUsername() {
	return username;
}
string User::getPassword() {
	return password;
}

// Functions Implementation
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

void User::sendMessage(int idOfReceived, string message)
{

}

void User::undoMessage()
{

}

void User::addContact(set<int>& contacts, int userID)
{
	if (contacts.find(userID) != contacts.end())
	{
		cout << "Contact with ID " << userID << " already exists!" << endl;
		return;
	}
	else{
		contacts.insert(userID);
		cout << "contact " << userID << " is added successfully" << endl << "############################";
	}
	
}
//done

void User::rmContact(set<int>& contacts, int contactID)
{
	auto it = contacts.find(contactID);
	if (contacts.find(contactID) == contacts.end())
	{
		cout << "Contact with ID " << contactID << " not found!" << endl;
		return;

	}
	else {
		contacts.erase(it);
		cout << "contact removed succssefully" << endl << "############################";
	}
}
//done

void User::viewContactsByNumMessages(set<int>& contacts, unordered_map<int, vector<Message>> receivedMessages)
{
	vector<pair<int, int>> contactsWithNumMessages; // vector of pairs (contact ID, number of messages)
	for (int contactId : contacts) {
		int numMessages = receivedMessages[contactId].size();
		contactsWithNumMessages.push_back(make_pair(contactId, numMessages));
	}
	sort(contactsWithNumMessages.begin(), contactsWithNumMessages.end(), [](const auto& a, const auto& b) {
		return a.second > b.second; // sort by number of messages in descending order
		});
	for (auto& it : contactsWithNumMessages) {

		cout << "Contact ID: " << it.first  << " - Number of messages: " << it.second << endl;
	}
}

bool User::searchContacts(int id)
{
	
}

void User::viewSentMsgs(stack<Message>& sentMessages)
{
	stack<Message> tempStack = sentMessages;
	cout << "All the sent messages:\n";
	while (!tempStack.empty()) {
		cout << "\t" << tempStack.top().getContent() << endl;
		tempStack.pop();
	}
}
//
void User::viewMessagesFromContact(int contactId)
{
	if (receivedMessages.count(contactId) == 0) {
		cout << "There are no messages from the contact with ID " << contactId << endl;
	}
	vector<Message>& messages = receivedMessages.at(contactId);
	//it creates a reference to a vector of Message objects  
	//associated with the specified contactId using the at() method of the receivedMessages container
	auto iterator = messages.begin(); //this is iterator for the beggining of the vector
	cout << "The received Messages from the contact with ID " << contactId << ":" << endl;

	while (iterator != messages.end()) { // messages --> vector
		Message& message = *iterator;  // to reference the iterator to equal the message content
		//it creates a reference to the current message pointed to by the iterator
		cout << message.getContent() << endl;
		++iterator;  // increase the iterator to the next message
	}
}
//
void User::addFavMsg(queue<Message>& favMessages )
{


}
//
void User::rmFavMsg(queue<Message>& favMessages)
{
	if (favMessages.empty())
	{
		cout << "No messages in favorites to remove.\n";
	}
	else
	{
		favMessages.pop();
		cout << "The message has been removed successfully.\n";
	}
}
//done
void User::viewFavMsgs(queue<Message> fav)
{
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