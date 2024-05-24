#include<bits/stdc++.h>
using namespace std;
int main() {
    string s;
    getline(cin, s);
    int n=s.length();
    stack<long long int> st;
    for(int i=0; i<n; i+=2){  //in string, after each character a space is there , so it incremented by 2
        if(s[i]>='0' && s[i]<='9') {
            st.push(s[i]-'0');
        }
        else{
          long long nums1=st.top(), nums2;
          st.pop();
          nums2=st.top();
          st.pop();
          if(s[i]=='+') nums2+=nums1;
          else if(s[i]=='-') nums2-=nums1;
          else if(s[i]=='*') nums2*=nums1;
          else nums2/=nums1;
          st.push(nums2);
        }
  }
cout<<st.top();
return 0;
}