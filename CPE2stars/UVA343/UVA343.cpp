#include<iostream>
#include<vector>
#include<string>
using namespace std;

//將vector依指定base轉回整數
long vecToLong(vector<int> vec,int base){
	long num=0;
	for(int k=0;k<vec.size();k++){
		num=num*base+vec[k];
	}
	return num;
}

int main(){
	string inputX,inputY;
	vector<int> X;
	vector<int> Y;
	int leastXb,leastYb;
	long gX,gY;
	int guessXb,guessYb;
	int outXb,outYb;
	int i,j;
	bool end;
	
	for(;cin>>inputX>>inputY;){
		
		X.clear();
		Y.clear();
		leastXb=1;
		leastYb=1;
		end=false;
		
		for(i=0;i<inputX.size();i++){
			//將char轉換成數字
			if(inputX[i]>='0' && inputX[i]<='9')X.push_back(inputX[i]-'0');
			else if(inputX[i]>='A' && inputX[i]<='Z')X.push_back(inputX[i]-'A'+10);
			
			//記錄最大數作為最小猜測
			if(X.back()>leastXb)leastXb=X.back();
		}
		
		for(i=0;i<inputY.size();i++){
			//將char轉換成數字
			if(inputY[i]>='0' && inputY[i]<='9')Y.push_back(inputY[i]-'0');
			else if(inputY[i]>='A' && inputY[i]<='Z')Y.push_back(inputY[i]-'A'+10);
			
			//記錄最大數作為最小猜測
			if(Y.back()>leastYb)leastYb=Y.back();
		}
		
		//以雙重迴圈猜測進位制
		for(guessXb=leastXb+1;guessXb<=36;guessXb++){
			gX=vecToLong(X,guessXb);
			for(guessYb=leastYb+1;guessYb<=36;guessYb++){
				gY=vecToLong(Y,guessYb);
				
				//若Y已超過X則返回
				if(gY>gX)break;
				
				//找出結果後記錄起來並跳出
				else if(gY==gX){
					outXb=guessXb;
					outYb=guessYb;
					end=true;
					break;
				}
			}
			if(end)break;
		}
		
		//根據有無結果進行不同輸出
		if(end)cout<<inputX<<" (base "<<outXb<<") = "<<inputY<<" (base "<<outYb<<")"<<endl;
		else cout<<inputX<<" is not equal to "<<inputY<<" in any base 2..36"<<endl;
	}
}