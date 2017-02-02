#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

/*******MINE*******/
/* string ran_num(int mine, string &(twoD[int i][int j])){
    twoD[i][j] = rand()%mine;
    return twoD[i][j];
    }
   */       
/**************/
/*******GRID********/
 void cell(){
    int rows, cols,mine,x;
    char field;
    
    srand(time(NULL));
    cout<<"How many rows? ";
    cin>>rows;
    cout<<"How many cols? ";
    cin>>cols;
    cout<<"How many mine? ";
    cin>>mine;
    string **twoD;
    twoD=new string*[rows];
    for (int i=0;i<rows;i++){
        twoD[i]=new string[cols];
        }
    for (int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
        cout<<'[';
        twoD[i][j]='0';
        cout << twoD[i][j];
        cout<<']';
        }
        cout <<endl;
        }
    for (int i=0;i<rows;i++){
        for (int j=0;j<cols;j++){
            x = rand()%mine;
            twoD[i][j] = x;
            cout<<'[';
            cout << twoD[i][j];
            cout<<']';
            }
            cout<<endl;
            }
    cout<<endl;
}

/*******GRID********/
int main(int argc, char** argv){
    cell();
    

    return 0;
}