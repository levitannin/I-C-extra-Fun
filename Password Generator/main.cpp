/*Security Password Generator
Created by Levitannin on 5 February 2019 at 10:27 AM

This program is designed to create passphrases for security implementation.
*/

//Header files
#include "genmenu.hpp"

int main(void){
  srand(time(NULL));
	banner();
	downloads();
	menu1();
	bye();
}
