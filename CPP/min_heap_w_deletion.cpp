/*
 * min_heap_w_deletion.cpp
 *
 *  Created on: Nov 15, 2016
 *      Author: mohammra
 */

#include "common.h"


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class my_heap {
public:
    vector<int> heap;

    my_heap() {
        heap = vector<int>(1, -1);
    }

    void add(int el) {
        heap.push_back(el);
        int el_idx = heap.size() - 1;
        int parent_idx = el_idx / 2;
        while(parent_idx != 0 && heap[parent_idx] > el) {
            swap(heap[parent_idx], heap[el_idx]);
            el_idx = parent_idx;
            parent_idx = el_idx / 2;
        }
    }

    void remove(int el) {
        int el_idx = 0;
        for(auto it = heap.begin(); it < heap.end(); it++) {
            if (*it == el) break;
            el_idx++;
        }
        heap[el_idx] = heap[heap.size() - 1];
        heap.pop_back();
        int parent_idx = el_idx / 2;
        while(parent_idx != 0 && heap[parent_idx] > el) {
            // traverse upward to find right position
            // If only min element deletion was allowed this part
            // was not necessary.
            swap(heap[parent_idx], heap[el_idx]);
            el_idx = parent_idx;
            parent_idx = el_idx / 2;
        }
        int left_idx = el_idx * 2;
        int right_idx = el_idx * 2 + 1;
        while(left_idx < heap.size() && right_idx < heap.size()) {
            // traverse downward if needed to find right position
            if (heap[el_idx] <= heap[left_idx] && heap[el_idx] <= heap[right_idx]) {
                // No need to traverse dowanward
                break;
            } else {
                if (heap[left_idx] <= heap[right_idx]) {
                    // Left child has the minimum
                    swap(heap[el_idx], heap[left_idx]);
                    el_idx = left_idx;
                } else {
                    // right child has the minimum
                    swap(heap[el_idx], heap[right_idx]);
                    el_idx = right_idx;
                }
                left_idx = el_idx * 2;
                right_idx = el_idx * 2 + 1;
            }
        }
    }

    void print () {
        cout << heap[1] << endl;
    }
};

int main() {
    int Q;
    cin >> Q;
    int choice, v;
    my_heap h;
    while(Q--){
        cin >> choice;
        switch(choice) {
            case 1:
                cin >> v;
                h.add(v);
                break;
            case 2:
                cin >> v;
                h.remove(v);
                break;
            case 3:
                h.print();
                break;
        }
    }
    return 0;
}
