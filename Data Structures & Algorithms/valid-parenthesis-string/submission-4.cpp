// 首先肯定要用stack
// 然后这可以暴力尝试，但是最坏情况是 O(3^n)

class Solution {
public:
    bool checkValidString(string s) {

        int leftMin = 0;
        int leftMax = 0;

        for (char c : s){

            if (c == '('){
                ++leftMin;
                ++leftMax;
            }

            if (c == '*'){

                // 1. 把它当作 (
                ++leftMax;

                // 2. 把他当作 )
                if (leftMin != 0){
                    --leftMin;
                }
            }

            if (c == ')'){

                if (leftMin != 0)
                    --leftMin;

                --leftMax;
            }

            // 一旦出现 leftMax < 0 的情况，也就是这个 ) 匹配不上 (, 也就是没得配，那之后就死局了
            if (leftMax < 0)
                return false;

        }

        return (leftMin == 0);
        
    }
};
