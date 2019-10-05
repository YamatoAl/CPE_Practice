#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;

bool coprime(int x,int y){
	int big,small;
	double limit;
	
	//判斷輸入是否為1
	if(x==1||y==1)return true;
	
	//尋找較小數以及確認本身是否為因數
	if(x>y){
		if(x%y==0)return false;
		big=x;
		small=y;
		limit=sqrt(y);
	}
	else if(x<y){
		if(y%x==0)return false;
		big=y;
		small=x;
		limit=sqrt(x);
	}
	else return false;
	
	//判斷小數的因數是否也為大數的因數
	for(int i=2;i<=limit;i++){
		if(small%i==0){
			if(big%i==0)return false;
			else if(big%(small/i)==0)return false;
		}
		else continue;
	}
	
	//未找到公因數則回傳true
	return true;
}

int main(){
	int N;
	int input;
	vector<int> inputs;
	int coprime_pair;
	double total_pair,output;
	
	for(;;){
		
		//初始化
		inputs.clear();
		coprime_pair=0;
		
		//輸入
		cin>>N;
		if(N==0)break;
		for(int i=0;i<N;i++){
			cin>>input;
			inputs.push_back(input);
		}
		
		//計算總組合數
		total_pair=N*(N-1)/2;
		
		//計算互質組合數
		for(int i=0;i<N;i++){
			for(int j=i+1;j<N;j++){
				if(coprime(inputs[i],inputs[j]))coprime_pair++;
			}
		}
		
		//輸出
		if(coprime_pair==0)cout<<"No estimate for this data set."<<endl;
		else cout<<fixed<<setprecision(6)<<sqrt(6*total_pair/coprime_pair)<<endl;
	}
}