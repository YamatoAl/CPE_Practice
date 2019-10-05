#include<iostream>
#include<string>
#include<vector>
#include<cstdlib>
using namespace std;

//建立struct
struct Card{ 
	int value;
	char word;
	char suit;
	bool open;
};

int main(){
	
	int i;
	string input;
	Card newCard;
	
	//建立二維Vector
	vector<vector<Card> > cards;
	
	//紀錄輸入及打開的牌數
	int inputCards,openCards;
	
	//紀錄最後一張翻開的牌
	Card lastOpenCard;
	
	for(;;){
		
		//初始化
		cards.resize(52); 
		for(i=0;i<52;i++){
			cards[i].clear();
		}
		inputCards=0;
		openCards=0;
		newCard.open=false;
		
		//處理輸入
		for(i=12;inputCards<52;){
			cin>>input;
			if(input=="#")return 0;
			switch(input[0]){
				case 'A':
					newCard.value=0;
					break;
				case 'T':
					newCard.value=9;
					break;
				case 'J':
					newCard.value=10;
					break;
				case 'Q':
					newCard.value=11;
					break;
				case 'K':
					newCard.value=12;
					break;
				default:
					newCard.value=input[0]-'0'-1;
			}
			newCard.word=input[0];
			newCard.suit=input[1];
			cards[i].insert(cards[i].begin(),newCard);
			inputCards++;
			if(i>0)i--;
			else i=12;
		}
		
		
		//從K牌堆進行處理，處理到已翻開的牌時跳出
		for(i=12;;){
			//跳出檢查
			if(cards[i].back().open==true)break;
			
			//紀錄最後一張翻開的牌
			lastOpenCard=cards[i].back();
			lastOpenCard.open=true;
			
			//移動牌
			cards[i].pop_back();
			i=lastOpenCard.value;
			cards[i].insert(cards[i].begin(),lastOpenCard);
			
			//紀錄打開的牌數
			openCards++;
		}
		
		//輸出(補0)
		if(openCards<10)
			cout<<"0"<<openCards<<","<<lastOpenCard.word<<lastOpenCard.suit<<endl;
		else
			cout<<openCards<<","<<lastOpenCard.word<<lastOpenCard.suit<<endl;
	}
}