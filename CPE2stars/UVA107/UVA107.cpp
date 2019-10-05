#include <iostream>
using namespace std;

int main(){
	for(;;){
		
		//變數建立
		int inHigh,inFinalCat;
		int outCat,outHigh;
		int N;
		int nowCat,nowHigh;
		bool ans=false;
		
		//輸入處理
		cin>>inHigh>>inFinalCat;
		if(inHigh==0 && inFinalCat==0)break;
		
		//找出N
		for(N=2;N<=inHigh;N++){
			if(inHigh%N == 0){
				nowCat=1;
				nowHigh=inHigh;
				outCat=0;
				outHigh=0;
				for(;nowHigh>1;){
					if(nowHigh%N != 0 || nowCat>inFinalCat)break;
					outHigh+=nowCat*nowHigh;
					outCat+=nowCat;
					nowCat*=N-1;
					nowHigh/=N;
					if(nowHigh==1 && nowCat==inFinalCat)ans=true;
				}
			}
			if(ans){
				outHigh+=nowCat*1;
				break;
			}
		}
		
		//處理特殊輸入
		if(inHigh==1 && inFinalCat==1){
			outCat=0;
			outHigh=1;
		}
		else if(inHigh==1){
			outCat=1;
			outHigh=inFinalCat;
		}
		
		
		
		//印出結果
		cout<<outCat<<" "<<outHigh<<endl;
	}
}