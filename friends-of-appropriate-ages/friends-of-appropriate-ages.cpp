class Solution {
public:
    bool check(int a, int b){
        bool ok = 1;
        if(2*b <=a+14 or b>a or b>100 and a<100)
            ok = 0;
        return ok;
    }
    
    int numFriendRequests(vector<int>& ages) {
        unordered_map<int,int>count;
        for(int i=0; i<ages.size(); i++)
            count[ages[i]]++;
        int ans=0;
        for(auto a:count){
            for(auto b:count){
                if(check(a.first,b.first))
                ans = ans+a.second*(b.second-(a.first==b.first?1 :0));
            }
        }
        return ans;
    }
};