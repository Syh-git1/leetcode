//
// Created by suyunhe on 18-7-4.
//

#include <unordered_map>
#include "Solution.h"

vector<int> Solution::plusOne(vector<int> &digits) {
    vector<int> res(digits.size(),0);
    int sum = 0;
    int one = 1;
    for (int i = digits.size()-1; i >=0 ; i--) {
        sum = one + digits[i];
        one = sum / 10;
        res[i] = sum % 10;
    }
    if (one == 1) {
        res.insert(res.begin(), one);
    }
    return res;
}

vector<vector<int>> Solution::pascalTriangle1(int numRows) {
    vector<vector<int>> pTriangle;
    pTriangle.resize(numRows);
    for (int i = 0; i < numRows; i++) {
        pTriangle[i].resize(i+1);
        pTriangle[i][0] = 1;
        pTriangle[i][pTriangle.size()-1] = 1;
        for (int j = 1; j < pTriangle.size()-1; j++) {
            pTriangle[i][j] = pTriangle[i-1][j-1] + pTriangle[i-1][j];
        }
    }
    return pTriangle;
}

vector<int> Solution::pascalTriangle2(int rowIndex) {
    vector<int> vals;
    vals.resize(rowIndex+1,1);
    for (int i = 0; i < rowIndex + 1; ++i) {
        for (int j = i-1; j >= 1 ; --j) {
            vals[j] = vals[j] + vals [j-1];
        }
    }
    return vals;
}

void Solution::merge(int *A, int m, int *B, int n) {
    int i = m + n - 1;
    int j = m - 1;
    int k = n - 1;
    while (i >= 0) {
        if (j >= 0&&k >= 0) {
            if (A[j] > B[k]) {
                A[i] = A[j];
                j--;
            }
            else {
                A[i] = B[k];
                k--;
            }
        }
        //注意此处else一定要加
        else if (j >= 0) {
            A[i] = A[j];
            j--;
        }
        else if (k >= 0) {
            A[i] = B[k];
            k--;
        }
        i--;
    }
}

vector<int> Solution::twoSum1(vector<int> &numbers, int target) {
    vector<int> ret;
    if (numbers.size()<2) {
        return ret;
    }
    int i,j,flag=0;
    for (i = 0; i < numbers.size(); ++i) {
        for (j = 0; j < numbers.size(); ++j) {
            if ((numbers[i] + numbers[j] == target) && (i != j)) {
                flag = 1;
                break;
            }
        }
        if (flag == 1)
            break;
    }
    if (i > j) {
        ret.push_back(j+1);
        ret.push_back(i+1);
    } else {
        ret.push_back(i+1);
        ret.push_back(j+1);
    }
    return ret;
}

vector<int> Solution::twoSum2(vector<int> &numbers, int target) {
    vector<int> ret;
    //处理边角问题
    if (numbers.size()<2) {
        return ret;
    }
    unordered_map<int,int> myMap;
    //将数组信息放入哈希表
    for (int i = 0; i < numbers.size(); ++i) {
        myMap[numbers[i]] = i;
    }
    for (int j = 0; j < numbers.size(); ++j) {
        int rest_val = target - numbers[j];
        //判断是否可以找到rest_val这个值
        if (myMap.find(rest_val) != myMap.end()) {
            int index = myMap[rest_val];
            if (index == j)
                continue;
            else if (index > j)
            {
                ret.push_back(j+1);
                ret.push_back(index+1);
                return  ret;
            }
            else {
                ret.push_back(index+1);
                ret.push_back(j+1);
                return ret;
            }
        }
    }
}

int Solution::findmin1(vector<int> &num) {
    int size =  num.size();
    if (size == 0) {
        return 0;
    }
    else if (size == 1) {
        return num[0];
    }
    else if (size == 2) {
        return min(num[0],num[1]);
    }

    int start = 0;
    int end = size - 1;
    while (start < end) {
        if (num[start] < num[end]) {
            return num[start];
        }
        int mid = (start + end) / 2;
        if (num[mid] < num[start]) {
            end = mid;
        }
        if (num[mid] > num[start]) {
            start = mid;
        }
        if (abs(start-end)<=1) {
            return min(num[end],num[start]);
        }
    }
}

/*由于数组有序,可以按照平时找最小值的通用方法直接进行求解
 * */
int Solution::findmin2(vector<int> &num) {
    for (int i = 0; i < num.size()-1; ++i) {
        if (num[i]>num[i+1])
            return num[i+1];
    }
    return num[0];
}

void Solution::rotate(vector<int> &nums, int k) {
    int rotatenum = k%nums.size();
    int midnum = nums.size()-rotatenum;
    int temp,count = 0;
    for (int i=0;i< midnum/2;i++) {
        temp = nums[i];
        nums[i] = nums[midnum-i-1];
        nums[midnum-i-1] =temp;
    }
    for (int i = midnum;i<(rotatenum/2)+midnum;i++) {
        temp = nums[i];
        nums[i] = nums[nums.size()-count-1];
        nums[nums.size()-count-1] = temp;
        count++;
    }
    for (int i = 0;i<nums.size()/2;i++) {
        temp = nums[i];
        nums[i] = nums[nums.size()-i-1];
        nums[nums.size()-i-1] = temp;
    }
//    for (int j = 0; j < nums.size(); ++j) {
//        cout<<nums[j]<<endl;
//    }

}

