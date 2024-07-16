#include<iostream>
#include<vector>
using namespace std;

vector<int> movezeros(vector<int>& nums) {
    //method 1
    // int n = nums.size();
    // int i = 0;
    // for (int j = 0; j < n; j++) {
    //     if (nums[j] != 0) {
    //        swap(nums[j], nums[i]);
    //        i++;
    //     }
    // }
    // return nums;
    //method 2
    vector<int>v;
    for(int i=0;i<nums.size();i++){
        if (nums[i]!=0){
            v.push_back(nums[i]);
        }
    }
    for(int i=0;i<nums.size();i++){
        if (nums[i]==0){
            v.push_back(nums[i]);
        }
    }
    for(int i=0;i<nums.size();i++){
        nums[i]=v[i];
    }
    return nums;
}

int main() {
    int n;
    cout << "Enter size of vector: " << endl;
    cin >> n;
    
    vector<int> nums(n);
    cout << "Please enter values of array: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
   
    vector<int> result = movezeros(nums);
    cout << "Modified array: ";
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    
    return 0;
}
