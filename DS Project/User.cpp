#include "User.h"

User::User(QWidget* parent) : QWidget(parent) {

	// MAIN WINDOW
	{
		setWindowTitle("Sarahah");
		this->setStyleSheet("background-color:#f5f8fa;");
	}

	// DECLARATION FOR THE HEADER
	{
		// TITLE "SARAHAH"
			sarahahTitle = new QLabel("Sarahah", this);
			sarahahTitle->setVisible(false);

		// SARAHAH LOGO
			mainIcon = new QWidget(this);
			mainIcon->setVisible(false);

		// BUTTON CLICKED FLAGS
			signUpClicked = logInClicked = false;

		// SIGN UP BUTTON
			signUp = new QPushButton(this);
			connect(signUp, &QPushButton::clicked, this, &User::SignUpClicked);
			signUp->setVisible(false);

		// SIGN UP ICON
			signUpIcon = new QWidget(this);
			signUpIcon->setVisible(false);

		// LOG IN BUTTON
			logInHeader = new QPushButton(this);
			connect(logInHeader, &QPushButton::clicked, this, &User::LogInClicked);
			logInHeader->setVisible(false);

		// LOG OUT BUTTON
			logOut = new QPushButton(this);
			connect(logOut, &QPushButton::clicked, this, &User::LogOutClicked);
			logOut->setVisible(false);

		// LOG IN ICON
			logInIcon = new QWidget(this);
			logInIcon->setVisible(false);

	}

	// DECLARATION FOR STARTING PAGE
	{
		startPagePhoto = new QWidget(this);
		startPagePhoto->setVisible(false);
	}

	// DECLARATION FOR LOG IN PAGE
	{
		// ACCOUNT LOGIN LABEL
			accountLoginLabel = new QLabel(this);
			accountLoginLabel->setVisible(false);
	
		// USERNAME TEXTBOX
			userBorder = new QLineEdit(this);
			userBorder->setVisible(false);
	
		// PASSWORD TEXTBOX
			passBorder = new QLineEdit(this);
			passBorder->setVisible(false);
			connect(passBorder, &QLineEdit::returnPressed, this, &User::Logged);

		// LOGIN BUTTON
			logIn = new QPushButton(this);
			logIn->setVisible(false);
			connect(logIn, &QPushButton::clicked, this, &User::Logged);

		// LOGGED IN STATUS LABEL
			loggedInStatus = new QLabel(this);
			loggedInStatus->setVisible(false);
	}

	// DECLARATION FOR SIGNUP PAGE
	{
		// REGISTER LABEL
			registerLabel = new QLabel(this);
			registerLabel->setVisible(false);

		// HORIOZONTAL LINE
			line = new QLabel(this);
			line->setVisible(false);

		// USERNAME LABEL
			usernameLabel = new QLabel(this);
			usernameLabel->setVisible(false);

		// USERNAME BORDER BOX
			r_userBorder = new QLineEdit(this);
			r_userBorder->setVisible(false);

		// PASSWORD LABEL
			passwordLabel = new QLabel(this);
			passwordLabel->setVisible(false);
	
		// PASSWORD BORDER BOX
			r_passBorder = new QLineEdit(this);
			r_passBorder->setVisible(false);
			connect(r_passBorder, &QLineEdit::returnPressed, this, &User::Registered);

		// REGISTER BUTTON
			Register = new QPushButton(this);
			Register->setVisible(false);
			connect(Register, &QPushButton::clicked, this, &User::Registered);
	
		// USERNAME invalidUsername LABEL
			invalidUsername = new QLabel(this);
			invalidUsername->setVisible(false);

		// PASSWORD MUST 8 LABEL
			invalidPassword = new QLabel( this);
			invalidPassword->setVisible(false);

		// ID LABEL
			idLabel = new QLabel(this);
			idLabel->setVisible(false);

		// ID NUMBER
			idNumberLabel = new QLabel(this);
			idNumberLabel->setVisible(false);
	}

	// DECLARATION FOR HOME PAGE
	{
		hiPhoto = new QWidget(this);
		hiPhoto->setVisible(false);

		hiLabel = new QLabel(this);
		hiLabel->setVisible(false);
	}

	StartingPage(true);
	
	SarahahHeader(true);
	reg = false;
}

