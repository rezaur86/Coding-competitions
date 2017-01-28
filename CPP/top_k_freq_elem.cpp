//
//  top_k_freq_elem.cpp
//  Interview
//
//  Created by Mohammad Rahman on 10/19/16.
//  Copyright © 2016 Mohammad Rahman. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>
#include <cstdlib>
using namespace std;

class compareMap {
public:
    bool operator() (const pair<int, int>& p1, const pair<int, int>& p2) {
        return p1.second < p2.second;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            if (m.find(nums[i]) != m.end()) {
                m[nums[i]]++;
            } else{
                m[nums[i]] = 0;
            }
        }
        priority_queue <pair<int, int>, vector<pair<int, int>>, compareMap> pq;
        for(pair<int, int> p : m) {
            pq.push(p);
        }
        vector<int> res;
        for(int i = 0; i < k; i++) {
            res.push_back(pq.top().first);
            pq.pop();
        }
        return res;
    }
};
