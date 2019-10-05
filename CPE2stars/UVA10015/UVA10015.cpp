//UVA10015 Joseph's Cousin

#include<iostream>
#include<vector>

using namespace std;

bool isPrime(int, vector<int>);

int main(){
	
	vector<int> people;
	vector<int> primes;
	int input;
	
	for(int i=2;primes.size()<3503;i++){
		if(isPrime(i,primes))primes.push_back(i);
		
	}
	
	for(;;){
		cin>>input;
		if(input==0)break;
		
		people.clear();
		for(int i=0;i<input;i++){
			people.push_back(i+1);
		}
		
		int count=0;
		for(int i=0;i<input-1;i++){
			count--;
			
			count=(count+primes[i])%people.size();
			
			people.erase(people.begin()+count);
		}
		
		cout<<people[0]<<endl;
	}
}

bool isPrime(int num, vector<int> primes){
	for(int i=0;i<primes.size() && primes[i]*primes[i]<=num;i++){
		if(num%primes[i]==0)return false;
	}
	
	return true;
}