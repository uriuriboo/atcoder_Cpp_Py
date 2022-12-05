#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)


//回転する点、回転中心。反時計回りに回転する角度
pair<double,double> rotate_point(double x,double y,double cx,double cy,double th){
    double resx,resy;
    resx = x * cos(th) - y * sin(th) + cx * (1 - cos(th)) + cy * sin(th);
    resy = x * sin(th) + y * cos(th) - cx * sin(th) + cy * (1 - cos(th));
    return make_pair(resx,resy);
}