#include <QtWidgets/QApplication>
#include "User.h"
#include <vector>

using namespace std;

int main(int argc, char* argv[])
{
	QApplication Sarahah(argc, argv);

	// DECLARATION
	vector<UserDataFile> userData;
	UserDataFile userDataFile;
	int oldDataSize, newDataSize;
	ifstream readUserData("Userdata.txt");
	ofstream writeUserData("Userdata.txt", ios::app);

	// READ DATA OF THE USER FROM FILE
	while (readUserData >> userDataFile.f_name >> userDataFile.f_password >> userDataFile.f_id) {
		userData.push_back(userDataFile);
	}
	readUserData.close();

	oldDataSize = userData.size();

	User user;

	user.setVector(userData);

	QObject::connect(user.close, &QPushButton::clicked, [&]() {

		// WRITE DATA OF THE USER IN FILE
		userData = user.getVector();
		if (userData.size() > oldDataSize)
		{
			newDataSize = userData.size() - oldDataSize;
			for (int i = 0; i < newDataSize; i++) {
				writeUserData << userData[oldDataSize+i].f_name << " " << userData[oldDataSize + i].f_password << " " << userData[oldDataSize + i].f_id << endl;
			}
		}
		writeUserData.close();
		Sarahah.exit();

	});

	user.setWindowState(Qt::WindowMaximized);
	user.setWindowFlags(Qt::FramelessWindowHint);
	user.show();

	return Sarahah.exec();
}