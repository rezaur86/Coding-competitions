//
//  topo_sort.cpp
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

#define NOT_ORDERED 0
#define PARTIAL 1
#define ORDERED 2

bool dfs(vector<int> graph[], vector<int>& visited, int i){
    if (visited[i] == PARTIAL) return false; //found cycle
    if (visited[i] == NOT_ORDERED){
        visited[i] = PARTIAL;
        for(int v : graph[i]) {
            if (!dfs(graph, visited, v)) return false;
        }
        visited[i] = ORDERED;
    }
    return true;
}

int * topoSort(vector<int> graph[], int N)
{
    vector<int> visited(N, NOT_ORDERED);
    for(int i = 0; i < N; i++) {
        if (visited[i] == NOT_ORDERED) {
            if (!dfs(graph, visited, i)) return new int(0);
        }
    }
    return new int(1);
}

void topoSort_test(){
    vector<int> graph[8];
    int arr[] = {1,2,3,6,7};
    graph[0] = vector<int>(arr, arr+sizeof(arr)/sizeof(arr[0]));
    
    int arr1[] = {3,4};
    graph[1] = vector<int>(arr1, arr1+sizeof(arr1)/sizeof(arr1[0]));
    
    int arr2[] = {4,5};
    graph[2] = vector<int>(arr2, arr2+sizeof(arr2)/sizeof(arr2[0]));
    
    int arr3[] = {4};
    graph[3] = vector<int>(arr3, arr3+sizeof(arr3)/sizeof(arr3[0]));
    
    int arr4[] = {6,7};
    graph[4] = vector<int>(arr4, arr4+sizeof(arr4)/sizeof(arr4[0]));
    
    int arr5[] = {6};
    graph[5] = vector<int>(arr5, arr5+sizeof(arr5)/sizeof(arr5[0]));
    
    graph[6] = vector<int>();
    graph[7] = vector<int>();
    
    cout << "Topological sort " << (bool) *topoSort(graph, 8) << endl;
}
