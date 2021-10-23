#include <iostream>
class Solution {
public:
    string multiply(string num1, string num2) {
        int size1 = num1.size();
        int size2 = num2.size();
        string result(size1+size2, '0');
        int add = 0;
        
        for (int i = size1-1; i >= 0; i--){
            for (int j = size2-1; j >= 0; j--){
                int tmp = (result[i+j+1]-'0') + (num1[i]-'0')*(num2[j]-'0') + add;
                result[i+j+1] = tmp%10 + '0';
                add = tmp/10;
            }
            if (add > 0){
                result[i] = add + '0';  
            }
            add = 0;
        }
        int idx = 0;
        while (result[idx] == '0' && idx < size1+size2-1)idx++;
        result = result.substr(idx);
        return result;
    }
};