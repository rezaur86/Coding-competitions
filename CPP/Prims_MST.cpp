/*
 * Prims_MST.cpp
 *
 *  Created on: Nov 2, 2016
 *      Author: mohammra
 */

#include "common.h"


#include <cmath>
#include <cstdio>
#include <climits>
#include <vector>
#include <unordered_map>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int, int> ipair;

class compare {
public:
    bool operator()(ipair p1, ipair p2){
        return p1.second > p2.second;
    }
};

class Graph {
public:
    int N;
    vector<unordered_map<int, int>> adj;
    Graph(int n) {
        N = n;
        adj = vector<unordered_map<int, int>>(N, unordered_map<int, int>());
    }

    void add_edge(int u, int v, int w) {
        if(adj[u].find(v) == adj[u].end()) adj[u][v] = w;
        else if (adj[u][v] > w) {
            adj[u][v] = w;
        }
        if(adj[v].find(u) == adj[v].end()) adj[v][u] = w;
        else if (adj[v][u] > w) {
            adj[v][u] = w;
        }
    }

    int prim(int source) {
        vector<int> edge_weights(N, INT_MAX);
        edge_weights[source] = 0;
        priority_queue<ipair, vector<ipair>, compare> pq;
        vector<bool> finished (N, false);
        pq.push(make_pair(source, 0));
        int sum = 0;
        while(!pq.empty()) {
            while(!pq.empty() && finished[pq.top().first]) pq.pop();
            if (pq.empty()) break;
            int u = pq.top().first;
            int du = pq.top().second;
            sum += du;
            finished[u] = true;
            pq.pop();
            for(auto p : adj[u]) {
                int v = p.first;
                int w = p.second;
                if (!finished[v] && edge_weights[v] > w) {
                    edge_weights[v] = w;
                    pq.push(make_pair(v, edge_weights[v]));
                }
            }
        }
        return sum;
    }
};

int main() {
    int N, M;
    cin >> N >> M;
    Graph g(N);
    for(int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g.add_edge(--u, --v, w);
    }
    int s;
    cin >> s;
    cout << g.prim(--s) << endl;
    return 0;
}
