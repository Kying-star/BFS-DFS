#include <stdio.h>
#include <stdlib.h>
#define infinity 65536
int vexs[10];
int sum;
int n;
int G[100][100];
void Dfs(int CityID);
void Bfs(int CityID);
void bfs_2(int k);
int visited[10];
typedef struct {
    int num[10];
    int top;
}Stack;
void push(Stack* arr,int num){
    arr->num[arr->top++] = num;
}
int pop(Stack* arr){
    return arr->num[arr->top--];
}
void init();
void initData();
int main(){
    n = 10;
    int startCity = 5;
    init();
    initData();
    visited[startCity] = startCity;
    Dfs(startCity);
    printf("\n");
    Bfs(startCity);
    return 0;
}
void initData(){
    FILE *fp = NULL;
    int CityID,targetCityID;
    if((fp=fopen("/Users/kying-star/Documents/文档/大学/大二下/移动通信/实验课3-通信网/lab_3/data.txt","r")) == NULL)
    {
        printf("文件data.txt打开失败,请检查路径\n");
        exit(-1);
    }
    while (fscanf(fp, "%d %d",&CityID,&targetCityID) != EOF){
        G[CityID][targetCityID] = 1;
        G[targetCityID][CityID] = 1;
    }
    fclose(fp);
    for (int i = 0; i < 10; ++i) {
        vexs[i] = i;
    }
}
void init() {
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i==j)
                G[i][j] = 0;
            else
                G[i][j] = infinity;
}
void Dfs(int CityID)
{
    sum++;
    printf("%d ",CityID + 1);
    if(sum == 10)
        return;
    for(int i = 0;i <= n;i++) {
        if( G[CityID][i]==1 && visited[i]==0 ) {
            visited[i] = 1;
            Dfs(i);
        }
    }
}
void Bfs(int CityID) {
      int i,j,front=0,rear=0;
      int queue[17];
      for( i=0; i<10; i++)
          visited[i]=0;
      for( i=0; i<17; i++)
          queue[i]=-1;
      printf("%d ",vexs[CityID]+1);
      visited[CityID]=1;
      queue[rear]=CityID;
      while(queue[front]!=-1) {
          i=queue[front]; front=front+1;
          for(j=0;j<10;j++)
          if(!visited[j] && G[i][j]==1) {
              printf("%d ",vexs[j]+1);
              visited[j]=1;  rear=rear+1; queue[rear]=j;
          }
      }
}
void bfs_2(int CityID){
    Stack StackFirst,StackLast;
    StackFirst.top = 0;
    StackLast.top = 0;
    for (int i = 0; i < 10; ++i) {
        visited[i] = 0;
    }
    visited[CityID] = 1;
}
