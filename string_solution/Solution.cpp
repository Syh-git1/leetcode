//
// Created by suyunhe on 18-7-17.
//

#include <jmorecfg.h>
#include <map>
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

int Solution::reverse(int x) {
    int result = 0;
    while (x != 0) {
        int tmp = result*10 + x%10;
//        如果溢出,tmp/10!=result*10
        if (tmp / 10 != result)
            return 0;
        result = tmp;
        x = x/10;
    }
    return result;
}

bool Solution::isAnagram(string s, string t) {
    if (s.size()!=t.size()) {
        return false;
    }
    multimap<char, int> s_map;
    for (int i = 0; i < s.size(); ++i) {
        s_map.insert(make_pair(s[i],i));
    }
    for (int i = 0; i < t.size(); ++i) {
        if (s_map.find(t[i]) != s_map.end()) {
            s_map.erase(s_map.find(t[i]));
        }

    }
    if (s_map.empty())
        return true;
    else
        return false;
    // 剽窃一下别人的算法 4ms
    /*    int lenS = s.size(), lenT = t.size();

        if (lenS != lenT)
            return false;

        int alphabeta[26] = {0};

        for (char c:s)
            alphabeta[c - 'a']++;
        for (char c:t)
            alphabeta[c - 'a']--;

        for (int i:alphabeta)
            if (i != 0)
                return false;

        return true;*/
}
