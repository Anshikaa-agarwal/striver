/*Problem Statement: Given an array, print all the elements which are leaders. 
A Leader is an element that is greater than all of the elements on its right side in the array.
*/
#include<iostream>
#include<vector>
using namespace std;
void leader(vector<int> arr, vector<int> & result) {
    for(int i=0; i<arr.size()-1; i++) {
        if(arr[i+1]<arr[i]) result.push_back(arr[i]);
        else result.clear();
    }
    result.push_back(arr[arr.size()-1]);
}
int main() {
    vector<int> arr = {4,3,2,7,1,0};
    vector<int> result;
    leader(arr, result);
    for(int i=0; i<result.size(); i++) cout << result[i] << " ";
    return 0;
}
//time complexity: O(n^2) (due to clear operation)