#import "common.h"

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](const int& n1, const int& n2) {
            return to_string(n1) + to_string(n2) > to_string(n2) + to_string(n1);
        });
        string res = "";
        for(auto s : nums) {
            if (s == 0 && res == "0") continue;
            res += to_string(s);
        }
        return res;
    }
};