void User::SarahahHeader(bool test)
{
	sarahahTitle->setVisible(true);
	mainIcon->setVisible(true);
	signUp->setVisible(test);
	signUpIcon->setVisible(test);
	logInHeader->setVisible(test);
	logInIcon->setVisible(true);
	logOut->setVisible(!test);

	sarahahTitle->move(0, 0);
	sarahahTitle->setStyleSheet("color:#f5f8fa;background-color:#10bbb3;font: bold 40px;padding-left:125px;");
	sarahahTitle->setFixedWidth(1600);
	sarahahTitle->setFixedHeight(70);

	mainIcon->setFixedWidth(80);
	mainIcon->setFixedHeight(50);
	mainIcon->move(45, 5);
	mainIcon->setStyleSheet("background-image: url(Log_Reg_icons/icon)");

	signUp->setText("Sign Up");
	signUp->setStyleSheet("background-color:transparent;color:#f5f8fa;font:bold 18px;");
	signUp->setFixedWidth(100);
	signUp->setFixedHeight(50);
	signUp->move(1270, 10);

	signUpIcon->setFixedWidth(22);
	signUpIcon->setFixedHeight(30);
	signUpIcon->move(1255, 17);
	signUpIcon->setStyleSheet("background-image: url(Log_Reg_icons/signupicon)");

	logInHeader->setText("Log In");
	logInHeader->setStyleSheet("background-color:transparent;color:#f5f8fa;font:bold 18px;");
	logInHeader->setFixedWidth(100);
	logInHeader->setFixedHeight(50);
	logInHeader->move(1410, 10);

	logInIcon->setFixedWidth(22);
	logInIcon->setFixedHeight(30);
	logInIcon->move(1400, 22);
	logInIcon->setStyleSheet("background-image: url(Log_Reg_icons/loginicon)");

	logOut->setText("Log Out");
	logOut->setStyleSheet("background-color:transparent;color:#f5f8fa;font:bold 18px;");
	logOut->setFixedWidth(100);
	logOut->setFixedHeight(50);
	logOut->move(1410, 10);

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
	userBorder->setVisible(test);
	passBorder->setVisible(test);
	logIn->setVisible(test);
	loggedInStatus->setVisible(false);

	accountLoginLabel->setText("Account Login");
	accountLoginLabel->setFixedWidth(200);
	accountLoginLabel->setFixedHeight(30);
	accountLoginLabel->move(700, 120);
	accountLoginLabel->setStyleSheet("color:#1e3948;font:bold 24px;");

	loggedInStatus->setFixedWidth(300);
	loggedInStatus->setFixedHeight(50);
	loggedInStatus->setStyleSheet("background-color:#f2dede;color:#a9446b;font:16px;padding-left:10px;");

	userBorder->move(630, 190);
	userBorder->setFixedWidth(300);
	userBorder->setFixedHeight(36);
	userBorder->setPlaceholderText("Username");
	userBorder->setStyleSheet("background-color:white;font:14px;padding-left:10px;");

	passBorder->move(630, 265);
	passBorder->setFixedWidth(300);
	passBorder->setFixedHeight(36);
	passBorder->setPlaceholderText("Password");
	passBorder->setStyleSheet("background-color:white;font:14px;padding-left:10px;");
	passBorder->setEchoMode(QLineEdit::Password);

	logIn->setText("Login");
	logIn->setStyleSheet("color:#10bbb3;font:14px;border:1px solid;border-left-color:#10bbb3;border-right-color:#10bbb3;border-top-color:#10bbb3;border-bottom-color:#10bbb3;");
	logIn->move(740, 330);
	logIn->setFixedWidth(70);
	logIn->setFixedHeight(40);

	userBorder->clear();
	passBorder->clear();
}

