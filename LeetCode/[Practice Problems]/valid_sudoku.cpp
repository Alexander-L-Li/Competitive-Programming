class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int a=0; a<9; a++){
            for(int b=0; b<9; b++){
                for(int c=0; c<9; c++){
                    if(b != c && board[a][b] == board[a][c] && board[a][b] != '.'){
                        return false;
                    }
                }
                for(int c=0; c<9; c++){
                    if(b != c && board[b][a] == board[c][a] && board[b][a] != '.'){
                        return false;
                    }
                }
                if(a % 3 == 0 && b % 3 == 0){
                    int arr[10]; fill(arr, arr+10, 0);
                    for(int c=a; c<a+3; c++){
                        for(int d=b; d<b+3; d++){
                            if(board[c][d] != '.'){
                                arr[board[c][d] - '0']++;
                                if(arr[board[c][d] - '0'] > 1){
                                    return false;
                                }    
                            }
                        }
                    }
                }
            }
        }
        return true;
    }
};
