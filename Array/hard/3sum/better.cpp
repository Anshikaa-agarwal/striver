// Problem Statement: Given an array of N integers, your task is to find unique triplets that add up to give a sum of zero. 
// In short, you need to return an array of all the unique triplets [arr[a], arr[b], arr[c]] such that i!=j, j!=k, k!=i, and their sum is equal to zero.

//Approach: Hashing
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
vector<vector<int>> threesum(vector<int> arr) {
    vector<vector<int>> result;
    sort(arr.begin(), arr.end());

    for(int i=0; i<arr.size(); i++) {
        unordered_map<int, bool> mpp;
        if (i > 0 && arr[i] == arr[i - 1]) continue;

        for(int j=i+1; j<arr.size(); j++) {
            
            int element = -(arr[i]+arr[j]);
            vector<int> temp;
            if(mpp.find(element)!=mpp.end() && mpp[element]==true) {
                temp.push_back(arr[i]);
                temp.push_back(arr[j]);
                temp.push_back(element);

                result.push_back(temp);
                while (j + 1 < arr.size() && arr[j] == arr[j + 1]) j++;
            } else {
                mpp[arr[j]] = true;
            }
        }
    }
    return result;
}
int main() {
    vector<int> arr = {1,2,3,4,-5,-6};
    vector<vector<int>> result = threesum(arr);

    for(int i=0; i<result.size(); i++) {
        for(int j=0; j<result[i].size(); j++) cout << result[i][j] << " ";
        cout << endl;
    }
}