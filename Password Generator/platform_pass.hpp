#pragma once

//Header file
#include "tools.hpp"
#include "Wordbank.hpp"
#include "genmenu.hpp"

/*Platform passphrase generation class.  These
passwords are automatically set to 36 characters.*/
class platform_pass {
private:
	vector<string>p_names;
	vector<string>p_phrase;
	int count = 0;
public:
	platform_pass() { ; };
	void p_download();
	void gen_phrase();
	void p_count(string passphrase);
	void p_upload();
};
