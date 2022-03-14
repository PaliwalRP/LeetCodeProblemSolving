class Solution {
   public:
    string simplifyPath(string path) {
        istringstream ss(path);
        string dir;
        stack<string> st;
        while (getline(ss, dir, '/')) {
            if (!st.empty() && dir == "..") {
                st.pop();
            } else if (dir != ".." && dir != "." && dir != "") {
                st.push(dir);
            }
        }
        string ans = "";
        vector<string> arr = stackToArray(st);
        reverse(arr.begin(), arr.end());
        for (const auto &ele : arr) {
            ans += "/";
            ans += ele;
        }
       
        return ans.empty() ? "/" : ans;
    }

    vector<string> stackToArray(stack<string> &st) {
        vector<string> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};