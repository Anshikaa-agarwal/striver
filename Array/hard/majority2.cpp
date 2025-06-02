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

vector<int> majority2(vector<int> &nums) {
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

vector<int> majority3(vector<int> &nums) {

    sort(nums.begin(), nums.end());

    vector<int> result;
    int n = nums.size();
    int count = 1;

    for(int i=1; i<nums.size(); i++) {
        if(nums[i] == nums[i-1]) {
            count++;
        }
        else {
            if(count > n/3) {
                result.push_back(nums[i-1]);
            }
            count = 1;
        }

        if(result.size() == 2)
        break;
    }

    if(count > n/3) {
        result.push_back(nums[n-1]);
    }

    return result;
}

vector<int> optimal(vector<int> &nums) {
    int c1 = 0, c2 = 0;
    int el1 = INT32_MIN, el2 = INT32_MIN;
    int n = nums.size();

    for(int i=0; i<n; i++) {
        if(c1 == 0 && nums[i] != el2) {
            c1++;
            el1 = nums[i];
        }
        else if(c2 == 0 && nums[i] != el1) {
            c2++;
            el2 = nums[i];
        }
        else if(nums[i] == el1) c1++;
        else if(nums[i] == el2) c2++;
        else {
            c1--;
            c2--;
        }
    }

    vector<int> result;
    c1=0, c2=0;
    for(int i=0; i<n; i++) {
        if(nums[i] == el1) c1++;
        else if(nums[i] == el2) c2++;
    }

    if(c1 > n/3) result.push_back(el1);
    if(c2 > n/3) result.push_back(el2);

    return result;
}
void printArr(vector<int> &nums) {
    for(int i=0; i<nums.size(); i++) 
    cout << nums[i] << " ";
}
 
int main() {
    vector<int> nums = {11,33,33,11,33,11};
    vector<int> result = majority(nums);
    vector<int> result2 = majority2(nums);
    vector<int> result3 = majority3(nums);
    vector<int> result4 = optimal(nums);

    printArr(result);
    cout << endl;

    printArr(result2);
    cout << endl;

    printArr(result3);
    cout << endl;

    printArr(result4);
    cout << endl;

    return 0;
}