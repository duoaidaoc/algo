#include <bits/stdc++.h>

using namespace std;

const int N = 1e6+20;

int nex[N];
int n;
string s1,s2;
void crn(){
	nex[0] = -1;
	int i = 0,j = -1;
	while(i < n){
		if(j == -1 || s2[i] == s2[j])nex[++i] = ++j;
		else j = nex[j];
	}
}
void kmp(){
	int i = 0, j = 0;
	while(i < 2 * n){
		if(s1[i] == s2[j])i++,j++;
		else{
			j = nex[j];
			if(j == -1){
				i++,j++;
				continue;
			}
		}
		if(j == n)//Æ¥Åä³É¹¦
		{
			cout << "Yes\n" << min(i - n,2 * n - i);
  			return;
		}
	}
	cout << "No\n";
}


int main()
{
  cin >> n;
  getchar();
  cin >> s1 >> s2;
  for(int i = 0;i < n;i++){
    if(s1[i]<='z' && s1[i]>='a')
      s1[i] = s1[i] - 'a' + 'A';
    else
      s1[i] = s1[i] - 'A' + 'a';
  }
  s1 += s1;
  crn();
  kmp();
  
}
