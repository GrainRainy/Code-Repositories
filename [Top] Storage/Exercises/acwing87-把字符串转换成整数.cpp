	class Solution {
	public:
	    int strToInt(string str) 
		{
			int k = 0;
			long long res = 0;
			while (k < str.size() && str[k] == ' ') k ++;
			//���˿ո� 
			bool flag = 0;
			if (k < str.size())
				if (str[k] == '-') 
				{
					flag = 1;
					k ++;
				}
				else if (str[k] == '+') k ++;
			//���˵���������� 
			for (k; k < str.size() && str[k] >= '0' && str[k] <= '9'; k ++)
			{
				res = res * 10 + str[k] - '0';
				if (res > 1e11) break;
			}
				
			
			if (flag) res *= -1;
			if (res > INT_MAX) return INT_MAX;
			if (res < INT_MIN) return INT_MIN; 
			return res;
	    }
	};
