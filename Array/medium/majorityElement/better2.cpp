// use hashmap
#include<iostream>
#include<vector>
#include<map>
using namespace std;
int majority(vector<int> arr) {
    map<int, int> mpp; // <element, frequency>
    for(int i=0; i<arr.size(); i++) mpp[arr[i]]++;

    //iterate the map and find which element's frequency is greater than n/2
    for(auto it : mpp) {
        if(it.second > arr.size()/2) return it.first;
    }
    
    return -1;
}
int main() {
    vector<int> arr = {1,1,1,1,2,3,4};
    cout << "Majority element is " << majority(arr);
    return 0;
}