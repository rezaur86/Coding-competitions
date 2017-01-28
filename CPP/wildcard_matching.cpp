//
//  wildcard_matching.cpp
//  Interview
//
//  Created by Mohammad Rahman on 10/14/16.
//  Copyright © 2016 Mohammad Rahman. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        if (s.empty() && p.empty()) return true;
        long m = s.size();
        long n = p.size();
        vector<vector<bool>> match(m + 1, vector<bool>(n + 1, false));
        match[0][0] = true;
        for (int i = 1; i <= m; i++) {
            match[i][0] = false;
        }
        for (int j = 1; j <= n; j++) {
            if (p[j-1] == '*') match[0][j] = match[0][j-1];
            else match[0][j] = false;
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (p[j-1] == '?') match[i][j] = match[i-1][j-1];
                else if (p[j-1] == '*') match[i][j] = match[i-1][j-1]
                    || match[i-1][j] || match[i][j-1];
                else if (s[i-1] == p[j-1]) match[i][j] = match[i-1][j-1];
                else match[i][j] = false;
            }
        }
        return match[m][n];
    }
};
