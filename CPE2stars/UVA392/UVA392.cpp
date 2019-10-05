#include<iostream>
#include<vector>
using namespace std;

int pos(int num){
	if(num<0)return -num;
	else return num;
}

int main(){
	int input;
	bool first;
	int count;
	vector<int> coef;
	
	for(;cin>>input;){
		
		//初始化
		coef.clear();
		first=true;
		count=0;
		
		//輸入
		coef.push_back(input);
		for(int i=0;i<8;i++){
			cin>>input;
			coef.push_back(input);
		}
		
		//進行多項判斷並依序輸出
		for(int i=0;i<9;i++){
			
			if(coef[i]==0 && i==8  && first)cout<<0;
			if(coef[i]==0)continue;
			else if(!first)cout<<" ";
			if(coef[i]<0 && !first)cout<<"- ";
			else if(coef[i]<0)cout<<"-";
			else if(coef[i]>0 && !first)cout<<"+ ";
			if( pos(coef[i])!=1 || i==8)cout<<pos(coef[i]);
			if(i!=8)cout<<"x";
			if(i!=7 && i!=8)cout<<"^"<<8-i;
			first=false;
		}
		cout<<endl;
	}
}