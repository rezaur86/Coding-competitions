//
//  surrounded_region.cpp
//  Interview
//
//  Created by Mohammad Rahman on 10/13/16.
//  Copyright © 2016 Mohammad Rahman. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

class Solution {
    
public:    
    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;
        long m = board.size();
        long n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n , false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j])
                    visit(board, visited, i, j);
            }
        }
    }
    
    void visit(vector<vector<char>>& board, vector<vector<bool>>& visited, long i, long j) {
        if (board.empty()) return;
        long m = board.size();
        long n = board[0].size();
        if (!(i >= 0 && i < m && j >= 0 && j < n)) return;
        visited[i][j] = true;
        if (board[i][j] == 'X') {
            return;
        } else if (!(i > 0 && i < m - 1 && j > 0 && j < n - 1)) {
            return;
        } else {
            board[i][j] = 'P';
            if (!visited[i][j - 1] ) visit(board, visited, i, j - 1);
            if (!visited[i][j + 1] ) visit(board, visited, i, j + 1);
            if (!visited[i - 1][j] ) visit(board, visited, i - 1, j);
            if (!visited[i + 1][j] ) visit(board, visited, i + 1, j);
            if ((board[i][j - 1] == 'X' || board[i][j - 1] == 'P')
                && (board[i][j + 1] == 'X' || board[i][j + 1] == 'P')
                && (board[i - 1][j] == 'X' || board[i - 1][j] == 'P')
                && (board[i + 1][j] == 'X' || board[i + 1][j] == 'P')) {
                board[i][j] = 'X';
            } else {
                board[i][j] = 'O';
            }
        }
    }
};
