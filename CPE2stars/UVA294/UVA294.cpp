#include<iostream>
using namespace std;

long getDivisors(long num){
	
	//處理特殊情況(1)
	if(num==1)return 1;
	
	long d;
	long count_d=0;
	
	//由2開始尋找因數，至平方根停止
	for(d=2;d*d<num;d++){
		if(num%d==0)count_d+=2;
	}
	
	//確認平方根是否為因數
	if(num==d*d)count_d+=1;
	
	//加上1和其本身後回傳
	return count_d+2;
}

int main(){
	int CASE;
	long L,U;
	long tempCount;
	long outNum,outCount;
	
	cin>>CASE;
	
	for(int T=0;T<CASE;T++){
		
		//輸入
		cin>>L>>U;
		
		//記錄第一個數
		outNum=L;
		outCount=getDivisors(L);
		
		//比對第二至最後一個數
		for(long l=L+1;l<=U;l++){
			tempCount=getDivisors(l);
			if(tempCount>outCount){
				outCount=tempCount;
				outNum=l;
			}
		}
		
		//輸出
		cout<<"Between "<<L<<" and "<<U<<", "<<outNum<<" has a maximum of "<<outCount<<" divisors."<<endl;
	}
}