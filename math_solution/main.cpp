#include <iostream>
#include "Solution.h"
using namespace std;
int main() {
//    std::cout << "Hello, World!" << std::endl;
    Solution *solution = new Solution;
    cout<<solution->countPrimes(1500000);
    return 0;
}