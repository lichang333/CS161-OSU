#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

/*
bool is_positive_int(string s){
    for(int i=0; i<s.length(); i++){
        if(!(s.at(i)>='0' || s.at(i)<='9'))
            return false;
    }
    return true;
}
*/


bool is_positive_int(string s){
    for(int i=0; i<s.length(); i++){
        if((s.at(i)<'0' || s.at(i)>'9'))
            return false;
    }
    return true;
}

bool is_right_choice(string s){
    for(int i=0; i<s.length(); i++){
        if((s.at(i)=='0' || s.at(i)=='1'))
            return true;
    }
    return false;
}




/*void print_string(string) {

}
*/


int main()
{
    string choice;
    int user_input, i;
    bool running = true;
    string password;
    string pass;
    int pass_length;
    bool lower = false, upper = false, number = false, special = false;
    double lower_percent = 0, upper_percent = 0, number_percent = 0, special_percent = 0;
    int lower_num = 0, upper_num = 0, number_num = 0, special_num = 0;
    int rand_num;
    srand(time(NULL));
    
    
    
    do
    {
        cout << "Please tell me your password length: ";
        cin >> pass;
    }while(is_positive_int(pass) == false);
    pass_length = atoi(pass.c_str());
    
    
    do
    {
        lower = upper = number = special = false;
        lower_percent = upper_percent = number_percent = special_percent = 0;
        lower_num = upper_num = number_num = special_num = 0;
        
        cout << "Do you want uppercase letters? (1-YES 0-NO)" << endl;
        cin >> choice;
    // }while(is_right_choice(choice) == true){


        int user_input = atoi(choice.c_str());

        if (user_input == 1)
        {
            upper = true;
            cout << "What percentage of uppercase letters?" << endl;
            cin >> upper_percent;
        }
        else{
            cout<<"Please type 1 or 0"<<endl;
         }
        
        cout << "Do you want lowercase letters? 1-YES 0-NO" << endl;
        cin >> choice;
        if (is_positive_int(choice)){
            user_input = atoi(choice.c_str());

            if (user_input ==1 )
            {
                number=true;
            }
            while (user_input!=1 && user_input!=0){
                cout<<"Please enter 1 or 0."<<endl;
            }

        }
        else{
        cout<<"wrooooooong"<<endl;   
        }
        if (user_input == 1)
        {
            lower = true;
            cout << "What percentage of lowercase letters?" << endl;
            cin >> lower_percent;
        }
        
        cout << "Do you want numbers? 1-YES 0-NO" << endl;
        cin >> choice;
        if (is_positive_int(choice)){
        user_input = atoi(choice.c_str());

        
        if (user_input == 1)
        {
            number = true;
            cout << "What percentage of numbers?" << endl;
            cin >> number_percent;
        }
        while (user_input!=1 && user_input!=0){
            cout<<"Please enter 1 or 0."<<endl;
            cin >> choice;
            user_input = atoi(choice.c_str());
        }
         }else{
            cout<<"Please type 1 or 0"<<endl;
         }

        
        cout << "Do you want special characters? 1-YES 0-NO" << endl;
        cin >> choice;

        user_input =atoi(choice.c_str());
        
        if (user_input == 1)
        {
            special = true;
            cout << "What percentage of special characters?" << endl;
            cin >> special_percent;
        }
        
        if (upper_percent + lower_percent + number_percent + special_percent != 100)
        {
            cout << "You need to input numbers ONLY, add up the percentages to 100." << endl;
        }
    } while (upper_percent + lower_percent + number_percent + special_percent != 100);
    
    for (int i = 0; i < pass_length; i++)
    {
        rand_num = rand() % 128; // Range of ASCII characters
        
        if (rand_num >= 65 && rand_num <= 90)
        {
            if (((double) upper_num) / pass_length < (upper_percent / 100))
            {
                password += (char) rand_num;
                upper_num += 1;
            }
            else i--;
        }
        else if (rand_num >= 97 && rand_num <= 122)
        {
            if (((double) lower_num) / pass_length < (lower_percent / 100))
            {
                password += (char) rand_num;
                lower_num += 1;
            }
            else i--;
        }
        else if (rand_num >= 48 && rand_num <= 57)
        {
            if (((double) number_num) / pass_length < (number_percent / 100))
            {
                password += (char) rand_num;
                number_num += 1;
            }
            else i--;
        }
        else if ((rand_num >= 33 && rand_num <= 47) ||
                 (rand_num >= 58 && rand_num <= 64) ||
                 (rand_num >= 91 && rand_num <= 96) ||
                 (rand_num >= 123 && rand_num <= 126))
        {
            if (((double) special_num) / pass_length < (special_percent / 100))
            {
                password += (char) rand_num;
                special_num += 1;
            }
            else i--;
        }
        else i--;
    }
    
    cout << "Your password is " << password << endl;
    
    
return 0;
}