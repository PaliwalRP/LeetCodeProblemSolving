class Solution {
public:
    int isPalindrome(string&s){
        int i=0,j=s.size()-1;
        while(i<j){
            if(s[i]!=s[j]){
                return 0;
            }
            i++;j--;
        }
        return 1;
    }
    int removePalindromeSub(string s) {
        bool check = isPalindrome(s);
        if(check){
            return 1;
        }
        else return 2;
    }
};