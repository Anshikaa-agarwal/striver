// Use hashing
#include<iostream>
#include<vector>
#include<map>
using namespace std;

bool twoSum(vector<int> arr, int k) {
    map<int,int> mpp;
    for(int i=0; i<arr.size(); i++) {
        int a = arr[i];
        int element = k-a;
        if(mpp.find(element) != mpp.end()) { //the element exists
            return true;
        }
        mpp[a] = i;
    }
    return false;
}
int main() {
    vector<int> arr = {1,4,2,0,9,7};
    int k = 11;
    if(twoSum(arr, k)) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}