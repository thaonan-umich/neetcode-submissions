// 合并思路：开一个空数组，遍历原数组往里面丢

// 1. 先排序，让数组可以单向狂吞，不用怕被杀回马枪
// 2. 遍历准备扔进新数组末尾
// 3. 扔进去前看看要不要合并
    // 要合并的话, 把最后一个元素合并再扔进去
    // 不用合并的话直接扔进去

// 指导思路：一定要边想边写，不要只想不写

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        // init
        vector<vector<int>> result;

        // 1. 先排序
        sort(intervals.begin(), intervals.end(), 
            [](const vector<int>& a, const vector<int>& b){
                return a[0] < b[0];
            });
        
        // 2. 遍历intervals
        for (const auto& interval : intervals){

            if (result.empty()){
                result.push_back(interval);
            }

            if (interval[0] > result.back()[1]){
                result.push_back(interval);
            }
            else{   // 重叠情况， interval[0] <= result.back[1] 
                result.back()[1] = max(result.back()[1], interval[1]);
            }
            // 算法正确保证条件：前面的都是已经合并好的
            // 不行啊 我现在这个想法无法处理  1,2  3,4 1, 5 这种序列啊， 难道只能O(n^2)的写法了吗
            // 先排序可以直接避免这种情况

        }

        return result;



    }
};
