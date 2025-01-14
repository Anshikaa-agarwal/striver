// Problem Statement: Given an array of N integers, your task is to find unique triplets that add up to give a sum of zero. 
// In short, you need to return an array of all the unique triplets [arr[a], arr[b], arr[c]] such that i!=j, j!=k, k!=i, and their sum is equal to zero.
#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> triplet(vector<int> arr) {
    vector<vector<int>> result;
    for(int i=0; i<arr.size(); i++) {
        for(int j=i+1; j<arr.size(); j++) {
            for(int k=j+1; k<arr.size(); k++) {
                vector<int> temp;
                if(arr[i]+arr[j]+arr[k]==0) {
                    temp.push_back(arr[i]);
                    temp.push_back(arr[j]);
                    temp.push_back(arr[k]);

                    result.push_back(temp);
                }
            }
        }
    }

    return result;
}
int main() {
    vector<int> arr = {1,2,3,4,-5,-6};
    vector<vector<int>> result = triplet(arr);

    for(int i=0; i<result.size(); i++) {
        for(int j=0; j<result[i].size(); j++) cout << result[i][j] << " ";
        cout << endl;
    }
}
//Time complexity: O(n^3)