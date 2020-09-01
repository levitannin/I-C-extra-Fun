//Header Files
#include "Wordbank.hpp"

//______________________________________________________________________________
/*This function takes all of the words in the initialwords text file and 
downloads them into three ''columns'' that the passphrase will be pulled from.*/
wordbank::wordbank() {
	ifstream wordbank("initialwords.txt");
	string word;

	if (wordbank.fail()) {
		cout << "\nThere has been an error opening the "
			<< "'initialwords.txt' file.  Check and restart the system." << endl;
		fatal("Terminating");
		//look into editing fatal();
	}
  for (int cursor = 0; cursor < MaxColumn; ++cursor) {
    getline(wordbank, word);
    if (wordbank.good()) column1.push_back(word);
    else if (wordbank.eof()) break;
  }

  for (int cursor = 0; cursor < MaxColumn; ++cursor) {
    getline(wordbank, word);
    if (wordbank.good()) column2.push_back(word);
    else if (wordbank.eof()) break;
  }

  for (int cursor = 0; cursor < MaxColumn; ++cursor) {
    getline(wordbank, word);
    if (wordbank.good()) column3.push_back(word);
    else if (wordbank.eof()) break;
  }
  wordbank.close();
  //phrasetest() ;    //used for debugging phrasetest();
  //phrase_generation();    //for debugging phrase_generation();
  // debug_columns();     //for debugging column data.
}

//______________________________________________________________________________
/*test function to review columns.
void wordbank::debug_columns(){
  cout<<"\nColumn 1"<<endl;
  for(int cursor = 0; cursor < MaxColumn; ++cursor){
    cout<<column1[cursor]<<endl;
  }

  cout<<"\nColumn 2"<<endl;
  for(int cursor = 0; cursor < MaxColumn; ++cursor){
    cout<<column2[cursor]<<endl;
  }

  cout<<"\nColumn 3"<<endl;
  for(int cursor = 0; cursor < MaxColumn; ++cursor){
    cout<<column3[cursor]<<endl;
  }
}*/

//______________________________________________________________________________
string wordbank::phrase_generation() {

  //cout<<"This is a debug line in phrase generation."<<endl<<endl;   //debug line

	int local1 = rand() % MaxColumn;
  string word1 = column1[local1];

	int local2 = rand() % MaxColumn;
	string word2 = column2[local2];

	int local3 = rand() % MaxColumn;
	string word3 = column3[local3];
  

	word1.append(word3);
	word2.append(word1);

  string passphrase = word2;

	return passphrase;
}

//______________________________________________________________________________
/*This is a test function.  It will show a sample passphrase and can be shut off
to avoid confusion.  Used for debugging and examples.
void wordbank::phrasetest() {
	srand(time(NULL));

	int local1 = rand() % MaxColumn;
	string word1 = column1[local1];
	int local2 = rand() % MaxColumn;
	string word2 = column2[local2];
	int local3 = rand() % MaxColumn;
	string word3 = column3[local3];

	word1.append(word2);
	word1.append(word3);

	cout << "\n" << word1 << endl;

	//this section of the code will count the above phrase and review it.

	cout << "\nThe phrase is " << word1.size() << " character's long." << endl;

	//This will edit the cursor until it is the same length as PassMax.
	while(word1.size() != PassMax) {

		if (word1.size() > 8 && word1.size() < PassMax) {
			int y = rand() % 8;
			word1.insert(word1.begin() + y, '-');
		}
		else if (word1.size() < 8) {
			int y = rand() % 4;
			word1.insert(word1.begin() + y, '~');
		}
		else if (word1.size() > PassMax) {
			int y = rand() % PassMax;
			word1.erase(word1.begin() + y);

		}
	}
  cout << "\nThis passphrase is just right: " << word1 << endl;
}*/
