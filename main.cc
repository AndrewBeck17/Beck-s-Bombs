//temp empty
#include "beck.cc"
#include "tenji.cc"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
	int lifetime = 100;
	int choice = 0;

	cout << "Pick and Option (1 or 2): " << endl;
	cout << "1. Tenji Vang " << endl;
	cout << "2. Andrew Beck " << endl;
	cin >> choice;
	if (!cin) die();
	if (choice == 1) tenjis_function(lifetime);//runs tenjis .cc function
	else if (choice == 2) becks_bomb(lifetime); //runs andrews .cc function
	else {
		cout << "Input Needs to be 1 or 2!" << endl;
		die(); //handles problematic inputs
	}

	return 0;
}
