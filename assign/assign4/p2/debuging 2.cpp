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
int wheel();


//settings
void settings(int &player, int &round){
	cout<<"How many player we have (1-3): "<<endl;
	cin>>player;
	cout<<"How many round we have (1-3): "<<endl;
	cin>>round;
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
char lower_case(char ch){return ((ch>='A'&&ch<='Z'))?ch-'A'+'a':ch; };
//type:0=>all 1=>menu 2=>non vowel 3=>vowel
char input_char(string require,int type)
{
	char ch;
	cout<<require;
	while(1){
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
//GUESS vowel
//player_info[id][3]=>{money,wheel,win_round}
int guess_vowel(string &hidden,string &message,int player_info[3][3],int &player_count,int &player_now)
{
	char guess;
	int guessed_count=0;
	string test;
	guess=input_char("Guess a vowel: ",3);
	player_info[player_now][__player_money__]=player_info[player_now][__player_money__]-10;
	for (int i=0; i < hidden.length();i++)
	{	if ((hidden[i]=='-')&&(lower_case(message[i]) == lower_case(guess))){guessed_count++;test[i] = guess;}//finded char
		else {test[i]=hidden[i];}/*other*/}
	player_info[player_now][__player_money__]+=guessed_count*player_info[player_now][__player_wheel__];hidden=test;
	printf("%d found. Total: $%d\n",guessed_count,player_info[player_now][__player_money__]);
	printf("The message is %s\n",string_add_space(hidden).c_str());
	return 0;
}
//GUESS non vowel
int guess_nonvowel(string &hidden,string &message,int player_info[3][3],int &player_count,int &player_now)
{
	char guess;
	int guessed_count=0;string test;
	guess=input_char("Guess a letter: ",2);
	for (int i=0; i < hidden.length();i++)
	{	if ((hidden[i]=='-')&&(lower_case(message[i]) == lower_case(guess))){guessed_count++;test[i] = message[i];}//finded char
		else {test[i]=hidden[i];}/*other*/}
	player_info[player_now][__player_money__]+=guessed_count*player_info[player_now][__player_wheel__];hidden=test;
	printf("%d found. Total: $%d\n",guessed_count,player_info[player_now][__player_money__]);
	printf("The message is %s\n",string_add_space(hidden).c_str());
	return 0;
}



//CHOICE
int choice()
{

cout<<"Do you want to spin (1), solve the puzzle (2), or buy a vowel (3): "<<endl;
char choice=input_char("",1);
return choice-'0';
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


//wheel range deal
int game_spin(string &hidden,string &message,int player_info[3][3],int &player_count,int &player_now)
{
	int next_player=(player_now+1) % player_count;
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
int game_direct(string &hidden,string &message,int player_info[3][3],int &player_count,int &player_now)
{
	cout<<"Guess message: ";
	string str;
	cin.ignore();
	getline(cin,message);
	if (str==message) return player_now+1;
	else { cout<<"Wrong message!"<<endl;return 0;}
}
//game loop
//player_info[id][3]=>{money,wheel,win_round}
int game_loop(string &hidden,string &message,int player_info[3][3],int &player_count,int &player_now)
{
	int cmd;
	
	//output require
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
	int player_info[3][3];
	
	settings(player,round);
	int player_count=player;
	//secret_message(message);
	//player_mod(player);
	for (int a=0;a<round;a++){
		int player_now=0;	
		int ret=0;
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

