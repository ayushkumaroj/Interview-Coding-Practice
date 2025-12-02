#include <bits/stdc++.h>   // Includes all standard libraries (useful for competitive coding)
using namespace std;

/*
Game of Life Problem:
- You are given a board (grid) with cells either alive (1) or dead (0).
- Update the board to its next state based on these rules:
    1. A live cell with fewer than 2 live neighbors dies (under-population).
    2. A live cell with 2 or 3 live neighbors lives on (survival).
    3. A live cell with more than 3 live neighbors dies (over-population).
    4. A dead cell with exactly 3 live neighbors becomes alive (reproduction).

We must do this IN PLACE (no extra board allowed).

Time Complexity: O(M * N) → Traverse each cell and check 8 neighbors.
Space Complexity: O(1) → Use same board for updates (with temporary markers).
*/

//TC: O(m*n), SC: O(1)
// Step 1: Function to check if a neighbor cell (x, y) is valid (inside the board)
bool isValidNeighbor(int x, int y, vector<vector<int>>& board) {
    // Check if row index is within bounds AND column index is within bounds.
    // If yes, return true, else return false.
    if (x >= 0 && x < board.size() && y >= 0 && y < board[0].size()) {
        return true;
    }
    return false;
}

// Step 2: Main function that applies Game of Life rules to the board
void gameOfLife(vector<vector<int>>& board) {
    // Step 3: Create two arrays (dx and dy) to represent directions of 8 neighbors:
    // dx and dy hold relative positions (top, bottom, left, right, and diagonals).
    vector<int> dx = {0, 0, 1, 1, 1, -1, -1, -1};   // Row changes
    vector<int> dy = {1, -1, 1, -1, 0, 0, 1, -1};  // Column changes

    // Step 4: Outer loop: Traverse each row of the board.
    for (int row = 0; row < board.size(); row++) {
        // Step 5: Inner loop: Traverse each column in the current row.
        for (int col = 0; col < board[0].size(); col++) {

            // Step 6: Initialize a counter for live neighbors around the current cell.
            int count_live_neighbours = 0;

            // Step 7: Loop through all 8 directions to check neighbors.
            for (int i = 0; i < 8; i++) {
                // Calculate neighbor's coordinates.
                int curr_x = row + dx[i]; // Neighbor row index.
                int curr_y = col + dy[i]; // Neighbor column index.

                // Step 8: If neighbor is valid (inside board) AND originally alive:
                // Use abs() because:
                //   - We will mark some cells as -1 (was alive → now dead)
                //   - Or 2 (was dead → now alive)
                // abs() ensures original state is considered for counting.
                if (isValidNeighbor(curr_x, curr_y, board) && abs(board[curr_x][curr_y]) == 1) {
                    count_live_neighbours++; // Increase live neighbor count.
                }
            }

            // Step 9: Apply Game of Life rules to the current cell:
            // Rule 1 & 3: Live cell dies if it has fewer than 2 or more than 3 live neighbors.
            // We cannot immediately make it 0 because neighbors still need its original value.
            // So, mark it as -1 (means it was alive but now should be dead).
            if (board[row][col] == 1 && (count_live_neighbours < 2 || count_live_neighbours > 3)) {
                board[row][col] = -1; // Temporarily mark for death.
            }

            //  Step 10: Rule 4 ,Dead cell becomes alive if it has exactly 3 live neighbors.
            // Similarly, we mark as 2 (means it was dead but now should be alive).
            if (board[row][col] == 0 && count_live_neighbours == 3) {
                board[row][col] = 2; // Temporarily mark for birth.
            }
        }
    }

    //  Step 11: Second pass: Update all cells to their final state.
    // Convert markers (-1 and 2) to actual values (0 or 1).
    for (int row = 0; row < board.size(); row++) {
        for (int col = 0; col < board[0].size(); col++) {
            // If value is positive (1 or 2), final state is alive (1).
            // If value is 0 or negative (-1), final state is dead (0).
            if (board[row][col] > 0) {
                board[row][col] = 1; // Alive
            } else {
                board[row][col] = 0; // Dead
            }
        }
    }
}

/* ------------------------------------------------------ */
/* Main function to test the solution */
int main() {
    // Define a sample board.
    vector<vector<int>> board = {
        {0, 1, 0},
        {0, 0, 1},
        {1, 1, 1},
        {0, 0, 0}
    };

    // Print original board before applying rules.
    cout << "Original Board:\n";
    for (auto row : board) {
        for (auto cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }

    // Call the gameOfLife function to update the board.
    gameOfLife(board);

    // Print the board after applying Game of Life rules.
    cout << "\nNext State Board:\n";
    for (auto row : board) {
        for (auto cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }

    return 0; // End of program.
}
