class Solution {
    
    vector<int> p;

    int Find(int n)
    {
        if (p[n] == -1) return n;
        p[n] = Find(p[n]);
        return p[n];
    }
    void Union(int a, int b)
    {
        a = Find(a);
        b = Find(b);
	    if (a != b)
            p[b] = a;
    }

public:
	string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
		int n = s.size();
		p = vector<int>(n, -1);
		for (int i = 0; i<pairs.size(); i++) {
			Union(pairs[i][0], pairs[i][1]);
		}

		map<int, priority_queue<char, vector<char>, greater<char>>> m; 
		for (int i = 0; i<n; i++) {
			m[Find(i)].push(s[i]);
		}
		string ans = "";
		for (int i = 0; i<n; i++) {
			char now = m[Find(i)].top();
			m[Find(i)].pop();
			ans.push_back(now);
		}

		return ans;
	}

};