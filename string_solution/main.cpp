#include <iostream>
#include <vector>
#include "Solution.h"

int main() {

    vector<string> strs;
    strs.push_back("flower");
    strs.push_back("flow");
    strs.push_back("flight");
    Solution *solution = new Solution;
    cout<<solution->longestCommonPrefix(strs);
//    cout<<solution->myAtoi("2147483647");

    return 0;

}