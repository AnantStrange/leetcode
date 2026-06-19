#include <iostream>
#include <ostream>
#include <unordered_set>
#include <vector>

using namespace std;

bool isValidRow(const vector<vector<char>> &board){
    unordered_set<char> set;
    for(auto row : board){
        for(char digit : row){
            if(digit == '.'){
                continue;
            }
            else if(set.find(digit) != set.end()){
                return false;
            }
            else{
                set.insert(digit);
            }
        }
        set.clear();
    }
    return true;
};

bool isValidColumn(const vector<vector<char>> &board){
    unordered_set<char> set;
    for(int j=0;j<9;j++){
        for(int i=0;i<9;i++){
            if(board[i][j] == '.'){
                continue;
            }
            else if(set.find(board[i][j]) != set.end()){
                return false;
            }
            else{
                set.insert(board[i][j]);
            }
        }
        set.clear();
    }
    return true;
};

bool isValidCell(vector<vector<char>> &board){
    vector<pair<int, int>> base_cords = {{0,0},{0,3},{0,6},
                                        {3,0},{3,3},{3,6},
                                        {6,0},{6,3},{6,6}};

    unordered_set<char> set;
    for(auto [i_base, j_base] : base_cords){
        for(int i=i_base;i<i_base+3;i++){
            for(int j=j_base;j<j_base+3;j++){
                if(board[i][j] == '.'){
                    continue;
                }
                else if(set.find(board[i][j]) != set.end()){
                    return false;
                }
                else{
                    set.insert(board[i][j]);
                }
            }
        }
        set.clear();
    }
    return true;
};

class Solution {
  public:
    bool isValidSudokuNaive(vector<vector<char>> &board){
        bool to_return = isValidRow(board);
        cout<<"to_return : "<<to_return<<endl;
        if(to_return){
            to_return = isValidColumn(board);
            cout<<"to_return : "<<to_return<<endl;
            if(to_return){
                to_return = isValidCell(board);
                cout<<"to_return : "<<to_return<<endl;
            }
        }
        return to_return;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> rows[9], cols[9], boxes[9];

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char c = board[i][j];
                if (c == '.') continue;

                int boxIdx = (i / 3) * 3 + (j / 3);

                if (rows[i].count(c) || cols[j].count(c) || boxes[boxIdx].count(c)) {
                    return false;
                }

                rows[i].insert(c);
                cols[j].insert(c);
                boxes[boxIdx].insert(c);
            }
        }
        return true;
    }
};


int main(){
    Solution sol;

    vector<vector<char>> board1 = {{'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}};

    vector<vector<char>> board2 = {{'8','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}};

    vector<vector<char>> board3 = {{'.','.','.','.','5','.','.','1','.'},
                                   {'.','4','.','3','.','.','.','.','.'},
                                   {'.','.','.','.','.','3','.','.','1'},
                                   {'8','.','.','.','.','.','.','2','.'},
                                   {'.','.','2','.','7','.','.','.','.'},
                                   {'.','1','5','.','.','.','.','.','.'},
                                   {'.','.','.','.','.','2','.','.','.'},
                                   {'.','2','.','9','.','.','.','.','.'},
                                   {'.','.','4','.','.','.','.','.','.'}};

    cout<<sol.isValidSudoku(board1)<<endl;
    cout<<sol.isValidSudoku(board2)<<endl;
    cout<<sol.isValidSudoku(board3)<<endl;
}
