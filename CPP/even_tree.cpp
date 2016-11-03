/*
 * even_tree.cpp
 *
 *  Created on: Nov 3, 2016
 *      Author: mohammra
 */

#include "common.h"


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Graph {
public:
    int N;
    vector<vector<int>> adj;
    vector<bool> visited;
    Graph(int n) {
        N = n;
        adj = vector<vector<int>>(N, vector<int>());
        visited = vector<bool>(N, false);
    }

    void add_edge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int even_tree(int root, int& size) {
        visited[root] = true;
        if(adj[root].empty()) {
            size++;
            return 0;
        }
        int even_tree_count = 0;
        for(int v : adj[root]) {
            if(!visited[v]) {
                int temp_size = 0;
                even_tree_count += even_tree(v, temp_size);
                if (temp_size % 2 == 0) {
                    even_tree_count++;
                }
                size += temp_size;
            }
        }
        size++;
        return even_tree_count;
    }
};

int main() {
    int N, M;
    cin >> N >> M;
    Graph g(N);
    for(int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        g.add_edge(--u, --v);
    }
    int size = 0;
    cout << g.even_tree(0, size) << endl;
    return 0;
}
