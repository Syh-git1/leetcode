//
// Created by suyunhe on 18-7-17.
//

#include <jmorecfg.h>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>
#include <stdlib.h>
#include "Solution.h"
using namespace std;

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

bool Solution::isPalindrome(string s) {
    if (s.empty())
        return true;
    vector<int> s_vet;
    vector<int> s_reverse;
    for (int i = 0; i < s.size(); ++i) {
        // 判断是否是字母或者数字
        if (!isalnum(s[i]))
            continue;
        else if(s[i]>='A'&&s[i]<='Z') {
        // 大小写字母转换
            s[i]=towlower(s[i]);
        }
        s_vet.push_back(s[i]);
    }
    for (int i = s_vet.size()-1; i >=0 ; --i) {
        s_reverse.push_back(s_vet[i]);
    }
    if (s_vet==s_reverse) {
        return true;
    } else
        return false;

}

int Solution::myAtoi(string str) {
    if (str.empty())
        return 0;
    vector<int> ato_vet;
    int index;
    double result=0;
    for (int i = 0; i < str.size(); ++i) {
        if (str[i]!=' ') {
            if ((str[i]>='0'&&str[i]<='9')||str[i] == '+'||str[i] == '-') {
                index = i;
                ato_vet.push_back(str[i]-'0');
                break;
            } else
                return 0;
        }
    }
    if (ato_vet.empty())
        return 0;
    for (int i = index+1; i < str.size(); ++i) {
        if (str[i]>='0'&&str[i]<='9')
            ato_vet.push_back(str[i]-'0');
        else
            break;
    }
    std::reverse(ato_vet.begin(),ato_vet.end());
    for (int i = ato_vet.size()-1; i >0; --i) {
        if (ato_vet[ato_vet.size()-1]==-3)
            result += (-1)*ato_vet[i-1]*pow(10,i-1);
        else if (ato_vet[ato_vet.size()-1]==-5)
            result += ato_vet[i-1]*pow(10,i-1);
        else
            result += ato_vet[i]*pow(10,i);
    }
    if ((ato_vet[ato_vet.size()-1]<=9)&&(ato_vet[ato_vet.size()-1])>=0)
        result =result + ato_vet[0];
    if (result>=INT32_MAX)
        return INT32_MAX;
    else if (result<=INT32_MIN)
        return INT32_MIN;
    else
        return result;
}

string Solution::countAndSay(int n) {
    string genernal="1";
    for (int i = 1; i < n; ++i) {
        string genernal_term="";
        int j = 0;
        for (; j < genernal.size(); ) {
            char val = genernal[j];
            int count = 0;
            while (genernal[j]==val&&j<genernal.size()) {
                count++;
                j++;
            }
            genernal_term+=to_string(count);
            genernal_term+=val;
        }
        genernal = genernal_term;
    }
    return genernal;
}

int Solution::strStr(string haystack, string needle) {
    if (needle == "")
        return 0;
    int i = 0,j = 0, index = 0, count = 0;
    while (i < haystack.size()) {
        if (haystack[i] != needle[j]) {
            if (0 < count&&count != needle.size()) {
                i = i - count + 1;
                count = 0;
                j = 0;
            }
            else if (0 == count) {
                i++;
                continue;
            }
        }
        else if (haystack[i] == needle[j]&&j < needle.size()) {
            count++;
            i++;
            j++;
        }
        if (j == needle.size()) {
            index = i - j;
            break;
        }
    }
    if (i == haystack.size()&&j != needle.size())
        return -1;
    return index;
}

string Solution::longestCommonPrefix(vector<string> &strs) {
    if (strs.empty())
        return "";
    int num = strs.size();
    int len = strs[0].size();
    for (int i = 0; i < len; i++)
        for (int j = 1; j < num; ++j) {
            if (i >strs[j].size()||strs[j][i] != strs[0][i])
                return strs[0].substr(0,i);
        }
    return strs[0];
/*    string Prefix = strs[0];
    for (int i = 1; i < strs.size(); ++i) {

    }
    return std::__cxx11::string();*/
}
