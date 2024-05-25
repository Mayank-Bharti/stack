#include <bits/stdc++.h>
//#include<cmath> ///both we can use 
#include<math.h>  
using namespace std;
bool predicate(long long int n,long long int mid){
 if((mid*(mid+1))/2<=n){
   return true;
 }
 else{
   return false;
 }
  
}

int main() {
  long long int n;
  cin>>n;
  int l=0,r=2*sqrt(n);
  while(l+1<r){
    long long int mid=l+(r-l)/2;
    if(predicate(n,mid)){
      l=mid;
    }
    else{
      r=mid;
    }

  }
    cout<<l;
  

  return 0;

}