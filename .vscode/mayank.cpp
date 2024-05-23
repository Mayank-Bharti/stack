#include <iostream>
using namespace std;
int func(char a[]){
    int count=0;
    for(int i=0; a[i] != '\0';i++){
        count++;
    }
    return count;
}

int main() {
  char a[20];
  cout<<"enter your name:"<<endl;
  cin>> a;
  cout<<"your name is:";
  cout<<a<<endl;
  cout<<"length of string is:"<<func(a)<<endl;

  return 0;
}