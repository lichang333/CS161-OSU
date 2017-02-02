/******************************************************
** Program: wheel_fortune.cpp
** Author: Chang LI
** Date: 2/13/2016
** Description: This program is to simulate the TV show Wheel of Fortune
** Input: player, round ,message, ch, player_info, player_now, guess, str, 
** Output:hidden, dollars 
******************************************************/

#include <iostream>
#include <cctype>
#include <cstdlib>
#include <string>
#include <ctime>
#include <stdlib.h> 
#include <stdio.h>   

using namespace std;

void settings(int &player, int &round);
void start(string hidden, string message,int dollars, int x);
void player_mod(int player);
void balance (int dollars);
int get_player(int player);
int get_round(int round);
int choice();

void secret_message(string &message);
string hidden_message(string message);

string guess_char(string test, string message); 


/*********************************************************************
 ** Function: settings
 ** Description: To collect how many player and round in the game have.
 ** Parameters: player, round
 ** Pre-Conditions: players, 1-3, rounds, positive numbers
 ** Post-Conditions: save the number of players and number of rounds 
 *********************************************************************/ 
//settings
void settings(int &player, int &round){
	cout<<"How many player we have (1-3): "<<endl;
	cin>>player;
	cout<<"How many round we have: "<<endl;
	cin>>round;
}



/*********************************************************************
 ** Function: secret_message
 ** Description: To collect what is the guess message is.
 ** Parameters: message
 ** Pre-Conditions: A-Z and a-z.
 ** Post-Conditions: create a hidden message.
 *********************************************************************/ 
//MESSAGE
void secret_message(string &message){
		cout<<"please enter the message: ";
		cin.ignore(9999,'\n');
		getline(cin,message);
}

/*********************************************************************
 ** Function: hidden_message
 ** Description: transform message to hidden message (eg "_______")
 ** Parameters: message
 ** Pre-Conditions: string
 ** Post-Conditions: hidden secret message
 *********************************************************************/ 
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
	cout<<"The message is(hidden): "<<hidden<<endl;
	return hidden;
}



