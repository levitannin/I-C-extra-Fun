#pragma once

//Header file
#include "tools.hpp"
#include "Wordbank.hpp"
#include "genmenu.hpp"

//Controller passphrase generation class
class controlpass{
private:
	vector<string>c_names;
	vector<string>c_phrase;
	int count = 0;
public:
	controlpass() { ; };
	void cdownload();
	void eight();
	void cconst();
	void c_create_phrase(string passphrase);
	void counter_eight(string passphrase);
	void counter_const(string passphrase);
	void cupload();
};
