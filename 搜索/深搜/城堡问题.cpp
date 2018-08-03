/*
���ѳǱ�����----ջ 
1.block����洢�����ǽ��visited��¼�����Ƿ񱻷��� 
2.��дDfs��v��
3.��λ&���㡣��0˵���˷���δ���� 
*/ 
#include <iostream>
#include <algorithm>
#include <stack>
#include <cstring>
using namespace std;
int row,column;
int block[60][60];
int visited[60][60];
int area = 0;
int room = 0;
int maxArea;
struct Room {
	int row;
	int column;
	Room(int r,int c):row(r),column(c){}	
};
void Dfs(int i , int j){

	stack<Room> stk;
	stk.push(Room(i,j));
	while(!stk.empty()){
		Room rm = stk.top();
		int i = rm.row;
		int j = rm.column;
		if(visited[i][j])	//���ʹ� 
			stk.pop();
		else{
			visited[i][j] = room;	//���Ϊ���ʹ�
			area++;
			//������v���ڵĵ�
			if((block[i][j] & 1) == 0)
				Dfs(i,j-1);	
			if((block[i][j] & 2)== 0)
				Dfs(i-1,j);		
			if((block[i][j] & 4) == 0)
				Dfs(i,j+1);
			if((block[i][j] & 8) == 0)
				Dfs(i+1,j);
		}
		
	}	
} 

int main(){
	cin >> row >> column;
	for(int i = 0; i < row; i++)
		for(int j = 0; j < column; j++){
			cin >> block[i][j];
		}
	memset(visited,0,sizeof(visited));
	for(int i = 0; i < row; i++)
		for(int j = 0; j < column; j++){
			if(!visited[i][j]){
				//δ���ʹ�
				area = 0;
				room++;
				Dfs(i,j);
				maxArea = max(maxArea,area);
			}
		}
	cout << room << endl;
	cout << maxArea << endl;
	return 0;
}
