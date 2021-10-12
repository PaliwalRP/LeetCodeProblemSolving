class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        if(s1.size()>s2.size()) return false;
        
        vector<int> count_s1(26,0);
        vector<int> count_s2(26,0);
        
        int right = 0, left =0;
        
        while(right<s1.size()){
            count_s1[s1[right]-'a']++;
            count_s2[s2[right]-'a']++;
            right++;
        }
        right--;
        while(right<s2.size()){
            if(count_s1==count_s2) return true;
            
            right++;
            if(right != s2.size()){
                count_s2[s2[right]-'a']++;
                count_s2[s2[left]-'a']--;
                left++;
            }
        }
        return false;
    }
};