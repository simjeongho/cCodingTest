#include <iostream>
#include <algorithm>
using namespace std;

int n; // ��ũ�� ������ �ִ� ĭ ��
int m; // �ٱ��ϰ� �����ϴ�  ĭ ��
int loc; // ���� ��ġ   
int j; // �������� ��� ���� 
int ret; // �̵� Ƚ ��
int apple[20];

int count(){
	ret = 0;
	for(int i = 0; i < j; i++){
		loc = m;
		
		if(loc >= apple[i] && loc -m <= apple[i]){ // �������� �ʾƵ� �Ǵ� ���  
			ret = ret;
			loc = loc;
		}
		else{
			if(loc < apple[i]) // ���������� �������� �ϴ� ���  
			{
				ret += apple[i] - loc;
				loc = apple[i];
				 
			}
			else {
				ret += loc - apple[i] - m;
				loc = apple[i] +m;
			} // �������� �������� �ϴ� ���
			 				
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
