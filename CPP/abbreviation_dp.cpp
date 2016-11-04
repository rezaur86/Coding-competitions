/*
 * abbreviation_dp.cpp
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

bool abbreviate(string a, string b) {
    bool m[b.size() + 1][a.size() + 1];
    m[0][0] = true;
    for(int j = 1; j <= a.size(); j++) {
        if (a[j - 1] >= 'A' && a[j - 1] <= 'Z') m[0][j] = false;
        else m[0][j] = m[0][j - 1];
    }
    for(int i = 1; i <= b.size(); i++) {
        for(int j = 0; j <= a.size(); j++) {
            if (j == 0) {
                m[i][j] = false;
                continue;
            }
            if (toupper(a[j - 1]) == b[i - 1]) {
                m[i][j] =  m[i - 1][j - 1] | m[i][j - 1];
            } else if (a[j - 1] >= 'a' && a[j - 1] <= 'z') {
                m[i][j] =  m[i][j - 1];
            } else {
                m[i][j] =  false;
            }
        }
    }
    return m[b.size()][a.size()];
}


int main() {
    int q;
    cin >> q;
    while(q--) {
        string a, b;
        cin >> a >> b;
        string out = abbreviate(a, b) ? "YES" : "NO";
        cout << out << endl;
    }
    return 0;
}
