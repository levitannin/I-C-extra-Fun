//Header File
#include "genmenu.hpp"

//______________________________________________________________________________
void downloads() {
	servpass sinput;
	sinput.sdownload();
	controlpass cinput;
	cinput.cdownload();
	platform_pass pinput;
	pinput.p_download();
}

//______________________________________________________________________________
//This is the initial menu for the program, leading into a split of capabilities.
void menu1(){
	int choice1;
	platform_pass select;

	do{
	cout << "\nThe following are supported options for passphrase generation:\n\n"
		<< "\t1 | Generate Server or Camera Passphrase\n"
		<< "\t2 | Generate Controller Passphrase\n"
		<< "\t3 | Generate Platform Passphrase\n"
		<< "\t4 | Exit Program\n\n"
		<< "Selection: " << endl;
	cin >> choice1;

		switch (choice1){
		case 1: servmenu(); break;
		case 2: controlmenu(); break;
		case 3: select.gen_phrase(); break;
		case 4: break;
		default: cout << "\nError: Please input an option between '1' and '4' to continue." << endl;
		}
	} while (choice1 != 4);
}

//______________________________________________________________________________
//This menu type is focused on server passphrase needs.
void servmenu(){
	servpass server;
	int choice2;

	do{
    cout << "\nThe choices below are based on the needs of components attached"
      << "to the servers.  Choose as necessary.\n\n"
      << "\t1 | 8 bit character passphrase\n"
      << "\t2 | "<< PassMax <<" bit character passphrase\n"
      << "\t3 | Exit to main menu\n"
      << "Selection: " << endl;
    cin >> choice2;

		switch (choice2){
		case 1: server.eight(); break;
		case 2: server.sconst(); break;
		case 3: break;
		default: cout << "\nError: Please input an option between '1' and '3' to continue." << endl;
		}
	} while (choice2 != 3);
}

//______________________________________________________________________________
//This menu type is focused on controll passphrase needs.
void controlmenu(){
	controlpass controller;
	int choice;

  do{
    cout << "\nThe choices below are based on the needs of components attached"
      << "to controllers.  Choose as necessary.\n\n"
      << "\t1 | 8 bit character passphrase\n"
      << "\t2 | " << PassMax << " bit character passphrase\n"
      << "\t3 | Exit to main menu\n"
      << "Selection: " << endl;
    cin >> choice;

	
		switch (choice){
		case 1: controller.eight(); break;
		case 2: controller.cconst(); break;
		case 3: break;
		default: cout << "\nError: Please input an option between '1' and '3' to continue." << endl;
		}
	} while (choice != 3);
}
