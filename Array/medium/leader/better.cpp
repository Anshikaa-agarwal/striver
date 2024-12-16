/*Problem Statement: Given an array, print all the elements which are leaders. 
A Leader is an element that is greater than all of the elements on its right side in the array.
*/
#include<iostream>
#include<vector>
using namespace std;
void leader(vector<int> arr, vector<int>& result) {
    int i;
    for(i=arr.size()-1; i>0; i--) {
        if(arr[i-1]>arr[i]) result.push_back(arr[i]);
        else break;
    }
    result.push_back(arr[i]);
}
int main() {
    vector<int> arr = {4,3,2,1,0};
    vector<int> result;
    leader(arr, result);
    for(int i=0; i<result.size(); i++) cout << result[i] << " ";
    return 0;
}