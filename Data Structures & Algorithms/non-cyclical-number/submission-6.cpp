class Solution {
public:
    bool isHappy(int n) {
        
        int num_now = n;
        unordered_set<int> shown;

        while (1) {

            int sum = 0;

            while (num_now != 0){
                int digit = num_now % 10;
                sum += digit * digit;
                num_now /= 10;
            }

            if (sum == 1)
                return true;
                         
            // 如果之前出现过
            if (shown.find(sum) != shown.end())
                return false;
            
            // 如果之前没出现过
            shown.insert(sum);
            
            num_now = sum;  // 重置 num_now 
        }

    }
};
