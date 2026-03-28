class Solution {
public:
    int movesToChessboard(vector<vector<int>>& board) {
        int n = board.size();

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int x = board[0][0] ^ board[i][0];
                int y = board[0][j] ^ board[i][j];
                if((x ^ y) != 0){
                    return -1;
                }
            }
        }

        int rSum = 0, cSum = 0;
        int rSwap = 0, cSwap = 0;

        for(int i = 0; i < n; i++){
            rSum += board[0][i];
            cSum += board[i][0];

            if(board[i][0] == (i % 2)){
                rSwap++;
            }

            if(board[0][i] == (i % 2)){
                cSwap++;
            }
        }

        if(rSum != n/2 && rSum != (n+1)/2) return -1;
        if(cSum != n/2 && cSum != (n+1)/2) return -1;

        if(n % 2 == 1){
            if(rSwap % 2 == 1){
                rSwap = n - rSwap;
            }
            if(cSwap % 2 == 1){
                cSwap = n - cSwap;
            }
        } else {
            if(rSwap > n - rSwap){
                rSwap = n - rSwap;
            }
            if(cSwap > n - cSwap){
                cSwap = n - cSwap;
            }
        }

        return (rSwap + cSwap) / 2;
    }
};
