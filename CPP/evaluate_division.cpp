/*
 * evaluate_division.cpp
 *
 *  Created on: Nov 1, 2016
 *      Author: mohammra
 */

#include "common.h"


class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        unordered_map<string, int> variables;
        int v = 0;
        for (int i = 0; i < equations.size(); i++) {
            if (variables.find(equations[i].first) == variables.end()) variables[equations[i].first] = v++;
            if (variables.find(equations[i].second) == variables.end()) variables[equations[i].second] = v++;
        }
        double adj[variables.size()][variables.size()];
        for (int i = 0; i < variables.size(); i++) {
            for (int j = 0; j < variables.size(); j++) {
                adj[i][j] = -1.0;
            }
        }

        for (int i = 0; i < equations.size(); i++) {
            int idx = variables[equations[i].first];
            int idy = variables[equations[i].second];
            adj[idx][idx] = 1;
            adj[idy][idy] = 1;
            adj[idx][idy] = values[i];
            adj[idy][idx] = 1 / values[i];
        }

        for (int k = 0; k < variables.size(); k++) {
            for (int i = 0; i < variables.size(); i++) {
                for (int j = 0; j < variables.size(); j++) {
                    if (adj[i][k] != -1.0 && adj[k][j] != -1.0) {
                        adj[i][j] = adj[i][k]*adj[k][j];
                    }
                }
            }
        }

        vector<double> res;
        for (int i = 0; i < queries.size(); i++) {
            int idx = variables.find(queries[i].first) == variables.end() ? -1 : variables[queries[i].first];
            int idy = variables.find(queries[i].second) == variables.end() ? -1 : variables[queries[i].second];
            if (idx != -1 && idy != -1) res.push_back(adj[idx][idy]);
            else res.push_back(-1.0);
        }

        return res;
    }
};
