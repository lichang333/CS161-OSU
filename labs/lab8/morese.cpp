#include <iostream>
#include <cstdlib>

using namespace std;


int main(){
//char a,b,c,d,e,f,g;
//char* morse;

int rows = 5;
int columns = 3;

int[][] array = new int[rows][columns];

for(int i = 0; i<rows; i++)
    for(int j = 0; j<columns; j++)
        array[i][j] = 0;

for(int i = 0; i<rows; i++)
{
    for(int j = 0; j<columns; j++)
    {
        System.out.print(array[i][j]);
    }
    System.out.println();
}




//morse[][]   
//eg: morse[0][0]   >>  [A][".-"]

//i  >>  [abcdefg >> - a = ]
/*

//morse[0] ==	".-";

[0]morse[A] >>		".-"
[1]morse[B] >>		"-..."
[2]morse[C] >>		"-.-."
[3]morse[D] >>		"-.."
[4]morse[E] >>		"."
[5]morse[F] >>		"..-."
[6]morse[G] >>		"--."
[7]morse[H] >>		"...."
[8]morse[I] >>		".."
[9]morse[J] >>		".---"
[10]morse[K] >>		"-.-"
[11]morse[L] >>		".-.."
[12]morse[M] >>		"--"
[13]morse[N] >>		"-."
[14]morse[O] >>		"---"
[15]morse[P] >>		".--."
[16]morse[Q] >>		"--.-"
[17]morse[R] >>		".-."
[18]morse[S] >>		"..."
[19]morse[T] >>		"-"
[20]morse[U] >>		"..-"
[21]morse[V] >>		"...-"
[22]morse[W] >>		".--"
[23]morse[X] >>		"-..-"
[24]morse[Y] >>		"-.--"
[25]morse[Z] >>		"--.."
[26]morse[ ] >>		"      "  				//space
[27]morse[0]  >>	"-----""
[28]morse[1]  >>	".----""
[29]morse[2]  >>	"..---""
[30]morse[3]  >>	"...--""
[31]morse[4]  >>	"....-""
[32]morse[5]  >>	"....."
[33]morse[6]  >>	"-...."
[34]morse[7]  >>	"--..."
[35]morse[8]  >>	"---.."
[36]morse[9]  >>	"----."

*/





return 0;
}