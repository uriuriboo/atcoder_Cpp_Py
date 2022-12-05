#include <bits/stdc++.h>
using namespace std;

/*前に大きい数が来るように*/

template <class T>
T GCD(T a, T b) {
	if (b == 0)
		return a;
	else
		return GCD(b, a % b);
}

template <class T>
inline T LCM(T a, T b) {
	 return (a * b) / GCD(a, b);
}

