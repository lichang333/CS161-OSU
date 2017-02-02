#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <array>
//#include <unicode/unistr.h>
//#include <unicode/ustream.h>


using namespace std;

void chooseMenu();
void getInput(string, char*);
int str_len(char *);
bool is_alpha(char *);
bool is_num(char *);
bool is_1_2(char *);
void encode_out();
void decode_out();

static const char* alpha[30] = {
    ".-",   //A
    "-...", //B
    "-.-.", //C
    "-..",  //D
    ".",    //E
    "..-.", //F
    "--.",  //G
    "....", //H
    "..",   //I
    ".---", //J
    "-.-",  //K
    ".-..", //L
    "--",   //M
    "-.",   //N
    "---",  //O
    ".--.", //P
    "--.-", //Q
    ".-.",  //R
    "...",  //S
    "-",    //T
    "..-",  //U
    "...-", //V
    ".--",  //W
    "-..-", //X
    "-.--", //Y
    "--..", //Z
    "(space)       "//SPACE[26]
    "(split)   "//SPLIT[27]
};
static const char *num[10] = {
    "-----", //0
    ".----", //1
    "..---", //2
    "...--", //3
    "....-", //4
    ".....", //5
    "-....", //6
    "--...", //7
    "---..", //8
    "----.", //9
};

char caps_case(char ch){return ((ch>='A'&&ch<='Z'))?ch-'A'+'a':ch; };

void chooseMenu(){
	char choice[255];
	do{
		getInput("(1) Translate english to morse code ; (2) Translate morse code to english : ", choice);
	}while(!(is_num(choice) && is_1_2(choice)));  	
    if (choice[0]=='1'){
    encode_out();
    }
    else if (choice[0]=='2'){
    decode_out();
    }
}
	

void getInput(string s, char arr[]){
	cout << s;
	cin.getline(arr,255);
}


int str_len(char array[]){
   int i=0;
   while(array[i]!='\0'){
      i++;						//how do you append the null char?
   }return i;
} 

bool is_alpha(char arr[]){
	for(int i=0; i<str_len(arr); i++){
		if(!((arr[i]>='a'&& arr[i]<='z') || (arr[i]>='A' && arr[i]<='Z')))
			return false;
	}return true;
}

bool is_num(char arr[]){   
	for(int i=0; i<str_len(arr);i++){           //for the length of the string check
		if ((arr[i]>='0' && arr[i]<='9')){  //if the char at i is NOT between 0-9 
    		return true;                       //return false
		}else{
			cout<<"Type 1-2! " << endl;
			return false;
		}
	}  
}

bool is_1_2(char arr[]){
	while(str_len(arr)==1){
		if(arr[0]>='1' && arr[0]<='2'){
			return true;
		}else
			break;
	}
	cout<<"Type 1-2! "<<endl;
	return false;
}


void encode_out(){
    char eng_str[100];
    cout<<"Please tell me the message in English:";
    cin.get(eng_str,100);
    for (int i=0;i<eng_str[100]);i++){
        printf("The string you input is: %s.",eng_str[i]);  

    }
    

}
void decode_out(){
    char eng_str[300];
    cout<<"Please tell me the morse message:";
    cin.get(eng_str,300);
    printf("The string you input is: %s.",eng_str);  

}


int main(){
//    chooseMenu();
//    encode_out();
//    decode_out();






    return 0;
}



//std::cout << someUString.toUpper() << "\n";

