#include<stdio.h>
#include<conio.h>
#define MAX 10
int G[MAX][MAX],edges;
int color_tab[MAX];
void main()
{
	int i,j,n;
	void Gen_col_value(int,int);
	void Gr_coloring(int,int);
	int get_data();
	void display(int);
	clrscr();
	printf("\n\n\t Graph coloring \n");
	for(i=0;i<MAX;i++)
	{
		for(j=0;j<MAX;j++)
		{
			G[i][j]=0;
			color_tab[i]=0;
		}
	}
	n=get_data();
	Gr_coloring(1,n);
	display(n);
	getch();
}
void Gen_col_value(int k,int n)
{
	int j,m;
	int a,b;
	while(1)
	{
		a=color_tab[k]+1;
		b=m+1;
		color_tab[k]=a%b;
		if(color_tab[k]==0)return;
		for(j=1;j<=n;j++)
		{

			if(G[k][j]&&color_tab[k]==color_tab[j])
				break;
		}
		if(j==n+1)return;
	}
}
void Gr_coloring(int k,int n)
{
	Gen_col_value(k,n);
	if(color_tab[k]==0)return;
	if(k==n)return;
	else Gr_coloring(k+1,n);
}
int get_data()
{
	int m,v1,v2,i,n;
	printf("\n Enter the number of nodes");
	scanf("%d",&n);
	printf("\n Enter the number of edges");
	scanf("%d",&edges);
	m=n-1;
	printf("\n Enter the edges of the graph");
	printf("By giving values of V1 and V2\n");
	for(i=1;i<edges;i++)
	{
		scanf("%d%d",&v1,&v2);
		G[v1][v2]=G[v2][v1]=1;
	}
	return n;
}
void display(int n)
{
	int i;
	printf("\n the vertices to be colored as....\n");
	for(i=1;i<=n;i++)
		printf("\nV%d:=%d",i,color_tab[i]);
}
