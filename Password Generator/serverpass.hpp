#pragma once

//Header file
#include "tools.hpp"
#include "Wordbank.hpp"
#include "genmenu.hpp"

//Server passphrase generation class
class servpass{
private:
	vector<string>s_names;
	vector<string>s_phrase;
	int count;
public:
	servpass() { count = 0; };
	void sdownload();
	void eight();
	void sconst();
	void s_create_phrase(string passphrase);
	void counter_eight(string passphrase);
	void counter_const(string passphrase);
	void supload();
};
