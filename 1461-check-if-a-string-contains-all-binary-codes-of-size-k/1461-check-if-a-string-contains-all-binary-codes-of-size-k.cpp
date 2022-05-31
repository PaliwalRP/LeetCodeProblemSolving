class Solution {
public:
    bool hasAllCodes(string s, int k) {
        set<string> strOcc; int n = s.size();
        
        string temp = s.substr(0,k);
        for(int i = 0 ; i <= n - k ; i++) strOcc.insert(temp), temp.erase(0,1), temp += s[i+k];
        return (strOcc.size() >= (1 << k));
    }
};