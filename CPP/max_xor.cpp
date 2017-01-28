//
//  max_xor.cpp
//  Interview
//
//  Created by Mohammad Rahman on 10/16/16.
//  Copyright © 2016 Mohammad Rahman. All rights reserved.
//

#include <iostream>
#include <unordered_set>
#include <vector>
#include <cstdlib>
using namespace std;


class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        if(nums.empty()) return 0;
        int max = 0;
        int mask = 0;
        int num_width = sizeof(int)*8;
        unordered_set<int> s;
        for (int i = num_width - 1; i >= 0; i--) {
            s.clear();
            mask = mask | (1 << i);
            for (int j = 0; j < nums.size(); j++) {
                s.insert(nums[j] & mask);
            }
            int temp = max | (1 << i);
            for (int x : s){
                if (s.find(x ^ temp) != s.end()) {
                    max = temp;
                    break;
                }
            }
        }
        return max;
    }
};

