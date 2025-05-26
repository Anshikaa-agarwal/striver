#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

int majority1(vector<int> nums) {
    sort(nums.begin(), nums.end());
    int mid = nums.size()/2;
    return nums[mid];

    // Time: o(n*log n)
    // Space: O(1)
}
int majority2(vector<int> &nums) {
    map<int, int> mpp;

    for(int i=0; i<nums.size(); i++) {
        mpp[nums[i]]++;
    }

    for(auto it: mpp) {
        if(it.second > nums.size()/2)
        return it.first;
    }

    return -1;

    // Time Complexity: O(n log n)
    // Space Complexity: O(n)
}

int majority3(vector<int> &nums) {
    //Moore's voting algorithm
    int element = 0, count = 0;

    element = nums[0];
    count = 1;
    for(int i=1; i<nums.size(); i++) {
        if(count == 0) {
            element = nums[i];
            count++;
        }
        if(nums[i] == element) {
            count++;
        }
        else
        count--;
    }

    return element;

    // Time complexity: O(n)
    // Space Complexity: O(1)
}
int main() {
    vector<int> arr = {3,2,3};
    cout << majority1(arr) << endl;
    cout << majority2(arr) << endl;
    cout << majority3(arr) << endl;

    return 0;
}