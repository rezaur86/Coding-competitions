// Using divide and conquer
#include <cmath>
#include <cstdio>
#include <climits>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int max_cross_subarray(vector<int> A, int& left_idx, int& right_idx) {
    int mid = (left_idx + right_idx) / 2;
    int max_left = INT_MIN;
    int sum = 0;
    int i = mid;
    int low = left_idx;
    while(i >= low) {
        sum += A[i];
        if (max_left < sum) {
            max_left = sum;
            left_idx = i;
        }
        i--;
    }
    int max_right = INT_MIN;
    sum = 0;
    int j = mid + 1;
    int high = right_idx;
    while(j <= high) {
        sum += A[j];
        if (max_right < sum) {
            max_right = sum;
            right_idx = j;
        }
        j++;
    }
    return max(max(max_left, max_right), max_left + max_right);
}

int max_subarray(vector<int> A, int& low, int& high) {
    if(low >= high) return A[low];
    int mid = (low + high) / 2;
    int left_sub_low = low, left_sub_high = mid;
    int left_max = max_subarray(A, left_sub_low, left_sub_high);
    int right_sub_low = mid + 1, right_sub_high = high;
    int right_max = max_subarray(A, right_sub_low, right_sub_high);
    int left_idx = low, right_idx = high;
    int cross_max = max_cross_subarray(A, left_idx, right_idx);
    int sub_max = INT_MIN;
    if (sub_max < left_max) {
        sub_max = left_max;
        low = left_sub_low;
        high = left_sub_high;
    }
    if (sub_max < right_max) {
        sub_max = right_max;
        low = right_sub_low;
        high = right_sub_high;
    }
    if (sub_max < cross_max) {
        sub_max = cross_max;
        low = left_idx;
        high = right_idx;
    }
    return sub_max;
}

int max_non_contiguous_subarray(vector<int> A, int& low, int& high) {
    if(low >= high) return A[low];
    int mid = (low + high) / 2;
    int left_sub_low = low, left_sub_high = mid;
    int left_max = max_non_contiguous_subarray(A, left_sub_low, left_sub_high);
    int right_sub_low = mid + 1, right_sub_high = high;
    int right_max = max_non_contiguous_subarray(A, right_sub_low,
    		right_sub_high);
    return (max(max(left_max, right_max), left_max + right_max));
}

int test() {
    int T;
    cin >> T;
    while(T-- > 0){
        int N;
        cin >> N;
        vector<int> A(N);
        for(int i = 0; i < N; i++) {
            cin >> A[i];
        }
        int low = 0;
        int high = N - 1;
        cout << max_subarray(A, low, high) << " "
        		<< max_non_contiguous_subarray(A, low, high) << endl;
    }
    return 0;
}
