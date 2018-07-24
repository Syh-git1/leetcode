//
// Created by suyunhe on 18-7-17.
//

#ifndef STRING_SOLUTION_SOLUTION_H
#define STRING_SOLUTION_SOLUTION_H

#include <iostream>
#include <ctype.h>
using namespace std;
class Solution
{
public:
    // 字符串中的第一个唯一字符
    int firstUniqChar(string s);
    // 颠倒整数
    int reverse(int x);
    // 有效的字母异位词
    bool isAnagram(string s, string t);
    //验证回文字符串
    bool isPalindrome(string s);
    //字符串转整数(atoi)
    int myAtoi(string str);
    //数数并说 (感觉是规律题目)
    string countAndSay(int n);
    //实现strStr()
    int strStr(string haystack, string needle);
    //最长公共前缀
    string longestCommonPrefix(vector<string>& strs);
};


#endif //STRING_SOLUTION_SOLUTION_H
