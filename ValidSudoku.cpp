#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int getBoxNum(int i, int j) {
        int row, col;
        if (i < 3) {row = 0;}
        else if (i < 6) {row = 1;}
        else row = 2;

        if (j < 3) col = 0;
        else if (j < 6) col = 1;
        else col = 2;

        int index = (row * 3) + col;
        return index;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        // iterate through whole vector
        // use a set to track each row and check for duplicates
        // use 9 sets to track columns
        // use 9 sets to track squares

        int rows = board.size();
        int cols = board[0].size();

        vector<set<char>>colVec(9);
        vector<set<char>>boxVec(9);

        for (int i = 0; i < rows; i++) {
            set<char> rowSet; // can simply reuse this for every row
            for (int j = 0; j < cols; j++) {
                // check if board[i][j] is already in any relevant set, return false if so
                char currChar = board[i][j];
                if (currChar == '.') {
                    continue; // empty square, does not need to be validated
                }
                if (
                    rowSet.count(currChar) > 0 ||
                    colVec[j].count(currChar) > 0 ||
                    boxVec[getBoxNum(i, j)].count(currChar) > 0
                ) {
                    return false;
                }
                // add board[i][j] to all relevant sets 
                rowSet.insert(currChar);
                colVec[j].insert(currChar);
                boxVec[getBoxNum(i, j)].insert(currChar);
            }
        }

        return true;
    }
};