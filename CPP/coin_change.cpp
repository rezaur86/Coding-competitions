/*
 * coin_change.cpp
 *
 *  Created on: Nov 3, 2016
 *      Author: mohammra
 */

#include "common.h"


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long int coin_change(vector<int> C, int N) {
    sort(C.begin(), C.end());
    long long int dp[C.size() + 1][N + 1];
    for(int i = 0; i <= N; i++) {
        dp[0][i] = 0;
    }
    for(int i = 1; i <= C.size(); i++) {
        for(int j = 0; j <= N; j++){
            if (j == 0) dp[i][j] = 1;
            else if (j < C[i - 1]) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = dp[i - 1][j] + dp[i][j - C[i - 1]];
            }
        }
    }
    return dp[C.size()][N];
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> C (M);
    for(int i = 0; i < M; i++) {
        cin >> C[i];
    }
    cout << coin_change(C, N) << endl;
    return 0;
}
