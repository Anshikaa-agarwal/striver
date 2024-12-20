// Problem Statement: Given an array of N integers. Find the elements that appear more than N/3 times in the array. If no such element exists, return an empty vector.

// using hashmap
#include<iostream>
#include<vector>
#include<map>
using namespace std;
vector<int> majority(vector<int> arr) {
    vector<int> result;

    map<int, int> mpp; // element, frequency
    for(int i=0; i<arr.size(); i++) mpp[arr[i]]++; //increase frequency as element occurs
    
    for(auto it : mpp) {
        if(it.second>arr.size()/3) result.push_back(it.first);
    }

    return result;
}
int main() {
    vector<int> arr = {11,33,33,11,33,11};
    vector<int> result = majority(arr);
    
    for(int i=0; i<result.size(); i++) cout << result[i] << " ";
}