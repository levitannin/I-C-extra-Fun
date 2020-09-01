#pragma once

//Header files
#include "tools.hpp"

class wordbank{
private:
	vector <string> column1;
	vector <string> column2;
	vector <string> column3;
public:
	wordbank();
  ~wordbank()=default;
  //void debug_columns();
	string phrase_generation();
	//void phrasetest();
};
