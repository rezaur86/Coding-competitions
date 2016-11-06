/*
 * median_without_sorting.cpp
 *
 *  Created on: Nov 5, 2016
 *      Author: mohammra
 */

#include "common.h"


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int partition(vector<int>& a, int low, int high) {
    if (low >= high) return a[a.size() / 2];
    int i = low;
    int less_i = low;
    int pivot = a[high];
    while(i < high) {
        if (a[i] < pivot) {
            swap(a[less_i], a[i]);
            less_i++;
        }
        i++;
    }
    swap(a[high], a[less_i]);
    if (less_i < a.size() / 2) return partition(a, less_i + 1, high);
    else if (less_i > a.size() / 2) return partition(a, low, less_i - 1);
    else return a[a.size() / 2];
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << partition(a, 0, n - 1) << endl;
    return 0;
}
