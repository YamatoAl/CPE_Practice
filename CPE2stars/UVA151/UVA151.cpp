//Josephus Problem

#include <iostream>
using namespace std;

//找出下一個地區
int next(bool area[],int i,int j,int total_area){  
	int k;
	for(k=0;k<i;){
		j=(j+1)%total_area;
		//如果已停電則跳過
		if(area[j]==false)k++;  
	}
	return j;
}

int main(){
	
	int total_area,i,j,count;
	bool area[101];
	
	for(;;){
		cin>>total_area;
		if(total_area == 0)break;
		
		for(i=1;i<=total_area;i++){
			
			//初始化
			for(j=0;j<total_area;j++){ 
				area[j]=false;
			}
			count=0;
			
			//逐一停電
			for(j=0;j<total_area;j=next(area,i,j,total_area)){
				if(j==12 || count>=total_area)break;
				area[j]=true;
				count++;
			}
			
			if(j==12 && count==total_area-1){  
			//經過所有區域(扣掉威靈頓)則表示為正確答案
				cout<<i<<endl;
				break;
			}
		}
	}
}