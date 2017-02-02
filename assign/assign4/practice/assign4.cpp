#include <cstdlib>
#include <string>
#include <ctime>
#include <cctype>
#include <iostream>
#include <stdlib.h>   

using namespace std;

int balance(int money);
//bool is_char(string &str);
//string secret_message (string message);
//int players(int player, int winning);
int wheel( int i );


int main (){

    int p,i,winning;
    string message;
//    secret_message (message);
    wheel(i);
    balance(i);
    balance(i);
    
//  players(p,winning);    
    return 0;
}




//WHEEL NUMBER GENERATOR
int wheel( int *i ) {
    srand( time( NULL ) );
    /* generate a number between 0 to 21: */
    i = rand() % 21;
    // cout <<"Your wheel landed on: " << i << endl;
    return i;
}




int balance(){
int money;
money = 0;
money = money + wheel()*10;

cout<<"Your current balance is: "<<money<<endl;
}

int players(int player, int winning){
cout<<"How many players do you have? (1-3)\n";
cin>>player;
cout<<"How many rounds for winning? "<<endl;
cin>> winning;
}









/*
bool is_char(string &str){
    for (int i=0;i<message.length();i++)
    {
        if(str.at(i)>='A' && str.at(i)<='Z')
        {
            return true;
        }
        else if (str.at(i)>='a' && str.at(i)<='z')
        {
        return ture;    
        }
        
        else if (str.at(i) == ' ')
        {
            return true;
        }
    }
    return false;
}

*/

/*
string secret_message (string message){
    int i;
    string guess_message;
    cout<<"Please input your secret message: ";
    getline(cin, message);
    for (int i=0;i<message.length();i++)
    {
        guess_message[message.length()]="_";
    }
    cout<<message<<endl;
    guess_message[message.length()];

    cout<<guess_message<<endl;
    return message;
}
*/

 