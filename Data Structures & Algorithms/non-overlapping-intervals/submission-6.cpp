// 先试试之前惯用伎俩吧
// 1. 先排个序
// 最少的溢出 = 最多的保留
// 排序之后开一个新的res数组，扫描原始intervals一个一个加入，如果重叠了就不加入

// 目前不知道这个思路有啥问题，只能先写出来拿信息了
// 如果两个区间重叠，结束得更早的区间更值得留下，因为它占用右侧空间更少，给后面的区间留出了更多生存空间。

// 前面的原则已经确定 新来的选项一旦重叠，你就必须再新来的和最后一个interval中做出选择
// 选择的原则是贪心，让对未来的代价最小 -> 选结束最早的那个
// 不会出现来的interval不会横跨两个已经排好再result里面的intervals的情况，因为按起点排序之后这种情况不可能发生
// 所以可以直接用这种贪心策略，也能保证这种贪心策略确实可以得到最优解

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        // init
        int remove_count = 0;

        // 1. 先排序
        sort(intervals.begin(), intervals.end(),
            [](const vector<int>& a, const vector<int>& b){
                return a[0] < b[0];
            });
        
        int keptEnd = intervals[0][1];
        
        // 2. 遍历 intervals
        for (int i = 1; i < intervals.size(); ++i){

            if (keptEnd <= intervals[i][0]){
                // 不重叠，直接更新末尾
                keptEnd = intervals[i][1];
            }
            else{
                // 重叠，必须要做出抉择
                remove_count++;

                // 保留结束时间更早的
                keptEnd = min(intervals[i][1], keptEnd);
            }

        }

        return remove_count;
    }
};

/*
关键导致卡住的问题：


*/
