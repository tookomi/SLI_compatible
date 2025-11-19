// SLI_compatible.cpp: определяет точку входа для приложения.
//

#include "SLI_compatible.h"


using namespace std;

int main()
{
	cycle_queue<int> box;
	for (int i = 1; i != 22; i++) {
		box.push(i);
		if (!box.empty())
		cout << i%6<< " is " << box.pull() << endl;
	}
	return 0;
}
