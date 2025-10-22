#include<vector>
using namespace std;
class Solution {
public:
    int uniquePaths(int m, int n) {
        // start at 0, 0
        // at each point, try both going right and going down, if possible
        vector<vector<int>> memo(m, vector<int>(n, -1)); // makes mxn vector of all -1
        return pathsHelper(0, 0, m, n, memo);
    }

    int pathsHelper(int curM, int curN, int m, int n, vector<vector<int>>& memo) {
        if (curM == m - 1 && curN == n - 1) return 1;

        if (memo[curM][curN] != -1) return memo[curM][curN];

        int goRight = 0; 
        if (curM + 1 < m) goRight = pathsHelper(curM + 1, curN, m, n, memo);

        int goDown = 0;
        if (curN + 1 < n) goDown = pathsHelper(curM, curN + 1, m, n, memo);

        memo[curM][curN] = goRight + goDown;
        return goRight + goDown;
    }
};