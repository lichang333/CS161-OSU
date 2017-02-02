
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <string>
using namespace std;

struct field_struct{
	//public: 
	int rows;
	int cols;
	int mines;
};
/***************Play again************/
struct field_struct play_again(struct field_struct &temp){
int rows;int cols;int mines;
	cout<<"How many rows?: ";
	cin>>cols;
	temp.cols=cols;
	cout<<"How many cols?: ";
	cin>>rows; 
	temp.rows=rows;
	cout<<"How many mines?: ";
	cin>>mines;    
	temp.mines=mines;
}
/********random_mine**********/
void random_mine (char **twoD, int cols,int rows,int mine){
	int field_x,field_y;
for (int count_mine=mine;count_mine>0;count_mine--){    
		field_x=rand()%cols;field_y=rand()%rows;twoD[field_y][field_x]='*';
		}
	}
	
	
/*********IS BOARD FULL*************/	

bool is_boardFull(char** twoD_user,int rows, int cols,struct field_struct user_board){
		for (int i=0;i<user_board.rows;i++){
			for (int j=0;j<user_board.cols;j++){cout<<'[';
				if(twoD_user[i][j] == ' ') {return false;}
			}
		}
	return true;
} 


/************UESER BOARD*****************/

	// while --> board is not full --> game contine, {!=' '}
	/*
	CreateBoard()
	playGame()
		hit --> bool
		while !boardFull
			hit=guess() --> flag or open
			
			if(hit){
				break
			}
			
			if(hit){
				print : you lost
			}		
			
			else{ print: you won}
	bool guess(...){return ture or false.}
	

	*/

void remove_all_0(struct field_struct f,char** map_user,char** map,int i,int j)
{
	//printf("removing %d %d\n", i,j );
	if ((i<0)||(j<0)||(i>=f.rows)||(j>=f.cols))return;
	if (map_user[i][j]!=' ')return ;
	if (map[i][j]!='0')
	{
		map_user[i][j]=map[i][j];
		return;
	}
	map_user[i][j]=map[i][j];
	remove_all_0(f,map_user,map,i-1,j);
	remove_all_0(f,map_user,map,i-1,j-1);
	remove_all_0(f,map_user,map,i,j-1);
	remove_all_0(f,map_user,map,i+1,j-1);
	remove_all_0(f,map_user,map,i+1,j);
	remove_all_0(f,map_user,map,i+1,j+1);
	remove_all_0(f,map_user,map,i,j+1);
	remove_all_0(f,map_user,map,i-1,j+1);
}
// check map is open fully or not 0=>need more work 1=> opend all
int check_pass(struct field_struct f,char** map_user,char** map)
{
	int i;int j;
	
	for (i=0;i<f.rows;i++)
	{
		for ( j = 0; j < f.cols; ++j)
		{
			if ((map[i][j]>='0')&&(map[i][j]<='9')&&(map_user[i][j]==' '))return 0;
		}
	}
	return 1;
}
 char** cell(struct field_struct f);
