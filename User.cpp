#include "User.h"

User::User(QWidget* parent) : QWidget(parent) {

	// MAIN WINDOW
	{
		setWindowTitle("Sarahah");
		this->setStyleSheet("background-color:#f5f8fa;");
	}

	// DECLARATION FOR THE HEADER
	{
		sarahahTitle = new QLabel("Sarahah", this);
		sarahahTitle->setVisible(false);

		sarahahLogo = new QWidget(this);
		sarahahLogo->setVisible(false);

		signUp = new QPushButton(this);
		connect(signUp, &QPushButton::clicked, [&]() {
			PagesVisibility(true, false, false, true, false);
			});
		signUp->setVisible(false);

		signUpIcon = new QWidget(this);
		signUpIcon->setVisible(false);

		logInHeader = new QPushButton(this);
		connect(logInHeader, &QPushButton::clicked, [&]() {
			PagesVisibility(true, false, true, false, false);
			});
		logInHeader->setVisible(false);

		logOut = new QPushButton(this);
		connect(logOut, &QPushButton::clicked, [&]() {
			PagesVisibility(true, true, false, false, false);
			});
		logOut->setVisible(false);

		logInIcon = new QWidget(this);
		logInIcon->setVisible(false);

		close = new QPushButton(this);
		close->setVisible(false);

	}

	// DECLARATION FOR STARTING PAGE
	{
		startPagePhoto = new QWidget(this);
		startPagePhoto->setVisible(false);
	}

	// DECLARATION FOR LOG IN PAGE
	{
		accountLoginLabel = new QLabel(this);
		accountLoginLabel->setVisible(false);
	
		username_Form = new QLineEdit(this);
		username_Form->setVisible(false);

		password_Form = new QLineEdit(this);
		password_Form->setVisible(false);
		connect(password_Form, &QLineEdit::returnPressed, this, &User::Logged);

		logIn = new QPushButton(this);
		logIn->setVisible(false);
		connect(logIn, &QPushButton::clicked, this, &User::Logged);

		logInInability = new QLabel(this);
		logInInability->setVisible(false);
	}

	// DECLARATION FOR SIGNUP PAGE
	{
		registerLabel = new QLabel(this);
		registerLabel->setVisible(false);

		line = new QLabel(this);
		line->setVisible(false);

		usernameLabel = new QLabel(this);
		usernameLabel->setVisible(false);

		r_username_Form = new QLineEdit(this);
		r_username_Form->setVisible(false);

		passwordLabel = new QLabel(this);
		passwordLabel->setVisible(false);
	
		r_password_Form = new QLineEdit(this);
		r_password_Form->setVisible(false);
		connect(r_password_Form, &QLineEdit::returnPressed, this, &User::Registered);

		Register = new QPushButton(this);
		Register->setVisible(false);
		connect(Register, &QPushButton::clicked, this, &User::Registered);

	
		invalidUsername = new QLabel(this);
		invalidUsername->setVisible(false);

		invalidPassword = new QLabel( this);
		invalidPassword->setVisible(false);

	}

	// DECLARATION FOR HOME PAGE
	{
		panelHeading = new QWidget(this);
		panelHeading->setVisible(false);

		identityText = new QLabel(this);
		identityText->setVisible(false);
	}

	StartingPage(true);
	
	SarahahHeader(true);
}

void User::SarahahHeader(bool test)
{
	sarahahTitle->setVisible(true);
	sarahahLogo->setVisible(true);
	logInIcon->setVisible(true);
	close->setVisible(true);
	signUp->setVisible(test);
	signUpIcon->setVisible(test);
	logInHeader->setVisible(test);
	logOut->setVisible(!test);

	sarahahTitle->move(0, 0);
	sarahahTitle->setStyleSheet("color:#f5f8fa;background-color:#10bbb3;font: bold 40px;padding-left:125px;");
	sarahahTitle->setFixedWidth(1600);
	sarahahTitle->setFixedHeight(70);

	sarahahLogo->setFixedWidth(80);
	sarahahLogo->setFixedHeight(50);
	sarahahLogo->move(45, 5);
	sarahahLogo->setStyleSheet("background-image: url(Sarahah_Icons/sarahahicon)");

	signUp->setText("Sign Up");
	signUp->setStyleSheet("background-color:transparent;color:#f5f8fa;font:bold 18px;");
	signUp->setFixedWidth(100);
	signUp->setFixedHeight(50);
	signUp->move(1170, 10);

	signUpIcon->setFixedWidth(22);
	signUpIcon->setFixedHeight(30);
	signUpIcon->move(1155, 17);
	signUpIcon->setStyleSheet("background-image: url(Sarahah_Icons/signupicon)");

	logInHeader->setText("Log In");
	logInHeader->setStyleSheet("background-color:transparent;color:#f5f8fa;font:bold 18px;");
	logInHeader->setFixedWidth(100);
	logInHeader->setFixedHeight(50);
	logInHeader->move(1310, 10);

	logInIcon->setFixedWidth(22);
	logInIcon->setFixedHeight(30);
	logInIcon->move(1300, 22);
	logInIcon->setStyleSheet("background-image: url(Sarahah_Icons/loginicon)");

	logOut->setText("Log Out");
	logOut->setStyleSheet("background-color:transparent;color:#f5f8fa;font:bold 18px;");
	logOut->setFixedWidth(100);
	logOut->setFixedHeight(50);
	logOut->move(1310, 10);

	close->setStyleSheet("background-image: url(Sarahah_Icons/closeicon);background-color:transparent;border-color:transparent;");
	close->setFixedWidth(50);
	close->setFixedHeight(50);
	close->move(1435, 10);
}

