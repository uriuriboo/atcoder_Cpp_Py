#include <bits/stdc++.h>
using namespace std;

/*nが素数であるかbool型で判定*/
bool isPrime(int n){
    if(n == 2)
        return true;

    for(int i = 2;i*i <= n;i++){
        if(n%i == 0)
            return false;
    }

    return true;
}
