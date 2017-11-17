#include <iostream>
#include <vector>
using namespace std;
#define N 31
vector<int> path;  //负号代表红色
int d;
int main()
{
  int k,n,vertex[N],temp;
  scanf("%d",&k);
  for(int i=0;i<k;++i)
  {
    scanf("%d",&n);
    for( int j=0;j<n;++j)
      scanf("%d",&vertex[j]);
    //以上完成输入输出
    if (vertex[0]<0)//如果一开始为红色的节点，
    {
      printf("%s\n","No");
      continue;
    }
    path.push_back(vertex[0]);
    for( int j=1;j<n;++j)
    {
      if(vertex[j]<0 && path[path.size()-1]<0)//两个红色连续出现
      {
        printf("%s\n","No");
        continue;
      }

    }
  }
}
