/*
 * find_running_median.cpp
 *
 *  Created on: Nov 15, 2016
 *      Author: mohammra
 */

#include "common.h"


#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class median {
public:
    priority_queue<int, vector<int>> max_queue;
    priority_queue<int, vector<int>, greater<int>> min_queue;

    void adjust() {
        if(max_queue.size() > min_queue.size() + 1) {
            min_queue.push(max_queue.top());
            max_queue.pop();
        }
        if(max_queue.size() < min_queue.size()) {
            max_queue.push(min_queue.top());
            min_queue.pop();
        }
    }

    void add(int el) {
        if (!max_queue.empty() && el <= max_queue.top()) {
            max_queue.push(el);
        } else {
            min_queue.push(el);
        }
        adjust();
    }

    void print(){
        if (max_queue.size() == min_queue.size()) {
            cout << ((float) (max_queue.top() + min_queue.top())) / 2 << endl;
        } else {
            cout << max_queue.top() << endl;
        }
    }
};

using namespace std;
int main() {
    median m;
    int n, a;
    cin >> n;
    while(n--) {
        cin >> a;
        m.add(a);
        m.print();
    }
    return 0;
}
