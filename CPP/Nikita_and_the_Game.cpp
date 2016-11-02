/*
 * Nikita_and_the_Game.cpp
 *
 *  Created on: Nov 2, 2016
 *      Author: mohammra
 */

#include "common.h"

// using divide and conquer
#include <cmath>
#include <cstdio>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;

int solve_nikita(vector<int> A, int sum, int low, int high) {
    if (low == high) return 0;
    int i = low, partition = low;
    int part_sum = 0;
    while(i <= high && part_sum != sum - part_sum) {
        part_sum += A[i];
        partition = i++;
    }
    int left_part = 0, right_part = 0;
    if (part_sum == sum - part_sum) {
        left_part = solve_nikita(A, part_sum, low, partition);
        right_part = solve_nikita(A, part_sum, partition + 1, high);
        return max(left_part, right_part) + 1;
    } else {
        return 0;
    }
}

int main() {
    int T;
    cin >> T;
    while(T-- > 0){
        int N;
        cin >> N;
        vector<int> A(N);
        int sum = 0;
        for(int i = 0; i < N; i++) {
            cin >> A[i];
            sum += A[i];
        }
        cout << solve_nikita(A, sum, 0, N - 1) << endl;
    }
    return 0;
}
