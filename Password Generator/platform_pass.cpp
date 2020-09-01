//Header Files
#include "platform_pass.hpp"

//______________________________________________________________________________
void platform_pass::p_download() {
	ifstream PlatformList("platform_list.txt");
	string name, passphrase;

	if (PlatformList.fail()) {
		cout << "\nThere has been an error opening the "
			<< "'platform_list.txt' file.  Check and restart the system." << endl;
		fatal("Terminating");
	}
  for (;;) {
    getline(PlatformList, name, ',');
    getline(PlatformList, passphrase);
    if (PlatformList.good()) {
      p_names.push_back(name);
      p_phrase.push_back(passphrase);
      count++;
    }
    else if (PlatformList.eof()) break;
  }
  PlatformList.close();
}

//______________________________________________________________________________
void platform_pass::gen_phrase() {
	char choice;
	cout << "\nTo confirm, you require a 36 character passphrase? (Y/N)" << endl;
	cin >> choice;

	if (choice == 'n' || choice == 'N') {
		cout << "\nYou will be redirected to the main menu." << endl;
	}
	else if (choice == 'y' || choice == 'Y') {
		string nickname;
		cout << "\nEnter a single-word title for this platform:" << endl;
		cin >> nickname;
		p_names.push_back(nickname);

		cout << "\nYour 36 character passphrase will be generated now: ";
		wordbank bank;
		string passphrase = bank.phrase_generation();
    cout<<passphrase<<endl;
		p_count(passphrase);

		cout << "\nPlatform " << p_names[count] << "'s passphrase is: " 
			<< p_phrase[count] << endl;

		count++;
    p_upload();
	}
  else cout<<"Invalid input.  Try again."<<endl;
}

//______________________________________________________________________________
void platform_pass::p_count(string passphrase) {

	int counter = passphrase.size();

	while (counter != 36) {
		if (counter > 36) {
			int sub = rand() % counter;
			passphrase.erase(sub, 1);
      counter = passphrase.size();
		}
		else if (counter < 36) {
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
      else if (add == 11) passphrase.insert(add, 1, '!');
      else if (add == 12) passphrase.insert(add, 1, '?');
      else if (add == 13) passphrase.insert(add, 1, '/');
      else if (add == 14) passphrase.insert(add, 1, '%');
      else if (add == 15) passphrase.insert(add, 1, '#');
			else if (add == 16) passphrase.insert(add, 1, '+');
      else if (add == 17) passphrase.insert(add, 1, '=');
      else if (add == 18) passphrase.insert(add, 1, '_');
      else if (add == 19) passphrase.insert(add, 1, '>');
      else if (add == 20) passphrase.insert(add, 1, '<');
			else passphrase.insert(add, 1, '@');
      counter = passphrase.size();
		}
	}
	p_phrase.push_back(passphrase);
}

//______________________________________________________________________________
void platform_pass::p_upload() {
	ofstream PlatformList("platform_list.txt", ios::app);
	string name, passphrase;

	if (PlatformList.fail()) {
		cout << "\nThere has been an error opening the 'platform_list.txt' file." << endl;
		fatal("Terminating");
	}
  for (int cursor = 0 ; cursor < count ; cursor++) {
    PlatformList << p_names[cursor] << ",";
    PlatformList << p_phrase[cursor] << endl;
  }
  PlatformList.close();
}
