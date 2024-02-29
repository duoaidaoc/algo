#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long

const int N = 233333;
int n,m,Bsize = 1;
int a[N],buc[1000011];
int ans,res[N];
struct que{
	int l,r,tim,id;
}vec[N];
int vecsize = 0;
struct mod{
	int pos,nw;
}mod[N];
int modcnt = 0;

int l = 1, r = 0,t = 0;
bool cmp(const que& X,const que& Y){
	return X.l/Bsize == Y.l/Bsize ? (X.r == Y.r ? X.tim < Y.tim : X.r < Y.r) : X.l < Y.l;
}
inline void add(const int &val){
	ans += !buc[val]++;

}
inline void del(const int &val){
	ans -= !--buc[val];
}
inline void modify(const int &t){
	if(l<= mod[t].pos && mod[t].pos <= r){	
		del(a[mod[t].pos]);
		add(mod[t].nw);
	}
	swap(a[mod[t].pos],mod[t].nw);
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i = 1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int cnt = 0;
	for(int i = 1;i<=m;i++){
		char x[5];
		int y,z;
		scanf("%s%d%d",x,&y,&z);
		if(x[0] == 'Q'){
			vec[++vecsize] = {y,z,modcnt,++cnt};
		}
		else{
			mod[++modcnt] = {y,z};
		}
	}
	Bsize = int(pow(double(n), 0.666));
	sort(vec+1,vec+vecsize+1,cmp);
	for(int i = 1;i<=vecsize;i++){
		while(r < vec[i].r){
			r++;
			add(a[r]);
		}
		while(r > vec[i].r){
			del(a[r]);
			r--;
		}
		while(l < vec[i].l){
			del(a[l]);
			l++;
		}
		while(l > vec[i].l){
			l--;
			add(a[l]);
		}
		while(t < vec[i].tim){
			t++;
			modify(t);
		}
		while(t > vec[i].tim){
			modify(t);
			t--;
		}
		res[vec[i].id] = ans;
	}
	for(int i = 1;i <= cnt;i++){
		printf("%d\n",res[i]);
	}
	return 0;
}