void guess_init(struct field_struct user_board){
	int choice,o_x,o_y,count=0,rowcount =0,colcount=0,field_x=0, field_y=0;
	char **twoD_user,field;
	char **target_map;
	target_map=cell(user_board);

	twoD_user=new char*[user_board.rows];
	for (int i=0;i<user_board.rows;i++){
		twoD_user[i]=new char[user_board.cols];
		}
		
	for (int i=0;i<user_board.rows;i++){
		for(int j=0;j<user_board.cols;j++){
		twoD_user[i][j]=' ';      
		}}

	for (int i=0;i<user_board.rows;i++){
		for (int j=0;j<user_board.cols;j++){cout<<'[';
		if(twoD_user[i][j] == ' ') {cout << ' ';}
			else {cout << twoD_user[i][j];}cout<<']';}cout<<endl;} 
			cout<<endl;

while(field_x==0){
    cout<<"Flag(1) or Open(2): ";cin>>choice;
	if(choice==1){
        cout<<"cols,rows (x y): ";
        cin>>o_y>>o_x;
        twoD_user[o_y][o_x]='!';
        }
    if(choice==2){
        cout<<"rows, cols: ";
        cin>>o_y>>o_x;
        if (target_map[o_y][o_x]=='*')
        {
        	//mine has been open!
        	cout<<endl<<"Boom!"<<endl;
        	return;
        }
        else
        {
        	//twoD_user[o_y][o_x]=target_map[o_y][o_x];
        	remove_all_0(user_board,twoD_user,target_map,o_y,o_x);
        	if (check_pass(user_board,twoD_user,target_map)==1)
        	{
        		//game success!
        		printf("Success!\n");
				for (int i=0;i<user_board.rows;i++){
						for (int j=0;j<user_board.cols;j++){cout<<'[';
						if(twoD_user[i][j] == ' ') {cout << ' ';}
							else {cout << twoD_user[i][j];}cout<<']';}cout<<endl;} 
							cout<<endl;        		
       			return;
        	}
        }
//        twoD_user[o_y][o_x]=twoD[o_y][o_x];
}
	else{cout<<"wrong input!"<<endl;}
    
    for(int i=0;i<user_board.rows;i++){
        for(int j=0;j<user_board.cols;j++){cout<<'[';
        if(twoD_user[i][j] == ' ') {cout << ' ';}
        else if(twoD_user[i][j] == '!') {cout << "\e[1;33m!\e[0m";}
        
        
            else{cout<<twoD_user[i][j];}
            cout<<']';}cout<<endl;}
            cout<<endl;     
}
}
/*********PRINT USER GRID***********/
void print_user_grid(){
 /*   
    cout<<"Flag(1) or Open(2): ";cin>>choice;
	if(choice==1){cout<<"cols,rows (x y): ";cin>>o_y>>o_x;twoD_user[o_y][o_x]='!';}
//	if(choice==2){cout<<"rows, cols: ";cin>>o_y>>o_x;twoD_user[o_y][o_x]=twoD[o_y][o_x];}
	else{cout<<"wrong input!"<<endl;}
    
    for(int i=0;i<user_board.rows;i++){
        for(int j=0;j<user_board.cols;j++){cout<<'[';
        if(twoD_user[i][j] == ' ') {cout << ' ';}
            else{cout<<twoD_user[i][j];}cout<<']';}cout<<endl;}
            cout<<endl;  
*/    
    
}





