//Wheel of Fortune Program
#include<ctime>
#include<iomanip>
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string>
#include<cstring>
using namespace std;
//=============================================================================
//Function Prototypes
int spin_wheel();
char isvowel(char guess);
void print_puzzle (string puzzle);
void print_score (int players, int score[]);
void initialize_arrays (string& phrase, string& puzzle);
void printHeading();
bool buy_vowel (int player, int score[], string phrase, string& puzzle);
bool spin (int player, int score[], string phrase, string& puzzle);
bool player_turn (int player, int score[], string phrase, string& puzzle);
bool solve (int player, int score[], string phrase, string& puzzle);
//=============================================================================
//Global Constants
const string STAR = "*";
const int MAX = 14;
const int PHRASE_SIZE = 81;
const int NUM_PLAYERS = 3;
const int VOWEL_COST = 250;
const int BANKRUPT = 0;
const int LOSE_TURN = -1;
const int WHEEL_SIZE = 15;
const int WHEEL[WHEEL_SIZE] = 
	{50, 100, 150, 200, 250, 300, 350, 400, 450, 500, 1000, 1500, 2500,
	BANKRUPT, LOSE_TURN};
//=============================================================================
int main()
{
//Declaring variables
	bool notSolved = false;
	string puzzle, phrase;
	int player = 0;
	int currentPlayer = 0;
	int score[NUM_PLAYERS] = {0, 0, 0};
//Function call to open a data file that contains the phrase
	initialize_arrays(phrase, puzzle);
//Function call to initialize the player's turn
	do 
	{
		player = currentPlayer + 1;
		player = currentPlayer % 3;
	}
	while (notSolved);
	{
	player_turn(player, score, phrase, puzzle);
	}
	return 0;
}
//=============================================================================
//Function call to open file and put it into an array
void initialize_arrays (string& phrase, string& puzzle)
{
	int count;
	ifstream inFile;
	string userInput;
//Error test loop
	cout << "Please enter a file name you wish to open ->";
	cin >> userInput;
	inFile.open(userInput.c_str());
	while(!inFile)
	{
		inFile.clear();
		cout << "Please enter a valid file name->";
		cin >> userInput;
		inFile.open(userInput.c_str());
	}
	
	cout << "Here is your phrase: " << endl;
//Loop to store phrase into array
	
	getline(inFile, phrase);
	for(count = 0; phrase.length() > count; count ++)
	{
		puzzle.insert (count, STAR);
	}	
	cout << puzzle;
	cout << endl << endl;
	inFile.clear();
	inFile.close();
}
//=============================================================================
//Function to print the file's heading
void printHeading()
{
	cout << "Welcome to Wheel of Fortune!" << endl;
}
//=============================================================================
//Function that generates what the wheel spin's value will be
int spin_wheel()
{	
	int spin, luckyNumbers;
	unsigned seed = time(0);
	srand(seed);
	spin = rand() % 14;
	cout << WHEEL[spin] << endl << endl;
	luckyNumbers = WHEEL[spin];
	return(luckyNumbers);
}
//=============================================================================
//Function that prints the phrase array after the puzzle has been solved
void print_puzzle(string phrase)
{
	cout << "CONGRATULATIONS! You've solved the puzzle:" << phrase << endl;
}
//=============================================================================
//Function that directs the players turn
bool player_turn (int player, int score[], string phrase, string& puzzle)
{
//Declaring local variables
	char choice;
	bool validChoice = false;
	cout << "It is player " << player + 1 << "'s turn" << endl;
	cout << "What would you like to do with your turn?" << endl;
	cout << "Here are your options:" << endl;
	cout << "(s)pin the wheel, s(o)lve he puzzle, or (b)uy a vowel" << endl;
	cout << "Type the corresponding lower case letter in () to move on ->";
	cin >> choice;
//Loop to make sure the player entered a valid character to execute
//a function
	while (!validChoice)
	{
		validChoice = false;
		switch (choice)
		{
			case 's': spin (player, score, phrase, puzzle);
				cout << endl;
				validChoice = true;
				break;
			case 'o': solve (player, score, phrase, puzzle);
				cout << endl;
				validChoice = true;
				break;
			case 'b':
				buy_vowel(player, score, phrase, puzzle);
				cout << endl;
				validChoice = true;
				break;
			default : cout << "Please make sure you typed a lower case letter" << endl;
		}
	}
	return(player_turn);
}	
//=============================================================================
//Function to determine if the letter the user selects is a vowel
char isvowel (char guess)
{
//Declaring local variables
	bool notVowel = false;
	enum VOWELS {a, e, i, o, u};
//Error checking loop to make sure player entered a recognized vowel
	while(!notVowel)
	{
		notVowel = false;
		switch(guess)
		{
		case 'a' : guess = a;
			notVowel = true;
			break;
		case 'e' : guess = e;
			notVowel = true;
			break;
		case 'i' : guess = i;
			notVowel = true;
			break;
		case 'o' : guess = o;
			notVowel = true;
			break;
		case 'u' : guess = u;
			notVowel = true;
			break;
		default : cout << "Invalid character" << endl;
			cout << "Please enter a lowercase vowel ->";
			cin >> guess;
		}
	}
	cout << "The vowel you chose is: " << guess << endl << endl;
	return (guess);
}
//=============================================================================
bool buy_vowel(int player, int score[], string phrase, string& puzzle)
{
//Declaring local variables
	string insertChar;
	char secretChar, guess;
	int count, letterPosition = 0, foundAt;
	bool vowelFound = false;
	
//Getting the player's guess
	cout << "Please enter the vowel you wish to buy ";
	cout <<	"as a lowercase character ->";
	cin >> guess;	
	isvowel(guess);
//Loop to scan array length
	for(count = 0;  (count < phrase.length()) && (phrase[count] != guess); count++)
		continue;
//Checking phrase array for player's guess' letter position 
	while (letterPosition < count && !vowelFound)
	{
		if (phrase[letterPosition] != guess)
		{
			letterPosition++;
		}
		else
		{
			vowelFound = true;
		}
	}
//Indexing where the vowel was found
	foundAt = letterPosition;
//Returning the character from the position that the loop found
	secretChar = phrase.at(foundAt);
//Changing secretChar into string
	insertChar = secretChar;
//Inserting guessed character into puzzle string
	puzzle.insert(foundAt, insertChar);
//Deleting the asterik holding the letter's position
	puzzle.erase(foundAt+1, 1);
//Printing the modified puzzle
	cout << "Here is the current progress: " << endl;
	cout << puzzle << endl;
	return (vowelFound);
}
//=============================================================================
bool spin (int player, int score[], string phrase, string& puzzle)
{
spin_wheel();
int count, luckyNumbers, numLetters = 0, puzzleLength = 0;
bool lucky;
char letter;
string foundLetter;
cout << "You've spun " << luckyNumbers << endl;
if (luckyNumbers = 0)
{
	score[player] = 0;
	cout << "BANKRUPT! Better luck next time" << endl;
	lucky = false;
}
	if (luckyNumbers = -1)
	{
		cout << "LOSE TURN! Better luck next time" << endl;
		lucky = false;
	}
	else
	{
		lucky = true;
		cout << "Please enter a lowercase letter you wish to guess ->";
		cin >> letter;
	}
	puzzleLength = phrase.length();
//Loop to scan array for matching letters
	while(lucky)
	{
		
		for(count = 0; count < puzzleLength; count++)
			if(letter == phrase[count])
			{
				lucky = true;
				foundLetter = letter;
				puzzle.insert(count, foundLetter);
				numLetters++;
			}
				if(letter !=phrase[count] && count < puzzleLength)
				{
					lucky = true;
				}
				else (letter !=phrase[count] && count == puzzleLength);
				{
					lucky = false;
				}
	}
	score[player] = numLetters * luckyNumbers;
	
	print_score(player, score);
	return (spin);
}
//=============================================================================
void print_score (int player, int score[])
{
	const string LINE = "========";
	cout << setw(50) << "Here are your current scores: " << endl;
	cout << setw(15) << "PLAYER 1" << setw(15) << "PLAYER 2";
	cout << setw(15) << "PLAYER 3" << endl;
	cout << setw(15) << LINE << setw(15) << LINE << setw(15) << LINE << endl;
	cout << setw(15) << score[0] << score[1] << score[2] << endl << endl;
}
//=============================================================================
bool solve (int player, int score[], string phrase, string& puzzle)
{
	return(solve);
}