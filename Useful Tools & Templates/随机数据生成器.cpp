#include <cstdio>
#include <cstdlib>
#include <ctime>
ll random(ll mod);
int main()
{
    srand(time(0));
	/*
	 * ����������ӣ�time(0) ��Ҫ�õ� ctime �� 
	 * �������������ӣ����ɵ������ÿ�ζ���һ���� 
	 */
    printf("%d %d\n", rand(), rand());
	/*
	 * ������������Ҫ��Χ����ʱ�����Բ��� % + ���������� 
	 * ע�������Ŀ�����������ʽ���и��� 
	 */
}
/*
 * Ȼ�� Windows�� rand() ���ɵķ�Χ�� 0~32767 ֮�� 
 * ��εõ��� 32767 �����������أ�
 * ����������Ķ� 
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
// ��ȡ 0 ~ mod - 1 ֮�������� 
    srand((unsigned)time(0));
    ll n;
    while (1){
        n = random(1000000);
        // ��ȡ 0 ~ 999999 ֮�������� 
        cout << n << endl;
    }
    
/*
 * ���⣬��������ʹ�� c++11�е� mt19937 ��ȡ������� 
 * ��������ʱ��ǰ�� �� 
 */

#include <random> // ʹ�� random ͷ�ļ�  

mt19937 mt_rand(time(0)); // ����������� 
// ����ʱʹ�� 
mt_rand() % MOD;
