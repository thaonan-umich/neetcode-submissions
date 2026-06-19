class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        for (int i = n - 1; i >= 0; --i){
            if (digits[i] == 9){
                digits[i] = 0;  // 携带一个进位
            }
            else{
                digits[i]++;
                return digits;
            }
        }

        // 到这就是全都是9
        digits.insert(digits.begin(), 1);
        return digits;
    }


};
