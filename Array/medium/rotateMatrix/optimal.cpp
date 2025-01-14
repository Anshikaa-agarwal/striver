// Rotate Matrix anti-clockwise by 90 degree

//Problem statement: Given a matrix, your task is to rotate matrix anti-clockwise by 90 degrees.
#include<iostream>
#include<vector>
using namespace std;
void swap(int& x, int& y) {
    x=x+y;
    y=x-y;
    x=x-y;
}
void transpose(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    for(int i=0; i<n; i++) {
        for(int j=i+1; j<m; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}
void reverseColumns(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0, k = n - 1; j < k; j++, k--) {
            swap(matrix[j][i], matrix[k][i]);
        }
    }
}
void rotate90(vector<vector<int>> &matrix) {
    transpose(matrix);
    reverseColumns(matrix);
}
int main() {
    vector<vector<int>> matrix = {{1,2,3},
                                  {4,5,6},
                                  {7,8,9}};

    cout << "Original matrix: " << endl;
    for(int i=0; i<matrix.size(); i++) {
        for(int j=0; j<matrix[0].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    rotate90(matrix);
    cout << "Rotated matrix: " << endl;
    for(int i=0; i<matrix.size(); i++) {
        for(int j=0; j<matrix[0].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}