bool Solution::containsDuplicate(vector<int> &nums) {
    //排序方法
/*    if (nums.size() == 0)
        return false;
    sort(nums.begin(),nums.end());
    for (int i = 0; i < nums.size()-1; ++i) {
        if (nums[i] == nums[i+1])
            return true;
    }
    return false;*/
    //双重循环,时间超出,可以换一种写法.
 /*   for (int i = 0; i < nums.size(); ++i) {
        for (int j = 0; j < nums.size(); ++j) {
            if (nums[i] == nums[j]&&i!=j)
                return true;
        }
    }
    return false;*/

 // 和下边的算法写的基本一致,只是没有将nums.size()求出来,竟然通过不了
//    讲nums.size()赋值之后可以通过……
/*    for (int j = 0; j < nums.size()-1; ++j) {
        for (int i = j+1; i < nums.size(); ++i) {
            if (nums[i] == nums[j])
                return true;
        }
    }
    return false;*/
    int len = nums.size();
    for(int i=0; i<len-1; ++i)
    {
        for(int j=i+1; j<len; ++j)
        {
            if(nums[i] == nums[j])
                return true;
        }
    }
    return false;
}

int Solution::maxProfit(vector<int> &prices) {
    int Max;
    int sum = 0;
    if (prices.empty()) {
        return 0;
    }
    for (int i = 1;i < prices.size(); i++) {
        Max = prices[i] - prices[i-1];
        if (Max > 0) {
            sum +=Max;
        }
    }
    return sum;
}

int Solution::singleNumber(vector<int> &nums) {
    //本人算法,已经通过,更好的算法如下,按位异或
/*    sort(nums.begin(),nums.end());
    if (nums[0] != nums[1])
        return nums[0];
    if (nums[nums.size()-1] != nums[nums.size()-2])
        return nums[nums.size()-1];
    int count = 0;
    for (int i = 0; i < nums.size()-1; ++i) {
        if (nums[i] == nums[i+1])
            count = 0;
        else
            ++count;
        if (count == 2)
            return nums[i];
    }*/
//  同一个值异或运算两次则为0,0和任何值异或是值本身
    int a = 0;
    for (int i = 0;i < nums.size();i++){
        a = a^nums[i];
    }
    return a;
}

vector<int> Solution::intersect(vector<int> &nums1, vector<int> &nums2) {
    //思路有问题,但是还是值得商榷
/*    vector<int> intersect={};
    vector<int> fintersect={};
    if (nums1.empty()||nums2.empty())
    {
        return intersect;
    }
    if (nums1.size() <= nums2.size()) {
        for (int i = 0; i < nums1.size(); ++i) {
            vector<int>::iterator it = find(nums2.begin(),nums2.end(),nums1[i]);
            if (it != nums2.end())
                intersect.push_back(nums1[i]);
        }
    }
    else {
        for (int i = 0; i < nums2.size(); ++i) {
            vector<int>::iterator it = find(nums1.begin(),nums1.end(),nums2[i]);
            if (it != nums1.end())
                intersect.push_back(nums2[i]);
        }
    }
    if (intersect.empty()) {
        return intersect;
    }
    int i =0;
    for (int j = 1; j < intersect.size(); ++j) {
        if (intersect[i]==intersect[j])
            continue;
        else
            intersect[++i] = intersect[j];
    }
    for (int k = 0; k < i+1; ++k) {
        fintersect.push_back(intersect[k]);
    }
    return fintersect;*/
    sort(nums1.begin(),nums1.end());
    sort(nums2.begin(),nums2.end());
    vector<int> intersect;
    int i = 0,j = 0;
    while ((i < nums1.size())&&(j < nums2.size())) {
        if (nums1[i] < nums2[j]) {
            i++;
        }
        else if (nums1[i] > nums2[j]) {
            j++;
        }
        else {
            intersect.push_back(nums1[i]);
            i++;
            j++;
        }
    }
    return intersect;
}

void Solution::movezeroes(vector<int> &nums) {
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] == 0) {
            for (int j = i+1; j < nums.size(); ++j) {
                if (nums[i] != nums[j]) {
                    nums[i] = nums[j];
                    nums[j] = 0;
                    break;
                }
            }
        }
    }
}

bool Solution::isValidSudoku(vector<vector<char>> &board) {
    vector<vector<bool>> rowFlag(9,vector<bool>(9));
    vector<vector<bool>> colFlag(9,vector<bool>(9));
    vector<vector<bool >> cellFlag(9,vector<bool>(9));

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (board[i][j] >= '1'&& board[i][j] <= '9')
            {
                int temp = board[i][j] - '1';
                if (rowFlag[i][temp]||colFlag[j][temp]||cellFlag[3*(i/3)+j/3][temp])
                    return false;
                rowFlag[i][temp] = true;
                colFlag[j][temp] = true;
                cellFlag[3*(i/3)+j/3][temp] = true;
            }
        }
    }
    return true;
}

string Solution::reverseString(string s) {
    if (s.empty())
        return s;
    char temp;
    for (int i = 0; i < s.size()/2; ++i) {
        temp = s[i];
        s[i] = s[s.size()-i-1];
        s[s.size()-i-1] = temp;
    }
    return s;
//    使用内置函数,一句话完事
//    reverse(s.begin(),s.end());
}

void Solution::rotate(vector<vector<int>> &matrix) {
    int rows = matrix.size();
    for (int i = 0; i < rows; i++) {
        for (int j = i+1; j < rows; j++)
            swap(matrix[i][j], matrix[j][i]);
    }
    for (int i = 0; i < rows; i++) {
        reverse(matrix[i].begin(),matrix[i].end());
    }

}
