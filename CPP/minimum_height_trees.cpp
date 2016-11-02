/*
 * minimum_height_trees.cpp
 *
 *  Created on: Nov 1, 2016
 *      Author: mohammra
 */

#include "common.h"


class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<set<int>> adj(n, set<int>());
        vector<int> degrees(n, 0);
        for(int i = 0; i < edges.size(); i++){
            adj[edges[i].first].insert(edges[i].second);
            adj[edges[i].second].insert(edges[i].first);
            degrees[edges[i].first]++;
            degrees[edges[i].second]++;
        }
        vector<int> leaves;
        for(int i = 0; i < degrees.size(); i++) {
            if (degrees[i] <= 1) leaves.push_back(i);
        }

        set<int> temp;
        while(n > 2) {
            n -= leaves.size();
            for(int l : leaves) {
                degrees[l]--;
                int next = *adj[l].begin();
                degrees[next]--;
                adj[l].clear();
                adj[next].erase(adj[next].find(l));
                if (degrees[next] <= 1) temp.insert(next);
            }
            leaves.clear();
            leaves= vector<int>(temp.begin(), temp.end());
            temp.clear();
        }
        return leaves;
    }
};
