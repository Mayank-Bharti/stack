#include<bits/stdc++.h>
using namespace std;

int main(){
    int maxi=0;
    int n;
    int k;
    cin>>n>>k;
    for(int i=1;i<=k;i++){
        maxi=max(n^i,maxi);
    }
    cout<<maxi<<endl;

}