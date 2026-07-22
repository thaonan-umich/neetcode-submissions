// 双指针写法
/*


搜完这个盘
          j →
          0    1    2    3    4
       ┌────┬────┬────┬────┬────┐
i = 0  │ a  │ ab │ aba│abab│ababa
       ├────┼────┼────┼────┼────┤
i = 1  │    │ b  │ ba │ bab│baba
       ├────┼────┼────┼────┼────┤
i = 2  │    │    │ a  │ ab │ aba
       ├────┼────┼────┼────┼────┤
i = 3  │    │    │    │ b  │ ba
       ├────┼────┼────┼────┼────┤
i = 4  │    │    │    │    │ a
       └────┴────┴────┴────┴────┘
       
*/

class Solution {
public:
    int countSubstrings(string s) {
       int n = s.size();
       int res = 0;

       for (int i = 0; i < n; i++){
           
           // odd condition
           int left = i;
           int right = i;

           while (left >= 0 & right <= n){
              if (s[left] == s[right]){
                  res++;
                  left--;
                  right++;
              }
              else{
                  break;
              }
           }

           // even condition
           left = i;
           right = i+1;

           while (left >= 0 & right <= n){
              if (s[left] == s[right]){
                  res++;
                  left--;
                  right++;
              }
              else{
                  break;
              }
           }
       }

       return res;
        
    }
};
