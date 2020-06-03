
/*/////////////////////////////////////////////////////////////////////////////////////////

								Program start

*/////////////////////////////////////////////////////////////////////////////////////////


#include <iostream>		//in and out stream
#include <string>		//strings
#include <stdlib.h>		//standard libary
#include <ctime>		//clock time
#include <random>		//random



using std::endl;		//end of line
using std::cout;		//console out
using std::cin;			//console in
using std::string;		// string text 
using std::time;		//time clock


/*/////////////////////////////////////////////////////////////////////////////////////////

								Main Function

*/////////////////////////////////////////////////////////////////////////////////////////


int main() {

	const int size = 10;		//declare size as 10
	enum fields { WORD, HINT, fields };		//enumeration
	string wordBank[size][fields] = {		//word bank
		{"lunch",  "Mid day eating."},		//lunch
		{"earthly", "Something to do with our planet."},		//earthly
		{"camera", "You take pictures with this."},			//camera
		{"majestic",  "A unicorn is this."},				//magestic
		{"land",  "Not water but..."},						//land
		{"mess",  "Clean up that ____."},					//mess
		{"cherries",  "Has a pit."},						//cherries
		{"inquisitive",   "Another word for curious."},		//inquisitive
		{"carriage", "Has wheels."},						//carriage
		{"precede",  "Another word for Continue."}			//precede
	};

	/////////////////////////////////////////////////////////// welcome display
	cout << " Welcome, \n ";		//welcome
	cout << "The following simulation will train you to unscramble coded words, \n ";		//directions										
	cout << "You can enter hint to receive a tip if you get stuck.\n\n";					//hint options
	system("pause");																		//pause screen

	char PlayAgain = 'y';	//delcare PlayAgain

	while (PlayAgain != 'n') {				//while game loop 
		
		int totalAttempts = 0;				//declare total attemps
		int incorrectGuesses = 0;			//declare incroect guesses

			for (int i = 0; i < 3; i++) {		//for ever 3 incorect guesses

				incorrectGuesses = 0;			//set incorrect guesses to 0
				srand(static_cast<unsigned int>(time(0)));		//random number
				int choice = rand() % size;					//setting choice to random
				string theWord = wordBank[choice][WORD];	//delcareing the word
				string theHint = wordBank[choice][HINT];	//declaring the hint
				string MixedWord = theWord;				//declaring mixed word

				for (int j = 0; j < MixedWord.length(); j++) {		//how many letters there are
		
					int index1 = rand() % MixedWord.length();		//declaring index1
					int index2 = rand() % MixedWord.length();		//declaring index2		
					char buffer = MixedWord[index1];				//declaring buffer
					MixedWord[index1] = MixedWord[index2];			//index1 = index2
					MixedWord[index2] = buffer;						//index2 = buffer
				}

					cout << ">>>Your jumbled word is: " << MixedWord << endl;		//display mixed word
					string playerGuess = "";			//delcare players guess
	
					while (playerGuess != theWord) {	//while players guess does not = the word 
			
						if ((incorrectGuesses % 3 == 0) && (incorrectGuesses > 0)) {		//if incorrectly guessed 3 times 
							
							cout << "Enter 'hint'\n";							//display option of hint
						}

							totalAttempts++;		// increment total attemps by 1				
							cout << "Your guess: ";		//ask for guess
							cin >> playerGuess;			//players input
	
						if (playerGuess == "hint") {		//if guess = hint	
				
							incorrectGuesses = 0;			// set incorrect guesses to 0
							cout << theHint << endl << endl;	//show hint

						}
			
						else if (playerGuess != theWord) {		//if player guess does not = the word
							
							incorrectGuesses++;					//increment incorrect guess
							cout << "Incorrect!\n\n";			//display incorect
						}
					}

					cout << "Correct!\n\n";			//display correct
			}

		cout << "||||||COMPLETE|||||||\n\n";
		cout << "Total attempts: " << totalAttempts << endl << endl;

		do {      //do this
			cout << "Play again? y/n: ";		//display play again
			cin >> PlayAgain;					//give option
		} 
		
		while (PlayAgain!= 'y' && PlayAgain != 'n');	//while playagain does not = y and n
	}
	return 0;		//return 0 to end program
}


/*/////////////////////////////////////////////////////////////////////////////////////////

								Program End

*/////////////////////////////////////////////////////////////////////////////////////////