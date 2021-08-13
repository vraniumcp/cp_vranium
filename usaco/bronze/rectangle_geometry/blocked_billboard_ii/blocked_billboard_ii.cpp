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

void setIO(string name) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
}

struct Rect{
    int x1,x2,y1,y2; // lower left and upper right corners
    int area(){
        return (x2-x1)*(y2-y1);
    }
};

int intersection(Rect a, Rect b){
    int x_intersection = max(0,min(a.x2,b.x2) - max(a.x1,b.x1));
    int y_intersection = max(0,min(a.y2,b.y2) - max(a.y1,b.y1));
    return x_intersection*y_intersection;
}

bool point_in_rectangle(Rect a, int x, int y){
    if(x >= a.x1 && x <= a.x2 && y >= a.y1 && y <= a.y2) return 1;
    return 0;
}
/*
1. if no overlap, cover lawn bb fully
2. if overlap, is it a clean or dirty intersection
    - dirty intersection means less than 2 corners are overlapping
    - more specifically, less than 2 corners of lawn bb are encompassed in cow bb
3. if clean intersection output area of intersection
4. if dirty intersection output entire area of lawn bb
*/
void solve(){
   Rect lawn_bb, cow_bb;
   read(lawn_bb.x1,lawn_bb.y1,lawn_bb.x2,lawn_bb.y2);
   read(cow_bb.x1,cow_bb.y1,cow_bb.x2,cow_bb.y2);

   int total_good_corners = 0;
   if(point_in_rectangle(cow_bb,lawn_bb.x1,lawn_bb.y1)) ++total_good_corners;
   if(point_in_rectangle(cow_bb,lawn_bb.x1,lawn_bb.y2)) ++total_good_corners;
   if(point_in_rectangle(cow_bb,lawn_bb.x2,lawn_bb.y1)) ++total_good_corners;
   if(point_in_rectangle(cow_bb,lawn_bb.x2,lawn_bb.y2)) ++total_good_corners;

   if(total_good_corners < 2){
      cout << lawn_bb.area();
   } else{
      cout << lawn_bb.area() - intersection(lawn_bb,cow_bb);
   }
}
 
int main(){
    setIO("billboard");
	cin.tie(0);
	solve();
	return 0;
}
 
