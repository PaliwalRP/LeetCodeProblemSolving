class Solution {
public:
    void nextPermutation(vector<int>& v) {
        int n = v.size(), k,l;
        
        for(k = n-2; k>=0; k--){
            if(v[k]<v[k+1])
                break;
        }
        if(k<0){
            reverse(v.begin(),v.end());
        }
        
        else{
        for(l=n-1; l>k; l--){
            if(v[k]<v[l])
                break;
        }
        
        swap(v[k],v[l]);
        reverse(v.begin()+k+1,v.end());
      }
    }
};