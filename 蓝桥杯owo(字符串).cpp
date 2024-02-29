#incldue<bits/stdc++.h>
using namespace std;


int n;
string str;

int totlen;
int state[8]; 


int main(){
	cin >> n;
	for(int i = 1;i<=n;i++){
		cin >> str;
		int len = str.size();
		int j = 0;
		while(j < len){
			while(j < len && str[j] != 'o')j++;
			while(j + 2 < len){
				if(str[j + 1] == 'w' && str[j + 2] == 'o'){
					j += 2;
					totlen++;	
				}
				else{
					j += 1;
					break;
				}
			}
		}
		if(len == 1 && str[0] == 'o'){
			state[0]++;
		}
		else if(len >= 2){
			if(str[0] == 'o'){
				if(str[len - 1] == 'o')								state[0]++;//o-o
				else if(str[len - 1] == 'w' && str[len - 2] == 'o')state[1]++;//o-ow
				else 												state[2]++;//o-x
			}
			else if(str[0] == 'w' && str[1] == 'o'){
				if(str[len - 1] == 'o')								state[3]++;//wo-o
				else if(str[len - 1] == 'w' && str[len - 2] == 'o')state[4]++;//wo-ow
				else 												state[5]++;//wo-x
			}
			else{
				if(str[len - 1] == 'o')								state[6]++;//x-o
				else if(str[len - 1] == 'w' && str[len - 2] == 'o')state[7]++;//x-ow
				//default x-x : useless.
			}
		}
		int ans = totlen;
		if(state[])
	}
}
