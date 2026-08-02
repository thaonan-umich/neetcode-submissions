// 直观思路；链表扩张方法 但是说实话向前向后膨胀的操作有点复杂 根据lazy原则有更简单的方法就用更简单的

// 神奇思路: 扫描，但跳过被吞掉的区间
// 客观评价这个神奇思路：确实很优雅，很搞笑，但是要想到这里的脚手架搭建工作有难度，第一次没法自己写出来正常，说实话能想到还是挺诡异的

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        vector<vector<int>> result;
        int i = 0;  // 这是在干啥 当前迭代指针，全局一直保留
        int n = intervals.size();

        // 1. 扫描全部列表，把完全位于newInterval左边的区间直接放进去
        while (i < n && intervals[i][1] < newInterval[0]){
            result.push_back(intervals[i]);
            ++i;
        }

        // 一旦退出上面这个循环，就说明遇到一个有重叠的区间了

        // 2. 吞掉所有与newInterval重叠的区间
        while (i < n && intervals[i][0] <= newInterval[1]){      // 对于所有开始时间小于 新时段 结束时间的段落 都扫描一遍看看要不要吞掉
            newInterval[0] = min(intervals[i][0], newInterval[0]);
            newInterval[1] = max(intervals[i][1], newInterval[1]);
            ++i;
        }

        // 一旦退出上面这个循环就说明重叠区间吞完了

        // 3. 该吞的都吞了，新段落塞把进去
        result.push_back(newInterval);

        // 4. 把剩下没塞进去的塞进去
        while (i < n){
            result.push_back(intervals[i]);
            ++i;
        }

        return result;

        
    }
};
