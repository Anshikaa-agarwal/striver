/*Problem Statement:
There’s an array ‘A’ of size ‘N’ with an equal number of positive and negative elements. 
Without altering the relative order of positive and negative elements, you must return an array of alternately positive and negative values.
Note: Start the array with positive elements.*/
#include<iostream>
#include<vector>
using namespace std;
void increaseI(int& i, vector<int> arr) {
    while(i < arr.size() && arr[i] < 0) i++;
}
void increaseJ(int& j, vector<int> arr) {
    while(j < arr.size() && arr[j] > 0) j++;
}
vector<int> rearrange(vector<int> arr) {
    int i=0, j=0;
    increaseI(i, arr);
    increaseJ(j, arr);
    vector<int> result;
    for(int k=0; k<arr.size()/2; k++) {
        result.push_back(arr[i++]);
        result.push_back(arr[j++]);
        increaseI(i, arr);
        increaseJ(j, arr);
    }
    return result;
}
int main() {
    vector<int> arr = {1,2,3,-3,-5,-9};
    vector<int> result;
    result = rearrange(arr);
    for(int i=0; i<result.size(); i++) cout << result[i] << " ";
}