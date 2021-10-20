class Solution {
public:
    string reverseWords(string s) {
        string temp="";
        int n=s.length();int c=1;
        vector<string> res;
        for(int i=0;i<n;i++){
            if(s[i]==' '){
                if(c==0 )
                res.push_back(temp);
                c++;
                temp="";
            }else{
                c=0;
                temp+=s[i];
            }
        }
        if(temp!=""){
            res.push_back(temp);
        }
        string r="";
        int st=res.size();
        for(int i=st-1;i>=0;i--){
            r+=res[i];
            if(i!=0){
                r+=' ';
            }
        }
        return r;
    }
};