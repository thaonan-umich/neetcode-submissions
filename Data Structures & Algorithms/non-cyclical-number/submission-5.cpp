class Solution {
public:
    bool isHappy(int n) {
        
        int sum = 0;
        int num_now = n;
        unordered_set<int> shown;

        while (1) {

            while (num_now != 0){
                int digit = num_now % 10;
                sum += digit * digit;
                num_now /= 10;
            }


            if (sum == 1){
                return true;
            }
            else{
                
                // 如果之前出现过
                if (shown.find(sum) != shown.end()){
                    return false;
                }

                // 如果之前没出现过
                shown.insert(sum);
            }

            num_now = sum;  // 重置 num_now  重置要在sum清零之前
            // sum清零
            sum = 0;
            
        }

    }
};
