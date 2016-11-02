/*
 * course_schedule.cpp
 *
 *  Created on: Nov 1, 2016
 *      Author: mohammra
 */

#include "common.h"


class Solution {
public:
    vector<vector<int>> adj;
    vector<int> visited;
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        adj = vector<vector<int>>(numCourses, vector<int>());
        visited = vector<int>(numCourses, 0);
        for(auto p : prerequisites) {
            adj[p.first].push_back(p.second);
        }
        for(int i = 0; i < numCourses; i++) {
            if (visited[i] == 0) {
                if (!dfs(i)) return false;
            }
        }
        return true;
    }

    bool dfs(int course) {
        visited[course] = 1;
        for(int c : adj[course]) {
            if (visited[c] == 1) return false;
            if (visited[c] == 0) {
                if (!dfs(c)) return false;
            }
        }
        visited[course] = 2;
        return true;
    }
};
