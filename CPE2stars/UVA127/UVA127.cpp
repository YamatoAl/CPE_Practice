#include<iostream>
#include<string>
#include<vector>
#include<cstdlib>
using namespace std;

//建立struct
struct Card{ 
	char suit;
	int value;
};

int main(){
	
	int i;
	string input;
	Card newCard;
	
	//建立二維Vector
	vector<vector<Card> > cards; 
	
	for(;;){
		
		//初始化
		cards.resize(52); 
		for(i=0;i<52;i++){
			cards[i].clear();
		}
		
		//處理輸入
		for(i=0;i<52;i++){ 
			cin>>input;
			if(input=="#")break;
			newCard.suit=input[1];
			if(input[0]=='A')newCard.value=1;
			else if(input[0]=='T')newCard.value=10;
			else if(input[0]=='J')newCard.value=11;
			else if(input[0]=='Q')newCard.value=12;
			else if(input[0]=='K')newCard.value=13;
			else newCard.value=input[0]-'0';
			
			cards[i].push_back(newCard);		
		}
		if(input=="#")break;
		
		//從第二個牌堆進行處理，至最後一個牌堆時仍無法移動則跳出
		for(i=1;i<cards.size();){ 
			
			//檢查左邊第三張牌
			if(i>=3 && ((cards[i].back().value == cards[i-3].back().value)||(cards[i].back().suit == cards[i-3].back().suit))){ 
				
				//將牌放至牌堆最後一張
				cards[i-3].push_back(cards[i].back()); 
				
				//移除原牌堆最後一張
				cards[i].pop_back(); 
				
				//若變成空牌堆則消除
				if(cards[i].empty())cards.erase(cards.begin()+i); 
				
				//回到第二個牌堆
				i=1; 
			}
			
			//檢查左邊第一張牌
			else if(i>=1 && ((cards[i].back().value == cards[i-1].back().value)||(cards[i].back().suit == cards[i-1].back().suit))){ 
				cards[i-1].push_back(cards[i].back());
				cards[i].pop_back();
				if(cards[i].empty())cards.erase(cards.begin()+i);
				i=1;
			}
			
			//無法移動則檢查下一個牌堆
			else i++; 
			
		}
		
		//總牌堆數
		cout<<cards.size(); 
		
		//處理單複數
		if(cards.size()==1)cout<<" pile remaining: ";
		else cout<<" piles remaining: ";
		
		//每牌堆張數
		for(i=0;i<cards.size();i++){
			cout<<cards[i].size();
			if(i==cards.size()-1)cout<<endl;
			else cout<<" ";
		}
	}
	
}