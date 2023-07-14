#include <iostream>
#include <sstream>
using namespace std;
string ver_string(int a, int b, int c) {
	ostringstream ss;
	ss << a << '.' << b << '.' << c;
	return ss.str();
}

int main() {
	string true_cxx =
    #ifdef __clang__
    	"clang++";
    #else
    	"g++";
    #endif
    cout << true_cxx << ' ';

	string true_cxx_ver =
    #ifdef __clang__
    	ver_string(__clang_major__, __clang_minor__, __clang_patchlevel__);
    #else
    	ver_string(__GNUC__, __GNUC_MINOR__, __GNUC_PATCHLEVEL__);
    #endif

	cout << true_cxx_ver << endl;
	
	return 0;
}
