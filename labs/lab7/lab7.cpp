#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <cstdlib>
//#include <boost/algorithm/string.hpp>
//#include <boost/algorithm/string/replace.hpp>

using namespace std;


void get_search_replace_strings(string input)
{
   int change;
   char messg[256];
   char search[256], replace1[256];
   cout << "Would you like to replace a part of your string? Yes = 1 No = 0" << endl;
   //printf("Would you like to replace a part of your string? Yes = 1 No = 0\n").c_str();  
   cin >> change;
   cout<<input<<endl;
   if(change == 1)
   {
      cout << "What do you want to change?" << endl;
      //cin >> search;
      cin.ignore();
      cin.getline(search,255);
      input.find(search);
      cout << "What string do you want it to be replaced with" << endl;
      //cin >> replace1;
      cin.getline(replace1,255);
//    replace();
      std::string input;
      
//      boost::replace_all(input, replace1, search);

      char* replace(input,search,replace1){
         num = 0;
         for (int i=0;strlen(input)<=i；i++){
            if(input[i] == search[i]){
               input[i] = replace1[num];
               num++;
            }
         }
      }
//      replace(input,search,replace1);
//      replace_all(input, search, replace1);
   vim}
     
     cout<<input<<endl;
}

/*string search_replace(string input)
{
   
}a
*/

void userInput(char* input)
{

   cout << "Input a string" << endl;
   cin.getline(input,255);

   //return input;
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
   char input[256];
   userInput(input);
   determine_palindrome(input);
   get_search_replace_strings(input);
   return 0;
}
