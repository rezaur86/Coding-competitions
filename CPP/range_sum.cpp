/*
 * range_sum.cpp
 *
 *  Created on: Nov 16, 2016
 *      Author: mohammra
 */

#include "common.h"


class segmentTree {
public:
    int num;
    int low;
    int high;
    segmentTree* left;
    segmentTree* right;
    segmentTree(int num, int low, int high) {
        this->num = num;
        this->low = low;
        this->high = high;
        this->left = NULL;
        this->right = NULL;
    }
};

class NumArray {
public:
    segmentTree* root;
    NumArray(vector<int> &nums) {
        if (!nums.empty())
            root = construct(nums, 0, nums.size() - 1);
    }

    segmentTree* construct(vector<int> nums, int low, int high){
        if (low == high) {
            segmentTree* n = new segmentTree(nums[low], low, high);
            cout << n->num << endl;
            return n;
        }
        int mid = (low + high) / 2;
        segmentTree* n = new segmentTree(nums[low], low, high);
        n->left = construct(nums, low, mid);
        n->right = construct(nums, mid + 1, high);
        n->num = n->left->num + n->right->num;
        return n;
    }

    void update(int i, int val) {
        updateHelper(root, i, val);
    }

    int updateHelper(segmentTree* r, int i, int val) {
        if (i == r->low && i == r->high) {
            int diff = val - r->num;
            r->num = val;
            return diff;
        } else if (i >= r->left->low && i <= r->left->high) {
            int diff = updateHelper(r->left, i, val);
            r->num += diff;
            return diff;
        } else {
            int diff = updateHelper(r->right, i, val);
            r->num += diff;
            return diff;
        }
    }

    int sumRange(int i, int j) {
        return sumRangeHelper(root, i, j);
    }

    int sumRangeHelper(segmentTree* r, int i, int j) {
        if (i == r->low && j == r->high) {
            return r->num;
        } else if (i >= r->left->low && j <= r->left->high) {
            return sumRangeHelper(r->left, i, j);
        } else if (i >= r->right->low && j <= r->right->high) {
            return sumRangeHelper(r->right, i, j);
        } else {
            return sumRangeHelper(r->left, i, r->left->high) + sumRangeHelper(r->right, r->right->low, j);
        }
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);
