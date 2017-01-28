#include <iostream>
#include <cstdlib>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (!divisor || (dividend == INT_MIN && divisor == -1))
            return INT_MAX;
        bool sign = false;
        if (dividend < 0 ^ divisor < 0) sign = true;
        unsigned int abs1 = abs(dividend);
        unsigned int abs2 = abs(divisor);
        if (abs1 < abs2) return 0;
        long x;
        unsigned int result = 0;
        while(abs1 >= abs2) {
            unsigned int res = 1;
            x = abs2;
            while ((x << 1) <= abs1) {
                x <<= 1;
                res <<= 1;
            }
            abs1 -= x;
            result += res;
        }
        return sign ? 0 - result : result;
    }
};

int main (int argc, char** argv) {
    Solution sln;
    cout << "Output "<< sln.divide(stoi(argv[1]), stoi(argv[2])) << endl;
}
