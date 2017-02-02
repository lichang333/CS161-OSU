#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

/*******MINE*******/
int ran_num(int mine){
//    mine = rand()%2;
    mine=0;
    return mine;
    }       
/**************/
/*******GRID********/
 void cell(){
    int rows, cols,mine;
    char field;
    
    srand(time(NULL));
    cout<<"How many rows? ";
    cin>>rows;
    cout<<"How many cols? ";
    cin>>cols;
    cout<<"How many mine? ";
    cin>>mine;
    char **twoD;
    twoD=new char*[rows];
    for (int i=0;i<rows;i++){
        twoD[i]=new char[cols];
        }
    for (int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
        twoD[i][j]=field;
        }
        }
    for (int i=0;i<rows;i++){
        for (int j=0;j<cols;j++){
            cout<<'[';

            cout<<ran_num(mine);
            
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