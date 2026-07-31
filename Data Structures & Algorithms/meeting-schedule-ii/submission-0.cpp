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

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        
        // 1. 扫描处最晚时间点
        int lastest = 0;

        for (Interval interval : intervals){
            lastest = max(lastest, interval.end);
        }

        // 2. 创建扫描数组
        vector<int> timeline(lastest+1, 0);

        // 3. 开始填充数组
        for (Interval interval : intervals){
            timeline[interval.start]++;
            timeline[interval.end]--;
        }

        // 4. 扫描数组，找出最大会议数量
        int max_meeting = 0;
        int cur_meeting = 0;

        for (int i = 0; i < timeline.size(); ++i){
            cur_meeting += timeline[i];
            max_meeting = max(max_meeting, cur_meeting);
        }

        return max_meeting;

    }
};
