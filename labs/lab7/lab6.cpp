#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/replace.hpp>

using namespace std;


void get_search_replace_strings(string input)
{
   int change;
   char messg[256];
   string search, replace1;
   //cout << "Would you like to replace a part of your string? Yes = 1 No = 0" << endl;
   printf("Would you like to replace a part of your string? Yes = 1 No = 0\n").c_str();  
   cin >> change;
   cout<<input<<endl;
   if(change == 1)
   {
      cout << "What do you want to change?" << endl;
      cin >> search;
      input.find(search);
      cout << "What string do you want it to be replaced with" << endl;
      cin >> replace1;
//    std::string input;
	  boost::replace_all(input, search, replace1);
//	  replace_all(input, search, replace1);
	  }
	  cout<<input<<endl;
}

/*string search_replace(string input)
{
	
}
*/

string userInput(string input)
{

   cout << "Input a string" << endl;
   getline(cin,input);

   return input;
}

bool determine_palindrome(string input)
{
   int beg = 0;
   int end = input.length()-1;
   while(beg < end)
   {
      if(input[beg] != input[end])
      {
         cout << "Aint a palindrome" << endl;
	 return false;
         
      }
      beg++;
      end--;
   }
   cout << "Is a palindrome" << endl;
   return true;
}

int main()
{
   string input;
   input = userInput(input);
   determine_palindrome(input);
   get_search_replace_strings(input);
   return 0;
}
