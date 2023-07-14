class Solution {
public:
    vector<int> findNumbersWithSum(vector<int>& nums, int target) {
        unordered_set<int> s;
        for (auto x : nums)
        {
        	if (s.count(target - x))
        		return {x, target - x};
        	s.insert(x);
		}
    }
};

/*
class Solution {
public:
    vector<int> findNumbersWithSum(vector<int>& nums, int target) {
        bool hax[1010] = {0};
        hax[0] = 1;
        for (int i = 0; i < nums.size(); i ++)
        {
        	if (hax[target - nums[i]])
        	{
        		vector<int> ans;
        		ans.push_back(nums[i]);
        		ans.push_back(target - nums[i]);
        		return ans;
        		//return {nums[i], target - nums[i]};
			}
			else
			{
				hax[nums[i]] = 1;
			}
		}
    }
};
*/

