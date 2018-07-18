//
// Created by suyunhe on 18-7-17.
//

#include <jmorecfg.h>
#include "Solution.h"

int Solution::firstUniqChar(string s) {
    if (s.empty())
    {
        return -1;
    }
    for (int i = 0; i <s.size(); ++i) {
        bool uniq = true;
        for (int j = 0; j <s.size(); ++j) {
            if (i == j)
                continue;
            if (s[i] == s[j]) {
                uniq = false;
                break;
            }
            else
                uniq = true;
        }
        if (uniq)
            return i;
    }
    return -1;
}
