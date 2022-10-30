//
//  veridenemec++.cpp
//  
//
//  Created by MAC on 30.10.2022.
//
#include <iostream>
#include <stdlib.h>
#include <string>
#include "veridenemec++.hpp"

class Solution {
public:
    string countOfAtoms(string formula) {
        map<string, int> mp;
        int carry = 1, n = formula.size(), count = 1; // count is the current number of atom, for example, "(H2)2", the carry of H is 2, and the count of H is 4;
        string cur = "", res = "";
        bool flag = false; // to deal with situation that has two or more consecutive upper chars, "(OH)"
        stack<int> stk; // record each used carry, "((H3)2)4", when reach H, stk = {4, 2}
        for (int i = n - 1; i >= 0; --i) {
            if (isdigit(formula[i])) {
                flag = false;
                int j = i;
                while (i - 1 >= 0 && isdigit(formula[i - 1])) --i; // deal with case "Be32"
                count = carry * stoi(formula.substr(i, j - i + 1));
            } else if (formula[i] == ')') {
                if (i + 1 < n && isdigit(formula[i + 1])) {
                    int k = i + 1;
                    while (k + 1 < n && isdigit(formula[k + 1])) ++k; // deal with case "(Be)32"
                    stk.push(stoi(formula.substr(i + 1, k - i)));
                    carry *= stoi(formula.substr(i + 1, k - i));
                } else stk.push(1);
            } else if (formula[i] == '(') {
                carry /= stk.top();
                stk.pop();
            } else if (isupper(formula[i])) {
                if (flag) count = carry;
                cur = formula[i];
                int t = i;
                while (t + 1 < n && islower(formula[t + 1])) {
                    cur += formula[t + 1];
                    ++t;
                }
                mp[cur] += count;
                flag = true;
            }
        }
        for (auto &m : mp) res += m.first + (m.second == 1 ? "" : to_string(m.second));
        return res;
    }
};
