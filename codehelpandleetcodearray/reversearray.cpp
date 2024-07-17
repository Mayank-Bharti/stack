#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cout<<"enter size of vector"<<endl;
    cin>>n;
    vector<int>arr(n);
    cout<<"enter value of array"<< endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    //Method 1
    // int start=0;
    // int end=n-1;
    // while(start<=end){
    //      swap(arr[start++],arr[end--]);
    //     //  start++;
    //     //  end--;
       
    // }

    //method 2: here space complexity will be more
    vector<int> temp(n);
    for(int i=0;i<n;i++){
        temp[i]=arr[n-i-1];
    }
     // Copy the reversed values back to the original array
    for (int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }

    //printing reversed array

    cout<<"reversed array"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"\t";
    }
}