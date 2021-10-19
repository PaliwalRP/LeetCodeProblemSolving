class Solution {
public:
            vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {                     vector<int> t;
                
                                                                                                                for(int i = 0; i < nums1.size(); i++){
                    int a = -1;
                    for(int j = nums2.size() - 1; nums2[j] != nums1[i]; j--){ 
                        if(nums2[j] > nums1[i]) {
                            a = nums2[j];
                        }
                    }
                    t.push_back(a);
                    
                                                                                                                }                                                                                            return t;
            }
};