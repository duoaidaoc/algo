#include<bits/stdc++.h>
using namespace std;
const int N = 2*1e6 + 20;

int p,q;
char str[N];
struct even{
	int l,r,id,blk;
}ev[N];

long long t[N];
long long res[N];
long long ans = 0;

bool cmp(even a,even b){
	if(a.blk == b.blk){
		return a.r < b.r;
	}
	return a.blk < b.blk;
}
int cnt[N];
void add(int x){
	ans += cnt[t[x]];
	cnt[t[x]]++;
}
void del(int x){
	cnt[t[x]]--;
	ans -= cnt[t[x]];
}

long long spos[N],scnt[N];
int main(){
	scanf("%d",&p);
	getchar();
	scanf("%s",str + 1);
	int len = strlen(str + 1);
	if(p==2 || p==5){
		scanf("%d",&q);
		set<int>st;
		if(p == 2){
			st.insert(0);st.insert(2);st.insert(4);st.insert(6);st.insert(8);
		}
		else{
			st.insert(0);st.insert(5);
		}
		
		for(int i = 1;i<=len;i++){
			int ok = st.count(str[i] - '0');
			spos[i] = spos[i - 1] + ok * i;
			scnt[i] = spos[i - 1] + ok;
		}
		
		for(int i = 1;i<=q;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			printf("%lld\n",spos[y] - spos[x-1] - (scnt[y] - scnt[x-1])*(x-1));
		}
		
		return 0;
	} 
	long long tmp = 1;
	for(int i = len;i>=1;i--){
		t[i] = (t[i + 1] + (str[i] - '0') * tmp % p) % p;
		tmp = tmp * 10 % p;
	}
	vector<pair<long long,int> >ttp;
	for(int i = 1;i<=len + 1;i++){
		ttp.push_back(make_pair(t[i],i));
	}
	sort(ttp.begin(),ttp.end());
	tmp = 0;
	for(int i = 0;i<=len;i++){
		if(i == 0|| ttp[i].first != ttp[i - 1].first)tmp++;
		t[ttp[i].second] = tmp;
	}
//	for(int i = 1;i<=len;i++)printf("%lld ",t[i]);printf("\n");
	scanf("%d",&q);
	int sqn = (int)sqrt(len);
	for(int i = 1;i<= q;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		ev[i].l = x;
		ev[i].r = y + 1;
		ev[i].id = i;
		ev[i].blk = x / sqn;
	}
	sort(ev+1,ev+q+1,cmp);
	int l = 1,r = 0;
	for(int i = 1;i<=q;i++){
		while(l < ev[i].l){
			del(l);
			l++;
		}
		while(l > ev[i].l){
			l--;
			add(l);
		}
		while(r < ev[i].r){
			r++;
			add(r);
		}
		while(r > ev[i].r){
			del(r);
			r--;
		}
		res[ev[i].id] = ans;
	}
	for(int i = 1;i<=q;i++){
		printf("%lld\n",res[i]);
	}
}