void User::SignUpWindow(bool test)
{
	registerLabel->setVisible(test);
	line->setVisible(test);
	usernameLabel->setVisible(test);
	r_userBorder->setVisible(test);
	passwordLabel->setVisible(test);
	r_passBorder->setVisible(test);
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

	r_userBorder->move(430, 220);
	r_userBorder->setFixedWidth(600);
	r_userBorder->setFixedHeight(36);
	r_userBorder->setStyleSheet("background-color:white;font:14px;padding-left:10px;");

	passwordLabel->setText("Password:");
	passwordLabel->move(300, 300);
	passwordLabel->setFixedWidth(120);
	passwordLabel->setFixedHeight(30);
	passwordLabel->setStyleSheet("color:#1e3948;font:bold 22px;");

	r_passBorder->move(430, 300);
	r_passBorder->setFixedWidth(600);
	r_passBorder->setFixedHeight(36);
	r_passBorder->setStyleSheet("background-color:white;font:14px;padding-left:10px;");
	r_passBorder->setEchoMode(QLineEdit::Password);

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

	idLabel->setText("Your ID:");
	idLabel->move(500, 430);
	idLabel->setFixedWidth(70);
	idLabel->setFixedHeight(30);
	idLabel->setStyleSheet("color:#1e3948;font:bold 20px;");
	idLabel->setVisible(false);

	idNumberLabel->move(590, 430);
	idNumberLabel->setFixedWidth(70);
	idNumberLabel->setFixedHeight(30);
	idNumberLabel->setStyleSheet("color:#1e3948;font:20px;");
	idNumberLabel->setVisible(false);

	r_userBorder->clear();
	r_passBorder->clear();
}

void User::LogInClicked() {
	logInClicked = true;
	signUpClicked = false;
	logOutClicked = false;
	PagesNavigator();
}

void User::SignUpClicked(){
	signUpClicked=true;
	logInClicked = false;
	logOutClicked = false;
	PagesNavigator();
}

void User::LogOutClicked() {
	signUpClicked = false;
	logInClicked = false;
	logOutClicked = true;
	PagesNavigator();
}

void User::HomePage(bool test) {
	
	hiPhoto->setVisible(test);
	hiLabel->setVisible(test);

	hiPhoto->move(100, 100);
	hiPhoto->setFixedWidth(400);
	hiPhoto->setFixedHeight(250);
	hiPhoto->setStyleSheet("background-image: url(Photos/pic)");

	QString name = getUsername().c_str();
	QString q_id = QString::number(getId());

	hiLabel->move(100, 350);
	hiLabel->setText("HI, " + name + " #" + q_id);
	hiLabel->setStyleSheet("color:#1e3948;background-color:white;font: bold 20px;padding-left:50px;");
	hiLabel->setFixedWidth(400);
	hiLabel->setFixedHeight(100);

}

void User::PagesNavigator() {

	if (signUpClicked)
	{
		SarahahHeader(true);
		StartingPage(false);
		SignUpWindow(true);
		LoginWindow(false);
		HomePage(false);	
	}
	else if (logInClicked) {
		SarahahHeader(true);
		StartingPage(false);
		SignUpWindow(false);
		LoginWindow(true);
		HomePage(false);
	}
	else if (logOutClicked) {
		SarahahHeader(true);
		StartingPage(true);
		SignUpWindow(false);
		LoginWindow(false);
		HomePage(false);
	}
	else if (loggedIn) {
		SarahahHeader(false);
		StartingPage(false);
		SignUpWindow(false);
		LoginWindow(false);
		HomePage(true);
	}

}

