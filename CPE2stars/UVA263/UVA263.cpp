#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//將vector轉換為數字
long vectorToInt(vector<int> vec){
	long toInt=0;
	for(int k=0;k<vec.size();k++){
		toInt=toInt*10+vec[k];
	}
	return toInt;
}

int main(){
	
	long input;
	long big,small;
	long newAns;
	int i,count;
	
	vector<int> lowToHigh;
	vector<int> highToLow;
	vector<long> existNum;
	
	for(;;){
		
		//處理輸入
		cin>>input;
		if(input==0)return 0;
		cout<<"Original number was "<<input<<endl;
		
		//初始化
		existNum.clear();
		newAns=input;
		
		for(count=0;;count++){
			
			//初始化
			lowToHigh.clear();
			highToLow.clear();
			
			//將數字轉存入vector
			for(i=0;newAns>0;i++){
				lowToHigh.push_back(newAns%10);
				newAns/=10;
			}
			
			//排序與倒轉
			sort(lowToHigh.begin(),lowToHigh.end());
			highToLow=lowToHigh;
			reverse(highToLow.begin(),highToLow.end());
			
			//將vector轉換為數字
			big=vectorToInt(highToLow);
			small=vectorToInt(lowToHigh);
			
			//相減
			newAns=big-small;
			
			cout<<big<<" - "<<small<<" = "<<newAns<<endl;
			
			//檢查重覆與輸出
			if(find(existNum.begin(),existNum.end(),newAns)!=existNum.end()){
				cout<<"Chain length "<<count+1<<endl;
				break;
			}
			//將新答案存入vector中
			else
				existNum.push_back(newAns);
		}
		cout<<endl;
	}
}