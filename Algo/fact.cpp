#include<iostream>
using namespace std;

 long double fact(long double a){
   if(a==0||a==1){
      return 1;
   }
   if(a<0){
      return -1;
   }
   return a*fact(a-1);
}
int main(){
   long double a;
   cin>>a;
   cout<<"fact of "<<a  <<"is  "<<fact(a)<<endl;
}