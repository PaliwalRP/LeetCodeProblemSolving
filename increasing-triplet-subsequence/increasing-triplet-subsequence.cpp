class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = nums[0];
        int second = -1;
        for(int i = 1; i < nums.size(); i++){
            if(second != -1 && nums[i] > second){
                return true;
            }
            
            if(second == -1){
                if(nums[i] > first){
                    second = nums[i];
                }
            }
            else{
                if(nums[i] > first){
                    second = min(second, nums[i]);
                }
            }
            
            first = min(first, nums[i]);
        }
        return false;
    }
};