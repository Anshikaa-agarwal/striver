// Print Pascal Triangle with n rows
#include<iostream>
#include<vector>
using namespace std;
int factorial(int n) {
    int x = 1;
    for(int i=2; i<=n; i++) x*=i;
    return x;
}
int nCr(int n, int r) {
    int up=1;
    for(int i=(n-r+1); i<=n; i++) up*=i;
    int down = factorial(r);
    return (up/down);
} 
void printPascal(int n) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<=i; j++) {
            cout << nCr(i, j) << " ";
        }
        cout << endl;
    }
}
int main() {
    printPascal(5);
    return 0;
}