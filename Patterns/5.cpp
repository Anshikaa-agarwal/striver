// * * * * *
// * * * * 
// * * * 
// * * 
// * 
#include<iostream>
using namespace std;
void printPattern(int n) {
    for(int i=n; i>=1; i--) {
        for(int j=1; j<=i; j++) cout << "* ";
        cout << endl;
    }
}
int main() {
    printPattern(5);
    return 0;
}