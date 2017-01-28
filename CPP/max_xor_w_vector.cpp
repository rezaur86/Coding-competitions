//
//  max_xor.cpp
//  Interview
//
//  Created by Mohammad Rahman on 10/16/16.
//  Copyright © 2016 Mohammad Rahman. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;


class trieNode {
public:
    const int num_width = sizeof(int)*8;
    vector<vector<int>> trie;
    
    trieNode() {
        trie.push_back(vector<int>(2, -1));
    }
    
    bool is_leaf(int node_n) {
        if (trie[node_n][0] != -1 && trie[node_n][1] != -1) return true;
        else return false;
    }
    
    bool has_child(int node_n, int child) {
        if (trie[node_n][child] != -1) return true;
        else return false;
    }
    
    int get_child(int node_n, int child) {
        return trie[node_n][child];
    }
    
    void set_new_child(int node_n, int child) {
        trie[node_n][child] = (int)trie.size();
        trie.push_back(vector<int>(2, -1));
    }
    
    bool get_bit(int x, int i) {
        return (x & (1 << i)) != 0;
    }
    
    void set_bit(int& x, int i) {
        x = x | (1 << i);
    }

    void insert(int x) {
        int p = 0;
        for (int i = 0; i < num_width; i++) {
            if (get_bit(x, num_width - 1 - i)) {
                if (!has_child(p, 1)){
                    set_new_child(p, 1);
                }
                p = get_child(p, 1);
            }
            else {
                if (!has_child(p, 0)){
                    set_new_child(p, 0);
                }
                p = get_child(p, 0);
            }
        }
    }
    
    int findMaxXor(int x) {
        int p = 0;
        int max_xor = 0;
        for (int i = 0; i < num_width; i++) {
            if (get_bit(x, num_width - 1 - i)) {
                if (has_child(p, 0)) {
                    p = get_child(p, 0);
                    set_bit(max_xor, num_width - 1 - i);
                } else {
                    p = get_child(p, 1);
                }
            } else {
                if (has_child(p, 1)) {
                    p = get_child(p, 1);
                    set_bit(max_xor, num_width - 1 - i);
                } else {
                    p = get_child(p, 0);
                }
            }
        }
        return max_xor;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        if (nums.empty()) return 0;
        int result = INT_MIN;
        trieNode tn;
        tn.insert(nums[0]);
        for(int i = 0; i < nums.size(); i++) {
            result = max(result, tn.findMaxXor(nums[i]));
            tn.insert(nums[i]);
        }
        return result;
    }
};
