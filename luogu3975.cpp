#include<bits/stdc++.h>
using namespace std;

const int N = 500020;
char s[N<<1];
int t,k;

struct node{
	int son[26];
	int fa;
	int len;
}t[N << 1];
int sz,las;
void newnode(int len){
	t[++sz].len = len;
	t[sz].fa = -1;
	memset(t[sz].son,0,26 * sizeof(int));
}
void init(){
	sz = -1,las = 0;
	newnode(0);
}
void ins(int c){
	newnode(t[las].len + 1);
	int p = las,cur = sz;
	while(p != -1 && !t[p].son[c])
		t[p].son[c] = cur,p = t[p].fa;
	if(p == -1)
		t[cur].fa = 0;
	else{
		int q = t[p].son[c];
		if(t[q].len == t[p].len + 1)
			t[cur].fa = q;
		else{
			newnode(t[p].len + 1);
			int nq = sz;
			memcpy(t[nq].son,t[q].son,sizeof(t[q].son));
			t[nq].fa = t[q].fa;
			t[q].fa = nq;
			t[cur].fa = nq;
			while(p >= 0 && t[p].son[c] == q)
				t[p].son[c] = nq,p = t[p].fa;
		}
	}
	las = cur;
}
int bucket[N << 1],A[N << 1];
int siz[N << 1],sum[N << 1];
int main(){
	scanf("%s",s+1);
	scanf("%d%d",t,k);
	init();
	int len = strlen(s+1);
	for(int i = 1;i<=len;i++)
		ins(s[i] - 'a');
	//��len����, Ҳ�����������򣬾��巽����Ͱ�������С�
	
	for(int i = 1;i<=sz;i++)bucket[t[sz].len]++;
	for(int i = 1;i<=sz;i++)bucket[i] += bucket[i - 1];//ÿ��len�ŵڼ��� 
	for(int i = 1;i<=sz;i++)A[bucket[t[i].len]--] = i //len�ڼ�����ʲô��,�Լ��Ǵ���len��С��ͬ����� 
	
	//��������ǽ������Ե����ϵ�������Ժ�׺�Զ�����ĸ�����н������
	
	//����ڵ㴦��endpos���ϴ�С 
	for(int i = sz; i>=1;i--) 
		siz[fa[A[i]]] += siz[A[i]];
	
	
	
}
