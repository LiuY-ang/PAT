#include <iostream>
using namespace std;
#define N 10010
int fathers[N];
int findFather(int x)
{
  int a=x;
  while( x!=fathers[x] )//找到根节点（父亲节点）
    x=fathers[x];
  while(a!=fathers[a])//路径压缩，即把路径的值全部赋值为根节点
  { //快速访问的根节点（即父亲的编号）
    int z=a;
    a=fathers[a];
    fathers[z]=x;
  }
  return x;
}
void join(int a,int b)//建立并查集
{
  int father_a=findFather(a);
  int father_b=findFather(b);
  //cout<<father_a<<"****"<<father_b<<endl;
  if ( father_a!=father_b )
    fathers[father_a]=father_b;
}
void init()//初始化操作
{
  for(int i=1;i<=N;i++)
    fathers[i]=i;
}
int main ()
{
  int n,k,first,temp,num_bird=0,num_tree=0;
  cin>>n;
  init();
  for(int i=0;i<n;i++)//处理输入输出
  {
    cin>>k>>first;
    if(num_bird<first)//找到鸟的最大编号，即鸟的数量
      num_bird=first;
    for(int j=1;j<k;j++)
    {
      cin>>temp;
      if(num_bird<temp)
        num_bird=temp;
      join(first,temp);
    }
  }
  // for(int i=1;i<=num_bird;i++)
  // {
  //   cout<<fathers[i]<<" ";
  // }
  // cout<<endl;
  for( int i=1;i<=num_bird;i++ )
    if( fathers[i]==i )
      num_tree++;//统计树的个数
  cout<<num_tree<<" "<<num_bird<<endl;
  int q,b1,b2;
  cin>>q;//查询的个数
  for(int i=0;i<q;i++)
  {
    cin>>b1>>b2;//输入需要查询的鸟的编号
    int father_b1=findFather(b1);
    int father_b2=findFather(b2);
    if(father_b1!=father_b2)
      cout<<"No"<<endl;
    else
      cout<<"Yes"<<endl;
  }
}
