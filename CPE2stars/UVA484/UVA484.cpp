#include<iostream>
#include<vector>
using namespace std;

struct Number{
	int num;
	int count;
};

int main(){
	
	int input;
	Number newNum;
	bool newCheck;
	vector<Number> numbers;
	
	newNum.count=1;
	for(;cin>>input;){
		
//		if(input==9487)break;
		
		newCheck=true;
		
		for(int i=0;i<numbers.size();i++){
			if(input==numbers[i].num){
				numbers[i].count++;
				newCheck=false;
				break;
			}
		}
		if(newCheck){
			newNum.num=input;
			numbers.push_back(newNum);
		}
	}
	
	for(int i=0;i<numbers.size();i++){
		cout<<numbers[i].num<<" "<<numbers[i].count<<endl;
	}
	
}