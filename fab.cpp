#include <bits/stdc++.h>
using namespace std;
int fab(int n){
  if(n<=1){
    return n;
  }
  else{
    return fab(n-1)+fab(n-2);
  }
}

int main() {
  int n;
  cin>>n;

  cout<<fab(n);

  return 0;

}