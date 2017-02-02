#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

/*******MINE*******/
int ran_num(int count, int Tmines, int rowcount,int colcount){
    int mine = rand()%2;

    if(mine == 1 && count != Tmines && rowcount < (Tmines/2)||colcount<(Tmines/2))
        return '*';
    return '0';
    }       
/**************/
/*******GRID********/
 void cell(){
    int rows, cols,mine,count=0,rowcount =0,colcount=0;
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
        twoD[i][j]=ran_num(count,mine,rowcount,colcount);
        if(twoD[i][j] == '*')
            count++;
            rowcount++;
            colcount++;
        }
        rowcount = 0;
        }
    for (int i=0;i<rows;i++){
        for (int j=0;j<cols;j++){
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