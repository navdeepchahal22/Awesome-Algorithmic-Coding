#include<stdio.h>
#include<stdlib.h>
#define m 1000000007
#define MAXSIZE	100001
void dfs(long long int);
void dfs2(long long int);
long long int final_count,final_cost,min,n,k,x,y,max,num,cost[1000005],a[1000005],finish[1000005],visited[1000005],visited2[1000005],flag=1,i,j=0,count;
typedef struct node{
	long long int data;
	struct node* next;
}node;
struct stack
{
	long long int stk[MAXSIZE];
	long long int top;
};
typedef struct stack STACK;
STACK s;
void push(long long int);
long long int  pop(void);
void display(void);
node *arr[1000005];
node *arr2[1000005];

int main()
{	
		for(i=1;i<=1000003;i++)
		{
			a[i]=0;
			visited[i]=0;
			arr[i]=(node*)malloc(sizeof(node));
			arr2[i]=(node*)malloc(sizeof(node));
		}
	long long int tc;
	scanf("%lld",&tc);
	while(tc--)
	{


		min=10000000000000;
		count=1;
		final_count=1;
		final_cost=0;
		scanf("%lld %lld",&n,&k);
		for(i=1;i<=n;i++)
		{
			arr[i]->next=NULL;
			arr2[i]->next=NULL;
			visited[i]=0;
			a[i]=0;
		}
		for(i=1;i<=n;i++)
			scanf("%lld",&cost[i]);
		for(i=1;i<=k;i++)
		{
			scanf("%lld %lld",&x,&y);

			node *current=arr[x];
			while(current->next!=NULL)
			{
				current=current->next;
			}
			node *temp=(node*)malloc(sizeof(node));
			temp->data=y;
			temp->next=NULL;
			current->next=temp;
			node *current2=arr2[y];
			while(current2->next!=NULL)
				current2=current2->next;
			node *temp2=(node*)malloc(sizeof(node));
			temp2->data=x;
			temp2->next=NULL;
			current2->next=temp2;
			
		}

		for(i=1;i<=n;i++)
			if(visited[i]==0)
				dfs(i);
		while(s.top!=0)
		{	
			num=pop();
			if(visited[num]!=-1)
			{
				dfs2(num);
				final_cost+=min;
				
				final_count=((final_count)%m*(count%m))%m;
				
				min=1000000000000000;
				count=1;
				
			}
		}
		printf("%lld %lld\n",final_cost,final_count);
	}
	return 0;
}
void dfs(long long int num)
{
	visited[num]=1;
	node *current=arr[num];
	while(current->next!=NULL)
	{
		if(visited[current->next->data]!=1)
		{
			dfs(current->next->data);
		}
		current=current->next;
	}
	push(num);
}
void dfs2(long long int num)
{
	visited[num]=-1;
	
	node *current2=arr2[num];
	if(cost[num]<min)
		min=cost[num];
	
	while(current2->next!=NULL)
	{
		if(visited[current2->next->data]!=-1)
		{
			if(cost[current2->next->data]==min)
				count++;
		
			dfs2(current2->next->data);
		}
		current2=current2->next;
	}
}
void push (long long int num)
{
	if (s.top == (MAXSIZE - 1))
	{
		printf ("Stack is Full\n");
		return;
	}
	else
	{
		s.top = s.top + 1;
		s.stk[s.top] = num;
	}
	return;
}
long long int pop ()
{
	long long int num;
	if (s.top == 0)
	{
		printf ("Stack is Empty\n");
		return (s.top);
	}
	else
	{
		num = s.stk[s.top];
		s.top = s.top - 1;
	}
	return(num);
}

