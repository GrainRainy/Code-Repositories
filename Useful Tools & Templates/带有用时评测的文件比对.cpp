#include <iostream>
#include <cstdio>
#include <windows.h>
#include <cstdlib>
#include <ctime>
using namespace std;
int main(){
    int n = 50, ok = 0;
    for (int i = 1; i <= n; ++i){
        system("make.exe > make.txt");
        system("mysol.exe < make.txt > mysol.txt");
        double begin = clock();
        system("std.exe < make.txt > std.txt");
        double end = clock();

        double t = (end - begin);
        if (system("fc mysol.txt std.txt")) {
            printf("Test#%d Wrong Answer\n", i);
            return 0;
        } else if (t > 1000) {
            printf("Test#%d Time Limited Exceeded with Time %.0lfms\n", i, t);
        } else {
            printf("Test#%d Accepted with time %.0lfms\n", i, t);
            ok ++;
        }
    }
    printf("\n");
    printf("AC %d Tests out of %d Tests in totle\n", ok, n);
    Sleep(1000);
    return 0;
}

