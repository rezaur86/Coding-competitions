/*
 * trapping_rain_water.cpp
 *
 *  Created on: Nov 15, 2016
 *      Author: mohammra
 */

#include "common.h"


class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> s;
        int rain = 0;
        int l = 0, r = height.size() - 1, h = 0;
        while(l < r) {
            h = max(h, min(height[l], height[r]));
            if (height[l] <= height[r]) {
                rain += h > height[l] ? h - height[l] : 0;
                l++;
            } else {
                rain += h > height[r] ? h - height[r] : 0;
                r--;
            }
        }
        return rain;
    }
};
