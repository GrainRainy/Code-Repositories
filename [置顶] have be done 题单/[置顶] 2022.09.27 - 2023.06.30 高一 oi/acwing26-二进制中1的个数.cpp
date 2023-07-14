class Solution {
public:
    int NumberOf1(int n) {
        int res = 0;
        while (n)
        {
        	if (n & -n) res ++;
			n -= n & -n;
        	
        	n >> 1;
		}
		return res;
    }
};
