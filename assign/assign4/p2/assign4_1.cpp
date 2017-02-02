#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

struct Player {
	string name;
	int money;
	};
	
int main(){

	//PLAYER INFORMATION AND WELCOME
	Player one;
	one.money = 0;
	cout << "Welcome to 'Wheel of Fortune'! What is your name?: ";
	cin >> one.name;
	cout << "Hello, " << one.name << ". You start the game with $" << one.money << "." << endl;
	
	// READ FROM FILE
	ifstream infile;
	string phrase;
	string category;
	int phrase_length;
	infile.open("input.txt");∑
	
	while(infile){
		infile >> phrase >> category;
		}
	phrase_length = phrase.length();
		
	cout << "The category is " << category << endl << endl;
	
	
	// WHEEL
	int wheel[24];
	wheel[0] = 0;
	wheel[1] = 0; 
	wheel[2] = 800;
	wheel[3] = 350;
	wheel[4] = 450;
	wheel[5] = 700;
	wheel[6] = 300;
	wheel[7] = 600;
	wheel[8] = 5000;
	wheel[9] = 600;
	wheel[10] = 500;
	wheel[11] = 300;
	wheel[12] = 500;
	wheel[13] = 800;
	wheel[14] = 550;
	wheel[15] = 400;
	wheel[16] = 300;
	wheel[17] = 900;
	wheel[18] = 500;
	wheel[19] = 300;
	wheel[20] = 900;
	wheel[21] = 600;
	wheel[22] = 400;
	wheel[23] = 300;
	
	int player_menu;
	char player_choice;
	bool spin_wheel;
	long seed = time(NULL); // gets time
	srand(seed);
	int spin;
	bool playing = true;
	int player_spins = 0;
	string player_solve;
	bool player_win = false;
	
	char copy_phrase[phrase_length];
		for(int i = 0; i < phrase_length; i++){
			copy_phrase[i] = '-';
			}
			
	while(playing == true && player_win == false){
	
	if(player_spins < 1){ // Check to see if the player has spun the wheel yet.
		cout << "Spin the wheel to start..." << endl;
		player_menu = 2;
		char copy_phrase[phrase_length];
		for(int i = 0; i < phrase_length; i++){
			copy_phrase[i] = '-';
			}
		}
	else{
		cout << "\n\nWhat would you like to do?: " << endl << "1. Guess a letter" << endl << "2. Spin the wheel" << endl << "3. Buy a vowel (- $250)" << endl << "4. Solve the puzzle" << endl;
		cin >> player_menu;
		}
		player_choice = '*';
		// EVALUATE THE PLAYERS MENU CHOICE
		if(player_menu == 1){
			cout << "Guess a consonant: ";
			cin >> player_choice;
			
			}
		if(player_menu == 2){
			player_spins++;
			// RANDOM NUMBER GENERATOR
			spin = rand() % 25;
			cout << endl << "The wheel landed on: $" << wheel[spin] << "." << endl;
			if(spin == 0 || spin == 1){
				one.money == 0;
				cout << "OH NO! Bankrupt!" << endl;
				}
			}
		if(player_menu == 3){
			one.money -= 250;
			cout << "Here is your money now: $" << one.money << ". " << "Guess a vowel: ";
			cin >> player_choice;
			}
		if(player_menu == 4){
			cout << "You want to solve (no caps please and use underscores for spaces):"; // Underscores because of time constraints.
			cin >> player_solve;
			if(player_solve == phrase){
				cout << "You win!" << endl;
				player_win = true;
				playing = false;
				}
			}
			
		for(int i = 0; i < phrase_length; i++){
			if(phrase[i] == '_'){
				copy_phrase[i] = ' ';
				}
			if(phrase[i] == player_choice){
				copy_phrase[i] = player_choice;
				one.money += wheel[spin];
				cout << "Your money: $" << one.money << endl;
				}				
			}
		cout << endl;
		if (player_win == false){
			for(int i = 0; i < phrase_length; i++){
				cout << copy_phrase[i];
				}
			}
		}
	if(player_win == true){
		cout << "Thanks for playing Wheel of Fortune!" << endl << "Your earnings today were $" << one.money << " in cash and prizes." << endl;
		}
	return 0;
	}