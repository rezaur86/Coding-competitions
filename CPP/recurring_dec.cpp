#include <iostream>
#include <cstdlib>
#include <map>
using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (denominator == 0 || (numerator == INT_MIN && denominator == -1)) return to_string(INT_MAX);
        string s = to_string(numerator / denominator);
        int r = numerator % denominator;
        map <int, int> rs;
        map <int, int> :: iterator it;
        if (r > 0) {
            s += ".";
            rs[r] = s.length();
        }
        bool repeat = false;
        while (r > 0) {
            numerator = r * 10;
            while (numerator < denominator) {
                numerator = numerator * 10;
                s += "0";
            }
            r = numerator % denominator;
            it = rs.find(r);
            if (it != rs.end()) {
                repeat = true;
            }
            rs[r] = s.length();
            s += to_string(numerator / denominator);
            if (repeat) break;
        }
        if (repeat) {
            s.insert(s.begin()+it->second, '(');
            s += ")";
        }
        return s;
    }
};


int main (int argc, char** argv) {
    Solution sln;
    cout << "Output "<< sln.fractionToDecimal(stoi(argv[1]), stoi(argv[2])) << endl;
}
