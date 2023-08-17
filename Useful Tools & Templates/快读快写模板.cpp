## �޷���ֵ�汾

```cpp
/* 
 * ʹ��δ������ getchar ���һ������  
 * ������ϵͳ��ʶ�������������Զ�����ϵͳ��ϢӦ��δ���� getchar  
 */

/*
#ifdef __LINUX__
#define getchar() getchar_unlocked()
#define putchar(a) putchar_unlocked(a)
#endif

#ifdef __WINDOWS__
#define getchar() _getchar_nolock()
#define putchar(a) _putchar_nolock()
#endif
 */ 
template <typename T> inline void input(T &x) {
	x = 0; char c = getchar(); bool f = false;
	for (; !isdigit(c); c = getchar()) f |= (c == '-');
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
	if (f) x = -x;
}
template <typename T, typename... Args>
void input(T &x, Args&... args) {
	input(x), input(args...);
}

template <typename T> inline void output(T x, char ed = '\n') {
	if (x < 0) putchar('-'), x = -x;
	static short st[20], top;
	do st[ ++ top] = x % 10, x /= 10; while (x);
	while (top) putchar(st[top -- ] | '0');
	putchar(ed);
}
template <typename T, typename ...Args>
void output(T x, char ch = ' ', Args... args) {
	output(x, ch);
	output(args...);
}


/* ����ʱ */
input(a, b, c);
output(a, ' ', b, ' ', c, ' ');
```

## �з���ֵ�汾

```cpp
/*
#ifdef __LINUX__
#define getchar() getchar_unlocked()
#define putchar(a) putchar_unlocked(a)
#endif

#ifdef __WINDOWS__
#define getchar() _getchar_nolock()
#define putchar(a) _putchar_nolock()
#endif
 */ 

template <typename T> struct INPUT {
	inline T operator()() {
		T x = 0; char c = getchar();
		bool f = false;
		for (; !isdigit(c); c = getchar()) f |= (c == '-');
		for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
		if (f) x = -x;
		return x;
	}
};
INPUT<int> input;

/* ����ʱ */
a = input();
```

## fread

const int L=1<<22;
char buf[L],*S,*T,pbuf[L],*P=pbuf;
#define getchar() (S==T&&(S=buf)==(T=buf+fread(buf,1,L,stdin)))?EOF:*S++;
