class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        int left_pointer = 0;
        int right_pointer = numbers.size() - 1;

        int sum = numbers[left_pointer] + numbers[right_pointer];

        while (sum != target){
            if (sum > target){
                sum -= numbers[right_pointer];
                right_pointer--;
                sum += numbers[right_pointer];
            }
            else{
                sum -= numbers[left_pointer];
                left_pointer++;
                sum += numbers[left_pointer];
            }
        }

        vector<int> answer = {left_pointer+1, right_pointer+1};
        return answer;   

    }
};
