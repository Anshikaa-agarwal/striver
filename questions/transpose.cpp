// Find transpose of a matrix
#include<iostream>
#include<vector>
using namespace std;
void swap(int &x, int& y) {
    //x=5, y=3
    x = x+y; //x=8, y=3
    y=x-y; //x=8, y=5
    x=x-y; //x=3, y=5
}
vector<vector<int>> transpose(vector<vector<int>> matrix) {
    int n = matrix.size();

    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    return matrix;
}
int main() {
    vector<vector<int>> mat = {{1,2,3},
                            {4,5,6},
                            {7,8,9}};

    cout << "Original matrix: " << endl;
    for(int i=0; i<mat.size(); i++) {
        for(int j=0; j<mat[0].size(); j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    vector<vector<int>> result = transpose(mat);

    cout << "Transposed matrix: " << endl;
    for(int i=0; i<result.size(); i++) {
        for(int j=0; j<result[0].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}