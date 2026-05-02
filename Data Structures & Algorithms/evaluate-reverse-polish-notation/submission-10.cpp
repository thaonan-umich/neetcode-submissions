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
                cout << num2 << endl;
                ustack.pop();
                int num1 = ustack.top();
                cout << num1 << endl;
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

                cout << result << endl;
                ustack.push(result);
            }
        }

        return ustack.top();
    }
};
