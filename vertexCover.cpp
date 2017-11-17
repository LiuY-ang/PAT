#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define N 10000
vector<int> adjlist[N];
int main()
{
  int m,n,k;
  scanf("%d%d",&n,&m);
  for (int i= 0; i<m; i++) //输入边
  {
    int e1,e2;
    scanf("%d%d",&e1,&e2);
    adjlist[e1].push_back(e2);
    adjlist[e2].push_back(e1);
  }
  scanf("%d",&k);//输入查询的次数
  for(int i=0;i<k;++i)
  {
    int nv;//输入本次查询的节点个数
    scanf("%d",&nv);
    vector<int> vertexs,visited;
    for(int j=0;j<nv;j++)
    {
      int temp;
      scanf("%d",&temp);
      vertexs.push_back(temp);//存储需要查询的节点
    }
    int count=0;
    for(int j=0;j<nv;j++)//依次取出要查询的节点
    {
      for(int t=0;t<adjlist[vertexs[j]].size();t++)//检查该节点所连接的边
      {
          if( find(visited.begin(),visited.end(),adjlist[vertexs[j]][t]) != visited.end() )
            count++;
      }
      visited.push_back(vertexs[j]);
    }
    printf("count=%d\n",count);
    printf("%s\n",(count<m?"No":"Yes"));
  }
}
