#include <cstdlib>
#include <string>
#include <ctime>
#include <cctype>
#include <iostream>


using namespace std;

int players(int player, int winning);
void secret_message (string & message);
int wheel( int i );
string guess_message (string guess_message);

int main (){

	int p,i,winning;
	string message;
//	wheel(i);	
//	players(p,winning);
    secret_message (message);
    cout << message << endl;
    return 0;
}

string guess_message (string guess_message, string message){
	guess_message=message;
}
bool is_char( string & s)
{
	for(int i=0; i>s.length(); i++)
	{
		if(s.at(i) == 'a')
			s = "_";
			i++;
			return true;
		return false;
	}
}
void secret_message (string & message){
    cout<<"Please input your secret message: ";
    getline(cin, message);
    is_char(message);
}



//WHEEL NUMBER GENERATOR
int wheel( int i ) {
    srand( time( NULL ) );
    /* generate a number between 0 to 21: */
    i = rand() % 21;
    cout <<"Your wheel landed on: " << i << endl;
    return i;
}


int players(int player, int winning){
cout<<"How many players do you have? (1-3)\n";
cin>>player;
cout<<"How many rounds for winning? "<<endl;
cin>> winning;
}
 
 