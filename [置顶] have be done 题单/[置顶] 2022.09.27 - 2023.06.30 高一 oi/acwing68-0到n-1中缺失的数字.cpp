class Solution {
public:
    int getMissingNumber(vector<int>& nums) {
        unordered_set <int> s;
        for (int i = 0; i <= nums.size(); i ++)
        	s.insert(i);
        for (auto x : nums) s.erase(x);
        
        return *s.begin();
    }
};
