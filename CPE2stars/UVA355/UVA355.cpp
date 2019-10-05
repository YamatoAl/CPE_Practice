#include<iostream>
#include<vector>
#include<string>
using namespace std;

//轉換進位制
vector<int> changeBase(vector<int> vec,int oldBase,int newBase){
	unsigned long long num=0;
	vector<int> newNum;
	
	//轉換成10進位制
	for(int k=0;k<vec.size();k++){
		num=num*oldBase+vec[k];
	}
	
	//轉換成新進位制
	for(;num>0;num/=newBase){
		newNum.insert(newNum.begin(),num%newBase);
	}
	
	//處理空值問題
	if(newNum.size()==0)newNum.push_back(0);
	
	return newNum;
}

int main(){
	int inBase,outBase;
	int i;
	bool illegal;
	char ch;
	string input;
	vector<int> oldBaseNum,newBaseNum;
	
	for(;cin>>inBase>>outBase>>input;){
		
		//初始化
		oldBaseNum.clear();
		newBaseNum.clear();
		illegal=false;
		
		//處理輸入
		for(i=0;i<input.size();i++){
			if(input[i]>='0' && input[i]<='9')oldBaseNum.push_back(input[i]-'0');
			else if(input[i]>='A' && input[i]<='Z')oldBaseNum.push_back(input[i]-'A'+10);
			
			//檢查非法輸入
			if(oldBaseNum.back()>=inBase){
				illegal=true;
				break;
			}
		}
		
		//非法輸入處理
		if(illegal){
			cout<<input<<" is an illegal base "<<inBase<<" number"<<endl;
			continue;
		}
		
		//轉換
		newBaseNum=changeBase(oldBaseNum,inBase,outBase);
		
		//輸出
		cout<<input<<" base "<<inBase<<" = ";
		for(int j=0;j<newBaseNum.size();j++){
			if(newBaseNum[j]<10)cout<<newBaseNum[j];
			//將大於或等於10的數字轉換成英文
			else{
				ch='A'+newBaseNum[j]-10;
				cout<<ch;
			}
		}
		cout<<" base "<<outBase<<endl;
	}
}