//
//  binaries_with_n_1s.cpp
//  Interview
//
//  Created by Mohammad Rahman on 10/18/16.
//  Copyright © 2016 Mohammad Rahman. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

class get_binaries_with_n_bit_set {
public:
    void gen_binary(vector<int>& binary, int init, int start_1s, int n) {
        if (n == 0) {
            binary.push_back(init);
            return;
        }
        for (int i = start_1s; i < 10; i++){
            gen_binary(binary, init | (1 << i), i + 1, n - 1);
        }
    }
    void static test_get_binaries_with_n_bit_set() {
        get_binaries_with_n_bit_set test;
        vector <int> b;
        cout << "Binaries with n = 1 bits set : " << endl;
        test.gen_binary(b, 0, 0, 1);
        for (int i = 0; i < b.size(); i++) {
            cout << " " << b[i];
        }
        cout << endl;
    }
};
