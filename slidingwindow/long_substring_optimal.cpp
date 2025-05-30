 //Longest substring with at most k distinct characters
 //Optimal solution: TC:O(N)+O(log 256) FOR ORDERED MAP AND O(N )+O(1) IN UNORDERED MAP AND SC:O(256) 256 IS TOTAL CHARACTERS


 #include<bits/stdc++.h>
 using namespace std;

int func(string &s,int k){
    int l=0;
    int r=0;
    int maxlen=0;
    unordered_map<char,int>mpp;
    while(r<s.length()){
        mpp[s[r]]++;
        if(mpp.size()>k){
            mpp[s[l]]--;
             if(mpp[s[l]]==0){
                mpp.erase(s[l]);
             }
             l++;
        }
        if(mpp.size()<=k){
            maxlen=max(maxlen,r-l+1);
        }
        r++;
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