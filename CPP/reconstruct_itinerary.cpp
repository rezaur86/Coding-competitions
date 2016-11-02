/*
 * reconstruct_itinerary.cpp
 *
 *  Created on: Nov 1, 2016
 *      Author: mohammra
 */

#include "common.h"


class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        unordered_map<string, multiset<string>> adj;
        for(int i = 0; i < tickets.size(); i++) {
            if (adj.find(tickets[i].first) == adj.end()) {
                adj[tickets[i].first] = multiset<string>();
            }
            if (adj.find(tickets[i].second) == adj.end()) {
                adj[tickets[i].second] = multiset<string>();
            }
            adj[tickets[i].first].insert(tickets[i].second);
        }
        vector<string> res;
        visit(res, adj, "JFK");
        return vector <string>(res.rbegin(), res.rend());
    }

    void visit(vector<string>& res, unordered_map<string, multiset<string>>& adj, string city) {
        while(adj[city].size()) {
            string next = *adj[city].begin();
            adj[city].erase(adj[city].begin());
            visit(res, adj, next);
        }
        res.push_back(city);
    }
};
