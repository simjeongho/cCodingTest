#include <iostream>
#include <algorithm>
using namespace std;

int n; // 스크린 나눠져 있는 칸 수
int m; // 바구니가 차지하는  칸 수
int loc; // 현재 위치   
int j; // 떨어지는 사과 개수 
int ret; // 이동 횟 수
int apple[20];

int count(){
	ret = 0;
	for(int i = 0; i < j; i++){
		loc = m;
		
		if(loc >= apple[i] && loc -m <= apple[i]){ // 움직이지 않아도 되는 경우  
			ret = ret;
			loc = loc;
		}
		else{
			if(loc < apple[i]) // 오른쪽으로 움직여야 하는 경우  
			{
				ret += apple[i] - loc;
				loc = apple[i];
				 
			}
			else {
				ret += loc - apple[i] - m;
				loc = apple[i] +m;
			} // 왼쪽으로 움직여야 하는 경우
			 				
			}	
		}
		cout <<  ret << endl;
		return ret;	
} 
int main(){	
	cin>> n;
	cin >> m;
	cin >> j;
	for(int i = 0; i < j; i++) {
		cin >> apple[i];	
	}
	count();
	return 0;
}
