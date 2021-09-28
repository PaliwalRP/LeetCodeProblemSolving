class Solution {
public:
    vector<int> twoSum(vector<int>& v, int t) {
        map<int,int> mp;
        for(int i=0; i<v.size(); i++){
           
            int x=v[i];
            int y = t-x;
            if(mp.find(y)!=mp.end()){
                return{i,mp[y]};
            }
            mp[v[i]] = i;
        
        }
        return{-1,-1};
        
        
        
        
        
        
        
        
        
//         for(auto i:mp){
            
//         }
        
//         map<int,int>::iterator i = mp.begin();
//         map<int,int>::iterator j = mp.end();
        
//         vector<int>ans;
//         while(i!=j){
//             if(i->first+j->first==t){
//                 ans.push_back(i->second);
//                 ans.push_back(j->second);
//                 break;
//             }
            
//             else if(i->first+j->first>t){
//                 j--;
//             }
            
//             else if(i->first+j->first<t){
//                 i++;
//             }
//         }
//         return ans;
    }
};