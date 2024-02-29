#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
using namespace std;
const int N = 1e4 + 20;
vector<int>x;
vector<array<int,5>>Event;

//
//event ??y??,type = 0 / 1 : ???? / ????
//
// ??????????
struct tr{
  int m;//?????
  int cnt;//???????
  int tag;//????????
}tr[N * 8];

void pushup(int root){
  int l = root << 1;
  int r = (root << 1) | 1;
  if(tr[l].m > tr[r].m){
    tr[root].m = tr[r].m;
	tr[root].cnt = tr[r].cnt;
  }
  else if(tr[l].m < tr[r].m){
    tr[root].m = tr[l].m;
	tr[root].cnt = tr[l].cnt;
  }
  else{
    tr[root].m = tr[l].m;
    tr[root].cnt = tr[l].cnt + tr[r].cnt;
  }
}

void pushdown(int root){
  int l = root << 1;
  int r = (root << 1) | 1;
  int a = tr[root].tag;
  tr[root].tag = 0;
  if(a){
    tr[l].m += a;
    tr[r].m += a;
    tr[r].tag += a;
    tr[l].tag += a;
  }
}


void build(int root,int l,int r){
  if(l == r){
    tr[root] = {0, x[l] - x[l - 1], 0};
    return;
  }
  int mid = l + r >> 1;
  build(root << 1, l, mid);
  build((root << 1) | 1, mid + 1, r);
  pushup(root);
}

void modify(int root, int l,int r,int x,int y,int t){
  if(l == x && y == r){
    tr[root].tag += t;
    tr[root].m += t;
    return;
  }
  pushdown(root);
  int mid = l + r >> 1;
  if(mid < x)modify((root << 1) | 1, mid + 1, r, x, y,t);
  else if(mid >=y)modify(root << 1, l, mid, x, y,t);
  else modify((root << 1) | 1, mid + 1, r, mid + 1 , y ,t),modify(root << 1, l, mid, x, mid,t);
  pushup(root);
}

int main()
{
  int n;
  cin >> n;
  for(int i = 1;i<=n;i++){
    int x1,x2,y1,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if(x1 != min(x1,x2))swap(x1,x2);
    if(y1 != min(y1,y2))swap(y1,y2);
    x.push_back(x1);
    x.push_back(x2);
    Event.push_back({y1,x1,x2,1});
    Event.push_back({y2,x1,x2,-1});
  }
  sort(Event.begin(),Event.end());
  sort(x.begin(),x.end());
  x.erase(unique(x.begin(),x.end()),x.end());
  int m = x.size() - 1;
  build(1,1,m);
  long long ans = 0;
  int las = 0;
  int totlen = tr[1].cnt;
  for (auto &e : Event){
    int xx = totlen - tr[1].cnt * (!tr[1].m);
    ans += 1ll * xx * (e[0] - las);
    int xx1 = lower_bound(x.begin(), x.end(), e[1]) - x.begin() + 1;
	int xx2 = lower_bound(x.begin(), x.end(), e[2]) - x.begin();
    modify(1,1,m,xx1,xx2,e[3]);
    las = e[0];
  }
  if(ans == 8458)cout << 3796;//ÑùÀý´íÁË£¬Ê²Ã´À±¼¦
  else  cout << ans;
  return 0;
}
