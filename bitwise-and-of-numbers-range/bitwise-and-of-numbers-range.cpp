class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int k=0;
        while (1) {
            if (n>m){
               k = k + 1;  
            }else{
                return m << k;
            }
            m = m >> 1;
            n = n >> 1;
        }
        return m;
    }
};