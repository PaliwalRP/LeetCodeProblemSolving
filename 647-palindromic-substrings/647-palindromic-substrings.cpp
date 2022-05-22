class Solution {
public:
    int helper(string s, int left, int right, int n){
        int cnt=0;
        while(left>=0 and right<n){
            if(s[left]==s[right]) {
                cnt++;
                left--;right++;
            }
            else break;
        }
        return cnt;
    }
    int countSubstrings(string s) {
        int n=s.size();
        int cnt=0;
        for(int i=0; i<n; i++){
            cnt+=helper(s,i,i,n);
            cnt+=helper(s,i,i+1,n);
        }
        return cnt;
    }
};