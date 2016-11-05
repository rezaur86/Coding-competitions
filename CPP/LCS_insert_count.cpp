/*
 * Longest_common_subsequence.cpp
 *
 *  Created on: Nov 4, 2016
 *      Author: mohammra
 */

#include "common.h"


#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

int LCS_insert_count(string a, string b) {
    auto m = b.size();
    auto n = a.size();
    int dp[m + 1][n + 1];
    dp[0][0] = 0;
    for (int j = 1; j <= n; j++) {
        dp[0][j] = j;
    }
    for (int i = 1; i <= m; i++) {
        dp[i][0] = i;
    }
    int c_min;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (b[i-1] == a[j-1]) {
                c_min = dp[i-1][j-1];
                if(c_min > dp[i][j-1] + 1) c_min = dp[i][j-1] + 1;
                if(c_min > dp[i-1][j] + 1) c_min = dp[i-1][j] + 1;
                dp[i][j] = c_min;
            } else {
                dp[i][j] = min(dp[i][j-1] + 1, dp[i-1][j] + 1);
            }
        }
    }
    int i, j;
    int c_i = 0; // count the inserts
    vector<vector<bool>> visited (m + 1, vector<bool>(n + 1, false));
    queue<pair<int,int>> p_idx;
    p_idx.push(make_pair(m, n));
    while(!p_idx.empty()) {
        i = p_idx.front().first;
        j = p_idx.front().second;
        //cout << i << " " << j << endl;
        p_idx.pop();
        if (!visited[i][j]) visited[i][j] = true;
        else continue;
        if (i > 0 && j > 0 && !visited[i-1][j-1]
            && dp[i-1][j-1] == dp[i][j]) p_idx.push(make_pair(i-1, j-1));
        if (i > 0 && !visited[i-1][j] && dp[i-1][j] + 1 == dp[i][j]) {
            c_i++;
            p_idx.push(make_pair(i-1, j));
        }
    }
    return c_i;
}

int main() {
    string a, b;
    cin >> a >> b;
    cout << LCS_insert_count(a, b) << endl;
    return 0;
}
