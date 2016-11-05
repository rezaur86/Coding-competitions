/*
 * Unique_Binary_Search_Trees.cpp
 *
 *  Created on: Nov 4, 2016
 *      Author: mohammra
 */

#include "common.h"


class Solution {
public:
    int numTrees(int n) {
        int c[n];
        c[0] = 1;
        for (int i = 1; i < n; i++) {
            c[i] = 2 * c[i-1];
            for(int j = i - 2; j >= 0; j--) {
                c[i] += c[j] * c[i - 2 - j];
            }
        }
        return c[n - 1];
    }
};
