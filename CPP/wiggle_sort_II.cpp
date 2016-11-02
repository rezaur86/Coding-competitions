class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        auto n = nums.size();
        auto mid_it = nums.begin() + n / 2;
        nth_element(nums.begin(), mid_it, nums.end());
        auto mid = *mid_it;

        #define A(i) nums[(2 * i + 1) % (n | 1)]

        // three way partitioning
        int bottom = 0, i = 0, top = n - 1;
        while(i <= top) {
            if (A(i) > mid) {
                swap(A(i), A(bottom));
                bottom++;
                i++;
            } else if (A(i) < mid) {
                swap(A(i), A(top));
                top--;
            } else {
                i++;
            }
        }
    }
};
