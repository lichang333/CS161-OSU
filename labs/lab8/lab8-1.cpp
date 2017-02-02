#include <iostream>
#include <string>

using namespace std;

//int array[3][3] = { {1, 0, 0},
//	            {2, 0, 0},		
//		    {3, 0, 0} };

void solve(int num, int b, int d, int c, int array[][3]){
   int num2 = 2;
   int num3 = 0;
   bool print = true; 
   bool print2 = true;  
	if(num > 0){
		solve(num - 1, b, c, d, array);
		cout << "Move disk " << num << " from tower " << b << " to tower " << d << endl;
	        while(print)
		{
		   if(array[num3][b - 1] == num)
		   {
                      array[num3][b - 1] = 0;
		      print = false;
		   }
		   num3++;
		}
		while(print2)
		{
		   if(array[num2][d - 1] == 0)
		   {
		      array[num2][d - 1] = num;
		      print2 = false;
		   }
		   num3++;
		   num2--;
		}
		num3 = 0;
		num2 = 2;
                
		cout << array[0][0] << array[0][1] << array[0][2] << endl;
   	        cout << array[1][0] << array[1][1] << array[1][2] << endl;	                
   	        cout << array[2][0] << array[2][1] << array[2][2] << endl;

		solve(num - 1, c, d, b, array);
	}
}

int main(){

	int a;
	int num;
        cout << "How many disks do you want?: ";
	cin >> a;
	num = a;
	int array[a][3];
	for(int i = 0; i < a; i++)
	{
           for(int j = 0; j < 3; j++)
	   {
              array[j][i] = 0;
	      cout << array[j][i];
	   }
	   cout << endl;
	}
	for(int i = 0; i < 3; i++)
	{
           array[a - 1][0] = num;
	   num++;
	}
	solve(a,1,2,3,array);
		
	return 0;
}
