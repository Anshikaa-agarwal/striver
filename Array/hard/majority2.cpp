// Problem Statement: Given an array of N integers. Find the elements that appear more than N/3 times in the array. If no such element exists, return an empty vector.

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
#include<unordered_map>
using namespace std;

vector<int> majority(vector<int> nums) {

    // Brute force: O(n^2)
    vector<int> result;
    int n = nums.size();
    unordered_set<int> visited;

    for(int i=0; i<nums.size(); i++) {
        int element = nums[i];
        int count = 0;

        // element already existed
        if(visited.find(element) != visited.end()) 
        continue;

        // otherwise add number to set and proceed
        visited.insert(element);

        for(int j=0; j<nums.size(); j++) {
            if(nums[j] == element)
            count++;
        }

        if(count>n/3)
        result.push_back(element);
    }

    return result;
}

vector<int> majorit2(vector<int> &nums) {
    // use hashmap
    // Better - o(n) avg, o(n^2) worst case but very rare
    unordered_map<int, int> mpp;
    vector<int> result;
    int n = nums.size();

    for(int i=0; i<n; i++) 
    mpp[nums[i]]++;

    for(auto it: mpp) {
        if(it.second > n/3)
        result.push_back(it.first);

        if(result.size() == 2)
        break;
    }

    return result;
}
void printArr(vector<int> &nums) {
    for(int i=0; i<nums.size(); i++) 
    cout << nums[i] << " ";
}
 
int main() {
    vector<int> nums = {11,33,33,11,33,11};
    vector<int> result = majority(nums);
    vector<int> result2 = majorit2(nums);

    printArr(result);
    cout << endl;

    printArr(result2);
    cout << endl;

    return 0;
}