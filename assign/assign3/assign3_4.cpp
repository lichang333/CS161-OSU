/***********************************************************************************************************
Name: assign3.cpp
Author: LI,CHANG
DATE: JAN 31, 2016
Description: finds the path from the starting positon to the ending position as well as prints the
path to the screen
Parameters: xStart, yStart, xEnd, yEnd
Return: None
Pre-Conditions: all parameters are valid integers
Post-Conditions: no change to the parameters and the path will have been printed to the screen
************************************************************************************************************/

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;


//FUNCTION PROTOTYPE: BAYMAX GO
void find_path(int xStart, int yStart, int xEnd, int yEnd);


//I AM IN HERE.

/***********************************************************************************************************
Function: in_here
Description: Prting function.
Parameters: NONE
Return: None
Pre-Conditions: all parameters are valid integers
Post-Conditions: no change to the parameters and the path will have been printed to the screen
************************************************************************************************************/
void in_here(){
    cout<<"\nNow I am already in the target place.\n";
    
}
    //SYSTEM START:
/***********************************************************************************************************
Function: start
Description: Prting function.
Parameters: NONE
Return: None
Pre-Conditions: all parameters are valid integers
Post-Conditions: no change to the parameters and the path will have been printed to the screen
************************************************************************************************************/
    void start(){
        cout<<"\n"<<endl;
        cout<<"Hi, I am baymax, I am in: Mars! Where do you want me to go?\n"<<endl;
        cout<<"Please tell me the axis in x,y format\n<I can going from 0 to 3.>\n";
        cout<<"\n";
    }
/***********************************************************************************************************
Function: is_pos_int
Description: //check user input range of 0-3 or not.    
Parameters: s
Return: T/F
Pre-Conditions: string
Post-Conditions: T: continue, F: return
************************************************************************************************************/
//check user input range of 0-3 or not.    
    bool is_pos_int(string s)
    {
        for(int i=0; i<s.length(); i++)
        {
            if(!(s.at(i)>='0' && s.at(i)<='3'))
                return false;
        }
        return true;
    }
    
    //Print grid: Print grid in a line
/***********************************************************************************************************
Function: print_grid
Description: print one line for 4 varible.
Parameters: a,b,c,d
Return: stringv ariable
Pre-Conditions: string
Post-Conditions: string variable
************************************************************************************************************/

    void print_grid(string a,string b, string c,string d){
        cout<<a<<b<<c<<d<<endl;
    }
    
