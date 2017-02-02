#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
using namespace std;


  static const char random[] =
  "0123456789";
  static const char random2[]=

  "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
static const char random3[]=
  "abcdefghijklmnopqrstuvqxyz";

static const char random4[]=
  "!@#$%^&*";


  int strlng = sizeof(random)-1;
  int strlng2 = sizeof(random2)-1;
  int strlng3 = sizeof(random3)-1;
  int strlng4 = sizeof(random4)-1;
  int string_choice=sizeof(random_choice)-1;
random[]+random2[]

bool choice,choice2,choice3,choice4;
  
  char getRndm()
{

    return random[(rand()%strlng)];
}


int main(){

  int a , percentage_up, percentage_low,percentage_num,percentage_special;
  cout<<"How long do you want your password? ";
  cin>>a;
  cout<<"Do you want uppercase letters? 0-no, 1-yes ";
  cin>>choice;
cout<<"Do you want lowercase letters? 0-no, 1-yes ";
cin>>choice2;
cout<<"What percent of the password should be upper case?";
cin>>percentage_up;
cout<<"What percent of the password should be lower case?";
cin>>percentage_low;
cout<<"What percent of the password should be numbers ?";
cin>>percentate_num;
cout<<"Do you want special character?";
cin>chocice4;
cout<<"What percent of the password should be special character?";
cin>>pencentage_special;

char userArray = random[]*choice*percentage_num*0.01 + random2[]*choice2*percentage_up*0.01 +random3[]*choice3*percentage_low*0.01 + random4[] * choice4*percentage_special*0.01;

  srand(time(NULL));
  char str;
  for(unsigned int x = 0;x < a; ++1)
{
    str += getRndm();

}

    cout<< str << endl;
x=userArray[0];
for(y=1;y<x;y++) {
int r;

r=(rand()%10)

cout<<r;
}
y=userArray[1]
{
for(c=1;c<y;c++)
  int t;
  
  t=(rand()%15+65));
  cout<<(char)t;
}

z = userArray[2];
for (c=1;c<z;c++){
int g;
g=(rand()%25+97);
cout<<g;
}

k=userArray[3];
for(c=1;c<k;c++){

int h;
h=(rand()
  return 0;
}
//lichang@oregonstate.edu Li


