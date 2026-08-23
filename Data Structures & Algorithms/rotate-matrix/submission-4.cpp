// 每个坐标使用 旋转变换矩阵之后 会有唯一的一个坐标
/*

[[cos x,  sin x],
 [-sin x, cos x]]

顺时针90°的话就是

[[0, 1 ]
 [-1, 0]]

那怎么转换坐标呢？是不是需要一个原点呢？

感觉把原点搞出来这题就解决了

i' = j
j' = n - 1 - i

*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int n = matrix.size();

        // 1. 沿着主对角线转置
        /*

        */
        // i' = j 
        // j' = i;
        for (int i = 0; i < n; ++i){
            for(int j = i+1; j < n; ++j){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // 每一行左右翻转
        // i'' = j
        // j'' = n - j'
        for (int i = 0; i < n; ++i){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
