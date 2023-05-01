#include "User.h"
#include <QtWidgets/QApplication>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication Sarahah(argc, argv);
	vector<UserDataFile> v;
	UserDataFile f;
	int oldDataSize, newDataSize;
	ifstream readUserData("Userdata.txt");
	ofstream writeUserData("Userdata.txt", ios::app);

	while (readUserData >> f.f_name >> f.f_password >> f.f_id) {
		v.push_back(f);
	}
	readUserData.close();

	oldDataSize = v.size();

	User user;

	user.setVector(v);

	if (user.reg) {
		v = user.getVector();

		if (v.size() > oldDataSize)
		{
			newDataSize = v.size() - oldDataSize;
			for (int i = 1; i <= newDataSize; i++) {
				writeUserData << v[v.size() - i].f_name << " " << v[v.size() - i].f_password << " " << v[v.size() - i].f_id << endl;
			}
		}
		writeUserData.close();
	}

	user.setWindowState(Qt::WindowMaximized);
	user.show();
    return Sarahah.exec();
}