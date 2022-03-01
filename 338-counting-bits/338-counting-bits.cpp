//UMESH PALIWAL 1928069(ROLL NO)
class Solution {
  public:
	vector<int> countBits(int u_069) {
		vector<int> ans(u_069 + 1);
		ans[0] = 0;
		for (int i = 0; i <= u_069; i++) {
			if ((i * 2) <= u_069) {
				ans[i * 2] = ans[i];
			}
			if ((i * 2) + 1 <= u_069) {
				ans[(i * 2) + 1] = ans[i] + 1;
			}
		}
		return ans;
	}
};