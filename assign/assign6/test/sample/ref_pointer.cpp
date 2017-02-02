#include <iostream>

using namespace std;

void get_string(string*);

int main(){
    string* stringName = new string;
    
    get_string(stringName);
    cout<<"My string is: "<<*stringName <<endl;
    
    return 0;
}

void get_string(string* stringName){
    cout<<"What is your string: ";
    getline(cin,*stringName);
}