class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& v) {
        sort(v.begin(),v.end());
        
        vector<vector<int>> ans;
        
        for(int i=0; i<v.size(); i++){
            
            if(i==0 or (i>0 and v[i] !=v[i-1])){
                int a =-v[i];
                int low = i+1;
                int high=v.size()-1;
                
                while(low<high){
                if(v[low] + v[high] == a){
                    vector<int>temp;
                    temp.push_back(v[i]);
                    temp.push_back(v[low]);
                    temp.push_back(v[high]);
                    ans.push_back(temp);
                   // temp.clear();
                  //  low++; high--;
                    
                    while(low<high and v[low]==v[low+1]) low++;
                    while(low<high and v[high]==v[high-1]) high--;
                    low++; high--;
                }
                    
                    else if(v[low]+v[high]<a){
                        low++;
                    }
                    else{
                        high--;
                    }
                
                }
            }
        }
        return ans;
    }
};