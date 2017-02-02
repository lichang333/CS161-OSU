#include <iostream>
#include <cctype>
#include <string>
using namespace std;

int char_check();


int main (){
char_check();

}
int char_check(){
	char ch;
	int charCount_a= 0;
	int charCount_b= 0;
	int charCount_c= 0;
	int charCount_d= 0;
	int charCount_e= 0;
	int charCount_f= 0;
	int charCount_g= 0;
	int charCount_h= 0;
	int charCount_i= 0;
	int charCount_j= 0;
	int charCount_k= 0;
	int charCount_l= 0;
	int charCount_m= 0;
	int charCount_n= 0;
	int charCount_o= 0;
	int charCount_p= 0;
	int charCount_q= 0;
	int charCount_r= 0;
	int charCount_s= 0;
	int charCount_t= 0;
	int charCount_u= 0;
	int charCount_v= 0;
	int charCount_w= 0;
	int charCount_x= 0;
	int charCount_y= 0;
	int charCount_z= 0;

	string sentence;

	cout<<"Enter any sentence you wish and I will\n";
		getline(cin,sentence);
//	cout<<"Guess a char\n";
//		cin>>ch_g;
	for (int pos = 0; pos<sentence.length();pos++)	
	{
		ch = toupper(sentence[pos]);

		switch (ch){
			case 'A': charCount_a++;
			break;
			case 'B': charCount_b++;
			break;
			case 'C': charCount_c++;
			break;
			case 'D': charCount_d++;
			break;
			case 'E': charCount_e++;
			break;
			case 'F': charCount_f++;
			break;
			case 'G': charCount_g++;
			break;
			case 'H': charCount_h++;
			break;
			case 'I': charCount_i++;
			break;
			case 'J': charCount_j++;
			break;
			case 'K': charCount_k++;
			break;
			case 'L': charCount_l++;
			break;
			case 'M': charCount_m++;
			break;
			case 'N': charCount_n++;
			break;
			case 'O': charCount_o++;
			break;
			case 'P': charCount_p++;
			break;
			case 'Q': charCount_q++;
			break;
			case 'R': charCount_r++;
			break;
			case 'S': charCount_s++;
			break;
			case 'T': charCount_t++;
			break;
			case 'U': charCount_u++;
			break;
			case 'V': charCount_v++;
			break;
			case 'W': charCount_w++;
			break;
			case 'X': charCount_x++;
			break;
			case 'Y': charCount_y++;
			break;
			case 'Z': charCount_z++;
			break;
		}

	}
	cout<<"There are "<<charCount_a<<" char is same.\n";
	cout<<"There are "<<charCount_b<<" char is same.\n";
	cout<<"There are "<<charCount_c<<" char is same.\n";
	cout<<"There are "<<charCount_d<<" char is same.\n";
	cout<<"There are "<<charCount_e<<" char is same.\n";
	cout<<"There are "<<charCount_f<<" char is same.\n";
	cout<<"There are "<<charCount_g<<" char is same.\n";
	cout<<"There are "<<charCount_h<<" char is same.\n";
	cout<<"There are "<<charCount_i<<" char is same.\n";
	cout<<"There are "<<charCount_j<<" char is same.\n";
	cout<<"There are "<<charCount_k<<" char is same.\n";
	cout<<"There are "<<charCount_l<<" char is same.\n";
	cout<<"There are "<<charCount_m<<" char is same.\n";
	cout<<"There are "<<charCount_n<<" char is same.\n";
	cout<<"There are "<<charCount_o<<" char is same.\n";
	cout<<"There are "<<charCount_p<<" char is same.\n";
	cout<<"There are "<<charCount_q<<" char is same.\n";
	cout<<"There are "<<charCount_r<<" char is same.\n";
	cout<<"There are "<<charCount_s<<" char is same.\n";
	cout<<"There are "<<charCount_t<<" char is same.\n";
	cout<<"There are "<<charCount_u<<" char is same.\n";
	cout<<"There are "<<charCount_v<<" char is same.\n";
	cout<<"There are "<<charCount_w<<" char is same.\n";
	cout<<"There are "<<charCount_x<<" char is same.\n";
	cout<<"There are "<<charCount_y<<" char is same.\n";
	cout<<"There are "<<charCount_z<<" char is same.\n";



	



}