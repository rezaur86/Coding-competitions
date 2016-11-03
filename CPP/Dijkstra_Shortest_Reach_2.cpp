/*
 * Dijkstra_Shortest_Reach_2.cpp
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
    vector<int> shortest_path;
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

    void dijkstra(int source) {
        shortest_path = vector<int>(N, INT_MAX);
        shortest_path[source] = 0;
        priority_queue<ipair, vector<ipair>, compare> pq;
        vector<bool> finished (N, false);
        pq.push(make_pair(source, 0));
        while(!pq.empty()) {
            while(!pq.empty() && finished[pq.top().first]) pq.pop();
            if (pq.empty()) break;
            int u = pq.top().first;
            int du = pq.top().second;
            pq.pop();
            for(auto p : adj[u]) {
                int v = p.first;
                int w = p.second;
                if (shortest_path[v] > shortest_path[u] + w) {
                    shortest_path[v] = shortest_path[u] + w;
                    pq.push(make_pair(v, shortest_path[v]));
                }
            }
        }
    }

    void print_shorted_path(int source) {
        for(int i = 0; i < N; i++) {
            if (i != source) {
                if (shortest_path[i] == INT_MAX) shortest_path[i] = -1;
                cout << shortest_path[i] << " ";
            }
        }
        cout << endl;
    }
};

int main() {
    int T;
    cin >> T;
    while(T--) {
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
        g.dijkstra(--s);
        g.print_shorted_path(s);
    }
    return 0;
}
