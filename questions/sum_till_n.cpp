// find sum upto n using recursion (1+2+3+...+n)
#include<iostream>
using namespace std;
int sumSeries(int n) {
    if(n==0) return 0;
    return n + sumSeries(n-1);
}
int main() {
    cout << sumSeries(5);
}