/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0. */
#include<iostream>
#include<vector>
using namespace std;
int maxProfit(vector<int> price) {
    int maxx = 0;
    int currentProfit = 0;

    for(int i=0; i<price.size()-1; i++) {
        for(int j=i+1; j<price.size(); j++) {
            currentProfit = price[j] - price[i];
            if(currentProfit>maxx) maxx = currentProfit;
        }
    }

    return maxx;
}
int main() {
    vector<int> arr = {7,1,5,3,6,4};
    cout <<maxProfit(arr);
}