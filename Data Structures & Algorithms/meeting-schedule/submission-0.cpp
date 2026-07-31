/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

// 先按照开始时间排序
// 然后对每两个靠近的检查，如果后面的开始时间 < 前面的结束时间，则冲突

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {

        int n = intervals.size();
        
        sort(intervals.begin(), intervals.end(),
            [](const Interval& a, const Interval& b){
                return a.start < b.start;   // 从小到大排序
            });
        
        for (int i = 1; i < n; ++i){
            if (intervals[i].start < intervals[i-1].end){
                return false;
            }
        }

        return true;

        
    }
};
