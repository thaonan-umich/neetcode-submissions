class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        stack<int> ustack;
        
        for (string token : tokens){

            // string to char
            if (token != "+" && token != "-" && token != "*" && token != "/"){
                int num = stoi(token);
                ustack.push(num);
            }
            else{
                // +, -, *, /
                int num2 = ustack.top();
                ustack.pop();
                int num1 = ustack.top();
                ustack.pop();
                int result = 0;

                if (token == "+"){
                    result = num1 + num2;
                }
                if (token == "-"){
                    result = num1 - num2;
                }
                if (token == "*"){
                    result = num1 * num2;
                }
                if (token == "/"){
                    result = num1 / num2 ;
                }
                ustack.push(result);
            }
        }

        return ustack.top();
    }
};
