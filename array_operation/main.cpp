#include <iostream>
#include "Solution.h"

int main() {

    Solution *solution = new Solution;
    vector<int> digits={4,3,9,3,1,9,7,6,9,7};
    vector<int> digit={5,0,8};
    vector<vector<char>> board(9,vector<char>(9));

    list<int> list1={1,2,3,4,5};
    list<int>::iterator it;
    int i;
    vector<int> list2(list1.size());

    char a[9][9] = {
            '5','3','.','.','7','.','.','.','.',
            '6','.','.','1','9','5','.','.','.',
            '.','9','8','.','.','.','.','6','.',
            '8','.','.','.','6','.','.','.','3',
            '4','.','.','8','.','3','.','.','1',
            '7','.','.','.','2','.','.','.','6',
            '.','6','.','.','.','.','2','8','.',
            '.','.','.','4','1','9','.','.','5',
            '.','.','.','.','8','.','.','7','9'
    };
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            board[i][j] = a[i][j];
        }
    }
    int temp = board[0][0] - '1';
    cout <<temp <<endl;
//    digits = solution->twoSum2(digits,4);
//    for (int i = 0; i < digits.size(); ++i) {
//        cout<<digits[i]<<endl;
//    }

//    cout<<solution->intersect(digits,digit)<<endl;
//    solution->intersect(digits,digit);
//    solution->isValidSudoku(board);
//    std::cout << solution->findmin2(digits)<< std::endl;
    return 0;
}