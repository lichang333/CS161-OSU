#include <cstdlib>
#include <iostream>

using namespace std;

int main(){
    int choice;
    int x=3;
    int y,num;
    bool again;
    char myanswer;
    
    y = x;
    
    cout << "y is set to: " << y << endl;
    
    cout << "Please input a number: ";
    cin >> x;
    again = true;
    while(again){
        if(x > y){
            cout << "X is greater than Y\n";
        }
        else if(x < y){
            cout << "X is less than Y" << endl;
    }
    else {
        cout << "X is equal to Y" << endl;
    }
        cout << "would you like to input another number(1-YES, 0-NO)?" << endl;
        cin>>choice;
        if (choice==1){
            return main();
        }
        else if (choice==0){
            again=false;
        }
}
for(x = 0; x < 10; x++)
cout << x << endl;

cout << "What number would you like to find the factorial for? " << endl;
cin >> num;
for(int x = num; x > 0; x--)
x = x * x;

cout << "Are you enjoying cs161? (y or n) " << endl;
cin >> myanswer;
if(myanswer = y)
cout << "YAY" << endl;
else
cout << "YOU WILL SOON!" << endl;

return 0;
}
