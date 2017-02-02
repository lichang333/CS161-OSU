/****************************************************** ** Program: assign2.cpp
** Author: Li, Chang
** Date: 1/15/2016
** Description: This program is design to help your financial sucesses.
** Input:i,P,n,C,t,x,r,gv
** Output: B,A,FV,gv,n
******************************************************/
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <cstdlib>

using namespace std;

int main(){
	double A,B,i,P,n,C,FV,t;
	//char x;
	//int x;
	int y,z;
	double r,pv,fv,gv;
	int test=0;
	double x;

	cout<<"\nWelcom to the Finacial Calculaor!\n"<<endl;
	while (test == 0){
	cout<<"\nWhat would you like to calculare?\n"<<endl;	
	cout<<"========================\n"<<endl;
	cout<<"1 - Loan Balance\n"<<endl;
	cout<<"2 - Countinously Compounded Interest\n"<<endl;
	cout<<"3 - Future Value\n"<<endl;
	cout<<"Selection: "<<endl;
	cin>>x;
		if(x==1){
		//case '2':
		cout<<"========================\n"<<endl;
		cout << "You have chosen to view Loan Balance.\n"<<endl;		
		test =1;
		cout <<"What is the initial Investment in Dollars (eg. 500): "<<endl;
		cin>>setprecision(2)>>A;
		if(A<=0){
			cout<<"\nInput value invalid.\n";
			return main();
		}
		cout <<"What is the annual interest rate (as a decimal): "<<endl;
		cin>>i;
		i=i/12;
		if(i<=0){
			cout<<"Input value invalid.\n";
			return main();
		}
		cout<<"Please tell me the amout of each equal payment? "<<endl;
		cin>>P;
		if(P<=0){
			cout<<"Input value invalid.\n";
			return main();
		}
		cout << "How long in years will be takes? \n"<<endl;
		cin>>setprecision(0)>>n;
		if(n<=0 ||n>200){
			cout<<"Input value invalid.\n";
			return main();
		}
		cout <<"What is your goal Amount in dollars by the provided time: "<<endl;
		cin>>setprecision(2)>>gv;
		if(gv<=0){
			cout<<"Input value invalid.\n";
			return main();
		}
		cout<<"Your goal amount was $"<<gv<<".\n"<<endl;
		B=A*pow((1+i),n)-(P/i)*(pow((1+i),n)-1);
		cout<<"The actual amount after "<<n<<" "<<"years is $"<<B<<endl;

		if(B >= gv){
			cout<<"You will meet your goal!"<<endl;
		}
		else{
			cout<<"You will not meet your goal."<<endl;
		}


		}

		else if (x==2){

		//case '1':
		cout<<"========================\n"<<endl;
		cout << "You have chosen to calculate Continuously Compounded Interest.\n"<<endl;
		test=1;
		cout << "What is your initial invenstment? (eg. 500)\n"<<endl;
		cin>>setprecision(2)>>P;
		if(P<=0){
			cout<<"\nInput value invalid.\n";
			return main();
		}
		cout << "What is your interest rate per year?(as a decimal)\n"<<endl;
		cin>>r;
		if(r<=0){
			cout<<"\nInput value invalid.\n";
			return main();
		}
		cout << "How long in years will be takes? \n"<<endl;
		cin>>setprecision(0)>>t;
		if(t<=0 || t>200){
			cout<<"\nInput value invalid.\n";
			return main();
		}
		cout << "What is your goal amount in dollars by the provided time: \n"<<endl;
		cin>>setprecision(2)>>gv;
		if(gv<=0){
			cout<<"\nInput value invalid.\n";
			return main();
		}
		
		cout<<"Your goal amount was $"<<gv<<".\n"<<endl;
		A=P*exp(r*t);
		cout<<"The actual amount after "<<t<<" "<<"years is $"<<A<<"\n"<<endl;
		if(A >= gv){
		cout<<"You will meet your goal!"<<endl;
		}
		else{
		cout<<"You will not meet your goal."<<endl;
		}

		}


		else if(x==3){

		//case '3':
			cout<<"========================\n"<<endl;
			cout << "You have chosen to calculate Future Value.\n"<<endl;
			test=1;
			cout << "Please enter your cash flow amount (eg. 500): \n"<<endl;
			cin>>setprecision(2)>>C;
			if(C<=0){
			cout<<"\nInput value invalid.\n";
			return main();
			}
			cout << "Please enter your interest rate per year (as a decimal):\n"<<endl;
			cin>>r;
			if(r<=0){
			cout<<"\nInput value invalid.\n";
			return main();
			}
			cout << "How long in years will be takes? \n"<<endl;
			cin>>setprecision(0)>>n;
			if(n<=0 ||n>200){
			cout<<"\nInput value invalid.\n";
			return main();
			}
			cout << "What is your goal amount in dollars by the provided time: \n"<<endl;
			cin>>setprecision(2)>>gv;
			if(gv<=0){
			cout<<"\nInput value invalid.\n";
			return main();
			}
			cout<<"Your goal amount was $"<<gv<<".\n"<<endl;
			FV=C*pow(1+r,n);
			cout<<"The actual amount after "<<n<<" "<<"years is $"<<FV<<endl;
			if(FV >= gv){
			cout<<"You will meet your goal!"<<endl;
			}
			else{
			cout<<"You will not meet your goal."<<endl;
			}

		}
		else{
		cout << "Selection invalid."<<endl;
		}
	 }
	 return 0;
	}
	
	