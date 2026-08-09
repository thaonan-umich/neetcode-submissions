// 这个贪心也许挺直观

/*
几个可能有用的信息

1. hand.size() / groupSize =  要开的 vector数量

核心思路：

从头到尾遍历hand，如果刚好是其中一个数组前一个递增，附加到该数组后面，如果不是，加到还剩的空数组中， 如果没有一个能加，直接返回false，全部遍历完才返回true

*/


class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {

        if (hand.size() % groupSize != 0){
            return false;
        }

        // 要先sort，不然本方法没有意义
        sort(hand.begin(), hand.end());
        
        int vectors_num = hand.size() / groupSize;

        unordered_map<int, int> count;  // 统计每种牌还有多少张

        for (int card : hand){
            count[card]++;;
        }

        // 从小到大遍历
        for (int card : hand){

            // 如果这张卡已经被消耗掉了
            if (count[card] == 0){
                continue;
            }

            // 如果还没被消耗掉，必须开始凑， 而且是作为起点来凑

            for (int next = card; next < card + groupSize; ++next){
                // 逐个访问count

                if (count[next] > 0){
                    count[next]--;
                }
                else{
                    return false;   // 凑不出来，完蛋 直接返回false
                }
            }

            // 通过上面的循环意味着全凑凑出来了，不错，继续遍历

        }

        // 全部搞定，return true
        return true;
    }
};
