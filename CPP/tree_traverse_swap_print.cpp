/*
 * tree_traverse_swap_print.cpp
 *
 *  Created on: Nov 7, 2016
 *      Author: mohammra
 */

#include "common.h"


#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int, int> ipair;

void print_inorder(vector<ipair> tree, int root) {
    //cout << tree[root].first << " " << tree[root].second << endl;
    if (tree[root].first != -1) print_inorder(tree, tree[root].first);
    cout << root + 1 << " ";
    if (tree[root].second != -1) print_inorder(tree, tree[root].second);
}

vector<vector<int>> get_level_order(vector<ipair> tree, int root) {
    queue<ipair> q;
    q.push(make_pair(root, 0));
    vector<vector<int>> levels;
    int n, l;
    while(!q.empty()) {
        n = q.front().first;
        l = q.front().second;
        if (levels.size() < l + 1) levels.push_back(vector<int>());
        levels[l].push_back(n);
        q.pop();
        if (tree[n].first != -1) q.push(make_pair(tree[n].first, l + 1));
        if (tree[n].second != -1) q.push(make_pair(tree[n].second, l + 1));
    }
    return levels;
}

void swap_tree(vector<ipair>& tree, int root, int k) {
    vector<vector<int>> levels = get_level_order(tree, root);
    int l = k;
    while(l <= levels.size()) {
        for(int n : levels[l - 1]) {
            swap(tree[n].first, tree[n].second);
        }
        l = l + k;
    }
}

int main() {
    int N;
    cin >> N;
    vector<ipair> tree (N);
    for(int i = 0; i < N; i++) {
        cin >> tree[i].first >> tree[i].second;
        if (tree[i].first > 0) tree[i].first--;
        if (tree[i].second > 0) tree[i].second--;
    }
    int T;
    cin >> T;
    int k;
    while(T-- > 0) {
        cin >> k;
        swap_tree(tree, 0, k);
        print_inorder(tree, 0);
        cout << endl;
    }
    return 0;
}