void User::Logged()
{	
	// TO TAKE DATA FROM USER 
	username = userBorder->text().toStdString().c_str();
	password = passBorder->text().toStdString().c_str();

	// DECLARATION OF FLAGS
	bool flag = false;
	bool flag2 = false;
	loggedIn = false;

	// COMPARING ENTERED DATA

	// CHECKING THAT DATA ISN'T EMPTY
	if (getUsername().empty() || getPassword().empty()) {
		loggedInStatus->setText("Provide username & password");
		loggedInStatus->move(630, 170);
		userBorder->move(630, 220);
		passBorder->move(630, 295);
		logIn->move(740, 360);
		loggedInStatus->setVisible(true);
	}

	else {
		for (int i = 0; i < userData.size(); i++) {
			userBorder->move(630, 190);
			passBorder->move(630, 265);
			logIn->move(740, 330);

			// IF USERNAME & PASSWORD ARE TRUE
			if (userData[i].f_name == getUsername() && userData[i].f_password == getPassword())
			{
				loggedInStatus->setText("Logged In");
				loggedInStatus->setStyleSheet("background-color:transparent;color:#1e3948;font:bold 14px;");
				loggedInStatus->setFixedHeight(30);
				loggedInStatus->move(740, 380);
				loggedInStatus->setVisible(true);
				id= userData[i].f_id;
				Delay(1000);
				loggedIn = true;
				signUpClicked = false;
				logInClicked = false;
				logOutClicked = false;
				PagesNavigator();
				flag = true;
				break;
			}
		}
		if (flag == false) {

			// IF USERNAME OR PASSWORD IS TRUE
			for (int j = 0; j < userData.size(); j++) {
				if (userData[j].f_name == getUsername() || userData[j].f_password == getPassword()) {
					loggedInStatus->setText("Error in Password or Email");
					loggedInStatus->move(630, 170);
					userBorder->move(630, 220);
					passBorder->move(630, 295);
					logIn->move(740, 360);
					loggedInStatus->setVisible(true);
					flag2 = true;
					break;
				}
			}

			// IF USERNAME AND PASSWORD ARE FALSE
			if (flag2 == false)
			{
				loggedInStatus->setText("You don't have account, Please Register");
				loggedInStatus->move(630, 170);
				userBorder->move(630, 220);
				passBorder->move(630, 295);
				logIn->move(740, 360);
				loggedInStatus->setVisible(true);

			}
		}
	}
	userBorder->clear();
	passBorder->clear();
}

void User::Registered() {

	// TO TAKE DATA FROM USER 
	username = r_userBorder->text().toStdString().c_str();
	password = r_passBorder->text().toStdString().c_str();

	// DECLARATION
	bool flagu, flagi, flagp;
	flagu = true;
	flagp = true;
	loggedIn = false;

	// CHECK THAT USERNAME AND PASSWORD AREN'T EMPTY
	if (getUsername().empty() || getPassword().empty()) {
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
			if (getUsername() == userData[i].f_name)
			{
				invalidUsername->setVisible(true);
				r_userBorder->clear();
				flagu = false;
				break;
			}
		}

		// PASSWORD REGISTERATION

		// TO CHECK PASSWORD IS AT LEAST 8 CHARACTERS
		if (getPassword().length() < 8)
		{
			invalidPassword->setText("Invalid Password , It should be 8 characters");
			invalidPassword->setStyleSheet("color:#a9446b;font: 16px;");
			r_passBorder->clear();
			flagp = false;
		}

		// WHEN USERNAME AND PASSWORD ARE VALID TO SAVE
		if (flagp == true && flagu == true) {
			userDataFile.f_name = getUsername();
			userDataFile.f_password = getPassword();

			// CREATE ID
			do {
				flagi = true;
				id = rand() % 1000 + 1000;
				for (int j = 0; j < userData.size(); j++) {
					if (userData[j].f_id == getId())
						flagi = false;
				}
			} while (flagi == false);

			userDataFile.f_id = getId();
			idLabel->setVisible(true);
			QString qid = QString::number(getId());
			idNumberLabel->setText(qid);
			idNumberLabel->setVisible(true);
			Register->setText("Registered");
			Register->setFixedWidth(250);
			Register->setStyleSheet("font:bold 20px;background-color:transparent;color:#10bbb3;border-left-color:transparent;border-right-color:transparent;border-top-color:transparent;border-bottom-color:transparent;");
			invalidUsername->setVisible(false);
			invalidPassword->setVisible(false);
			Delay(1000);
			userData.push_back(userDataFile);
			reg = true;
			loggedIn = true;
			signUpClicked = false;
			logInClicked = false;
			logOutClicked = false;
			PagesNavigator();		
		}
	}
}

inline void User::Delay(int millisecondsWait)
{
	QEventLoop loop;
	QTimer t;
	t.connect(&t, &QTimer::timeout, &loop, &QEventLoop::quit);
	t.start(millisecondsWait);
	loop.exec();
}

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

void User::setVector(vector<UserDataFile> U_D_F)
{
	// U_D_F = user data file
	// TO COPY USER DATA FILE INTO THE VECTOR
	
	userData = U_D_F;
}

vector <UserDataFile> User::getVector() {
	return userData;
}

User::~User()
{}