/*
 * q_sort_and_insertion_sort_compare.cpp
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

int partition(vector<int>& a, int& swap_count, int low, int high) {
    int i = low;
    int pivot = a[high];
    while(i < high) {
        if (a[i] < pivot) {
            swap(a[low], a[i]);
            swap_count++;
            low++;
        }
        i++;
    }
    swap(a[high], a[low]);
    swap_count++;
    return low;
}

void quick_sort(vector<int>& a, int& swap_count, int low, int high) {
    if (low >= high) return;
    int i = partition(a, swap_count, low, high);
    quick_sort(a, swap_count, low, i - 1);
    quick_sort(a, swap_count, i + 1, high);
}

void quick_sort_helper(vector<int> a, int& swap_count) {
    quick_sort(a, swap_count, 0, a.size() - 1);
}

void insertions_sort(vector<int>& a, int& shift_count) {
    for(int i = 1; i < a.size(); i++) {
        int j = i;
        int val = a[j--];
        while(j >= 0 && a[j] > val) {
            a[j + 1] = a[j--];
            shift_count++;
        }
        a[j + 1] = val;
    }
}
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int swap_count = 0;
    int shift_count = 0;
    quick_sort_helper(a, swap_count);
    insertions_sort(a, shift_count);
    cout << shift_count - swap_count << endl;
    return 0;
}
