class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        // 1. Init
        vector<pair<int, int>> blanks_vec;

        // 2. Loop1: Get Blanks
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++){
                blanks_vec.push_back({i, j});
            }
        } // 补全了此处缺失的右花括号
        
        // 3. Loop2 check-pipeline
        for (auto it = blanks_vec.begin(); it != blanks_vec.end(); ++it){
            
            // 3.1 check row
            int raw_now = it->first;
            int col_pointer = 0;
            unordered_set<char> remains_row = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
            while (col_pointer < 9){
                char element = board[raw_now][col_pointer];
                if (element != '.'){
                    if (remains_row.find(element) != remains_row.end()){
                        remains_row.erase(element);
                    } 
                    else{
                        return false;
                    }   
                }


                col_pointer++;
            }

            // 3.2 check col
            int col_now = it->second; // 修正：it -> second
            int raw_pointer = 0;
            unordered_set<char> remains_col = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
            while (raw_pointer < 9){
                char element = board[raw_pointer][col_now];
                if (element != '.'){
                    if (remains_col.find(element) != remains_col.end()){
                        remains_col.erase(element);
                    } 
                    else{
                        return false;
                    }   
                }

                raw_pointer++;
            }

            // 3.3 check block
            pair<int, int> block_idx;
            block_idx.first = it->first / 3;
            block_idx.second = it->second / 3;
            unordered_set<char> remains_block = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
            for (int k = block_idx.first * 3; k < (block_idx.first + 1) * 3; k++){
                for (int z = block_idx.second * 3; z < (block_idx.second + 1) * 3; z++){
                    char element = board[k][z];
                    if (element != '.'){
                        if (remains_block.find(element) != remains_block.end()){
                            remains_block.erase(element);
                        } 
                        else{
                            return false;
                        }   
                    }
                }
            }
        }
        
        // 4. return true
        return true;
    }
};