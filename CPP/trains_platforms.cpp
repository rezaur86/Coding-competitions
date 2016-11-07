/*
 * trains_platforms.cpp
 *
 *  Created on: Nov 6, 2016
 *      Author: mohammra
 */

#include "common.h"


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int findMinGates(vector < int > arrivals, vector < int > departures, int flights) {
    sort(departures.begin(), departures.end());
    int max = 0;
    int gate = 0;
    vector<int> s;
    int i = 0, j = 0;
    while(i < arrivals.size() ||  j < departures.size()) {
        if (i < arrivals.size() && arrivals[i] <= departures[j]) {
            gate++;
            i++;
        }
        else {
            gate--;
            j++;
        }
        if (max < gate) max = gate;
    }
    return max;
}


int main() {
    int N;
    cin >> N;
    vector<int> arrivals(N), departures(N);
    for(int i = 0; i < N; i++) {
        cin >> arrivals[i] >> departures[i];
    }
    cout << findMinGates(arrivals, departures, N) << endl;
    return 0;
}
