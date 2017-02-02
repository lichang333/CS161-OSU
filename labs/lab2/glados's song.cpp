#include <cstdio>
#include <iostream>
#include <cstdlib>

using namespace std;

int main(){
	int choice, test,x;
		cout<<"\nThis was a triumph! \n"<<endl;
		cout<<"\nI'm making a note here:\n"<<endl;
		cout<<"\nHUGE SUCCESS!\n"<<endl;
		cout<<"=====================\n"<<endl;
		cout<<"1. It's hard to overstate My satisfaction.\n"<<endl;
		cout<<"2. Aperture Science; We do what we must, Because we can.\n"<<endl;
		cout<<"3. For the good of all of us. \n"<<endl;
		cout<<"Selection: "<<endl;
		cin>>x;

		if (x==1){
			cout<<"But there's no sense crying Over every mistake."<<endl;
			cout<<"=====================\n"<<endl;
			cout<<"1. You just keep on trying Till you run out of cake."<<endl;
		    cout<<"2. I'm not even angry... "<<endl;
			cout<<"3. I was so happy for you! "<<endl;
			cin>>x;
			if(x==1){
				cout<<"But there's no sense crying Over every mistake."<<endl;
				exit(1);
			}
			else if(x==2){
			cout<<"I've experiments to run."<<endl;	
			exit(1);
			}
			else if(x==3){
			cout<<"Look at me; still talking, When there's science to do! "<<endl;	
			exit(1);
			}
			else{
				return main();
			}
		}
		else if (x==2){
			cout<<"But there's no sense crying Over every mistake."<<endl;
			cout<<"=====================\n"<<endl;
			cout<<"1. You just keep on trying Till you run out of cake."<<endl;
		    cout<<"2. I'm not even angry... "<<endl;
			cout<<"3. I was so happy for you! "<<endl;
			cin>>x;
			if(x==1){
			cout<<"But there's no sense crying Over every mistake."<<endl;
			exit(1);
			}
			else if(x==2){
			cout<<"I've experiments to run."<<endl;	
			exit(1);
			}
			else if(x==3){
			cout<<"Look at me; still talking, When there's science to do! "<<endl;	
			exit(1);
			}
			else{
				return main();
			}
		}  
		else if(x==3){
			cout<<"Hello and, again, welcome to the Aperture Science computer-aided enrichment center."<<endl;
			cout<<"=====================\n"<<endl;
			cout<<"1. Por favor bordón de fallar Muchos gracias de fallar gracias."<<endl;
		    cout<<"2. Well here we are again. "<<endl;
			cout<<"3. Goodbye my only friend. "<<endl;
			cin>>x;
			if(x==1){
			cout<<"Warning devices are required on all mobile equipment. However, alarms and flashing hazard lights have been found to agitate the high energy pellet and have therefore been disabled for your safety."<<endl;
			exit(1);
			}
			else if(x==2){
			cout<<"You did it! The Weighted Companion Cube certainly brought you good luck."<<endl;	
			exit(1);
			}
			else if(x==3){
			cout<<"Despite the best efforts of the Enrichment Center staff to ensure the safe performance of all authorized activities, you have managed to ensnare yourself permanently inside this room. "<<endl;	
			exit(1);
			}
			else if(x<=0 || x>3){
			cout<<"HAHA "<<endl;	
			return main();
			}
		}



		else if(x<=0 || x>3){
		cout<<"But there's no sense crying Over every mistake."<<endl;
		return main();
		}
}


/*
		case 1:
		cout<<""<<endl;
		test==1;
		
		cin>>choice;
			switch(choice){
				case 1:
				cout<<"Now, these points of data Make a beautiful line.\n"<<endl;
				cout<<"And we're out of BETA. We're releasing on time! \n"<<endl;
				cout<<"1. (Go ahead and leave me...)"<<endl;
				cout<<"2. (Maybe you'll find someone else To help you?)"<<endl;
				cout<<"3. Maybe Black Mesa?"<<endl;
				cin>>choice;
				switch(choice){
					cout<<"That was a joke! HAHA! FAT CHANCE! "<<endl;
			}
			}

		break;
		case 2:
		cout<<"1. You just keep on trying Till you run out of cake."<<endl;
		cout<<"2. I'm not even angry... "<<endl;
		cout<<"3. I was so happy for you! "<<endl;
		break;
		case 3:
		cout<<"1. "<<endl;
		cout<<"2. I'm not even angry... "<<endl;
		cout<<"3. I was so happy for you! "<<endl;
		break;

*/

