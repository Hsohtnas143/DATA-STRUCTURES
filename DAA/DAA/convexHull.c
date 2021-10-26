#include<stdio.h>
int main()
{
  int n;
  printf("\nEnter the no. of points : ");
  scanf("%d",&n);
  float arr[n][2];
  float m,c;
  int final[n];
  for(int i=0;i<n;i++)
  {
    final[i] = 0;
    printf("\nEnter the point x y : ");
    scanf("%f",&arr[i][0]);
    scanf("%f",&arr[i][1]);
  }
  float x1,x2,y1,y2,x,y;
  int left;
  int right;
  for(int i=0;i<n;i++)
  {
    for(int j=i+1;j<n;j++)
    {
      y2 = arr[j][1];
      y1 = arr[i][1];
      x2 = arr[j][0];
      x1 = arr[i][0];
      m = (y2 - y1)/(x2 - x1);
      c = ((x2*y1)-(x1*y2))/(x2-x1);
      left = 0;
      right = 0;
      for(int k=0;k<n;k++)
      {
        if(k!=i && k!=j && i!=j)
        {
          x = arr[k][0];
          y = arr[k][1];
          if(y > m*x + c)
          {
            right++;
          }
          else if(y < m*x + c)
          {
            left++;
          }
          if(right > 0 && left> 0)
          {
            break;
          }
        }
      }
      if(left == n-2 || right == n-2)
      {
        final[i] = 1;
        final[j] = 1;
      }
    }  
  }
  for(int i=0;i<n;i++)
  {
    if(final[i]==1)
    printf("\n{%f,%f}\n",arr[i][0],arr[i][1]);
  }
  return 0;
}