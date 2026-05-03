class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        // 1. Init
        vector<int> answer(temperatures.size(), 0);
        stack<int> istack;
        int pointer = 0;

        // 2. Loop
        while (pointer < temperatures.size()) {

            int curr_element = temperatures[pointer];

            // 2.1 Case 1 & 2
            if (istack.empty() || temperatures[istack.top()] >= curr_element) {
                istack.push(pointer);
            }

            // 2.2 Case 3
            else {
                while (!istack.empty() && temperatures[istack.top()] < curr_element) {
                    int index = istack.top();
                    answer[index] = pointer - index;
                    istack.pop();
                }
                istack.push(pointer);
            }

            pointer++;
        }

        // 3. Return
        return answer;
    }
};