#include <iostream>

#define NOC 1000

using namespace std;
int display(int **mat, int s)
{
  for(int i=0;i<s;i++)
    {
        for(int j=0;j<s;j++)
            cout<<mat[i][j]<<" ";
        cout<<endl;
    }
}
class warshall
{
  int **w,**d,size;
  public:
    warshall(int sz)
    {
      size=sz;
      w=new int*[sz]; 
      d=new int*[sz];
      for(int i=0;i<sz;i++)
      {
        w[i]=new int[sz];
        d[i]=new int[sz];
      }
    }
    int input();
    int algo();
};
int warshall::input()
{
  char node1,node2;
  cout<<"\nENTER ADJACENCY MATRIX : PUT ZERO IF NO PATH"<<endl;
  for(int i=0;i<size;i++)
    for(int j=0;j<size;j++)
    {
      node1=65+i;
      node2=65+j;
      cout<<"\nDISTANCE B/W "<<node1<<" AND "<<node2<<" IS : ";
      cin>>w[i][j];
      d[i][j]=w[i][j];
    }
  cout<<"\nYOU ENTERED : -"<<endl;
  display(d,size);
  for(int i=0;i<size;i++)
  {
    for(int j=0;j<size;j++)
      if(w[i][j]==0)
      {
        w[i][j]=NOC;
        d[i][j]=NOC;
      }
  } 
}
int warshall::algo()
{
  int t1,t2,t3,t4,i,j,k;
  
  for(k=0;k<size;k++)
    {
      for(i=0;i<size;i++)
      {
         for(j=0;j<size;j++)
         {
            t1=d[i][k];
            t2=d[k][j];
            t3=d[i][j];
            if( t1 < NOC && t2 < NOC )
            {
                t4=t1+t2;
                d[i][j]=t4<t3?t4:t3;
            }
         }
      }
    }
  cout<<"\nMINIMUM PATH MATRIX IS :- "<<endl;
  display(d,size);
}
int main()
{
  int node_no;
  cout<<"\nENTER NUMBER OF NODES : ";
  cin>>node_no;
  warshall obj(node_no);
  obj.input();
  obj.algo();
  cout<<"\n\n\t Programming @ C#ODE Studio";
  return 0;
}