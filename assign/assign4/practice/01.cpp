#include <iostream>
using namespace std;

int main(){
	int x=25;
	int *a;

	a = &x;

	
	cout <<x<<" "<<*a<<endl;
	*a = 100;
	cout <<x<<" "<<*a<<endl;



}