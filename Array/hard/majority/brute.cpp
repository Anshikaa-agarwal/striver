// Problem Statement: Given an array of N integers. Find the elements that appear more than N/3 times in the array. If no such element exists, return an empty vector.
#include<iostream>
#include<vector>
#include<set>
using namespace std;
set<int> majority(vector<int> arr) {
    set<int> result;
    for(int i=0; i<arr.size(); i++) {
        int count = 0;
        for(int j=0; j<arr.size(); j++) {
            if(arr[j]==arr[i]) count++;
        }
        if(count>arr.size()/3) result.insert(arr[i]);
    }
    return result;
}
int main() {
    vector<int> arr = {1,2,2,2,3};
    set<int> result = majority(arr);
    for(auto it : result) cout << it << " ";
    return 0;
}