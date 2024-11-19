#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[]={1,2,3,1,2,3,5};
    int a=0;
for(auto i:arr){
    a=a^i;
}
cout<<a<<endl;
return 0;

}

