// SLI_compatible.cpp: определяет точку входа для приложения.
//

#include "SLI_compatible.h"


using namespace std;

int main()
{
	cycle_queue<int> box;
	std::find(box.begin(), box.end(), 1);
	for (int i = 1; i != 7; i++) {
		box.push(i);
		cout << i<< " is " << box.pull() << endl;
	}
	//for (int i = 0; i != 6; i++)
		//cout<<box.pull()<<endl;
	/*for (auto it = box.begin(); it != box.end(); it++) {
		cout << *it << endl;
	}*/
	return 0;
}
