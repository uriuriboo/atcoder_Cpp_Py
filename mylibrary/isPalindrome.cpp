#include <bits/stdc++.h>
using namespace std;

bool ispal(string s){
    string t = s;
    reverse(t.begin(),t.end());
    return s == t;
}