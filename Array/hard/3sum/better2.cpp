// Problem Statement: Given an array of N integers, your task is to find unique triplets that add up to give a sum of zero. 
// In short, you need to return an array of all the unique triplets [arr[a], arr[b], arr[c]] such that i!=j, j!=k, k!=i, and their sum is equal to zero.
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

vector<vector<int>> triplet(vector<int> arr) {
    set<vector<int>> st;
    
    for(int i=0; i<arr.size(); i++) {
        set<int> hashset;
        for(int j=i+1; j<arr.size(); j++) {
            
            int element = -(arr[i]+arr[j]);
            if(hashset.find(element)!=hashset.end()) {
                vector<int> temp = {arr[i], arr[j], element};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            } else {
                hashset.insert(arr[j]);
            }
        }
    }

    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
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