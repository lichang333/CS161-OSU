#include <iostream>
#include <cctype>
#include <cstdlib>
#include <string>
#include <ctime>
#include <stdlib>   

using namespace std;

//void player_mod(int player, string hidden, string message, int dollars, int x);
void settings(int &player, int &round);
void start(string hidden, string message,int dollars, int x);
void balance (int dollars);
int get_player(int player);
int get_round(int round);
void choice(int choice, string message);

void secret_message(string &message);
string hidden_message(string message);

string guess_char(string test, string message); 
int wheel();



int main(){
	string message, hidden;
	char guess;
	int player, round, x, dollars;

	settings(player,round);
	secret_message(message);
	hidden=hidden_message(message);
	start(hidden,message,dollars,x); 

	while(round > 0){
		


}





return 0;
}

//settings
void settings(int &player, int &round){
	cout<<"How many player we have (1-3): "<<endl;
	cin>>player;
	cout<<"How many round we have (1-3): "<<endl;
	cin>>round;
}


//START
void start(string hidden, string message,int dollars, int x){
	balance (dollars);
	choice(x, message);
	guess_char(hidden, message);

}

//MESSAGE
void secret_message(string &message){
		cout<<"please enter the message: ";
		cin.ignore();
		getline(cin,message);
}

//HIDDEN MESSAGE
string hidden_message(string message){
	string hidden;
	hidden=message;
	for (int i = 0; i < message.length();i++){
		if(hidden[i] == ' '){
			hidden[i]=' ';
		}
		else{
			hidden[i]='-';
		}		
	}
	cout<<"The message is: "<<hidden<<endl;
	return hidden;
}



//PLAYER_TURN
void player_mod(int player, string hidden, string message, string test, int dollars, int x){
	while(player > 0){
		start(hidden,message,dollars,x);  //Start this in each round and player
	}

/*	
switch (player){
case 1:

break;
case 2:
break;
case 3:
break;
}
*/
}



void money(){
int i, player_1, player_2, player_3;
}

//GUESS
string guess_char(string test, string message){
//	cout << "Message: " << message << "\nTest: " << test << endl;
	char guess;
	bool is_in = false;
	cout<<"Guess a letter: ";
	cin>>guess;
	for (int i=0; i < test.length();i++){
		if (message[i] == guess){
			test[i] = guess;
			is_in = true;
		}
		else if(message[i] == ' ') {
			test[i]=' ';

		}
		else {
			test[i]='-';
		}
}
if (is_in == false) {
	cout<<"There is no "<<guess<<"."<<endl;
}
cout<<test<<endl;
return test;
}


//CHOICE
void choice(int choice, string message){
	string guess_message;
//string &hidden, &message;
cout<<"Do you want to spin (1), solve the puzzle (2), or buy a vowel (3): "<<endl;
cin>>choice;
switch (choice){
	case 1:
    wheel();

    break;
    case 2:
    cout<<"Tell me the message: ";
    cin>>guess_message;
    if (message==guess_message){
    	cout<<"You are correct!"<<endl;
    }
    else{
    	cout<<"That is not correct!"<<endl;
    }
    break;
    case 3:
    cout<<"What vowel you want to buy: ";
    break;
}
}

//MONEY BALANCE
void balance (int dollars){
cout<<"Your current money is: "<<dollars<<" dollars."<<endl;
}

//WHEEL
int wheel() {
int i;
srand( time( NULL ) );
/* generate a number between 0 to 21: */
i = rand() % 21;
cout <<"Your wheel landed on: " << i << endl;
return i;
}


