#include <cstdio>
#include <iostream>
#include <cmath>
#include <climits>

using namespace std;
int main(){
	double a,b,c,d,e,x;
	a=cos(2*M_PI/3);
	b=2*sin(2*M_PI/3);
	c=tan(-3*M_PI/4);
	d=log10(55.0);
	e=log(60.0);

cout << "\nPART1"<< endl;

	cout<<"cos(2pi/3) = "<<a<<endl;
	cout<<"2sin(2pi/3) = "<<b<<endl;
	cout<<"tan(-3pi/4) = "<<c<<endl;
	cout<<"log_10(55) = "<<d<<endl;
	cout<<"ln60 = "<<e<<endl;

	cout << "\n"<< endl;	

	b=2,x=15;
	a = log(x) / log(b);
	cout<<"log_2(15)="<<log(x)/log(b)<<endl;
	b = 4,x = 40;
	a = log(x) / log(b);
	//printf("log_%d(%d)=%f\n", (int)b, (int)x, a);
	cout << "log_" << b << "(" << x << ")" << "=" << a << endl;
	
	x=1;
	a=pow(3,sin(x));	
	//cout << x << endl;
	cout << "3^sinx=" << a <<"   When x="<<x<< endl;
	x=10;	
	a=pow(3,sin(x));
	//cout << x << endl;	
	cout << "3^sinx=" << a <<"   When x="<<x<< endl;	
	x=100;	
	a=pow(3,sin(x));	
	cout << "3^sinx=" << a <<"   When x="<<x<< endl;	
	
	cout << "\n"<< endl;	

	x=1;
	b=pow(x,2)+1;
	a=log2(b);
	cout <<"log_2(x^2+1)="<< a <<"   When x="<<x<< endl;

	x=10;
	b=pow(x,2)+1;
	a=log2(b);
	cout <<"log_2(x^2+1)="<< a <<"   When x="<<x<< endl;

	x=100;
	b=pow(x,2)+1;
	a=log2(b);
	cout <<"log_2(x^2+1)="<< a <<"   When x="<<x<< endl;

	cout << "\nPART 2"<< endl;

	cout<<"INT_MAX: "<<INT_MAX<< endl;
	cout<<"UINT_MAX: "<<UINT_MAX<< endl;
	cout<<"LONG_MAX: "<<LONG_MAX<< endl;
	cout<<"ULONG_MAX: "<<ULONG_MAX<< endl;
	cout<<"SHRT_MAX: "<<SHRT_MAX<< endl;
	cout<<"USHRT_MAX: "<<USHRT_MAX<< endl;

	cout<<"INT_MIN: "<<INT_MIN<< endl;
	cout<<"LONG_MIN: "<<LONG_MIN<< endl;
	cout<<"SHRT_MIN: "<<SHRT_MIN<< endl;
	
	short smal_short,lar_short;
	unsigned short u_lar_short;
	int smal_int,lar_int;
	unsigned int u_lar_int;
	long smal_long, lar_long;
	unsigned long u_lar_long;
	
/*	lar_short=SHRT_MAX;
	smal_int=INT_MIN;
	lar_int=INT_MAX; 
	smal_long=LONG_MIN;
	lar_long=LONG_MAX;
	u_lar_int=UINT_MAX;
	u_lar_long=ULONG_MAX;
	u_lar_short=USHRT_MAX;

*/

	lar_int=pow(2,(sizeof(int)*8)-1)-1;
	lar_long=(long)pow(2,(sizeof(long)*8)-1)-1;
	lar_short=(short)pow(2,(sizeof(short)*8)-1)-1;

	u_lar_int=pow(2,(sizeof(int)*8))-1;
	u_lar_long=(unsigned long)pow(2,(sizeof(long)*8))-1;
	u_lar_short=(unsigned short)pow(2,(sizeof(short)*8))-1;	

	smal_int=-pow(2,(sizeof(int)*8-1));
	smal_long=-pow(2,(sizeof(long)*8-1));	
	smal_short=-pow(2,(sizeof(short)*8-1));
	
	cout<<"\n"<< endl;
	
	cout<<lar_int<<" LARGEST INT"<< endl;
	cout<<u_lar_int<<" UNSIGNED LARGEST INT"<< endl;
	cout<<lar_long<<" LARGEST LONG"<< endl;
	cout<<u_lar_long<<" UNSIGNED LARGEST LONG"<< endl;
	cout<<lar_short<<" LARGEST SHORT"<< endl;
	cout<<u_lar_short<<" UNSIGNED LARGEST SHORT"<< endl;
	cout<<smal_int<<" SMALLEST INT"<< endl;
	cout<<smal_long<<" SMALLEST LONG"<< endl;
	cout<<smal_short<<" SMALLEST SHORT"<< endl;
	


	return 0;
}
