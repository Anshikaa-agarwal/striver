/*Problem Statement:
There’s an array ‘A’ of size ‘N’ with an equal number of positive and negative elements. 
Without altering the relative order of positive and negative elements, you must return an array of alternately positive and negative values.
Note: Start the array with positive elements.*/
#include<iostream>
#include<vector>
using namespace std;
vector<int> rearrange(vector<int> arr) {
    int i=0, j=1, k=0;
    vector<int> result(arr.size());
    while(k<arr.size()) {
        if(arr[k]>0) {
            result[i]=arr[k++];
            i+=2;
        }
        else if(arr[k]<0) {
            result[j] = arr[k++];
            j+=2;
        }
    }
    return result;
}
int main() {
    vector<int> arr = {1,2,3,-3,-5,-9};
    vector<int> result;
    result = rearrange(arr);
    for(int i=0; i<result.size(); i++) cout << result[i] << " ";
}