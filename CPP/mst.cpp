//
//  mst.cpp
//  Interview
//
//  Created by Mohammad Rahman on 10/20/16.
//  Copyright © 2016 Mohammad Rahman. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <cstdlib>
using namespace std;

/* Finds the sum of weights of the edges of the Minimum Spanning Tree.
 Graph is represented as adjacency list using array of vectors.  MAX
 is an upper  limit on number of vertices.
 g[u] represents adjacency list of vertex u,  Every element of this list
 is a pair<w,v>  where v is another vertex and w is weight of edge (u, v)
 Note : Vertex numbers start with 1 and don't need to be contiguous.   */

typedef bool(*compareFunc)(pair<int, int>, pair<int, int>);
bool compare(pair<int, int> p1, pair<int, int> p2) {
    return p1.first < p2.first;
}

int spanningTree(vector <pair<int,int> > g[], int MAX)
{
    int sum = 0;
    unordered_map<int, int> visited;
    for(int i = 0; i < MAX; i++) {
        visited[i] = false;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, compareFunc> pq(compare);
    for(int i = 0; i < g[0].size(); i++) {
        pq.push(g[0][i]);
    }
    int i = 0;
    while(i++ < MAX) {
        pair<int, int> edge = pq.top();
        pq.pop();
        int v = edge.second;
        sum += edge.first;
        visited[v] = true;
        for (pair<int, int> p: g[v]){
            if (visited[p.second] == false) {
                pq.push(p);
            }
        }
    }
    return sum;
}
