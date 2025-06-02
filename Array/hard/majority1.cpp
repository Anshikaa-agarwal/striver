#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int majority(vector<int> &nums) {
    int count = 1;
    int element = nums[0];
    int n = nums.size();

    for(int i=1; i<nums.size(); i++) {
        if(count == 0) {
            element = nums[i];
            count = 1;
            continue;
        }

        if(nums[i] == element) 
        count++;
        else {
            count--;
        }
    }
    count = 0;
    for(int num : nums) {
        if(num == element) count++;
    }

    if(count > nums.size() / 2)
        return element;
    else
        return -1;
}

int main() {
    vector<int> nums = {1,1,1,2,4,3,4,1,4,1,1};
    cout << majority(nums);

}