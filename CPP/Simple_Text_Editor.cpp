/*
 * Simple_Text_Editor.cpp
 *
 *  Created on: Nov 12, 2016
 *      Author: mohammra
 */

#include "common.h"


#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int Q;
    cin >> Q;
    int op, k;
    string S = "";
    string a;
    stack<string> s_states;
    s_states.push(S);
    while(Q--) {
        cin >> op;
        switch (op) {
            case 1:
                cin >> a;
                S += a;
                s_states.push(S);
                break;
            case 2:
                cin >> k;
                for(int i = 0; i < k; i++) {
                    S.erase(S.end() - 1);
                }
                s_states.push(S);
                break;
            case 3:
                cin >> k;
                cout << S[k - 1] << endl;
                break;
            case 4:
                s_states.pop();
                S = s_states.top();
                break;
        }
    }
    return 0;
}
