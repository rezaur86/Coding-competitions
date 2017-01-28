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


class BinaryTrie {
public:
    BinaryTrie* children[2];
    bool isLeaf;
    BinaryTrie() {
        isLeaf = true;
        children[0] = NULL;
        children[1] = NULL;
    }
    
};

class trieNode {
public:
    int num_width = sizeof(int)*8;
    
    bool get_bit(int x, int i) {
        return (x & (1 << i)) != 0;
    }
    
    void set_bit(int& x, int i) {
        x = x | (1 << i);
    }

    void insert(BinaryTrie* root, int x) {
        BinaryTrie* p = root;
        for (int i = 0; i < num_width; i++) {
            if (get_bit(x, num_width - 1 - i)) {
                p->isLeaf = false;
                if (p->children[1] == NULL) {
                    BinaryTrie* temp = new BinaryTrie();
                    p->children[1] = temp;
                }
                p = p->children[1];
            }
            else {
                p->isLeaf = false;
                if (p->children[0] == NULL) {
                    BinaryTrie* temp = new BinaryTrie();
                    p->children[0] = temp;
                }
                p = p->children[0];
            }
        }
    }
    
    int findMaxXor(BinaryTrie* root, int x) {
        BinaryTrie* p = root;
        int max_xor = 0;
        for (int i = 0; i < num_width; i++) {
            if (get_bit(x, num_width - 1 - i)) {
                if (p->children[0] != NULL) {
                    p = p->children[0];
                    set_bit(max_xor, num_width - 1 - i);
                } else {
                    p = p->children[1];
                }
                
            } else {
                if (p->children[1] != NULL) {
                    p = p->children[1];
                    set_bit(max_xor, num_width - 1 - i);
                } else {
                    p = p->children[0];
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
        BinaryTrie* root = new BinaryTrie();
        trieNode tn;
        tn.insert(root, nums[0]);
        for(int i = 0; i < nums.size(); i++) {
            result = max(result, tn.findMaxXor(root, nums[i]));
            tn.insert(root, nums[i]);
        }
        return result;
    }
};
