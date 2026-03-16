#include <iostream>
#include <vector>
using namespace std;

// Brute Force = TC: O(m*n*(m+n)), SC: O(m*n)
vector<vector<int>> BruteForce(vector<vector<int>> matrix) {
    int m = matrix.size();
    int n = matrix[0].size();

    // Step 1: Make a copy of the matrix to store updates
    vector<vector<int>> temp = matrix;

    // Step 2: Traverse each cell of the matrix
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            // Step 3: If the current cell is zero
            if (matrix[i][j] == 0) {
                // Step 4: Set entire row to zero in temp matrix
                for (int k = 0; k < n; k++) {
                    temp[i][k] = 0;
                }
                // Step 5: Set entire column to zero in temp matrix
                for (int k = 0; k < m; k++) {
                    temp[k][j] = 0;
                }
            }
        }
    }

    // Step 6: Return the updated matrix
    return temp;
}



// Better Approach = TC: O(m*n) , SC: O(m+n)
vector<vector<int>> BetterApproach(vector<vector<int>> matrix) {
    int m = matrix.size();
    int n = matrix[0].size();

    // Step 1: Create two arrays to mark rows and columns that should be zero
    vector<bool> row(m, false);
    vector<bool> col(n, false);

    // Step 2: Traverse the matrix, mark row[i] and col[j] if matrix[i][j] is zero
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 0) {
                row[i] = true;
                col[j] = true;
            }
        }
    }

    // Step 3: Traverse again and set cell to zero if its row or column is marked
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (row[i] || col[j]) {
                matrix[i][j] = 0;
            }
        }
    }
    // Step 4: Return the updated matrix
    return matrix;
}

//Optimal Approch: TC: O(M*n), SC: O(m+n)
vector<vector<int>> OptimalApproch(vector<vector<int>> matrix) {
    int m = matrix.size();
    int n = matrix[0].size();

    bool firstRowImpacted = false; // Will track if first row needs to be zero
    bool firstColImpacted = false; // Will track if first column needs to be zero

    // Step 1: Check if first row has any zero, if yes then set firstRowImpacted = true and stop checking
    for (int col = 0; col < n; col++) {
        if (matrix[0][col] == 0) {
            firstRowImpacted = true;
            break;
        }
    }

    // Step 2: Check if first column has any zero, if yes then set firstColImpacted = true and stop checking
    for (int row = 0; row < m; row++) {
        if (matrix[row][0] == 0) {
            firstColImpacted = true;
            break;
        }
    }

    // Step 3: For the rest of the matrix (excluding first row and first column),
    // if any cell is zero, mark its row by setting matrix[i][0] = 0 and mark its column by setting matrix[0][j] = 0
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    // Step 4: Traverse the rest of the matrix again (excluding first row and first column),
    // if its row OR column is marked (matrix[i][0] == 0 or matrix[0][j] == 0), set this cell to 0
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }

    // Step 5: If firstRowImpacted is true, set entire first row to zero
    if (firstRowImpacted) {
        for (int j = 0; j < n; j++) {
            matrix[0][j] = 0;
        }
    }

    // Step 6: If firstColImpacted is true, set entire first column to zero
    if (firstColImpacted) {
        for (int i = 0; i < m; i++) {
            matrix[i][0] = 0;
        }
    }

    // Step 7: Return the updated matrix
    return matrix;
}



int main() {
    // Example matrix
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 0, 6},
        {7, 8, 9}
    };

    // Call the SetZero function and get the updated matrix
    vector<vector<int>> result = OptimalApproch(matrix);

    cout << "\nMatrix after setting zeroes:" << endl;
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[0].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
