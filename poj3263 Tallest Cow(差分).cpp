#include<iostream>
#include<vector>
#include<map>

const int N = 10020;
int a[N],s[N];
int n,id,h,r;
std::map<std::pair<int,int>, int>mp;

int main(){
	std::cin >> n >> id >> h >> r;
	for(int i = 1;i<=r;i++){
		int x,y;
		std::cin >> x >> y;
		if(mp[std::make_pair(x,y)]!=0)
			continue;
		mp[std::make_pair(x,y)] = 1;
		if(x < y){
			a[x+1]--;
			a[y]++;
		} 
		else{
			a[y + 1]--;
			a[x]++;
		}
		
	}
	s[0] = h;
	for(int i = 1;i<=n;i++){
		s[i] = a[i] + s[i - 1];
		std::cout << s[i] << '\n';
	}
}
