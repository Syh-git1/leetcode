//
// Created by suyunhe on 18-7-16.
//

#include "Solution.h"
#include <math.h>
int Solution::countPrimes(int n) {
    //超出时间限制
    int count = 0;
    int temp = 0;
    for (int i = 2; i < n; ++i) {
        for (int j = 2; j <= sqrt(i); ++j) {
            if ((i%j)==0) {
                temp = 1;
                break;
            }
        }
        if (temp == 0) {
            count++;
        }
        else {
            temp = 0;
        }
    }
    return count;
}
