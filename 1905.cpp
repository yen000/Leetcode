// 2024.08.28

// 1905. Count Sub Islands (Medium)
// You are given two m x n binary matrices grid1 and grid2 containing only 0's (representing water) and 1's (representing land). 
// An island is a group of 1's connected 4-directionally (horizontal or vertical). Any cells outside of the grid are considered water cells.
// An island in grid2 is considered a sub-island if there is an island in grid1 that contains all the cells that make up this island in grid2.
// Return the number of islands in grid2 that are considered sub-islands.

// Time Complexity: O(row*col) -> dfs method

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) 
    {
        int cnt = 0; // number of sub-island 
        int row = grid1.size(), col = grid1[0].size();

        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                if(grid2[i][j] == 1 && grid1[i][j] == 1) // if is an island then so dfs function
                {
                    bool check = true; // to check if is grid 1's sub-island
                    dfs(i, j, row, col, grid1, grid2, check);
                    if(check)
                        cnt++;
                }
            }
        }
        
        return cnt;
    }

    void dfs(int i, int j, int row, int col, vector<vector<int>>& grid1, vector<vector<int>>& grid2, bool& check)
    {
        if(i<0 || j<0 || i>=row || j>=col || grid2[i][j]!=1) // to find complete island of grid2
            return;
        
        if(grid1[i][j] == 0) // to check if is grid 1's sub-island
        {
            check = false;
            return;
        }
        
        grid2[i][j] = 0; // to make visited marks

        // recursive go through four direction
        dfs(i+1, j, row, col, grid1, grid2, check);
        dfs(i, j+1, row, col, grid1, grid2, check);
        dfs(i-1, j, row, col, grid1, grid2, check);
        dfs(i, j-1, row, col, grid1, grid2, check);
    }
};