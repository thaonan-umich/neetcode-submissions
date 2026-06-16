class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        // 1. Init
        vector<int> count(26, 0);

        for (char task : tasks){
            count[task - 'A']++;
        }

        priority_queue<int> maxHeap;

        for (int cnt: count){
            if (cnt > 0){
                maxHeap.push(cnt);
            }
        }

        // 2. Loop
        int time = 0;
        queue<pair<int, int>> q;    // <count, 下一次被调用拿出来的time> 

        while(!maxHeap.empty() || !q.empty()){
            time++;

            if (maxHeap.empty()){
                time = q.front().second;
            }
            else{   // 正常情况
                int cnt = maxHeap.top() - 1;    // time++已经算了一次
                maxHeap.pop();

                if (cnt > 0){
                    q.push({cnt, time + n});    // 这个n是什么鬼？为什么是和他妈的time相加？我懵逼了
                }

                // cnt == 0了 就不加回去了

            }

            if (!q.empty() && q.front().second == time){    // 如果现在有到时间可以重新加入堆的，在队列中的元素
                maxHeap.push(q.front().first);
                q.pop();
            }
        }

        return time;
    }
};
