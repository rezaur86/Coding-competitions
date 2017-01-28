//
//  super_ugly_number.cpp
//  Interview
//
//  Created by Mohammad Rahman on 10/20/16.
//  Copyright © 2016 Mohammad Rahman. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>
#include <cstdlib>
using namespace std;

class SuperUglyNumber {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> nums(n, INT_MAX);
        vector<int> idx(primes.size(), 0);
        nums[0] = 1;
        int i = 1;
        while (i < n) {
            for(int j = 0; j < primes.size(); j++) {
                nums[i] = min(nums[i], nums[idx[j]]*primes[j]);
            }
            for(int j = 0; j < primes.size(); j++) {
                if(nums[i] == nums[idx[j]]*primes[j]){
                    idx[j]++;
                }
            }
            i++;
        }
        return nums[n - 1];
    }
    
    void static test(){
        SuperUglyNumber sun;
        vector<int> in;
        in.push_back(2);
        in.push_back(7);
        in.push_back(13);
        in.push_back(19);
        int result = sun.nthSuperUglyNumber(12, in);
        cout << "Output from nthSuperUglyNumber: " << result << endl;
    }
};
