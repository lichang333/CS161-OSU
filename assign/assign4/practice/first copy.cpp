#include <iostream> // to compile the prgram
#include <cstdlib>	// to convert string to int
#include <string>	// to use string

using namespace std;// so I won't repeat std::

void greating()
{
	cout << "welcome to Solve it or Lose it" << endl;
}
void greet_player(int &p)
{
	cout << "Hello player " << p << ", this is your round" << endl;
}
bool is_pos_int(string &str)
{
	for(int i=0; i<str.length(); i++)
	{
		if(!(str.at(i)>='0' && str.at(i)<='9'))
			return false;
	}
	return true;
}
bool is_in_range(string &str)
{
	int x = atoi(str.c_str());
	for(int i=0; i<str.length(); i++)
	{
		if(!(x >= 1 && x <=3))
			return false;
	}
	return true;
}
void check_players(string &x)
{
	int xx=0;
	while(xx>=0)
	{
		cout << "How many players do you have? ";
		cin >> x;
		if(!(is_pos_int(x)))
		{
			cout << "You idiot, try again!" << endl;
			xx++;
		}
		else if (!(is_in_range(x)))
		{
			cout << "You idiot, try again!" << endl;
			xx++;
		}
		else
		{
			break;
		}
	}
}
void check_rounds(string &x)
{
	int xx=0;
	while(xx>=0)
	{
		cout << "How many rounds for winning? ";
		cin >> x;
		if(!(is_pos_int(x)))
		{
			cout << "You idiot, try again!" << endl;
			xx++;
		}
		else
		{
			break;
		}
	}
}
void check_users(string &x)
{
	int xx=0;
	while(xx>=0)
	{
		cout << "Do you want to spin (1), solve the puzzle (2), or buy a vowel (3): ";
		cin >> x;
		if(!(is_pos_int(x)))
		{
			cout << "You idiot, try again!" << endl;
			xx++;
		}
		else if (!(is_in_range(x)))
		{
			cout << "You idiot, try again!" << endl;
			xx++;
		}
		else
		{
			break;
		}
	}
}
bool is_char(string &str)
{
	for(int i=0; i<str.length(); i++)
	{
		if(str.at(i)>='A' && str.at(i)<='Z')
		{
			return true;
		}
		else if(str.at(i)>='a' && str.at(i)<='z')
		{
			return true;
		}
	}
	return false;
}
bool is_x_vowel(string &str)
{
	for(int i=0; i<str.length(); i++)
	{
		if(str.at(i) =='A' || str.at(i) =='E' || str.at(i) =='I' || str.at(i) =='O' || str.at(i) =='U')
		{
			return false;
		}
		else if(str.at(i) =='a' || str.at(i) =='e' || str.at(i) =='i' || str.at(i) =='o' || str.at(i) =='u')
		{
			return false;
		}
	}
	return true;
}
bool is_vowel(string &str)
{
	for(int i=0; i<str.length(); i++)
	{
		if(str.at(i) =='A' || str.at(i) =='E' || str.at(i) =='I' || str.at(i) =='O' || str.at(i) =='U')
		{
			return true;
		}
		else if(str.at(i) =='a' || str.at(i) =='e' || str.at(i) =='i' || str.at(i) =='o' || str.at(i) =='u')
		{
			return true;
		}
	}
	return false;
}
void check_x_vowel(string &x)
{
	int xx=0;
	while(xx>=0)
	{
		cout << "Choose a letter: ";
		cin >> x;
		if(!(is_char(x)))
		{
			cout << "You idiot, try again!" << endl;
			xx++;
		}
		else if (!(is_x_vowel(x)))
		{
			cout << "You idiot, try again!" << endl;
			xx++;
		}
		else
		{
			break;
		}
	}
}
void check_vowel(string &x)
{
	int xx=0;
	while(xx>=0)
	{
		cout << "Choose a vowel: ";
		cin >> x;
		if(!(is_char(x)))
		{
			cout << "You idiot, try again!" << endl;
			xx++;
		}
		else if (!(is_vowel(x)))
		{
			cout << "You idiot, try again!" << endl;
			xx++;
		}
		else
		{
			break;
		}
	}
}
void ask(string &s)
{
	cout << "Please enter a message: ";
	cin >> s;
}
bool replace( string &s)
{
		for(int i = 0; i < s.length(); i++)
		{
			if (is_char(s))
			{
				s[i] = '_';

			}
			else if (!(is_char(s)))
			{
				s[i] = ' ';
			}
		}
		return true;
}
void ask_replace(string &s)
{
	ask(s);
	replace(s);
}
int main()
{
	string a, b, c, d, e, f;

	/* check_players(a);
	check_rounds(b);
	check_users(c);
	check_x_vowel(d);
	check_vowel(e); */
	ask_replace(f);

	cout /*<< a << b << c << d << e  */ << f << endl;

	return 0;
}