#include <cstdio>
#include <cstdlib>
#include <ctime>
ll random(ll mod);
int main()
{
    srand(time(0));
	/*
	 * 生成随机种子，time(0) 需要用到 ctime 库 
	 * 如果不加随机种子，生成的随机数每次都是一样的 
	 */
    printf("%d %d\n", rand(), rand());
	/*
	 * 当输入数据需要范围限制时，可以采用 % + 等运算生成 
	 * 注意根据题目中输入输出样式自行更改 
	 */
}
/*
 * 然而 Windows下 rand() 生成的范围在 0~32767 之间 
 * 如何得到比 32767 更大的随机数呢？
 * 请接着往下阅读 
 */
ll random(ll mod){
    ll n1, n2, n3, n4, ans;
    n1 = rand();
    n2 = rand();
    n3 = rand();
    n4 = rand();
    ans = n1 * n2 % mod;
    ans = ans * n3 % mod;
    ans = ans * n4 % mod;
    return ans;
}
// 获取 0 ~ mod - 1 之间的随机数 
    srand((unsigned)time(0));
    ll n;
    while (1){
        n = random(1000000);
        // 获取 0 ~ 999999 之间的随机数 
        cout << n << endl;
    }
    
/*
 * 另外，您还可以使用 c++11中的 mt19937 获取大随机数 
 * 助您走在时代前沿 ！ 
 */

#include <random> // 使用 random 头文件  

mt19937 mt_rand(time(0)); // 传入随机种子 
// 调用时使用 
mt_rand() % MOD;
