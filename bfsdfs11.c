#include<stdio.h>
#include<stdlib.h>


void bfs(int n,int a[20][20],int source,int visited[],int e[20][2])
{
    int f=0,r=-1,q[20];
    int u,v,k=1;

    visited[source]=1;
    r=r+1;
    q[r]=source;
    while(f<=r)
    {
        u=q[f];
        f=f+1;
        for ( v = 1; v <= n; v++)
        {
           if (a[u][v]==1 && visited[v]== 0)
           {
               visited[v]=1;
               r=r+1;
               q[r]=v;
               e[k][1]=u;
               e[k][2]=v;
               k=k+1;
           }
           
        }
        
    }
}

void dfs(int n,int a[20][20],int u,int visited[],int e[20][2])
{
    int v;
    static int k=1;

    visited[u]=1;

    for ( v = 1; v <= n; v++)
    {
        if (a[u][v]==1 && visited[v]==0)
        {
            e[k][1]=u;
            e[k][2]=v;
            k=k+1;
            dfs(n,a,v,visited,e);
        }
        
    }
    
}

void main()
{
    int n,i,j,a[20][20],source,visited[20],e[20][2],choice,flag;

    printf("\nEnter no of vertices\n");
    scanf("%d",&n);

    for ( i = 1; i <= n; i++)
    {
        for ( j = 1 ; j <= n; j++)
        {
            scanf("%d",&a[i][j]);
        }
        
    }

    printf("\nEnter the source vertex\n");
    scanf("%d",&source);

    for ( i = 1; i <= n; i++)
    {
        visited[i]=0;
    }

    printf("\n1.BFS 2.DFS\n");
    printf("Enter your choice\n");
    scanf("%d",&choice);


    if (choice==1)
    {
        bfs(n,a,source,visited,e);
    }
    else
    {
        dfs(n,a,source,visited,e);
    }

    flag=0;

    for ( i = 1; i <= n; i++)
    {
        if (visited[i]==0)
        {
            printf("%d is not reachable\n",i);
            flag=1;
        }
        else
        {
            printf("%d is reachable\n",i);
        }
        
        
    }

    if (flag==1)
    {
        printf("The Graph is not connected\n");
    }
    else
    {
        printf("The graph is connected\n");
        printf("The spanning tree or traversal tree is\n");

        for ( i =1 ; i <= n-1; i++)
        {
            printf("Edge from %d to %d\n",e[i][1],e[i][2]);
        }
    }
    
       
        
}