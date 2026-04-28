class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        // 1. Init
        int row[9][9] = {0};
        int col[9][9] = {0};
        int box[9][9] = {0};

        // 2. Loop
        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                
                char element_char = board[i][j];
                if (element_char != '.'){
                    int element_idx = int(element_char - '1');  // 索引转到 0-8

                    // 2.1 row_matrix operation
                    if (row[i][element_idx] == 0)
                        row[i][element_idx] = 1;
                    else
                        return false;
                    
                    // 2.2 col_matrix operation
                    if (col[j][element_idx] == 0)
                        col[j][element_idx] = 1;
                    else
                        return false;

                    // 2.3 box_matrix operation
                    if (box[(i/3) * 3 + (j/3)][element_idx] == 0)
                        box[(i/3) * 3 + (j/3)][element_idx] = 1;
                    else
                        return false;
                    
                }

            }
        }

        // 3. check end, return true;
        return true;
    }
};