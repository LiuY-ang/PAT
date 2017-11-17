#include <iostream>
#include <vector>
#include <map>
using namespace std;
#define N 10010
int findFather(int* paths,int child)
{
  int a=child;//赋值为child的父节点
  while( paths[a]!=-1 )//path[a]==-1，则找到根节点
    a=paths[a];
  return a;
}
int main()
{
  int n,k,q,num_tree=0,num_bird=0,temp[N],paths[N];
  map<int,bool> isAppear;//记录鸟是否出现过
  cin>>n;//输入照片的个数
  for( int i=0;i<n;i++ )
  {
    cin>>k;//照片中鸟的数量
    int previous=0;
    for( int j=0;j<k;j++ )
    {
      cin>>temp[j];//输入鸟的编号，
      if(temp[j]>num_bird)
        num_bird=temp[j];//记录鸟的最大编号，即鸟的数量
      if( isAppear.count(temp[j])==0 ) //如果该鸟的标号没有出现过
      {
        //cout<<"******"<<endl;
        isAppear[temp[j]]=true;//则将该鸟的编号temp[j]加入到isAppear中
      }
      else//isAppear.find(temp[j])！=isAppear.end()即鸟的编号temp[j]以前出现过的话
      {
        //cout<<"-------"<<endl;
        previous=temp[j];//则记下该出现过的鸟的编号
      }
    }
    //cout<<previous<<endl;
    if( k>0 && previous==0 )//该照片的鸟中以前都没有出现过，即previous为0，
    {//说明该组鸟在一棵全新的树上，则建立该树。k>0保证至少有一只鸟在图片之中
      //cout<<"previous=0"<<endl;
      paths[temp[0]]=-1;//设置该树的根节点，建立一棵全新的树
      for( int j=1;j<k;j++ )
        paths[temp[j]]=temp[0];
    }
    else //previous!=0说明该组鸟在以前就存在的一棵树上
    {//并且该树上的其中一个节点的编号为previous，即鸟的标号
      for( int j=0;j<k;j++ )//加入原先存在的树中
        if( temp[j]!=previous && paths[temp[j]]!=-1 )//不改变previous的值
          paths[temp[j]]=previous;
    }
  }
  //查看paths是否正确，鸟的编号从0开始
  /* for( int i=1;i<=num_bird;i++ )
  {
    if(i==num_bird)
      cout<<paths[i]<<endl;
    else
      cout<<paths[i]<<" ";
  } */
  for( int i=1;i<=num_bird;i++ )//统计树的个数
    if( paths[i]==-1 )
      num_tree++;
  cout<<num_tree<<" "<<num_bird<<endl;//输出树的个数，鸟的数量
  cin>>q;//输入查询的次数
  int b1,b2,father_b1,father_b2;
  for( int i=0;i<q;i++ )
  {
    cin>>b1>>b2;
    if( b1>num_bird || b2>num_bird )//输入的数据不在范围之内
    {
      cout<<"No"<<endl;
      continue;
    }
    father_b1=findFather(paths,b1);//搜索鸟b1所在的树的‘根’
    father_b2=findFather(paths,b2);//搜索鸟b2所在的树的‘根’
    if( father_b1==father_b2 )
      cout<<"Yes"<<endl;
    else
      cout<<"No"<<endl;
  }
}
