//Header Files
#include "controllerpass.hpp"

//______________________________________________________________________________
void controlpass::cdownload() {
	ifstream Control_List("control_list.txt");
	string name, passphrase;

	if (Control_List.fail()) {
		cout << "\nThere has been an error opening the "
			<< "'control_list.txt' file.  Check and restart the system." << endl;
		fatal("Terminating");
	}

  for (;;) {
    getline(Control_List, name, ',');
    getline(Control_List, passphrase);
    if (Control_List.good()) {
      c_names.push_back(name);
      c_phrase.push_back(passphrase);
      count++;
    }
    else if (Control_List.eof()) break;
  }
  Control_List.close();
}

//______________________________________________________________________________
void controlpass::eight() {
	char choice;

	cout << "\n To confirm, you require an 8 bit character passphrase?  (Y/N)?"
		<< endl;
	cin >> choice;

	if (choice == 'n' || choice == 'N') {
		cout << "\nYou will be redirected to the main menu." << endl;
	}
	else if (choice == 'y' || choice == 'Y') {
		string nickname;
		cout << "\nEnter a single-word title for this server:" << endl;
		cin >> nickname;
		c_names.push_back(nickname);

		cout << "\nYour 8 character passphrase will be generated now: ";
		wordbank bank;
		string passphrase = bank.phrase_generation();
    cout<<"Test line before counter"<<endl;
		counter_eight(passphrase);

		cout << "\nController " << c_names[count] << "'s passphrase is " << c_phrase[count]
			<< endl;

		count++;
    cupload();
	}
  else cout << "Invalid input. Try again."<< endl;
}

//______________________________________________________________________________
void controlpass::cconst() {
	char choice;

	cout << "\n To confirm, you require an " << PassMax
		<< " bit character passphrase?  (Y/N)?" << endl;
	cin >> choice;

	if (choice == 'n' || choice == 'N') {
		cout << "\nYou will be redirected to the main menu." << endl;
	}
	else if (choice == 'y' || choice == 'Y') {
		string nickname;
		cout << "\nEnter a single-word title for this controller:" << endl;
		cin >> nickname;
		c_names.push_back(nickname);

		cout << "\nYour " << PassMax << " character passphrase will be generated now: ";
		wordbank bank;
		string passphrase = bank.phrase_generation();
		counter_const(passphrase);

		cout << "\nController " << c_names[count] << "'s passphrase is " << c_phrase[count]
			<< endl;

		count++;
    cupload();
	}
  else cout << "Invalid input. Try again."<< endl;
}

//______________________________________________________________________________
void controlpass::c_create_phrase(string passphrase) {
	c_phrase.push_back(passphrase);
}

//______________________________________________________________________________
void controlpass::counter_eight(string passphrase) {

	int counter = passphrase.size();

	while (counter != 8) {
		if (counter > 8) {
			int sub = rand() % counter;
			passphrase.erase(sub, 1);
      counter = passphrase.size();
		}
		else if (counter < 8) {
			int add = rand() % counter;
			if (add == 1) passphrase.insert(add, 1, '_');
			else if (add == 2) passphrase.insert(add, 1, '-');
			else if (add == 3) passphrase.insert(add, 1, '~');
			else if (add == 4) passphrase.insert(add, 1, '*');
			else if (add == 5) passphrase.insert(add, 1, '(');
			else if (add == 6) passphrase.insert(add, 1, ')');
			else passphrase.insert(add, 1, '@');

      counter = passphrase.size();
		}
	}
	c_create_phrase(passphrase);
}

//______________________________________________________________________________
void controlpass::counter_const(string passphrase) {

	int counter = passphrase.size();

	while (counter != PassMax) {
		if (counter > PassMax) {
			int sub = rand() % counter;
			passphrase.erase(sub, 1);
      counter = passphrase.size();
		}
		else if (counter < PassMax) {
			int add = rand() % counter;
			if (add == 1) passphrase.insert(add, 1, '_');
			else if (add == 2) passphrase.insert(add, 1, '-');
			else if (add == 3) passphrase.insert(add, 1, '~');
			else if (add == 4) passphrase.insert(add, 1, '*');
			else if (add == 5) passphrase.insert(add, 1, '(');
			else if (add == 6) passphrase.insert(add, 1, ')');
			else if (add == 7) passphrase.insert(add, 1, '$');
			else if (add == 8) passphrase.insert(add, 1, '&');
			else if (add == 9) passphrase.insert(add, 1, '\\');
			else if (add == 10) passphrase.insert(add, 1, '^');
			else passphrase.insert(add, 1, '@');
			//Add more if PassMax goes above 12, and delete lines if it goes below 12.
      counter = passphrase.size();
		}
	}
	c_create_phrase(passphrase);
}

//______________________________________________________________________________
void controlpass::cupload() {
	ofstream Control_List("control_list.txt", ios::app);
	string name, passphrase;

	if (Control_List.fail()) {
		cout << "\nThere has been an error opening the 'control_list.txt' file." << endl;
		fatal("Terminating");
	}

  for (int cursor = 0 ; cursor < count ; cursor++) {
    Control_List << c_names[cursor] << ",";
    Control_List << c_phrase[cursor] << endl;
	}
  Control_List.close();
}
