#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<set>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums) {
    // O(n^3 * log(no. of unique triplets))
    set<vector<int>> st;

    for(int i=0; i<nums.size(); i++) {
        for(int j=i+1; j<nums.size(); j++) {
            for(int k=j+1; k<nums.size(); k++) {
                if(nums[i] + nums[j] + nums[k] == 0) {
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }
    }

    vector<vector<int>> result(st.begin(), st.end());
    return result;
}

vector<vector<int>> threeSum2(vector<int> &nums) {
    // hashing
    // O(n^2 log k)
    unordered_map<int, int> mpp;
    set<vector<int>> st;

    for(int i=0; i<nums.size(); i++) {
        mpp[nums[i]] = i;
    }

    for(int i=0; i<nums.size(); i++) {
        for(int j=i+1; j<nums.size(); j++) {
            int third = -(nums[i] + nums[j]);
            auto it = mpp.find(third);
            if(it != mpp.end() && it->second != j && it->second != i) {
                vector<int> temp = {nums[i], nums[j], third};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            } 
        }
    }

    vector<vector<int>> result(st.begin(), st.end());
    return result;
}

vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> result;
}

void printArr(vector<int> arr) {
    for(int i=0; i<arr.size(); i++) 
    cout << arr[i] << " ";
}

int main() {
    vector<int> arr = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result = threeSum2(arr);

    for(int i=0; i<result.size(); i++) {
        printArr(result[i]);
        cout << endl;
    }

    return 0;
}