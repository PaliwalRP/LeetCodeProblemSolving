class Solution {
public:
    vector<vector<int>>v;
    set<vector<int>>s;
    void solve(vector<int> nums,int n, int index){
        if(index==n){
            s.insert(nums);
            return;
        }
        for(int i=index; i<n; i++){
            swap(nums[i],nums[index]);
            solve(nums,n,index+1);
            swap(nums[i],nums[index]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n=nums.size();
        solve(nums,n,0);
        for(auto i:s){
            v.push_back(i);
        }
        return v;
    }
};