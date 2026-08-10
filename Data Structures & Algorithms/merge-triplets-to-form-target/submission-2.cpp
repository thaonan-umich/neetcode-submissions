// 核心信息：不断max各个分量只会越来越大
// 好像也不用，直接从头到尾合并？
    // 如果本次合并 非法，扔掉这一次的，继续下一次合并
    // 如果本次合并 合法，合并，合并后检查
        // 1. 如果合并后等于目标，直接返回
        // 2. 入过合并后不等于目标，继续

// 全部遍历完还不能成功合并，返回false



class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        
        vector<int> cur(3,0);

        for (const auto& triplet : triplets){

            // 开始尝试合并
            
            // 只要有一个分量大于target, 直接扔掉不合并
            bool valid = true;
            for (int i = 0; i < 3; ++i){
                if (triplet[i] > target[i]){
                    valid = false;
                    break; // 跳出本层循环
                }
            }

            if (valid == false)
                continue;

            // 合法，合并
            for (int i = 0; i < 3; ++i){
                cur[i] = max(cur[i], triplet[i]);
            }

            // 如果刚好等于
            
            if (cur == target){ // 值相等
                return true;
            }

        }

        return false;
    }
};
