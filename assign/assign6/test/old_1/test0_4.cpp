#include <iostream>

using namespace std;



int main(){
    int x=25,y=50,z=75;
    int *ptr;
    
    ptr=&x;
    *ptr *=2;
    
    ptr=&y;
    *ptr *=2;
    
    ptr=&z;
    *ptr *=2;

cout<<"x: "<<x<<" "<<"y: "<<y<<" "<<"z: "<<z<<" "<<endl;
    
   
       
    return 0;
}