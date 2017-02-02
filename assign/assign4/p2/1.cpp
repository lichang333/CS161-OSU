
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;
const int MAX_TRIES = 5;
int letterFill(char, string, string&);


int main()
{
	string name;
	char letter;
	int num_of_wrong_guesses = 0;
	string word;

	srand(time(NULL));   // ONLY NEED THIS ONCE!

	// welcome the user
	cout << "\n\nWelcome to hangman!! Guess a country that comes into your mind.";
	// Ask user for for Easy, Average, Hard
	string level;
	cout << "\nChoose a LEVEL(E - Easy, A - Average, H - Hard):" << endl;
	cin >> level;

	// compare level 
	if (level == "Easy")
	{
		//put all the string inside the array here
		string easy[] = { "india", "japan", "nepal", "china" };
		string word;

		int n = rand() % 4;
		word = easy[n];

		//call the function here for guessing game
		// Initialize the secret word with the * character.
		string unknown(word.length(), '*');
		cout << "\n\nEach letter is represented by an asterisk.";
		cout << "\n\nYou have to type only one letter in one try.";
		cout << "\n\nYou have " << MAX_TRIES << " tries to try and guess the country.";
		cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
		// Loop until the guesses are used up
		while (num_of_wrong_guesses < MAX_TRIES)
		{
			cout << "\n\n" << unknown;
			cout << "\n\nGuess a letter: ";
			cin >> letter;
			// Fill secret word with letter if the guess is correct,
			// otherwise increment the number of wrong guesses.
			if (letterFill(letter, word, unknown) == 0)
			{
				cout << endl << "Whoops! That letter isn't in there!" << endl;
				num_of_wrong_guesses++;
			}
			else
			{
				cout << endl << "You found a letter! Isn't that exciting?" << endl;
			}
			// Tell user how many guesses has left.
			cout << "You have " << MAX_TRIES - num_of_wrong_guesses;
			cout << " guesses left." << endl;
			// Check if user guessed the word.
			if (word == unknown)
			{
				cout << word << endl;
				cout << "Yeah! You got it!";
				break;
			}
		}
		if (num_of_wrong_guesses == MAX_TRIES)
		{
			cout << "\nSorry, you lose...you've been hanged." << endl;
			cout << "The word was : " << word << endl;
		}
		cin.ignore();
		cin.get();
		return 0;
	}

	else if (level == "Average")
	{
		//put all the string inside the array here
		string average[] = { "madagascar", "azerbaijan", "kyrgyzstan" };

		int n = rand() % 3;
		word = average[n];

		//call the function here for guessing game
		// Initialize the secret word with the * character.
		string unknown(word.length(), '*');
		cout << "\n\nEach letter is represented by an asterisk.";
		cout << "\n\nYou have to type only one letter in one try.";
		cout << "\n\nYou have " << MAX_TRIES << " tries to try and guess the country.";
		cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
		// Loop until the guesses are used up
		while (num_of_wrong_guesses < MAX_TRIES)
		{
			cout << "\n\n" << unknown;
			cout << "\n\nGuess a letter: ";
			cin >> letter;
			// Fill secret word with letter if the guess is correct,
			// otherwise increment the number of wrong guesses.
			if (letterFill(letter, word, unknown) == 0)
			{
				cout << endl << "Whoops! That letter isn't in there!" << endl;
				num_of_wrong_guesses++;
			}
			else
			{
				cout << endl << "You found a letter! Isn't that exciting?" << endl;
			}
			// Tell user how many guesses has left.
			cout << "You have " << MAX_TRIES - num_of_wrong_guesses;
			cout << " guesses left." << endl;
			// Check if user guessed the word.
			if (word == unknown)
			{
				cout << word << endl;
				cout << "Yeah! You got it!";
				break;
			}
		}
		if (num_of_wrong_guesses == MAX_TRIES)
		{
			cout << "\nSorry, you lose...you've been hanged." << endl;
			cout << "The word was : " << word << endl;
		}
		cin.ignore();
		cin.get();
		return 0;
	}

	else if (level == "Hard")
	{
		//put all the string inside the array here
		string hard[] = { "turkmenistan", "french guiana", "new caledonia" };

		int n = rand() % 3;
		word = hard[n];

		//call the function here for guessing game
		// Initialize the secret word with the * character.
		string unknown(word.length(), '*');
		cout << "\n\nEach letter is represented by an asterisk.";
		cout << "\n\nYou have to type only one letter in one try.";
		cout << "\n\nYou have " << MAX_TRIES << " tries to try and guess the country.";
		cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
		// Loop until the guesses are used up
		while (num_of_wrong_guesses < MAX_TRIES)
		{
			cout << "\n\n" << unknown;
			cout << "\n\nGuess a letter: ";
			cin >> letter;
			// Fill secret word with letter if the guess is correct,
			// otherwise increment the number of wrong guesses.
			if (letterFill(letter, word, unknown) == 0)
			{
				cout << endl << "Whoops! That letter isn't in there!" << endl;
				num_of_wrong_guesses++;
			}
			else
			{
				cout << endl << "You found a letter! Isn't that exciting?" << endl;
			}
			// Tell user how many guesses has left.
			cout << "You have " << MAX_TRIES - num_of_wrong_guesses;
			cout << " guesses left." << endl;
			// Check if user guessed the word.
			if (word == unknown)
			{
				cout << word << endl;
				cout << "Yeah! You got it!";
				break;
			}
		}
		if (num_of_wrong_guesses == MAX_TRIES)
		{
			cout << "\nSorry, you lose...you've been hanged." << endl;
			cout << "The word was : " << word << endl;
		}
		cin.ignore();
		cin.get();
		return 0;
	}

}

// as I said in my previous post, read up on functions!
int letterFill(char guess, string secretword, string &guessword)
{
	int i;
	int matches = 0;
	int len = secretword.length();
	for (i = 0; i< len; i++)
	{
		// Did we already match this letter in a previous guess?
		if (guess == guessword[i])
			return 0;
		// Is the guess in the secret word?
		if (guess == secretword[i])
		{
			guessword[i] = guess;
			matches++;
		}
	}
	return matches;
}