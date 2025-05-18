// Move 0's to end
#include<iostream>
#include<vector>
using namespace std;

void move0(vector<int> &nums) {
    int i=0, j=0;

    for(j=0; j<nums.size(); j++) {
        if(nums[j] != 0) {
            swap(nums[i++], nums[j]);
        }
    }
}
void printArr(vector<int> nums) {
    for(int i=0; i<nums.size(); i++) {
        cout << nums[i] << " ";
    }
}
int main() {
    vector<int> arr = {1,2,0,0,0,0,1,2};
    move0(arr);
    printArr(arr);

    return 0;
}