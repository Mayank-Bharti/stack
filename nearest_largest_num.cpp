#include <bits/stdc++.h>
using namespace std;

int main() {

  int n;
  cin>>n;
  vector<int>arr(n),ans(n,-1);
  for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
  stack<int>st;
  st.push(arr[0]);
  for(int i=1;i<n;i++){
    while(st.size()&&st.top()<=arr[i]){
      st.pop();
    }
    if(st.size()){
      ans[i]=st.top();
    }
    st.push(arr[i]);
  }
  for(int i=0;i<n;i++){
    cout<<ans[i]<<" ";
  }

  return 0;

}