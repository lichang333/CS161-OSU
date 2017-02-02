#include <iostream>

using namespace std;

void print(int **array, int length, int width){
    for(int x=0;x<length;x++){
        for(int y=0;y<width;y++){
            cout<<array[x][y]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    
    int **array;
    
    array=new int*[10];
    for(int x=0;x<10;x++){
        array[x]=new int[10];
    }
    print(array,10,10);
    return 0;
}