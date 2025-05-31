#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> nextPer(vector<int> &nums) {
    next_permutation(nums.begin(), nums.end());
    return nums;
}
vector<int> nextPermutation(vector<int> &nums) {
    int bp=-1, next=INT32_MAX, index;
    for(int i=0; i<nums.size()-1; i++) {
        if(nums[i] < nums[i+1]) {
            bp = i;
        }
    }
    if (bp == -1) {
        // Entire sequence is non-increasing
        reverse(nums.begin(), nums.end());
        return nums;
    }
    for(int i=bp+1; i<nums.size(); i++) {
        if(nums[i] < next && nums[i] > nums[bp]) {
            next = nums[i];
            index = i;
        }
    }

    swap(nums[bp], nums[index]);

    reverse(nums.begin()+bp+1, nums.end());

    return nums;
}

void printArr(vector<int> nums) {
    for(int i=0; i<nums.size(); i++)
    cout << nums[i] << " ";
}
int main() {
    vector<int> arr = {2,1,5};
    vector<int> ans = nextPermutation(arr);

    printArr(ans);
}