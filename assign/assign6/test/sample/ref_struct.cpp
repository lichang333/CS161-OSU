#include <iostream>

using namespace std;

struct animal{
    string type;
    string name;
    int weight;
    string color;
    string gender;
};

void print_animal(struct animal);
animal creat_animal();

int main(){
    struct animal tiger,bear,lion;
    
    tiger = creat_animal();
    bear = creat_animal();
    lion = creat_animal();    
    print_animal(tiger);
    print_animal(bear);
    print_animal(lion);

    return 0;
}

void print_animal(struct animal myAnimal){
    cout<<"I am a "<<myAnimal.type<<endl;
    cout<<"My name is "<<myAnimal.name<<endl;
    cout<<"I weight"<<myAnimal.weight<<"pounds"<<endl;
    cout<<"I am"<<myAnimal.color<<endl;
    cout<<"I am a"<<myAnimal.gender<<endl; 
}

animal create_animal(){
    struct animal temp;
    string type;
    string name;
    string color;
    string gender;
    int weight;
    
    cout<<"what type of animal is this: "<<endl;
    getline(cin,type);
    temp.name=type;
    
    cout<<"What would you like to make your animal:"<<endl;
    getline(cin,type);
    temp.name=name;
    
    cout<<"How much does your animal weight? : "<<endl;
    cin>>weight;
    temp.weight=weight;
    cin.ignore();
    
    cout<<"What color is your animal?: "<<endl;
    getline(cin,color);
    temp.color=color;
    
    cout<<"What gender is your animal?: "<<endl;
    getline(cin,gender);
    temp.gender=gender;

return temp;
}