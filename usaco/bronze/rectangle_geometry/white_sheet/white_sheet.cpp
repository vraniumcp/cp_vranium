// cpTest fileName.cpp (compiles and tests)    
// ./a.out < input.1.txt > res.1.txt
// cpMake dirName (optional 1 if want remake file)
//  g++ -std=c++17 fileName.cpp
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define all(x) (x).begin(),(x).end()
#define allr(x) (x).rbegin(),(x).rend()
#define pb push_back
#define ii pair<int,int>
#define vii vector<ii>
#define vi vector<int>
#define pi 2*acos(0.0)

#define F_OR(i, a, b, s) for (int i=(a); (s)>0?i<(b):i>(b); i+=(s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
#define FORE(x, a) for (auto& x: a)

#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
template<typename... Args> void read(Args&... args){ ((cin >> args), ...); }
template<typename... Args> void write(Args... args){ ((cout << args << " "), ...); }

struct Rect{
    ll x1,x2,y1,y2; // lower left and upper right corners
    ll area(){
        return (x2-x1)*(y2-y1);
    }
};

ll intersection(Rect a, Rect b){
    ll x_intersection = max(0LL,min(a.x2,b.x2) - max(a.x1,b.x1));
    ll y_intersection = max(0LL,min(a.y2,b.y2) - max(a.y1,b.y1));
    return x_intersection*y_intersection;
}



ll intersection(Rect a, Rect b, Rect c){
    ll x_intersection = max(0LL,min({a.x2,b.x2,c.x2}) - max({a.x1,b.x1,c.x1}));
    ll y_intersection = max(0LL,min({a.y2,b.y2,c.y2}) - max({a.y1,b.y1,c.y1}));
    return x_intersection*y_intersection;
}

void solve(){
    Rect white,b1,b2;
    read(white.x1,white.y1,white.x2,white.y2);
    read(b1.x1,b1.y1,b1.x2,b1.y2);
    read(b2.x1,b2.y1,b2.x2,b2.y2);
    ll not_covered_area = white.area() - intersection(white,b1) - intersection(white,b2) + intersection(white,b1,b2);
    debug(not_covered_area, white.area(), intersection(white,b1), intersection(white,b2), intersection(white,b1,b2)); 
    cout << (not_covered_area ? "YES" : "NO"); 
    
}
 
int main(){
	cin.tie(0);
	solve();
	return 0;
}
 
