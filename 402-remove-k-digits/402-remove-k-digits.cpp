class Solution {
  public:
    string removeKdigits(string num, int k) {
      int stringLength = num.size();
      if (stringLength == k) {
        return "0";
      }
      stack < char > S;
      int n = k, idx = 0;
      while (idx < stringLength) {
        int currentNumber = num[idx] - '0';
        while(n > 0 && !S.empty() && (S.top()-'0') > currentNumber)
        {
                n--;
                S.pop();
        }
        S.emplace(num[idx]);
        idx++;
      }

      while(n>0)
      {
         S.pop();
         n--;
      }

      string result;
      while (!S.empty()) {
        char digit = S.top();
        S.pop();
        result += digit;
      }


      idx = result.size() - 1;
      while (idx >= 0) {
        char digit = result[idx];
        if (digit - '0' > 0) {
          break;
        }
        result.erase(idx);
        idx--;
      }
      reverse(result.begin(), result.end());
      if(result == "") result = "0";
      return result;
    }
};