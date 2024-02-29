#include <bits/stdc++.h>
using namespace std;
int bit[200020];
int n,q;
vector<array<int,4>> even;

bool cmp(array<int,4>&xx,array<int,4>&yy){
  if(xx[1] == yy[1])return xx[2] < yy[2];
  return xx[1] < yy[1];
}

void add(int x,int q){
  for(int i = x;i<=n;i+=i&(-i)){
    bit[i] += q;
  }
}

int que(int x){
  int ans = 0;
  for(int i = x;i>0;i-=i&(-i)){
    ans += bit[i];
  }
  return ans;
}

int res[200020];

int main()
{
  cin >> n >> q;
  for(int i = 1;i<=n;i++){
    int x,y;
    cin >> x >> y;
    even.push_back({x,1,1,1});
    even.push_back({x,x,1,-1});
    even.push_back({x,y + 1,1,1});
    even.push_back({y + 1,1,1,-1});
    even.push_back({y + 1,x,1,1});
    even.push_back({y + 1,y + 1,1,-1});
  }
  for(int i = 1;i<=q;i++){
    int x,y;
    cin >> x >> y;
    even.push_back({x,y,2,i});
  }

  sort(even.begin(),even.end(),cmp);
  
  for(auto& ele : even){
    if(ele[2] == 1){
      add(ele[0],ele[3]);
    }
    else{
      res[ele[3]] = que(ele[0]);
    }
  }

  for(int i = 1;i<=q;i++){
    cout << res[i] << '\n';
  }
  return 0;
}
