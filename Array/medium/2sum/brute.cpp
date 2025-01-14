#include<iostream>
#include<vector>
using namespace std;
bool twoSum(vector<int> arr, int k) {
    for(int i=0; i<arr.size(); i++) {
        for(int j=0; j<arr.size(); j++) {
            if(arr[i]+arr[j]==k)
            return true;
        }
    }
    return false;
}
int main() {
    vector<int> arr = {1,4,2,0,9,7};
    int k = 12;
    if(twoSum(arr, k)) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}