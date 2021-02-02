#include<stdio.h>
int top = 0;
int n=6;
int insert(int stack[n],int val)
{
    if(top!=n)
        stack[top++] = val;
}

int pop(int stack[n])
{
    if(top!=0)
        top--;
}

int check_visited(int val,int visited_list[n])
{
    
    if(visited_list[val] == 1)
        return 1;
    else
        return 0;
}

int check_stack(int stack[n],int val)
{
    for(int i=0;i<top;i++)
    {
        if(stack[i] == val)
            return 1;
        else
            return 0;
    }
}

int main()
{
    int adj_matrix[][6] = {{0,1,1,0,0,1},{1,0,0,1,1,0},{1,0,0,0,1,0},{0,1,0,0,0,1},{0,1,1,0,0,1},{1,0,0,1,1,0}};
    //DFS
    int visited_list[6] = {0,0,0,0,0,0};
    int stack[6];
    insert(stack,1);
    printf("%d ",stack[top-1]);
    visited_list[0] = 1;
    int i=0,val,a,b,flag=0;
    while(i<5)
    {
        flag=0;
        val = stack[top-1];
        for(int j=0;j<6;j++)
        {
            if(adj_matrix[val-1][j] == 1)
            {
                a = check_visited(j,visited_list);
                b = check_stack(stack,j+1);
                if((a==0) && (b==0))
                {
                    insert(stack,j+1);
                    visited_list[j] = 1;
                    printf("%d ",j+1);
                    i++;
                    flag = 1;
                    break;
                }
                
            }
            
        }
        if(flag == 0)
        {
            pop(stack);
        }
        
    }
}
