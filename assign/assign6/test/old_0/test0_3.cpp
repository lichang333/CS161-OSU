#include <iostream>

using namespace std;



int main(){
    int x=25;
    int *ptr;
    
    ptr=&x;
    cout<<x<<" "<<*ptr<<endl;
    *ptr=100;
    cout<<x<<" "<<*ptr<<endl;
    
   
       
    return 0;
}