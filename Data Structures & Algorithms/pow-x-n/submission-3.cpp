    class Solution {
    public:
        double myPow(double x, int n) {

            if (x == 0){
                return 0;
            }

            if (n == 0 || x == 1){
                return 1;
            }

            double res = helper(x, abs(static_cast<long>(n)));  

            return (n >= 0) ? res : 1 / res;

        }

    private:
        double helper(double x, long n){    // 为啥这里要long?
            if (n == 0){
                return 1;
            }

            double half = helper(x, n / 2); // 先算一半出来

            if (n % 2 == 0){    // 正好还真是一半
                return half * half;         // 算出整个的公式就是这样
            }

            else{
                // half是少的那一半, x * 少的那一半 = 多的那一半
                return x * half * half;     // 算出整个的公式就是这样
            }

        }
    };
