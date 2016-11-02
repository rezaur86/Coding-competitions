/*
 * h_index.cpp
 *
 *  Created on: Nov 1, 2016
 *      Author: mohammra
 */

#import "common.h"

class Solution {
public:
    static bool compare(const int& i1, const int& i2) {
        return i2 < i1;
    }
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), compare);
        int h = 0;
        while(h < citations.size() && h + 1 <= citations[h]) h++;
        return h;
    }
};

