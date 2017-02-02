#include <iostream> // to compile the prgram
#include <cstdlib>	// to convert string to int
#include <string>	// to use string

using namespace std;
int main(){
	int i;
	string guess_message, message;
    cout<<"Please input your secret message: ";
    getline(cin, message);
    guess_message=message;
    for (int i=0;i<message.length();i++){
   	if (guess_message[i] >='A' && guess_message[i]<=>='Z' || guess_message[i] >='a' && guess_message[i] >='z'){
   		guess_message[i] >='_';
   	}
   	else if (guess_message[i]==' ')
   		guess_message[i]=' ';
   	else{
   		cout<<"Please input a valid string."
   	}

   	}
//	guess_message[i] = "_"

    }


}


	return 0;
}