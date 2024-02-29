#include<bits/stdc++.h>
using namespace std;
//Cx2 + + + ...
stack< vector < pair < long long,map<int,int> > > > st;
const int mod = 1e9+7;

long long intpow(long long x,int p){
	if(p < 0)return 0;
	if(p == 0) return 1;
	if(p == 1) return x;
	if(p % 2) return x * intpow(x * x % mod, p / 2) % mod;
	return intpow(x * x % mod, p / 2)%mod;
}

int main(){
	int n,m;
	cin >> n >> m;
	getchar();
	char c = getchar();
	while(c != '\n'){
		if(c == 'x'){
			long long x = 0;
			while( isdigit(c = getchar() ) ){
				x = x * 10 + c - '0';
			}
			st.push( {  {1, { {x, 1 } }  } } );
			continue;
		}
		else if(c == '+'){
			auto vec1 = st.top();
			st.pop();
			auto& vec2 = st.top();
			for(auto &ele : vec1){
				vec2.push_back(ele);
			}
		}
		else if(c=='-'){
			c = getchar();
			if(isdigit(c)){
				long long x = c - '0';
				while( isdigit(c = getchar() ) ){
					x = x * 10 + c - '0';
				}
				st.push( {  {-x, { }  } } );
				continue;
			}
			
			auto vec1 = st.top();
			st.pop();
			auto& vec2 = st.top();
			for(auto &ele : vec1){
				ele.first *= -1;
				vec2.push_back(ele);
			}
			continue;
		}
		else if(c == '*'){
			auto vec1 = st.top();
			st.pop();
			auto vec2 = st.top();
			st.pop();
			vector < pair < long long,map<int,int> > > vec3;
			for(auto &ele1 : vec1){
				for(auto &ele2 : vec2){
					pair < int,map<int,int> > ele3;
					ele3.first = ele1.first * ele2.first % mod;
					for(auto& key : ele1.second)
						ele3.second[key.first] += key.second;
					for(auto& key : ele2.second)
						ele3.second[key.first] += key.second;
					vec3.push_back(ele3);
				}
			}
			// debug
			/*
			for(auto &ele : vec3){
				
				printf("st :: %d",ele.first);
				for(auto &key : ele.second){
					printf("X%d^^%d ",key.first,key.second);
				}
			}
			printf("\n");
			*/
			//---
			st.push(vec3);
		}
		else if(isdigit(c)){
			long long x = c - '0';
			while( isdigit(c = getchar() ) ){
				x = x * 10 + c - '0';
			}
			st.push( {  {x, { }  } } );
			continue;
		}
		c = getchar();
	}
	auto vec = st.top();
	st.pop();
	/*
	for(auto &ele : vec){
		printf(" %d",ele.first);
		for(auto &key : ele.second){
			printf("X%d^^%d ",key.first,key.second);
		}
	}
	*/
	for(int i = 0;i< m;i++){
		int index;
		int x[600] = {0};
		cin >> index;
		for(int j = 1;j <=n;j++){
			cin >> x[j];
		}
		long long ans = 0;
		for(auto& ele : vec){
			long long tmp = 1;
			if(!ele.second.count(index)){
				continue;
			}
			for(auto &key : ele.second){
				if(key.first != index){
					tmp = tmp * intpow(x[key.first],key.second) % mod;
				}
				else{
					tmp = tmp * intpow(x[key.first],key.second - 1) % mod * key.second % mod;
				}
				//deg=bug
				//cout << tmp << endl;
			}
			ans = (ans + tmp * ele.first % mod) % mod;
		}
		cout << (ans + mod) % mod << '\n';
	}
}

