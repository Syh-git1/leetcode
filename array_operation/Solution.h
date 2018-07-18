//
// Created by suyunhe on 18-7-4.
//

#ifndef ARRAY_OPERATION_SOLUTION_H
#define ARRAY_OPERATION_SOLUTION_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;
class Solution
{
public:
    // 加法进位函数,其中最高位存在列表头
    vector<int> plusOne(vector<int> &digits);
    // Pascal's triangle
    /*规律：
     * 第k层有k个元素
     * 每层首个元素和最后一个元素均为1
     * 对于第k(k>2)层第n(n>1&&n<k)个元素A[k][n]=A[k-1][n-1]
     * +A[k-1][n]
     * */
    vector<vector<int>> pascalTriangle1(int numRows);

    // 得到帕斯卡三角的某一层,使用O(k)的空间复杂度
    vector<int> pascalTriangle2(int rowIndex);

    // 有序数组A和B合并到A中,假设A空间足够大
    void merge(int A[], int m, int B[], int n);

    // 2sum问题,使用brute force方法,时间复杂度O(n2),非正确答案
    vector<int> twoSum1(vector<int> &numbers, int target);

    // 2sum问题,使用hash map,降低时间复杂度,但是需要空间存储哈希表
    vector<int> twoSum2(vector<int> &numbers, int target);

    //旋转数组找最小值(Find Minimum in Rotated Sorted Array)
    int findmin1(vector<int> &num);/*二分法求解*/
    int findmin2(vector<int> &num);/*简单方法,通过规律求解*/

    //旋转数组生成
    void rotate(vector<int>& nums, int k);
    //判断数组是否含有重复元素
    bool containsDuplicate(vector<int>& nums);
    // 股票最大收益
    int maxProfit(vector<int>& prices);
    // 求数组中只出现一次的数字,数组非空
    int singleNumber(vector<int> &nums);
    // 求数组交集
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2);
    // 移动0,将0移动到数组最后
    void movezeroes(vector<int>& nums);
    // 判断数独是否有效
/*    数字 1-9 在每一行只能出现一次。
    数字 1-9 在每一列只能出现一次。
    数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。*/
    bool isValidSudoku(vector<vector<char>> &board);
    // 字符串操作
    string reverseString(string s);
    // 旋转图像
    /*给定 matrix =
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

原地旋转输入矩阵，使其变为:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]
     首先对原数组取其转置矩阵，然后把每行的数字翻转可得到结果，如下所示(其中蓝色数字表示翻转轴)：

1  2  3　　　 　　 1  4  7　　　　　  7  4  1

4  5  6　　-->　　 2  5  8　　 -->  　  8  5  2　　

7  8  9 　　　 　　3  6  9　　　　      9  6  3*/
    void rotate(vector<vector<int>>& matrix);


};


#endif //ARRAY_OPERATION_SOLUTION_H
