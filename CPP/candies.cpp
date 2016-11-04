/*
 * candies.cpp
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

long long int minimize_candies(vector<int> rating) {
    long long int candies[rating.size()];
    candies[0] = 1;
    long long int total = 1;
    for(int i = 1; i < rating.size(); i++) {
        if (rating[i - 1] < rating[i]) {
            candies[i] = candies[i - 1] + 1;
        } else {
            candies[i] = 1;
        }
        total += candies[i];
    }
    for(int i = rating.size() - 2; i >= 0; i--) {
        if (rating[i] > rating[i + 1] && candies[i + 1] >= candies[i]) {
            int temp = candies[i];
            candies[i] = candies[i + 1] + 1;
            total += (candies[i] - temp);
        }
    }
    return total;
}

int main() {
    int N;
    cin >> N;
    vector<int> rating(N);
    for(int i = 0; i < N; i++) {
        cin >> rating[i];
    }
    cout << minimize_candies(rating) << endl;
    return 0;
}
