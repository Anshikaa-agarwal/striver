// Given a Matrix, print the given matrix in spiral order.
#include<iostream>
#include<vector>
using namespace std;
void spiralTraversal(vector<vector<int>> matrix) {
    int rstart = 0, cstart = 0;
    int rend = matrix.size()-1;
    int cend = matrix[0].size()-1;

    while(rstart<=rend && cstart<=cend) {
        //forward (row)
        for(int i=cstart; i<=cend; i++) cout << matrix[rstart][i] << " ";
        rstart++;

        //downward (column)
        for(int i=rstart; i<=rend; i++) cout << matrix[i][cend] << " ";
        cend--;

        //backward (row)
        for(int i=cend; i>=cstart; i--) cout << matrix[rend][i] << " ";
        rend--;

        //upward (column)
        for(int i=rend; i>=rstart; i--) cout << matrix[i][cstart] << " ";
        cstart++;
    }
}
int main() {
    vector<vector<int>> matrix = {{1,2,3,4},
                                  {5,6,7,8},
                                  {9,10,11,12},
                                  {13,14,15,16}};

    spiralTraversal(matrix);
    return 0;
}