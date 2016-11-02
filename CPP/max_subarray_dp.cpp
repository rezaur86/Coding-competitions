// Using dynamic Programming
#include <cmath>
#include <cstdio>
#include <climits>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int max_subarray(vector<int> A) {
    int dp[A.size()];
    dp[0] = A[0];
    for (int i = 1; i < A.size(); i++) {
        dp[i] = max(dp[i-1] + A[i], A[i]);
    }
    int max = INT_MIN;
    for (int i = 0; i < A.size(); i++) {
        if (max < dp[i]) max = dp[i];
    }
    return max;
}

int max_non_contiguous_subarray(vector<int> A) {
    int dp[A.size()];
    dp[0] = A[0];
    for (int i = 1; i < A.size(); i++) {
        dp[i] = max(max(dp[i-1], dp[i-1] + A[i]), A[i]);
    }
    return dp[A.size() - 1];
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    cout << "enter" << endl;
    cin >> T;
    while(T-- > 0){
        int N;
        cin >> N;
        vector<int> A(N);
        for(int i = 0; i < N; i++) {
            cin >> A[i];
        }
        cout << max_subarray(A) << " " << max_non_contiguous_subarray(A) << endl;
    }
    return 0;
}
