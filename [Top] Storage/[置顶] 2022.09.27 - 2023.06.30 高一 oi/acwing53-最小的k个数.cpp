class Solution {
public:
    vector<int> getLeastNumbers_Solution(vector<int> input, int k) {
        sort(input.begin(), input.end());
        vector<int> ans;
        for (int i = 0 ;i < k; i ++)
        	ans.push_back(input[i]);
        	return ans;
        	
    }
};
