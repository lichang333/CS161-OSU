#include <iostream>
#include <string.h>
using namespace std;

void cell();

void cell(){
    int rows, cols;
    cout<<"How many rows? ";
    cin>>rows;
    cout<<"How many cols? ";
    cin>>cols;
    char **twoD;
    twoD=new char*[rows];
    for (int i=0;i<rows;i++){twoD[i]=new char[cols];}
    for (int i=0;i<rows;i++){for(int j=0;j<cols;j++){twoD[i][j]='0';}}
    for (int i=0;i<rows;i++){for (int j=0;j<cols;j++){cout<<'[';cout<<twoD[i][j];cout<<']';}cout<<endl;}
    cout<<endl;
}

int main(){
    cell();
    return 0;
}