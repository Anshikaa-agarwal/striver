// Problem Statement: Given an array of N integers, your task is to find unique triplets that add up to give a sum of zero. 
// In short, you need to return an array of all the unique triplets [arr[a], arr[b], arr[c]] such that i!=j, j!=k, k!=i, and their sum is equal to zero.

#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

vector<vector<int>> triplet(vector<int> arr) {
    sort(arr.begin(), arr.end());
    vector<vector<int>> result;

    for(int i=0; i<arr.size()-2; i++) {

        // skip duplicates
        if(i > 0 && arr[i] == arr[i - 1]) {
            continue;
        }

        int j=i+1;
        int k=arr.size()-1;

        while(j<k) {
            if((arr[i]+arr[j]+arr[k])<0) j++;
            else if((arr[i]+arr[j]+arr[k])>0) k--;
            else {
                vector<int> temp = {arr[i], arr[j], arr[k]};
                result.push_back(temp);
                while(j < k && arr[j] == arr[j + 1]) {
                    j++;
                }
                while(j < k && arr[k] == arr[k - 1]) {
                    k--;
                }
                j++;
                k--;
            }
        }
    }

    return result;
}
int main() {
    vector<int> arr = { -1, 0, 1, 2, -1, -4};
    int n = arr.size();
    vector<vector<int>> ans = triplet(arr);
    for (auto it : ans) {
        cout << "[";
        for (auto i : it) {
            cout << i << " ";
        }
        cout << "] ";
    }
    cout << "\n";
    return 0;
}