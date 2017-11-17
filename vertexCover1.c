#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
#define N 10000
vector<int> adjlist[N];
int main()
{
  int m,n,k,e1,e2,nv,vertex,count;
  map<int,int> mapping;
  scanf("%d%d",&n,&m);
  for (int i= 0; i<m; i++) //输入边
  {
    scanf("%d%d",&e1,&e2);
    adjlist[e1].push_back(e2);
    adjlist[e2].push_back(e1);
  }
  scanf("%d",&k);//输入查询的次数
  for(int i=0;i<k;++i)
  {
    // int nv;输入本次查询的节点个数,nv的定义在转移到最上边
    scanf("%d",&nv);
    mapping.clear();
    count=0;
    //以上都是处理程序的输入输出，下边的代码才是关键
    for(int j=0;j<nv;j++)
    {
      scanf("%d",&vertex);//输入待检查的节点
      for(int t=0;t<adjlist[vertex].size();t++)//检查该顶点所连接的所有的边
      {
        if ( mapping.count(adjlist[vertex][t])==0 )//这句话主要是为了避免重复统计边的条数。例如检查顶点1，8，4的时候
          count++;//1和8之间有边相连接，一开始首先检查1，1和8之间的边统计了一遍；当检查顶点8的时候，顶点1已经在mapping中，不会重复
      }
      mapping[vertex]=vertex;//保存该节点，以防止重复统计边的条数
    }
    // printf("count=%d\n",count);
    printf("%s\n",(count<m?"No":"Yes"));
  }
}
