//
//  battleship.cpp
//  Interview
//
//  Created by Mohammad Rahman on 10/16/16.
//  Copyright © 2016 Mohammad Rahman. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>
#include <cstdlib>
using namespace std;

class cell {
public:
    int row;
    int col;
    int dim_r;
    int dim_c;
    cell(int r, int c) {
        row = r;
        col = c;
    }
    cell top() {
        return cell(row - 1, col);
    }
    cell bottom() {
        return cell(row + 1, col);
    }
    cell left() {
        return cell(row, col - 1);
    }
    cell right() {
        return cell(row, col + 1);
    }
};

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        auto m = board.size();
        auto n = board[0].size();
        vector<vector<bool>> marked (m, vector<bool>(n, false));
        queue<cell> ships;
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!marked[i][j] && board[i][j] == '.') {
                    marked[i][j] = true;
                }
                if (!marked[i][j] && board[i][j] == 'X') {
                    ships.push(cell(i, j));
                    while(!ships.empty()) {
                        cell c = ships.front();
                        ships.pop();
                        marked[c.row][c.col] = true;
                        if (board[c.row][c.col] == 'X') {
                            if (c.row > 0 && !marked[c.top().row][c.top().col]) {
                                if (board[c.top().row][c.top().col] == 'X') {
                                    ships.push(c.top());
                                } else {
                                    marked[c.top().row][c.top().col] = true;
                                }
                            }
                            if (c.row < m - 1 && !marked[c.bottom().row][c.bottom().col]) {
                                if (board[c.bottom().row][c.bottom().col] == 'X') {
                                    ships.push(c.bottom());
                                } else {
                                    marked[c.bottom().row][c.bottom().col] = true;
                                }
                            }
                            if (c.col > 0 && !marked[c.left().row][c.left().col]) {
                                if (board[c.left().row][c.left().col] == 'X') {
                                    ships.push(c.left());
                                } else {
                                    marked[c.left().row][c.left().col] = true;
                                }
                            }
                            if (c.col < n - 1 && !marked[c.right().row][c.right().col]) {
                                if (board[c.right().row][c.right().col] == 'X') {
                                    ships.push(c.right());
                                } else {
                                    marked[c.right().row][c.right().col];
                                }
                            }
                        }
                    }
                    count++;
                }
                
            }
        }
        return count;
    }
};