void User::StartingPage(bool test) {

	startPagePhoto->setFixedWidth(1000);
	startPagePhoto->setFixedHeight(250);
	startPagePhoto->move(100, 100);
	startPagePhoto->setStyleSheet("background-image: url(Photos/startPage)");
	startPagePhoto->setVisible(test);

}

void User::LoginWindow(bool test) {

	accountLoginLabel->setVisible(test);
	username_Form->setVisible(test);
	password_Form->setVisible(test);
	logIn->setVisible(test);
	logInInability->setVisible(false);

	accountLoginLabel->setText("Account Login");
	accountLoginLabel->setFixedWidth(200);
	accountLoginLabel->setFixedHeight(30);
	accountLoginLabel->move(700, 120);
	accountLoginLabel->setStyleSheet("color:#1e3948;font:bold 24px;");

	logInInability->setFixedWidth(300);
	logInInability->setFixedHeight(50);
	logInInability->setStyleSheet("background-color:#f2dede;color:#a9446b;font:16px;padding-left:10px;");

	username_Form->move(630, 190);
	username_Form->setFixedWidth(300);
	username_Form->setFixedHeight(36);
	username_Form->setPlaceholderText("Username");
	username_Form->setStyleSheet("background-color:white;font:14px;padding-left:10px;");

	password_Form->move(630, 265);
	password_Form->setFixedWidth(300);
	password_Form->setFixedHeight(36);
	password_Form->setPlaceholderText("Password");
	password_Form->setStyleSheet("background-color:white;font:14px;padding-left:10px;");
	password_Form->setEchoMode(QLineEdit::Password);

	logIn->setText("Login");
	logIn->setStyleSheet("color:#10bbb3;font:14px;border:1px solid;border-left-color:#10bbb3;border-right-color:#10bbb3;border-top-color:#10bbb3;border-bottom-color:#10bbb3;");
	logIn->move(740, 330);
	logIn->setFixedWidth(70);
	logIn->setFixedHeight(40);

	username_Form->clear();
	password_Form->clear();
}

void User::SignUpWindow(bool test)
{
	registerLabel->setVisible(test);
	line->setVisible(test);
	usernameLabel->setVisible(test);
	r_username_Form->setVisible(test);
	passwordLabel->setVisible(test);
	r_password_Form->setVisible(test);
	invalidPassword->setVisible(test);
	Register->setVisible(test);


	registerLabel->setText("Register");
	registerLabel->move(200, 120);
	registerLabel->setFixedWidth(100);
	registerLabel->setFixedHeight(30);
	registerLabel->setStyleSheet("color:#1e3948;font:bold 24px;");

	line->setText("");
	line->move(200, 150);
	line->setFixedWidth(1100);
	line->setStyleSheet("border:1px solid; border-left-color:transparent;border-top-color:transparent;border-right-color:transparent;border-bottom-color:#d4dbe0;");

	usernameLabel->setText("Username:");
	usernameLabel->move(300, 220);
	usernameLabel->setFixedWidth(120);
	usernameLabel->setFixedHeight(30);
	usernameLabel->setStyleSheet("color:#1e3948;font:bold 22px;");

	r_username_Form->move(430, 220);
	r_username_Form->setFixedWidth(600);
	r_username_Form->setFixedHeight(36);
	r_username_Form->setStyleSheet("background-color:white;font:14px;padding-left:10px;");

	passwordLabel->setText("Password:");
	passwordLabel->move(300, 300);
	passwordLabel->setFixedWidth(120);
	passwordLabel->setFixedHeight(30);
	passwordLabel->setStyleSheet("color:#1e3948;font:bold 22px;");

	r_password_Form->move(430, 300);
	r_password_Form->setFixedWidth(600);
	r_password_Form->setFixedHeight(36);
	r_password_Form->setStyleSheet("background-color:white;font:14px;padding-left:10px;");
	r_password_Form->setEchoMode(QLineEdit::Password);

	invalidUsername->setText("User Name already exixts !");
	invalidUsername->move(430, 170);
	invalidUsername->setFixedWidth(300);
	invalidUsername->setFixedHeight(50);
	invalidUsername->setStyleSheet("background-color:#f2dede;color:#a9446b;font: 16px;padding-left:20px;");
	invalidUsername->setVisible(false);

	invalidPassword->setText("Password should be at least 8 characters");
	invalidPassword->move(440, 340);
	invalidPassword->setStyleSheet("color:black;font: 14px;");
	invalidPassword->setFixedWidth(350);
	invalidPassword->setFixedHeight(30);

	Register->setText("Register");
	Register->setStyleSheet("color:#10bbb3;font:14px;border:1px solid;border-left-color:#10bbb3;border-right-color:#10bbb3;border-top-color:#10bbb3;border-bottom-color:#10bbb3;");
	Register->move(430, 380);
	Register->setFixedHeight(40);
	Register->setFixedWidth(70);

	r_username_Form->clear();
	r_password_Form->clear();
}

