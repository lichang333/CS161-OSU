#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

/********random_mine**********/
void random_mine (char **twoD, int cols,int rows,int mine){
    int field_x,field_y;
for (int count_mine=mine;count_mine>0;count_mine--){    
        field_x=rand()%cols;
        field_y=rand()%rows;
        twoD[field_y][field_x]='*';
    }
}

/*****************************/

/*******MINE*******/
/*
int ran_num(int count, int Tmines, int rowcount,int colcount){
    int mine = rand()%2;
    if(mine == 1 && count != Tmines && rowcount < (Tmines/2)||colcount<(Tmines/2))
        return '*';
    return '0';
    }
*/           
/**************/
/*******GRID********/
 void cell(int rows,int cols,int mine){
    int count=0,rowcount =0,colcount=0,field_x=0, field_y=0;
    char field;
/*    
    cout<<"How many rows? ";
    cin>>rows;
    cout<<"How many cols? ";
    cin>>cols;
    cout<<"How many mine? ";
    cin>>mine;
*/  
  
    char **twoD;
    twoD=new char*[rows];
    for (int i=0;i<rows;i++){
        twoD[i]=new char[cols];
        }
  
      
    for (int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
        twoD[i][j]='0';      
        }
    }
        
    for (int count_mine=mine;count_mine>0;count_mine--){    
        field_x=rand()%cols;
        field_y=rand()%rows;
        twoD[field_y][field_x]='*';
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
    srand(time(NULL));
    int rows,cols,mine;
    if (argc==7){
        for(int i=1; i<argc; i+=2){
            if(argv[i][0]=='-'&&argv[i][1]=='r'&&argv[i][2]=='\0')
                {rows=atoi(argv[i+1]);}
            else if(argv[i][0]=='-'&&argv[i][1]=='c'&&argv[i][2]=='\0')
                {cols=atoi(argv[i+1]);}
            else if(argv[i][0]=='-'&&argv[i][1]=='m'&&argv[i][2]=='\0')
                {mine=atoi(argv[i+1]);}
            else 
                {cout<<"type -r for row;\ntype -c for col;\ntype -m for mine;\n"<<endl;}}}
    
    cell(rows,cols,mine);
    return 0;
}