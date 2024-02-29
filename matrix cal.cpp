#include <bits/stdc++.h>

class Matrix{
	private:
		int n,m;
		int** p;
		bool iotip;
		std :: string Name;
		
		void tip_print(const std :: string info){
			if(iotip) std :: cout << info;
		}
		void tip_print(const int x){
			if(iotip) std :: cout << x;
		}
	
	public:
		Matrix(int nn = 3,int mm = 3){
			n = nn,m = mm;
			Name = "Untitled Matrix";
			iotip = 1;
			
			p = new int*[n];
			for(int i = 0;i< n;i++){
				p[i] = new int[m];
			}
			for(int i = 0;i<n;i++){
				for(int j = 0;j<m;j++){
					if(i == j) p[i][j] = 1;
					else p[i][j] = 0;
				}
			}
		}
		~Matrix(){
			for(int i = 0;i<n;i++){
				delete p[i];
			}
			delete p;
		}
		Matrix(const Matrix& right){
			n = right.n;
			m = right.m;
			Name = right.Name;
			iotip = right.iotip;
			
			p = new int*[n];
			for(int i = 0;i< n;i++){
				p[i] = new int[m];
			}
			for(int i = 0;i<n;i++){
				for(int j = 0;j<m;j++){
					p[i][j] = right.p[i][j];
				}
			}
		}
		Matrix& operator=(const Matrix& right){
			iotip = right.iotip;
			for(int i = 0;i<n;i++){
				for(int j = 0;j<m;j++){
					p[i][j] = right.p[i][j];
				}
			}
			return *this;
		}
		Matrix& operator+(const Matrix& right){
			Matrix mx(n,m);
			for(int i = 0;i<n;i++)
				for(int j = 0;j<m;j++)
					mx.p[i][j] = right.p[i][j] + p[i][j];
			return mx;
		}
		int* operator[](const int x){
			return p[x];
		}
		void showinfo(){
			std :: cout << Name << "(" << n << "," << m << ")" << '\n';
		}
		void print(){
			tip_print(Name + " :" + "\n");
			for(int i = 0;i<n;i++){
				for(int j = 0;j <m;j++){
					std :: cout << p[i][j];
					if(j != m-1)
						std :: cout << ' ';
				}
				std :: cout << '\n';
			}
		}
		void input(){
			int x;
			tip_print(Name + " :" + "\n");
			for(int i = 0;i<n;i++){
				tip_print("line");
				tip_print(i);
				tip_print(":" );
				for(int j = 0;j<m;j++){
					std :: cin >> x;
					p[i][j] = x;
				}
			}
		}
		void set_tip(bool x){
			iotip = x;
		}
		void rename(){
			tip_print("you are renaming the matrix : ");
			tip_print(Name + "\n");
			std :: cin >> Name;
		}
};


int main(int argc,char* argv[]){
	/*
	if(argc == 2){
		std::cout << "A matrix with " << argv[0] << " col and " << argv[1] << " row is structed" << '\n';
	}
	else if(argc == 0){
		std::cout << "A matrix with " << 3 << " col and " << 3 << " row is structed" << '\n';		
	}
	else{
		std::cout << "???" << '\n'; 
	}
	*/
	std::string s;
	while(std::cin >> s){
		
	}
	return 0;
}