void User::HomePage(bool test) {
	
	panelHeading->setVisible(test);
	identityText->setVisible(test);

	panelHeading->move(100, 100);
	panelHeading->setFixedWidth(400);
	panelHeading->setFixedHeight(250);
	panelHeading->setStyleSheet("background-image: url(Photos/pic)");

	name = username.c_str();
	q_id = QString::number(getId());

	identityText->move(100, 350);
	identityText->setText("HI, " + name +"\nID: #" + q_id);
	identityText->setStyleSheet("color:#1e3948;background-color:white;font: bold 20px;padding-left:50px;");
	identityText->setFixedWidth(400);
	identityText->setFixedHeight(100);

}

void User::PagesVisibility(bool header,bool start, bool log, bool sign, bool home) {
	SarahahHeader(header);
	StartingPage(start);
	LoginWindow(log);
	SignUpWindow(sign);
	HomePage(home);
}

void User::Logged()
{	
	// TO TAKE DATA FROM USER 
	username = username_Form->text().toStdString().c_str();
	password = password_Form->text().toStdString().c_str();

	// DECLARATION
	flag = false;

	// COMPARING ENTERED DATA

	// CHECKING THAT DATA ISN'T EMPTY
	if (username.empty() || password.empty()) {
		
		logInInability->setText("Provide username & password");
		logInInability->move(630, 170);
		logInInability->setVisible(true);

		username_Form->move(630, 220);
		password_Form->move(630, 295);
		logIn->move(740, 360);
	}

	else {
			username_Form->move(630, 190);
			password_Form->move(630, 265);
			logIn->move(740, 330);

		for (int i = 0; i < userData.size(); i++) {

			// IF USERNAME & PASSWORD ARE TRUE
			if (userData[i].f_name == username && userData[i].f_password == password)
			{
				id= userData[i].f_id;
				PagesVisibility(false, false, false, false, true);
				flag = true;
				break;
			}
		}
		// IF USERNAME OR PASSWORD IS WRONG
		if (flag == false) {
			logInInability->setText("Error in Password or Email");
			logInInability->move(630, 170);

			username_Form->move(630, 220);
			password_Form->move(630, 295);
			logIn->move(740, 360);
			logInInability->setVisible(true);
		}
	}
	username_Form->clear();
	password_Form->clear();
}

void User::Registered() {

	// TO TAKE DATA FROM USER 
	username = r_username_Form->text().toStdString().c_str();
	password = r_password_Form->text().toStdString().c_str();

	// DECLARATION
	flagu = true;
	flagp = true;

	// CHECK THAT USERNAME AND PASSWORD AREN'T EMPTY
	if (username.empty() || password.empty()) {
		invalidUsername->setText("Provide Username");
		invalidUsername->setVisible(true);

		invalidPassword->setText("Provide Password");
		invalidPassword->setStyleSheet("color:#a9446b;font: 16px;");
		invalidPassword->setVisible(true);
	}

	else {
		// USERNAME REGISTERATION
		// TO CHECK THAT USERNAME DIDN'T EXIST BEFORE
		for (int i = 0; i < userData.size(); i++) {
			if (username == userData[i].f_name)
			{
				invalidUsername->setVisible(true);
				r_username_Form->clear();
				flagu = false;
				break;
			}
		}

		// PASSWORD REGISTERATION
		// TO CHECK PASSWORD IS AT LEAST 8 CHARACTERS
		if (password.length() < 8)
		{
			invalidPassword->setText("Invalid Password , It should be 8 characters");
			invalidPassword->setStyleSheet("color:#a9446b;font: 16px;");
			r_password_Form->clear();
			flagp = false;
		}

		// WHEN USERNAME AND PASSWORD ARE VALID TO SAVE
		if (flagu == true && flagp == true) {
			userDataFile.f_name = username;
			userDataFile.f_password = password;

			// CREATE ID
			if (userData.size() == 0)
				id = 1000;
			else
				id=(userData[userData.size() - 1].f_id) + 1;

			// TO LET USER KNOW HIS ID 
			userDataFile.f_id = getId();
			userData.push_back(userDataFile);
			PagesVisibility(false, false, false, false, true);
		}
	}
}

int User::getId()
{
	return id;
}

vector <UserDataFile> User::getVector() {
	return userData;
}

void User::setVector(vector<UserDataFile> U_D_F)
{
	// U_D_F = user data file
	// TO COPY USER DATA FILE INTO THE VECTOR
	
	userData = U_D_F;
}

void User::closeEvent(QCloseEvent* closeEvent) {
	closeEvent->ignore();
}

User::~User()
{}