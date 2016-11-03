/*
 * BFS_Shortest_Reach.cpp
 *
 *  Created on: Nov 2, 2016
 *      Author: mohammra
 */

#include "common.h"


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

class Graph {
    public:
        vector<vector<int>> adj;
        vector<int> distance;
        Graph(int n) {
            adj = vector<vector<int>>(n, vector<int>());
            distance = vector<int>(n, -1);
        }

        void add_edge(int u, int v) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> shortest_reach(int start) {
            do_bfs(start);
            return distance;
        }

        void do_bfs(int start) {
            queue<int> q;
            q.push(start);
            distance[start] = 0;
            while(!q.empty()){
                int n = q.front();
                q.pop();
                for(int i = 0; i < adj[n].size(); i++) {
                    if (distance[adj[n][i]] == -1) {
                        q.push(adj[n][i]);
                        distance[adj[n][i]] = distance[n] + 6;
                    }
                }
            }
        }
};

int main() {
    int queries;
    cin >> queries;

    for (int t = 0; t < queries; t++) {

      int n, m;
        cin >> n;
        // Create a graph of size n where each edge weight is 6:
        Graph graph(n);
        cin >> m;
        // read and set edges
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            // add each edge to the graph
            graph.add_edge(u, v);
        }
      int startId;
        cin >> startId;
        startId--;
        // Find shortest reach from node s
        vector<int> distances = graph.shortest_reach(startId);

        for (int i = 0; i < distances.size(); i++) {
            if (i != startId) {
                cout << distances[i] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
