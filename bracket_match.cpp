#include<iostream>
#include<stack>
#include <vector>
using namespace std;

vector<int> valid(const string& expression){
     stack<int>s;
     vector<int>ans(expression.length(),-1);
     for(int i=0;i<expression.length();i++){
        char ch=expression[i];
        //if opening bracket stack push indexex else if closing bracket then check top of stack and pop.
      if(ch=='('){
        s.push(i);
      }
      else if(ch==')'){
        if(!s.empty()){
            int top=s.top();
                s.pop();
                ans[top]=i;
                ans[i]=top;
               
        }
      }
    }
    return ans;
  }
 int main(){
    string expression;
    cin >> expression;
    vector<int>result=valid(expression);
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " "; 
    }
    cout << endl;

    return 0;
 }