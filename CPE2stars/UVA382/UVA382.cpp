#include<iostream>
using namespace std;

//計算
int perfection(long num){
	long sumOfDivisor=1;
	long i;
	
	//處理特殊輸入(1)
	if(num==1)return -1;
	
	//尋找並加總因數
	for(i=2;i*i<num;i++){
		if(num%i==0){
			sumOfDivisor=sumOfDivisor+i+num/i;
		}
		if(sumOfDivisor>num)return 1;
	}
	if(i*i==num)sumOfDivisor+=i;
	
	//回傳結果
	if(sumOfDivisor>num)return 1;
	else if(sumOfDivisor==num)return 0;
	else return -1;
}

int main(){
	long input;
	int result;
	
	cout<<"PERFECTION OUTPUT"<<endl;
	
	for(;;){
		//輸入
		cin>>input;
		if(input==0)break;
		
		//計算
		result=perfection(input);
		
		//縮排
		if(input<10000 && input>=1000)cout<<" ";
		else if(input<1000 && input>=100)cout<<"  ";
		else if(input<100 && input>=10)cout<<"   ";
		else if(input<10)cout<<"    ";
		
		//輸出
		if(result==-1)cout<<input<<"  DEFICIENT"<<endl;
		else if(result==0)cout<<input<<"  PERFECT"<<endl;
		else cout<<input<<"  ABUNDANT"<<endl;
	}
	cout<<"END OF OUTPUT"<<endl;
}