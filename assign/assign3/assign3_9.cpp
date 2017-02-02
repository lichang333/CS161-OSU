/******************************************************
 ** Program: assign3.cpp
 ** Author: Zihao Tu
 ** Date: 1/30/2016
 ** Description: The program makes 4 * 4 grid by user's input
 ** Input: X coord and Y coord
 ** Output: 4 * 4 grid
 ******************************************************/
#include<iostream>
using namespace std;
/***********************************************************************************************************
Function: between
Description: judge if loc is between start and endd or not
Parameters: 4 parameters
Return: true or false
Pre-Conditions:sign mean the direction between start and endd .
Post-Conditions:
************************************************************************************************************/
bool between(int loc,int start,int endd,int sign)
{
    if(sign==1)
    {
        if(start<=loc&&loc<=endd)
        {
            return true;
        }
    }
    else
    {
        if(endd<=loc&&loc<=start)
        {
            return true;
        }
    }
    return false;
}
/***********************************************************************************************************
Function: print_grid
Description: print a grid
Parameters: start location,now location,direction sign mean from start to now location
Return: none
Pre-Conditions:sign is coincident to direction between start and now location
Post-Conditions:print a grid
************************************************************************************************************/
void print_grid(int xStart, int yStart, int xloc, int yloc,int xsign,int ysign){
    for(int i=3;i>=0;i--)
    {
        for(int j=0;j<9;j++)
            cout<<"-";
        cout<<endl;
        for(int z=0;z<4;z++)
        {
            cout<<"|";
            //reg following using if block to distinguish print "X" or " "
            //to print a empty grid,just 'cout<<" ";' instead
            //#regStart
            if(z==xloc)
            {
                if(between(i,yStart,yloc,ysign))
                {
                    cout<<"X";
                }
                else
                    cout<<" ";
            }
            else if(i==yStart)
            {
                if(between(z,xStart,xloc,xsign))
                {
                    cout<<"X";
                }
                else
                    cout<<" ";
            }
            else
            {
                cout<<" ";
            }
            //#regEnd
        }
        cout<<"|"<<endl;
    }
    for(int j=0;j<9;j++)
        cout<<"-";
    cout<<endl;
    cout<<endl;
}
/***********************************************************************************************************
Function: stringtoint
Description: transform a string to integer,if there is an error,return -1,else return the value
Parameters: x:string to transform
Return: value or flag
Pre-Conditions:no
Post-Conditions:
************************************************************************************************************/
int stringtoint(string x)
{
    int sum=0;
    for(int i=0;i<x.length();i++)
    {
        if(x[i]>='0' && x[i]<='9')
        {
            sum=sum*10+x[i]-'0';
        }
        else
        {
            cout<<"Error input characters or float number."<<endl;
            return -1;
        }
    }
    if(sum>3)
    {
        cout<<"off the grid."<<endl;
        return -1;
    }
    return sum;
}
/***********************************************************************************************************
Function: get_int
Description: ask for inputing a integer.If there is an error,ask for inputing again.
Parameters: str:prompt information
Return: value or flag
Pre-Conditions:no
Post-Conditions:return an integer
************************************************************************************************************/
int get_int(string str){
    int flag=-1;
    string x;
    while(flag==-1){
        cout<<str;
        cin>>x;
        flag=stringtoint(x);
    }
    return flag;
}
/***********************************************************************************************************
Function: find_path
Description: finds the path from the starting positon to the ending position as well as prints the
path to the screen
Parameters: xStart, yStart, xEnd, yEnd
Return: None
Pre-Conditions: all parameters are valid integers
Post-Conditions: no change to the parameters and the path will have been printed to the screen
************************************************************************************************************/
void find_path(int xStart, int yStart, int xEnd, int yEnd){
    int xsign=1,ysign=1;
    int xloc=xStart,yloc=yStart;
    if(xStart>xEnd)
    {
        xsign=-1;
    }
     if(yStart>yEnd)
    {
        ysign=-1;
    }
    for(;xloc!=xEnd;xloc+=xsign)
    {
        print_grid(xStart,yStart,xloc,yloc,xsign,ysign);
    }
    print_grid(xStart,yStart,xloc,yloc,xsign,ysign);

    for(;yloc!=yEnd;yloc+=ysign)
    {
        print_grid(xStart,yStart,xloc,yloc,xsign,ysign);
    }
    print_grid(xStart,yStart,xloc,yloc,xsign,ysign);
}
int main(){
    int flag=1;
    int xstart,ystart,xend,yend;
    string str;
    while(flag){
        xstart=get_int("Starting X coord: ");
        ystart=get_int("Starting Y coord: ");
        xend=get_int("Ending X coord: ");
        yend=get_int("Ending Y coord: ");
        find_path(xstart,ystart,xend,yend);
        cout<<"Run Again? ";
        cin>>str;
        if(str=="no")
        {
            flag=0;
        }
    }
    return 0;
}
