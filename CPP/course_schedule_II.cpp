/*
 * course_schedule_II.cpp
 *
 *  Created on: Nov 1, 2016
 *      Author: mohammra
 */

#include "common.h"


class Solution {
public:
vector<vector<int>> adj;
    vector<int> visited;
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> res;
        adj = vector<vector<int>>(numCourses, vector<int>());
        visited = vector<int>(numCourses, 0);
        for(auto p : prerequisites) {
            adj[p.first].push_back(p.second);
        }
        for(int i = 0; i < numCourses; i++) {
            if (visited[i] == 0) {
                if (!dfs(i, res)) return vector<int>();
            }
        }
        return res;
    }

    bool dfs(int course, vector<int>& res) {
        visited[course] = 1;
        for(int c : adj[course]) {
            if (visited[c] == 1) return false;
            if (visited[c] == 0) {
                if (!dfs(c, res)) return false;
            }
        }
        visited[course] = 2;
        res.push_back(course);
        return true;
    }
};
