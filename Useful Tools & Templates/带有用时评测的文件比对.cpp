#include <iostream>
#include <cstdio>
#include <windows.h>
#include <cstdlib>
#include <ctime>
using namespace std;
int tot, cnt, ac;

int main() {
//	for (int cnt = 1; cnt <= (tot = 1000); ++ cnt) {
	while (++ cnt) {
        system("data.exe > data.in");
        system("test.exe < data.in > test.out");
        double begin = clock();
        system("bf.exe < data.in > bf.out");
        double end = clock();
        double t = end - begin;
        if (system("fc test.out bf.out")) {
            printf("Test#%d Wrong Answer\n", cnt);
            return 0;
        } else if (t > 1000) {
            printf("Test#%d Time Limited Exceeded with Time %.0lfms\n", cnt, t);
        } else {
            printf("Test#%d Accepted with time %.0lfms\n", cnt, t);
            ac ++;
        }
    }
    printf("\n");
//	printf("AC %d Tests out of %d Tests in totle\n", ac, tot);
    return 0;
}

