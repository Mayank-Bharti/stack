#include<iostream>
#include<vector>
using namespace std;
void merge(vector<int> &arr1,int n1,vector<int> &arr2,int n2,vector<int> &arr){
    int i=0,j=0,k=0;
    while(i<n1&&j<n2){
        if(arr1[i]<arr2[j]){
            arr[k]=arr1[i];
            i++;
            k++;
        }
        else{
            arr[k]=arr2[j];
            k++;
            j++;
        }
    }
    while(i<n1){
        arr[k]=arr1[i];
        k++;
        i++;
    }
    while(j<n2){
        arr[k]=arr2[j];
        k++;
        j++;
    }
    cout << "Modified array: ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main(){
    int n1;
    cout<<"enter size of vector1"<<endl;
    cin>>n1;
    vector<int>arr1(n1);
    cout<<"enter value of array1"<< endl;
    for(int i=0;i<n1;i++){
        cin>>arr1[i];
    }
    int n2;
    cout<<"enter size of vector2"<<endl;
    cin>>n2;
    vector<int>arr2(n2);
    cout<<"enter value of array2"<< endl;
    for(int i=0;i<n2;i++){
        cin>>arr2[i];
    }
    vector<int>arr(n1+n2);
    merge(arr1,n1,arr2,n2,arr);
}