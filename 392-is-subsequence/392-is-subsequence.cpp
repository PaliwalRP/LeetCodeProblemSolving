// U_069_1 & U_069_2 Umesh Paliwal (roll no 1928069)
class Solution {
   public:
    bool isSubsequence(string U_069_1, string U_069_2) {
        int n = U_069_1.size(), m = U_069_2.size(), j = 0;
        if (n > m) return false;
        if (n == m) return U_069_1 == U_069_2;
        if (m == 0) return false;
        if (n == 0) return true;
        for (int i = 0; i < m; i++) {
            if (U_069_1[j] == U_069_2[i]) {
                if (j == n - 1) return true;
                j++;
            }
        }
        return false;
    }
};