/*******GRID********/
 char** cell(struct field_struct f){
	 int rows=f.rows;int cols=f.cols;int mine=f.mines;
	int count=0,rowcount =0,colcount=0,field_x=0, field_y=0;
	char field;
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
	
	
/*********************/

//marker : +1 for [x+1][y+1]      
	  for (int i=1;i<rows-1;i++)
      {
          for (int j=1;j<cols-1;j++){
            if(twoD[i][j]=='0'){
                if(twoD[i+1][j+1]=='*'){
                    twoD[i][j]+=1;}
                if(twoD[i+1][j-1]=='*'){
                    twoD[i][j]+=1;
                }
                if(twoD[i-1][j-1]=='*'){
                    twoD[i][j]+=1;
                }
                if(twoD[i-1][j+1]=='*'){
                    twoD[i][j]+=1;
                }
                if(twoD[i+1][j]=='*'){
                    twoD[i][j]+=1;
                }
                if(twoD[i-1][j]=='*'){
                    twoD[i][j]+=1;
                }
                if(twoD[i][j+1]=='*'){
                    twoD[i][j]+=1;
                }
                if(twoD[i][j-1]=='*'){
                    twoD[i][j]+=1;
                }}}}
	  
//special marker: (x,y)(0,0)(x,0)(0,y)
	if(twoD[rows-rows][cols-cols]=='0'){if(twoD[rows-rows+1][cols-cols]=='*'){twoD[rows-rows][cols-cols]+=1;}if(twoD[rows-rows+1][cols-cols-1]=='*'){twoD[rows-rows][cols-cols]+=1;}if(twoD[rows-rows][cols-cols-1]=='*'){twoD[rows-rows][cols-cols]+=1;}}if(twoD[rows-1][cols-1]=='0'){if(twoD[rows-1][cols-2]=='*'){twoD[rows-1][cols-1]+=1;}if(twoD[rows-2][cols-2]=='*'){twoD[rows-1][cols-1]+=1;}if(twoD[rows-2][cols-1]=='*'){twoD[rows-1][cols-1]+=1;}}if(twoD[rows-rows][cols-1]=='0'){if(twoD[rows-rows][cols-2]=='*'){twoD[rows-rows][cols-1]+=1;}if(twoD[rows-rows+1][cols-2]=='*'){twoD[rows-rows][cols-1]+=1;}if(twoD[rows-rows+1][cols-1]=='*'){twoD[rows-rows][cols-1]+=1;}}if(twoD[rows-1][cols-cols]=='0'){if(twoD[rows-2][cols-cols]=='*'){twoD[rows-1][cols-cols]+=1;}if(twoD[rows-2][cols-cols+1]=='*'){twoD[rows-1][cols-cols]+=1;}if(twoD[rows-1][cols-cols+1]=='*'){twoD[rows-1][cols-cols]+=1;}}
		 
//special marker: +1 for (x,0))   --> top
	for(int t_x=1;t_x<cols-1;t_x++){if(twoD[rows-rows][t_x]=='0'){if(twoD[rows-rows][t_x-1]=='*'){twoD[rows-rows][t_x]+=1;}if(twoD[rows-rows+1][t_x-1]=='*'){twoD[rows-rows][t_x]+=1;}if(twoD[rows-rows+1][t_x]=='*'){twoD[rows-rows][t_x]+=1;}if(twoD[rows-rows+1][t_x+1]=='*'){twoD[rows-rows][t_x]+=1;}if(twoD[rows-rows][t_x+1]=='*'){twoD[rows-rows][t_x]+=1;}}}
	
//special marker: +1 for (x,y-1)  --> button
	for(int b_x=1;b_x<cols-1;b_x++){if(twoD[rows-1][b_x]=='0'){if(twoD[rows-1][b_x-1]=='*'){twoD[rows-1][b_x]+=1;}if(twoD[rows-2][b_x-1]=='*'){twoD[rows-1][b_x]+=1;}if(twoD[rows-2][b_x]=='*'){twoD[rows-1][b_x]+=1;}if(twoD[rows-2][b_x+1]=='*'){twoD[rows-1][b_x]+=1;}if(twoD[rows-1][b_x+1]=='*'){twoD[rows-1][b_x]+=1;}}}
	
//special marker: +1 for (0,y))   --> left
	for(int l_y=1;l_y<rows-1;l_y++){if(twoD[l_y][cols-cols]=='0'){if(twoD[l_y+1][cols-cols]=='*'){twoD[l_y][cols-cols]+=1;}if(twoD[l_y+1][cols-cols+1]=='*'){twoD[l_y][cols-cols]+=1;}if(twoD[l_y][cols-cols+1]=='*'){twoD[l_y][cols-cols]+=1;}if(twoD[l_y-1][cols-cols+1]=='*'){twoD[l_y][cols-cols]+=1;}if(twoD[l_y-1][cols-cols]=='*'){twoD[l_y][cols-cols]+=1;}}}
	
//special marker: +1 for (x-1,y-1))   --> right
	for(int r_y=1;r_y<rows-1;r_y++){if(twoD[r_y][cols-1]=='0'){if(twoD[r_y-1][cols-1]=='*'){twoD[r_y][cols-1]+=1;}if(twoD[r_y-1][cols-2]=='*'){twoD[r_y][cols-1]+=1;}if(twoD[r_y][cols-2]=='*'){twoD[r_y][cols-1]+=1;}if(twoD[r_y+1][cols-2]=='*'){twoD[r_y][cols-1]+=1;}if(twoD[r_y+1][cols-1]=='*'){twoD[r_y][cols-1]+=1;}}} 
	
//ANSI escape code sequence
	for (int i=0;i<rows;i++){
		for (int j=0;j<cols;j++){cout<<'[';
		if(twoD[i][j] == '*') {cout << "\e[1;31m*\e[0m";}
			else {cout << twoD[i][j];}cout<<']';}cout<<endl;} 
			cout<<endl;
	return twoD;
}
/*******MAIN********/
int main(int argc, char** argv){
	srand(time(NULL));
	int rows,cols,mines,choice;
	if (argc==7){
		for(int i=1; i<argc; i+=2){
			if(argv[i][0]=='-'&&argv[i][1]=='r'&&argv[i][2]=='\0')
				{rows=atoi(argv[i+1]);}
			else if(argv[i][0]=='-'&&argv[i][1]=='c'&&argv[i][2]=='\0')
				{cols=atoi(argv[i+1]);}
			else if(argv[i][0]=='-'&&argv[i][1]=='m'&&argv[i][2]=='\0')
				{mines=atoi(argv[i+1]);}
			else 
				{cout<<"type -r for row;\ntype -c for col;\ntype -m for mine;\n"<<endl;}}}
	struct field_struct f;
	f.rows=rows;
	f.cols=cols;
	f.mines=mines;
do{

	guess_init(f);
	//cell(f);
	cout<<"do you want to play again? (1-yes 2-no): ";
	cin>>choice;
	if (choice==1){play_again(f);} 
}while(choice == 1);
	
	return 0;
}


