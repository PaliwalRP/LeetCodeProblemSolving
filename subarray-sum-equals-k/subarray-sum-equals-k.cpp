class Solution {
public:
    int subarraySum(vector<int>& v, int k) {
        int lsum=0;
        int count=0;
        if(v.size()==1){
            if(v[0]==k) count++;
            return count;
        }
        unordered_map<int,int> mp;
        // int lsum=0;
        // int count=0;
            for(int i=0; i<v.size(); i++){
                lsum=lsum+v[i];
                if(lsum==k) count++;
                
                if(mp.find(lsum-k) !=mp.end()){
                    count=count+mp[lsum-k];
                }
                 mp[lsum]++;
            }
        return count;
    }
};