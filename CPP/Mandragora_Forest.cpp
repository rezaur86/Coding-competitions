/*
 * Mandragora_Forest.cpp
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

long long int maximize_experience(vector<long long> H, long long sum) {
    sort(H.begin(), H.end());
    long long int max_exp = sum;
    long long int temp_exp;
    int s = 2;
    for(long i = 0; i < H.size(); i++) {
        sum -= H[i];
        temp_exp = sum * s;
        if (temp_exp >= max_exp) {
            max_exp = temp_exp;
            s++;
        } else break;
    }
    return max_exp;
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        long N;
        cin >> N;
        vector<long long> H(N);
        long long sum = 0;
        for (long i = 0; i < N; i++) {
            cin >> H[i];
            sum += H[i];
        }
        cout << maximize_experience(H, sum) << endl;
    }
    return 0;
}
