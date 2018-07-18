#include <iostream>
#include "Solution.h"

int main() {

//    std::cout << "Hello, World!" << std::endl;
    Solution *solution = new Solution;
    cout<<solution->firstUniqChar("aadadaad");
    return 0;
}