/***********************************************************************************************************
Function: main
Description: a function for startup the program.
Parameters: xStart, yStart, xEnd, yEnd;
Return: 0
Pre-Conditions: 
Post-Conditions: 
************************************************************************************************************/
    int main()
    {
        //restart again ?
        char go;
        do
        {
            //define a-p as string, default value as "[ ]"
            string xStart,yStart, xEnd, yEnd;
            string a="[ ]", b="[ ]",c="[ ]",d="[ ]";
            string e="[ ]", f="[ ]",g="[ ]",h="[ ]";
            string i="[ ]", j="[ ]",k="[ ]",l="[ ]";
            string m="[ ]", n="[ ]",o="[ ]",p="[ ]";
            
            //SYSTEM START:
            start();
            //INITIAL WE IN !
            //Give user the x and y axis.
            print_grid("[3]",b,c,d);
            print_grid("[2]",f,g,h);
            print_grid("[1]",j,k,l);
            print_grid("[0]","[1]","[2]","[3]");
            cout<<"\n";


            //axis_input(x,y);
            
            int test=0;
            while(test>=0)
            {
            //GET the initiate point.
                cout<<"Now, Please enter the x-asix that you want to me to drop!(0-3): ";
                /*"I don't why you cannot directly input the value like(eg:2,3): "*/
                cin >> xStart;
                //right number?
                if(!(is_pos_int(xStart)))
                {
                    cout << "Please give me a right number." << endl;
                    test++;
                }
                else
                {
                    break;
                }
            }
            cout<<"\n";
            int test2=0;
            while(test2>=0)
            {
                cout<<"Now, Please enter the y-asix that you want to me to drop!(0-3): ";
                cin >> yStart;
                if(!(is_pos_int(yStart)))
                {
                    cout << "Please type a right number." << endl;
                    test2++;
                }
                else
                {
                    break;
                }

            }
            cout<<"\n";

                    

            //BAYMAX GO
            int X=0;
            while(X>=0)
            {
                cout << "Where do you want me to go? " << endl;
                cout << "Please enter the x-asix: " << endl;
                cin >> xEnd;
                if(!(is_pos_int(xEnd)))
                {
                    cout << "Please enter a right number."  << endl;
                    X++;
                }
                else
                {
                    break;
                }
                
            }
            cout<<"\n";
            int Y=0;
            while(Y>=0)
            {
                cout << "Please enter the y-asix: " << endl;
                cin >> yEnd;
                if(!(is_pos_int(yEnd)))
                {
                    cout << "Please enter a right number." << endl;
                    Y++;
                }
                else
                {
                    break;
                }
            }
            int x = atoi(xStart.c_str());
            int xE = atoi(xEnd.c_str());
            int y = atoi(yStart.c_str());
            int yE = atoi(yEnd.c_str());
            //  PLACE BAYMAX

            // find the (x,y) ==> {a,b,c,d....o,p}
            while( x >= xE || x < xE)
            {
                if( x > xE )    //Move in x-axis
                {
                    if (x==0 && y==0){
                        m="[x]";
                        print_grid(a,b,c,d);
                        print_grid(e,f,g,h);
                        print_grid(i,j,k,l);
                        print_grid(m,n,o,p);
                        cout<<"\nHey, I am already in here.\n";
                        
                    }
                    
                    else if (x==0 && y==1){
                        i="[x]";
                        print_grid(a,b,c,d);
                        print_grid(e,f,g,h);
                        print_grid(i,j,k,l);
                        print_grid(m,n,o,p);
                        in_here();
                        
                    }
                    
                    else if (x==0 && y==2){
                        e="[x]";
                        print_grid(a,b,c,d);
                        print_grid(e,f,g,h);
                        print_grid(i,j,k,l);
                        print_grid(m,n,o,p);
                        in_here();
                        
                    }
                    
                    else if (x==0 && y==3){
                        a="[x]";
                        print_grid(a,b,c,d);
                        print_grid(e,f,g,h);
                        print_grid(i,j,k,l);
                        print_grid(m,n,o,p);
                        in_here();
                        
                    }
                    else if (x==1 && y==0){
                        n="[x]";
                        print_grid(a,b,c,d);
                        print_grid(e,f,g,h);
                        print_grid(i,j,k,l);
                        print_grid(m,n,o,p);
                        in_here();
                        
                    }
                    else if (x==1 && y==1){
                        j="[x]";
                        print_grid(a,b,c,d);
                        print_grid(e,f,g,h);
                        print_grid(i,j,k,l);
                        print_grid(m,n,o,p);
                        in_here();
                        
                    }
                    else if (x==1 && y==2){
                        f="[x]";
                        print_grid(a,b,c,d);
                        print_grid(e,f,g,h);
                        print_grid(i,j,k,l);
                        print_grid(m,n,o,p);
                        in_here();
                    }
                    else if (x==1 && y==3){
                        b="[x]";
                        print_grid(a,b,c,d);
                        print_grid(e,f,g,h);
                        print_grid(i,j,k,l);
                        print_grid(m,n,o,p);
                        in_here();
                        
                    }
                    
                    else if (x==2 && y==0){
                        o="[x]";
                        print_grid(a,b,c,d);
                        print_grid(e,f,g,h);
                        print_grid(i,j,k,l);
                        print_grid(m,n,o,p);
                        in_here();
                        
                    }
                    else if (x==2 && y==1){
                        k="[x]";
                        print_grid(a,b,c,d);
                        print_grid(e,f,g,h);
                        print_grid(i,j,k,l);
                        print_grid(m,n,o,p);
                        in_here();
                        
                    }
                    
                    else if (x==2 && y==2){
                        g="[x]";
                        print_grid(a,b,c,d);
                        print_grid(e,f,g,h);
                        print_grid(i,j,k,l);
                        print_grid(m,n,o,p);
                        in_here();
                        
                    }
                    else if (x==2 && y==3){
                        c="[x]";
                        print_grid(a,b,c,d);
                        print_grid(e,f,g,h);
                        print_grid(i,j,k,l);
                        print_grid(m,n,o,p);
                        in_here();
                    }
                    else if (x==3 && y==0){
                        p="[x]";
                        print_grid(a,b,c,d);
                        print_grid(e,f,g,h);
                        print_grid(i,j,k,l);
                        print_grid(m,n,o,p);
                        in_here();
                        
                    }
                    else if (x==3 && y==1){
                        l="[x]";
                        print_grid(a,b,c,d);
                        print_grid(e,f,g,h);
                        print_grid(i,j,k,l);
                        print_grid(m,n,o,p);
                        in_here();
                        
                    }
                    else if (x==3 && y==2){
                        h="[x]";
                        print_grid(a,b,c,d);
                        print_grid(e,f,g,h);
                        print_grid(i,j,k,l);
                        print_grid(m,n,o,p);
                        in_here();
                        
                    }
                    else if (x==3 && y==3){
                        d="[x]";
                        print_grid(a,b,c,d);
                        print_grid(e,f,g,h);
                        print_grid(i,j,k,l);
                        print_grid(m,n,o,p);
                        in_here();
                    }
                    x--;
                    
                }
                else if ( x < xE )            //Move in x-axis
                {
                    if (x==0 && y==0){
                        m="[x]";
                        print_grid(a,b,c,d);
                        print_grid(e,f,g,h);
                        print_grid(i,j,k,l);
                        print_grid(m,n,o,p);
                        
                    }
                    
                    else if (x==0 && y==1){
                        i="[x]";
                        print_grid(a,b,c,d);
                        print_grid(e,f,g,h);
                        print_grid(i,j,k,l);
                        print_grid(m,n,o,p);
                        
                    }
                    
                    else if (x==0 && y==2){
                        e="[x]";
                        print_grid(a,b,c,d);
                        print_grid(e,f,g,h);
                        print_grid(i,j,k,l);
                        print_grid(m,n,o,p);
                        
                    }
                    
                    else if (x==0 && y==3){
                        a="[x]";
                        print_grid(a,b,c,d);
                        print_grid(e,f,g,h);
                        print_grid(i,j,k,l);
                        print_grid(m,n,o,p);
                        
                    }
                    else if (x==1 && y==0){
                        n="[x]";
                        print_grid(a,b,c,d);
                        print_grid(e,f,g,h);
                        print_grid(i,j,k,l);
                        print_grid(m,n,o,p);
                        
                    }
                    else if (x==1 && y==1){
                        j="[x]";
                        print_grid(a,b,c,d);
                        print_grid(e,f,g,h);
                        print_grid(i,j,k,l);
                        print_grid(m,n,o,p);
                        
                    }
                    else if (x==1 && y==2){
                        f="[x]";
                        print_grid(a,b,c,d);
                        print_grid(e,f,g,h);
                        print_grid(i,j,k,l);
                        print_grid(m,n,o,p);
                        
                    }
                    else if (x==1 && y==3){
                        b="[x]";
                        print_grid(a,b,c,d);
                        print_grid(e,f,g,h);
                        print_grid(i,j,k,l);
                        print_grid(m,n,o,p);
                        
                    }
                    
                    else if (x==2 && y==0){
                        o="[x]";
                        print_grid(a,b,c,d);
                        print_grid(e,f,g,h);
                        print_grid(i,j,k,l);
                        print_grid(m,n,o,p);
                        
                    }
                    else if (x==2 && y==1){
                        k="[x]";
                        print_grid(a,b,c,d);
                        print_grid(e,f,g,h);
                        print_grid(i,j,k,l);
                        print_grid(m,n,o,p);
                        
                    }
                    else if (x==2 && y==2){
                        g="[x]";
                        print_grid(a,b,c,d);
                        print_grid(e,f,g,h);
                        print_grid(i,j,k,l);
                        print_grid(m,n,o,p);
                        
                    }
                    else if (x==2 && y==3){
                        c="[x]";
                        print_grid(a,b,c,d);
                        print_grid(e,f,g,h);
                        print_grid(i,j,k,l);
                        print_grid(m,n,o,p);
                        
                    }
                    else if (x==3 && y==0){
                        p="[x]";
                        print_grid(a,b,c,d);
                        print_grid(e,f,g,h);
                        print_grid(i,j,k,l);
                        print_grid(m,n,o,p);
                        
                    }
                    else if (x==3 && y==1){
                        l="[x]";
                        print_grid(a,b,c,d);
                        print_grid(e,f,g,h);
                        print_grid(i,j,k,l);
                        print_grid(m,n,o,p);
                        
                    }
                    else if (x==3 && y==2){
                        h="[x]";
                        print_grid(a,b,c,d);
                        print_grid(e,f,g,h);
                        print_grid(i,j,k,l);
                        print_grid(m,n,o,p);
                        
                    }
                    else if (x==3 && y==3){
                        d="[x]";
                        print_grid(a,b,c,d);
                        print_grid(e,f,g,h);
                        print_grid(i,j,k,l);
                        print_grid(m,n,o,p);
                        
                    }
                    x++;
                    
                }
                else if ( x == xE)            //Move in x-axis
                {
                    if (x==0 && y==0){
                        m="[x]";
                        print_grid(a,b,c,d);
                        print_grid(e,f,g,h);
                        print_grid(i,j,k,l);
                        print_grid(m,n,o,p);
                        
                    }
                    
                    else if (x==0 && y==1){
                        i="[x]";
                        print_grid(a,b,c,d);
                        print_grid(e,f,g,h);
                        print_grid(i,j,k,l);
                        print_grid(m,n,o,p);
                        
                    }
                    
                    else if (x==0 && y==2){
                        e="[x]";
                        print_grid(a,b,c,d);
                        print_grid(e,f,g,h);
                        print_grid(i,j,k,l);
                        print_grid(m,n,o,p);
                        
                    }
                    
                    else if (x==0 && y==3){
                        a="[x]";
                        print_grid(a,b,c,d);
                        print_grid(e,f,g,h);
                        print_grid(i,j,k,l);
                        print_grid(m,n,o,p);
                        
                    }
                    else if (x==1 && y==0){
                        n="[x]";
                        print_grid(a,b,c,d);
                        print_grid(e,f,g,h);
                        print_grid(i,j,k,l);
                        print_grid(m,n,o,p);
                        
                    }
                    else if (x==1 && y==1){
                        j="[x]";
                        print_grid(a,b,c,d);
                        print_grid(e,f,g,h);
                        print_grid(i,j,k,l);
                        print_grid(m,n,o,p);
                        
                    }
                    else if (x==1 && y==2){
                        f="[x]";
                        print_grid(a,b,c,d);
                        print_grid(e,f,g,h);
                        print_grid(i,j,k,l);
                        print_grid(m,n,o,p);
                        
                    }
                    else if (x==1 && y==3){
                        b="[x]";
                        print_grid(a,b,c,d);
                        print_grid(e,f,g,h);
                        print_grid(i,j,k,l);
                        print_grid(m,n,o,p);
                        
                    }
                    
                    else if (x==2 && y==0){
                        o="[x]";
                        print_grid(a,b,c,d);
                        print_grid(e,f,g,h);
                        print_grid(i,j,k,l);
                        print_grid(m,n,o,p);
                        
                    }
                    else if (x==2 && y==1){
                        k="[x]";
                        print_grid(a,b,c,d);
                        print_grid(e,f,g,h);
                        print_grid(i,j,k,l);
                        print_grid(m,n,o,p);
                        
                    }
                    
                    else if (x==2 && y==2){
                        g="[x]";
                        print_grid(a,b,c,d);
                        print_grid(e,f,g,h);
                        print_grid(i,j,k,l);
                        print_grid(m,n,o,p);
                        
                    }
                    else if (x==2 && y==3){
                        c="[x]";
                        print_grid(a,b,c,d);
                        print_grid(e,f,g,h);
                        print_grid(i,j,k,l);
                        print_grid(m,n,o,p);
                        
                    }
                    else if (x==3 && y==0){
                        p="[x]";
                        print_grid(a,b,c,d);
                        print_grid(e,f,g,h);
                        print_grid(i,j,k,l);
                        print_grid(m,n,o,p);
                        
                    }
                    else if (x==3 && y==1){
                        l="[x]";
                        print_grid(a,b,c,d);
                        print_grid(e,f,g,h);
                        print_grid(i,j,k,l);
                        print_grid(m,n,o,p);
                        
                    }
                    else if (x==3 && y==2){
                        h="[x]";
                        print_grid(a,b,c,d);
                        print_grid(e,f,g,h);
                        print_grid(i,j,k,l);
                        print_grid(m,n,o,p);
                        
                    }
                    else if (x==3 && y==3){
                        d="[x]";
                        print_grid(a,b,c,d);
                        print_grid(e,f,g,h);
                        print_grid(i,j,k,l);
                        print_grid(m,n,o,p);
                    }
                    break;
                }
            }
            while(y >= yE || y < yE)
            {
                
                if( y > yE )                //Move in y-axis 
                {
                    if (x==0 && y==0){
                        m="[x]";
                        print_grid(a,b,c,d);
                        print_grid(e,f,g,h);
                        print_grid(i,j,k,l);
                        print_grid(m,n,o,p);
                        
                    }
                    
                    else if (x==0 && y==1){
                        i="[x]";
                        print_grid(a,b,c,d);
                        print_grid(e,f,g,h);
                        print_grid(i,j,k,l);
                        print_grid(m,n,o,p);
                        
                    }
                    
                    else if (x==0 && y==2){
                        e="[x]";
                        print_grid(a,b,c,d);
                        print_grid(e,f,g,h);
                        print_grid(i,j,k,l);
                        print_grid(m,n,o,p);
                        
                    }
                    
                    else if (x==0 && y==3){
                        a="[x]";
                        print_grid(a,b,c,d);
                        print_grid(e,f,g,h);
                        print_grid(i,j,k,l);
                        print_grid(m,n,o,p);
                        
                    }
                    else if (x==1 && y==0){
                        n="[x]";
                        print_grid(a,b,c,d);
                        print_grid(e,f,g,h);
                        print_grid(i,j,k,l);
                        print_grid(m,n,o,p);
                        
                    }
                    else if (x==1 && y==1){
                        j="[x]";
                        print_grid(a,b,c,d);
                        print_grid(e,f,g,h);
                        print_grid(i,j,k,l);
                        print_grid(m,n,o,p);
                        
                    }
                    else if (x==1 && y==2){
                        f="[x]";
                        print_grid(a,b,c,d);
                        print_grid(e,f,g,h);
                        print_grid(i,j,k,l);
                        print_grid(m,n,o,p);
                        
                    }
                    else if (x==1 && y==3){
                        b="[x]";
                        print_grid(a,b,c,d);
                        print_grid(e,f,g,h);
                        print_grid(i,j,k,l);
                        print_grid(m,n,o,p);
                        
                    }
                    
                    else if (x==2 && y==0){
                        o="[x]";
                        print_grid(a,b,c,d);
                        print_grid(e,f,g,h);
                        print_grid(i,j,k,l);
                        print_grid(m,n,o,p);
                        
                    }
                    else if (x==2 && y==1){
                        k="[x]";
                        print_grid(a,b,c,d);
                        print_grid(e,f,g,h);
                        print_grid(i,j,k,l);
                        print_grid(m,n,o,p);
                        
                    }
                    
                    else if (x==2 && y==2){
                        g="[x]";
                        print_grid(a,b,c,d);
                        print_grid(e,f,g,h);
                        print_grid(i,j,k,l);
                        print_grid(m,n,o,p);
                        
                    }
                    else if (x==2 && y==3){
                        c="[x]";
                        print_grid(a,b,c,d);
                        print_grid(e,f,g,h);
                        print_grid(i,j,k,l);
                        print_grid(m,n,o,p);
                        
                    }
                    else if (x==3 && y==0){
                        p="[x]";
                        print_grid(a,b,c,d);
                        print_grid(e,f,g,h);
                        print_grid(i,j,k,l);
                        print_grid(m,n,o,p);
                        
                    }
                    else if (x==3 && y==1){
                        l="[x]";
                        print_grid(a,b,c,d);
                        print_grid(e,f,g,h);
                        print_grid(i,j,k,l);
                        print_grid(m,n,o,p);
                        
                    }
                    else if (x==3 && y==2){
                        h="[x]";
                        print_grid(a,b,c,d);
                        print_grid(e,f,g,h);
                        print_grid(i,j,k,l);
                        print_grid(m,n,o,p);
                        
                    }
                    else if (x==3 && y==3){
                        d="[x]";
                        print_grid(a,b,c,d);
                        print_grid(e,f,g,h);
                        print_grid(i,j,k,l);
                        print_grid(m,n,o,p);
                    }
                    y--;
                }
                else if ( y < yE )          //Move in y-axis
                {
                    
                    if (x==0 && y==0){
                        m="[x]";
                        print_grid(a,b,c,d);
                        print_grid(e,f,g,h);
                        print_grid(i,j,k,l);
                        print_grid(m,n,o,p);
                        
                    }
                    
                    else if (x==0 && y==1){
                        i="[x]";
                        print_grid(a,b,c,d);
                        print_grid(e,f,g,h);
                        print_grid(i,j,k,l);
                        print_grid(m,n,o,p);
                        
                    }
                    
                    else if (x==0 && y==2){
                        e="[x]";
                        print_grid(a,b,c,d);
                        print_grid(e,f,g,h);
                        print_grid(i,j,k,l);
                        print_grid(m,n,o,p);
                        
                    }
                    
                    else if (x==0 && y==3){
                        a="[x]";
                        print_grid(a,b,c,d);
                        print_grid(e,f,g,h);
                        print_grid(i,j,k,l);
                        print_grid(m,n,o,p);
                        
                    }
                    else if (x==1 && y==0){
                        n="[x]";
                        print_grid(a,b,c,d);
                        print_grid(e,f,g,h);
                        print_grid(i,j,k,l);
                        print_grid(m,n,o,p);
                        
                    }
                    else if (x==1 && y==1){
                        j="[x]";
                        print_grid(a,b,c,d);
                        print_grid(e,f,g,h);
                        print_grid(i,j,k,l);
                        print_grid(m,n,o,p);
                        
                    }
                    else if (x==1 && y==2){
                        f="[x]";
                        print_grid(a,b,c,d);
                        print_grid(e,f,g,h);
                        print_grid(i,j,k,l);
                        print_grid(m,n,o,p);
                        
                    }
                    else if (x==1 && y==3){
                        b="[x]";
                        print_grid(a,b,c,d);
                        print_grid(e,f,g,h);
                        print_grid(i,j,k,l);
                        print_grid(m,n,o,p);
                        
                    }
                    
                    else if (x==2 && y==0){
                        o="[x]";
                        print_grid(a,b,c,d);
                        print_grid(e,f,g,h);
                        print_grid(i,j,k,l);
                        print_grid(m,n,o,p);
                        
                    }
                    else if (x==2 && y==1){
                        k="[x]";
                        print_grid(a,b,c,d);
                        print_grid(e,f,g,h);
                        print_grid(i,j,k,l);
                        print_grid(m,n,o,p);
                        
                    }
                    
                    else if (x==2 && y==2){
                        g="[x]";
                        print_grid(a,b,c,d);
                        print_grid(e,f,g,h);
                        print_grid(i,j,k,l);
                        print_grid(m,n,o,p);
                        
                    }
                    else if (x==2 && y==3){
                        c="[x]";
                        print_grid(a,b,c,d);
                        print_grid(e,f,g,h);
                        print_grid(i,j,k,l);
                        print_grid(m,n,o,p);
                        
                    }
                    else if (x==3 && y==0){
                        p="[x]";
                        print_grid(a,b,c,d);
                        print_grid(e,f,g,h);
                        print_grid(i,j,k,l);
                        print_grid(m,n,o,p);
                        
                    }
                    else if (x==3 && y==1){
                        l="[x]";
                        print_grid(a,b,c,d);
                        print_grid(e,f,g,h);
                        print_grid(i,j,k,l);
                        print_grid(m,n,o,p);
                        
                    }
                    else if (x==3 && y==2){
                        h="[x]";
                        print_grid(a,b,c,d);
                        print_grid(e,f,g,h);
                        print_grid(i,j,k,l);
                        print_grid(m,n,o,p);
                        
                    }
                    else if (x==3 && y==3){
                        d="[x]";
                        print_grid(a,b,c,d);
                        print_grid(e,f,g,h);
                        print_grid(i,j,k,l);
                        print_grid(m,n,o,p);
                        
                    }
                    y++;
                    
                }
                else if (y == yE)           //Move in x-axis
                {
                    if (x==0 && y==0){
                        m="[x]";
                        print_grid(a,b,c,d);
                        print_grid(e,f,g,h);
                        print_grid(i,j,k,l);
                        print_grid(m,n,o,p);
                        
                    }
                    
                    else if (x==0 && y==1){
                        i="[x]";
                        print_grid(a,b,c,d);
                        print_grid(e,f,g,h);
                        print_grid(i,j,k,l);
                        print_grid(m,n,o,p);
                        
                    }
                    
                    else if (x==0 && y==2){
                        e="[x]";
                        print_grid(a,b,c,d);
                        print_grid(e,f,g,h);
                        print_grid(i,j,k,l);
                        print_grid(m,n,o,p);
                        
                    }
                    
                    else if (x==0 && y==3){
                        a="[x]";
                        print_grid(a,b,c,d);
                        print_grid(e,f,g,h);
                        print_grid(i,j,k,l);
                        print_grid(m,n,o,p);
                        
                    }
                    else if (x==1 && y==0){
                        n="[x]";
                        print_grid(a,b,c,d);
                        print_grid(e,f,g,h);
                        print_grid(i,j,k,l);
                        print_grid(m,n,o,p);
                        
                    }
                    else if (x==1 && y==1){
                        j="[x]";
                        print_grid(a,b,c,d);
                        print_grid(e,f,g,h);
                        print_grid(i,j,k,l);
                        print_grid(m,n,o,p);
                        
                    }
                    else if (x==1 && y==2){
                        f="[x]";
                        print_grid(a,b,c,d);
                        print_grid(e,f,g,h);
                        print_grid(i,j,k,l);
                        print_grid(m,n,o,p);
                        
                    }
                    else if (x==1 && y==3){
                        b="[x]";
                        print_grid(a,b,c,d);
                        print_grid(e,f,g,h);
                        print_grid(i,j,k,l);
                        print_grid(m,n,o,p);
                        
                    }
                    
                    else if (x==2 && y==0){
                        o="[x]";
                        print_grid(a,b,c,d);
                        print_grid(e,f,g,h);
                        print_grid(i,j,k,l);
                        print_grid(m,n,o,p);
                        
                    }
                    else if (x==2 && y==1){
                        k="[x]";
                        print_grid(a,b,c,d);
                        print_grid(e,f,g,h);
                        print_grid(i,j,k,l);
                        print_grid(m,n,o,p);
                        
                    }
                    
                    else if (x==2 && y==2){
                        g="[x]";
                        print_grid(a,b,c,d);
                        print_grid(e,f,g,h);
                        print_grid(i,j,k,l);
                        print_grid(m,n,o,p);
                        
                    }
                    else if (x==2 && y==3){
                        c="[x]";
                        print_grid(a,b,c,d);
                        print_grid(e,f,g,h);
                        print_grid(i,j,k,l);
                        print_grid(m,n,o,p);
                        
                    }
                    else if (x==3 && y==0){
                        p="[x]";
                        print_grid(a,b,c,d);
                        print_grid(e,f,g,h);
                        print_grid(i,j,k,l);
                        print_grid(m,n,o,p);
                        
                    }
                    else if (x==3 && y==1){
                        l="[x]";
                        print_grid(a,b,c,d);
                        print_grid(e,f,g,h);
                        print_grid(i,j,k,l);
                        print_grid(m,n,o,p);
                        
                    }
                    else if (x==3 && y==2){
                        h="[x]";
                        print_grid(a,b,c,d);
                        print_grid(e,f,g,h);
                        print_grid(i,j,k,l);
                        print_grid(m,n,o,p);
                        
                    }
                    else if (x==3 && y==3)
                    {
                        d="[x]";
                        print_grid(a,b,c,d);
                        print_grid(e,f,g,h);
                        print_grid(i,j,k,l);
                        print_grid(m,n,o,p);
                        
                    }
                    break;
                }
            }
            cout << "Do you want to me to go somewhere alse? (y or n)?";
            cin >> go;
        }while(go == 'y');
        
        return 0;
    }
