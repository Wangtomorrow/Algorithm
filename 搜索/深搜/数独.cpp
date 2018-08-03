/*
ÿ3*3��ÿ�У�ÿ��1-9�������
poj2676 
ÿ�У�ÿ�У�û����3*3�񶼱��
ע���±����3*��row_�±�/3��+��col_�±�/3��=child_�±� 
ת����1-9��   3*����row-1��/3��+����col-1��/3��= child
*/
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int map[10][10];
bool row[10][10];	//ĳ������ĳ���Ƿ���� 
bool col[10][10];	//ĳ������ĳ���Ƿ���� 
bool child[10][10];	//ĳ������ĳ�Ӹ��Ƿ���� 
bool dfs(int i,int j){
	if(i == 10)		//Խ�� 
		return true;
	bool flag = false;
	
	if(map[i][j]){	//���Ʊ���ÿ��ÿ�� 
		//������/��
		if(j==9)
			flag = dfs(i+1,1);
		else
			flag = dfs(i,j+1);
		//�ж�flag���� 
		if(flag)
			return true;
		else
			return false;
	}
	else{
		int ch = 3*((i-1)/3)+((j-1)/3)+1;		//�ҵ������ĸ��Ӹ�
		for(int a = 1; a <= 9; a++){
			//1-9ö������
			if(!row[i][a] && !col[j][a] && !child[ch][a]){
				//�ڴ��С����С����Ӹ��ж�δ����
				map[i][j] = a;
				row[i][a] = true;
				col[j][a] = true;
				child[ch][a] = true;
				if(j == 9)
					flag = dfs(i+1,1);
				else
					flag = dfs(i,j+1);
				if(!flag){
					//���� 
					map[i][j] = 0;
					row[i][a] = false;
					col[j][a] = false;
					child[ch][a] = false;
				}
				else
					return true;
			} 
		} 
	} 
	//�÷������� 
	return false;
}
int main(){
	int n;
	cin >> n;
	while(n--){
		memset(row,false,sizeof(row));
		memset(col,false,sizeof(col));
		memset(child,false,sizeof(child));
		memset(map,0,sizeof(map));
		char in;
		for(int i = 1; i <= 9; i++)
			for(int j = 1; j <= 9; j++){
				cin >> in;
				map[i][j] = in-'0';
				if(map[i][j]){
					int ch = 3*((i-1)/3)+((j-1)/3)+1;
					row[i][map[i][j]] = true;
					col[j][map[i][j]] = true;
					child[ch][map[i][j]] = true;
				}
			}
		dfs(1,1);
		cout << endl;
		for(int i = 1; i <= 9; i++){
			for(int j = 1; j <= 9; j++){
				cout << map[i][j];
			}
			cout << endl;
		}
			
	} 
	return 0;
} 
