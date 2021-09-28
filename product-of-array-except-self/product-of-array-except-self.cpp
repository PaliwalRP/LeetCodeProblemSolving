class Solution {
public:
    vector<int> productExceptSelf(vector<int>& v) {
        int n = v.size();
        vector<int> a(n);
        int product =1;
        for(int i=0; i<n; i++){
            product = product*v[i];
            a[i] = product;
        }
        a[0] = v[0];
        
         product = 1;
        
        for(int i=n-1; i>0; i--){
            a[i] = a[i-1] * product;
            product=product*v[i];
        }
        a[0] = product;
        return a;
        
    }
};