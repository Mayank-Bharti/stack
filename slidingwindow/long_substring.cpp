 //Longest substring with at most k distinct characters
 //Brute force solution: TC:O(N^2)+O(256) FOR ORDERED MAP AND O(N^2 )+O(1) IN UNORDERED MAP AND SC:O(256) 256 IS TOTAL CHARACTERS


 #include<bits/stdc++.h>
 using namespace std;

 int func(string &s,int k){
   unordered_map<char,int>mpp;
   int maxlen=0;
   for(int i=0;i<s.length();i++){
    mpp.clear();
      for(int j=i;j<s.length();j++){
           mpp[s[j]]++;
           if(mpp.size()<=k){
            maxlen=max(maxlen,j-i+1);
           }
           else{
            break;
           }
      }
   }
   return maxlen;
 }
int main(){
    string s;
    cin>>s;
    int k;
    cin>>k;
    int result=func(s,k);
    cout<<result<<endl;
 }