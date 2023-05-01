#include <QtWidgets/QApplication>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QCloseEvent>
#include <fstream>
#include <vector>
#include <list>
#include <stack>
#include <queue>

using namespace std;

struct UserDataFile {
	string f_name, f_password;
	int f_id;
};

class User :public QWidget
{
	Q_OBJECT

public:

	User(QWidget* parent=nullptr);

	vector<UserDataFile> getVector();

	int getId();

	void setVector(vector<UserDataFile>);

	QPushButton *close ;

	~User();

private:

	QLabel *accountLoginLabel, *sarahahTitle, *logInInability, *identityText, *registerLabel, *line, *usernameLabel, *passwordLabel, *invalidUsername, *invalidPassword;

	QLineEdit *username_Form, *password_Form, *r_username_Form, *r_password_Form;

	QPushButton *logInHeader, *signUp, *logOut , *logIn, *Register;

	QWidget *sarahahLogo, *signUpIcon, *logInIcon , *startPagePhoto , *panelHeading;

	QString q_id,name;

	UserDataFile userDataFile;

	string username, password;

	int id;

	bool flagu, flagp,flag;

	list <int> listOfContacts;

	stack <string> messages;

	queue <string> favMessages;

	vector <UserDataFile> userData;

// FUNCTIONS

	void SarahahHeader(bool);

	void StartingPage(bool);

	void LoginWindow(bool);

	void SignUpWindow(bool);

	void HomePage(bool);

	void PagesVisibility(bool,bool,bool,bool,bool);

	void Logged();

	void Registered();

	void closeEvent(QCloseEvent* event);

};