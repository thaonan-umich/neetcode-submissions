// 感觉可能要用到哈希表
// 先遍历一遍s 获得每个字符的频率

// 然后开始切分遍历
    // 对于当前字符，如果吃掉（算入子串）之后，目前维持的字串中所有剩余的字符数都等于0，切出来一个字串，获取其长度
    // 如果不等于0，继续
    // 对于子串中剩余没吃的的数量为0的字符，剔出跟踪集，只考虑在子串中且还有剩余字符的字母

class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        vector<int> remain(26, 0); // 不用开unorder_map, 直接vector就行

        for (char c : s){
            ++remain[c - 'a'];
        }

        vector<int> res;

        // active[c]
        // 当前切分已经遇到过c
        // 且c在后面还有剩余
        vector<bool> active(26, false);
        int activeCount = 0;

        int start = 0;

        // 从左往右不断吃字符
        for (int i = 0; i < s.size(); ++i){
            int idx = s[i] - 'a';

            --remain[idx];

            if (remain[idx] > 0){   // 当前字符后面还有
                if (active[idx] == false){ // 需要有这个检查，不然同字符会一直加
                    active[idx] = true;
                    ++activeCount;  // 目前还没吃完的active char 数量+1
                }

            }
            else{
                // 当前字符已经彻底吃完
                if (remain[idx] == 0 && active[idx]){
                    active[idx] = false;
                    --activeCount;
                }
            }

            if (activeCount == 0){  // 当前 切分 中 已经没有任何字符延伸到未来
                res.push_back(i - start + 1);
                start = i + 1;
            }
        }

        return res;
    }
};
