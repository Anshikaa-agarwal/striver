// Generate all subarrays
#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> generateSubarrays(vector<int> arr) {
    vector<vector<int>> result;
    for(int i=0; i<arr.size(); i++) {
        vector<int> temp;
        for(int j=i; j<arr.size(); j++) {
            temp.push_back(arr[j]);
            result.push_back(temp);
        }
    }
    return result;
}
int main() {
    vector<int> arr = {1,2,3};
    vector<vector<int>> result = generateSubarrays(arr);
    for(int i=0; i<result.size(); i++) {
        cout << "{ ";
        for(int j=0; j<result[i].size(); j++) cout << result[i][j] << " ";
        cout << "}";
        cout << endl; 
    }
}