//PLAYER_TURN
void player_mod(int player){

cout<<player<<endl;

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


#define __player_money__ 0
#define __player_wheel__ 1
#define __player_win_rount__ 2
//input handle

/*********************************************************************
 ** Function: lower_case
 ** Description: Transform Capital letters to count with lower case letter.
 ** Parameters: ch
 ** Pre-Conditions: letter with capital or lower case
 ** Post-Conditions: treat lower case letters and capital letters as same.
 *********************************************************************/ 

char lower_case(char ch){return ((ch>='A'&&ch<='Z'))?ch-'A'+'a':ch; }; //transform cases


/*********************************************************************
 ** Function: input_char
 ** Description:  check user input in a-z and is vowel or not.
 ** Parameters: require, type
 ** Pre-Conditions: input a choice
 ** Post-Conditions: is the user input right or not
 *********************************************************************/ 

//type:0=>all 1=>menu 2=>non vowel 3=>vowel
char input_char(string require,int type)
{
	
	char ch;
	cout<<require;
	while(1){
		cin.ignore(9999,'\n');
		cin>>ch;
		if (type==0) {break;};
		if (type==1) {if ((ch>='1')&&(ch<='3')) break;};
		if (type==2) {
			if ((lower_case(ch)>='a')&&(lower_case(ch)<='z')
				&&(lower_case(ch)!='a')&&(lower_case(ch)!='e')&&(lower_case(ch)!='i')&&(lower_case(ch)!='o')&&(lower_case(ch)!='u')) break;
		};
		if (type==3) {
			if ((lower_case(ch)=='a')||(lower_case(ch)=='e')||(lower_case(ch)=='i')||(lower_case(ch)=='o')||(lower_case(ch)=='u')) break;
		};
		cout<<endl<<"Wrong input! Please re-input:";
	}
	return ch;
}
//hidden string add space
string string_add_space(string str){
	return str;
}



/*********************************************************************
 ** Function: guess_vowel
 ** Description:  check the secret hidden message have voel or not, if they have appear it and add money.
 ** Parameters: hidden,message,player_info, player_count, player_now, guess, input_char
 ** Pre-Conditions: the hiddenmessage and which player
 ** Post-Conditions: how many vowel characters found in the hidden message.
 *********************************************************************/ 
//GUESS vowel
//player_info[id][3]=>{money,wheel,win_round}
int guess_vowel(string &hidden,string &message,int player_info[3][4],int &player_count,int &player_now)
{

	char guess;
	int guessed_count=0;
//	string test;
	guess=input_char("Guess a vowel: ",3); //type == 3
	player_info[player_now][__player_money__]=player_info[player_now][__player_money__]-10;
	for (int i=0; i < hidden.length();i++)
	{	if ((hidden[i]=='-')&&(lower_case(message[i]) == lower_case(guess))){guessed_count++;hidden[i] = guess;}//finded char
	}
	//player_info[player_now][__player_money__]+=guessed_count*player_info[player_now][__player_wheel__];//hidden=test;
	printf("%d found. Total: $%d\n",guessed_count,player_info[player_now][__player_money__]);
	printf("The message is %s\n",string_add_space(hidden).c_str());    //transform c++ string to c
	return 0;
}


/*********************************************************************
 ** Function: guess_nonvowel
 ** Description: find is the secret hidden message have user's input or not. If have show it and add money to user.
 ** Parameters: hidden,message,player_info, player_count, player_now, guess, input_char
 ** Pre-Conditions: the hidden message and on which player
 ** Post-Conditions: how many characters found in the new hidden message.
 *********************************************************************/ 
//GUESS non vowel
int guess_nonvowel(string &hidden,string &message,int player_info[3][4],int &player_count,int &player_now)
{

	char guess;
	int guessed_count=0;//string *test=new string();
	guess=input_char("Guess a letter: ",2);	
	//cout<<hidden<<endl;
	for (int i=0; i < hidden.length();i++)
	{	if ((hidden[i]=='-')&&(lower_case(message[i]) == lower_case(guess))){guessed_count++;hidden[i] = message[i];}//finded char

	}
	player_info[player_now][__player_money__]+=guessed_count*player_info[player_now][__player_wheel__];
	//cout<<hidden<<endl;
	//hidden=*test;
	printf("%d found. Total: $%d\n",guessed_count,player_info[player_now][__player_money__]);
	
	printf("The message is %s\n",string_add_space(hidden).c_str());
	if (guessed_count==0){player_now=(player_now+1) % player_count;player_info[player_now][3]=1;};
	return 0;
}

/*********************************************************************
 ** Function: choice
 ** Description: ask user want to spin, solve the puzzle or buy a vowel.
 ** Parameters: input_char, choice
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/ 

//CHOICE
int choice()
{

cout<<"Do you want to spin (1), solve the puzzle (2), or buy a vowel (3): "<<endl;
char choice=input_char("",1);  //input a string.  1 >> [1-3]
return choice-'0';
}

/*********************************************************************
 ** Function: balance
 ** Description: pring how much money user have.
 ** Parameters: dollars
 ** Pre-Conditions: none
 ** Post-Conditions: how many dollar for the current
 *********************************************************************/ 
//MONEY BALANCE
void balance (int dollars){
cout<<"Your current money is: "<<dollars<<" dollars."<<endl;
}



/*********************************************************************
 ** Function: wheel
 ** Description: generate a number between 0 to 21
 ** Parameters: i
 ** Pre-Conditions: none
 ** Post-Conditions: what is the fortune wheel land on.
 *********************************************************************/ 

//WHEEL
int wheel() {
	int i;
	srand( time( NULL ) );
	/* generate a number between 0 to 21: */
	i = rand() % 21;
	cout <<"Your wheel landed on: " << i << endl;
	return i;
}


/*********************************************************************
 ** Function: game_spin
 ** Description: If the spin land on 0, erase the all the money and skip the player; If the spin land on 21, skip to next palyer;  
 ** Parameters: next_player, hidden, message, player_info, player_count, player_now
 ** Pre-Conditions: which the user should turn
 ** Post-Conditions: should turn to the next user
 *********************************************************************/ 
//wheel range deal
int game_spin(string &hidden,string &message,int player_info[3][4],int &player_count,int &player_now)
{
	int next_player=(player_now+1) % player_count;        // player is 1-3
		//wheel reset
		player_info[player_now][1]=wheel();
		if (player_info[player_now][1]==0)//wheel=0
		{
			player_info[player_now][0]=0;//reset money
			player_info[player_now][1]=21;//force next player(same action as 21)
		}
		if (player_info[player_now][1]==21)//wheel=21
		{
			player_count=next_player;//next player
			return 0;
		}
		return guess_nonvowel(hidden,message,player_info,player_count,player_now);	
}

/*********************************************************************
 ** Function: game_direct
 ** Description: Guess the hidden message, if guess is right, return to that player.
 ** Parameters: hidden, message, player_info, player_count,player_now，str
 ** Pre-Conditions: the player guess a message
 ** Post-Conditions: the guess is right or not
 *********************************************************************/ 

int game_direct(string &hidden,string &message,int player_info[3][4],int &player_count,int &player_now)
{
	cout<<"Guess message: ";
	string str;
	cin.ignore(9999,'\n');
	getline(cin,str);
	if (str==message) return player_now+1;
	else { cout<<"Wrong message!"<<endl;return 0;}
}
//game loop
//player_info[id][3]=>{money,wheel,win_round}



/*********************************************************************
 ** Function: game_loop
 ** Description: If user type 1 going to spin &guess fuction, If user type 2, going to guess message fuction, If user type 3, going to buy a vowel fuction.
 ** Parameters: hidden, message, player_info, player_count,player_now，player_info, cmd
 ** Pre-Conditions: string hidden and message; integer for player_info[][], player_count, player_now
 ** Post-Conditions: lunch spin, solve message and guess vowel.
 *********************************************************************/ 

int game_loop(string &hidden,string &message,int player_info[3][4],int &player_count,int &player_now)
{
	int cmd;
	//output require
	if(player_info[player_now][3]==1)printf("Player %d:\n",player_now+1);
	player_info[player_now][3]=0;
	balance(player_info[player_now][0]);
	cmd=choice();
	if (cmd==1) return game_spin(hidden,message,player_info,player_count,player_now);
	if(cmd==2) return game_direct(hidden,message,player_info,player_count,player_now);
	if(cmd==3)return guess_vowel(hidden,message,player_info,player_count,player_now);
	//read char input
	//check input(loop)
	//update status
	//check status
	return 0;
}

int main(){
	string message, hidden;
	char guess;
	int player, round, x, dollars;
	int player_info[3][4]={0};
	
	settings(player,round);
	int player_count=player;
	//secret_message(message);
	//player_mod(player);
	for (int a=0;a<round;a++){
		for(int j=0;j<12;j++)player_info[j/4][j%4]=0;  //
		dollars=0;
		int player_now=0;	
		int ret=0;
		secret_message(message);
		hidden=hidden_message(message);
		while((ret=game_loop(hidden,message,player_info,player_count,player_now))==0){};  //Start this in each round and player
		printf("You are correct! Player %d wins round %d.\n",ret,a+1);
		for (int i = 0; i < player_count; ++i)printf("Player %d total: $%d\n",i+1,player_info[i][__player_money__]);
		player_info[ret-1][__player_win_rount__]++;
	}
	int max_id=-1;
	int max_money=0;
	for (int i = 0; i < player_count; ++i)
		if (player_info[i][__player_money__]>=max_money){max_money=player_info[i][__player_money__];max_id=i;};
	printf("Player %d wins game!\n", max_id+1);
	return 0;
}

