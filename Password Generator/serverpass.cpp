//Header Files
#include "serverpass.hpp"

//______________________________________________________________________________
void servpass::sdownload() {
	ifstream Serv_List("serv_list.txt");
	string name, passphrase;

	if (Serv_List.fail()) {
		cout << "\nThere has been an error opening the "
			<< "'serv_list.txt' file.  Check and restart the system." << endl;
		fatal("Terminating");
	}

  for (;;) {
    getline(Serv_List, name, ',');
    getline(Serv_List, passphrase);
    if (Serv_List.good()) {
      s_names.push_back(name);
      s_phrase.push_back(passphrase);
      count++;
    }
    else if (Serv_List.eof()) break;
	}
  Serv_List.close();
}

//______________________________________________________________________________
void servpass::eight() {
	char choice;
  string nickname, passphrase;
  wordbank bank;

	cout << "\n To confirm, you require an 8 bit character passphrase?  (Y/N)?"
		<< endl;
	cin >> choice;

	if (choice == 'n' ||choice == 'N') {
		cout << "\nYou will be redirected to the main menu." << endl;
	}
	else if (choice == 'y' || choice == 'Y') {
		cout << "\nEnter a single-word title for this server:" << endl;
		cin >> nickname;
    //cout<<"\nConfirm you meant to type the name: "<<nickname<<"?"<<endl; //debugging
		s_names.push_back(nickname);
    //cout<<"\nThe nickname saved to the vector is: "<<s_names[count]<<endl;  //debugging

		cout << "\nYour 8 character passphrase will be generated now."<<endl;
		passphrase = bank.phrase_generation();
    
    cout<<"This is before the counter call"<<endl;    //debugger
		counter_eight(passphrase);

		cout << "\nServer/Camera " << s_names[count] << "'s passphrase is " << s_phrase[count]
			<< endl;

		count++;
    supload();
	}
  else cout<<"Invalid input.  Try again."<<endl;
}

//______________________________________________________________________________
void servpass::sconst() {
	char choice;

	cout << "\n To confirm, you require an " << PassMax 
		<< " bit character passphrase?  (Y/N)?" << endl;
	cin >> choice;

	if (choice == 'n' || choice == 'N') {
		cout << "\nYou will be redirected to the main menu." << endl;
	}
	else if (choice == 'y' || choice == 'Y') {
		string nickname;
		cout << "\nEnter a single-word title for this server:" << endl;
		cin >> nickname;
		s_names.push_back(nickname);

		cout << "\nYour " << PassMax << " character passphrase will be generated now: ";
		wordbank bank;
		string passphrase = bank.phrase_generation();
		counter_const(passphrase);

		cout << "\nServer/Camera " << s_names[count] << "'s passphrase is " << s_phrase[count]
			<< endl;

		count++;
    supload();
	}
  else cout<<"Invalid input.  Try again."<<endl;
}

//______________________________________________________________________________
void servpass::s_create_phrase(string passphrase) {
	s_phrase.push_back(passphrase);
}

//______________________________________________________________________________
void servpass::counter_eight(string passphrase) {

	int counter = passphrase.size();
  cout<<counter<<endl;

	while (counter != 8){
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
	s_create_phrase(passphrase);
}

//______________________________________________________________________________
void servpass::counter_const(string passphrase) {

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
	s_create_phrase(passphrase);
}

//______________________________________________________________________________
void servpass::supload() {
	ofstream Serv_List("serv_list.txt", ios::app);
	string name, passphrase;

	if (Serv_List.fail()) {
		cout << "\nThere has been an error opening the 'serv_list.txt' file." << endl;
		fatal("Terminating");
	}

  for (int cursor = 0 ; cursor < count ; cursor++) {
    Serv_List << s_names[cursor] << ",";
    Serv_List << s_phrase[cursor] << endl;
	}
  Serv_List.close();
}
