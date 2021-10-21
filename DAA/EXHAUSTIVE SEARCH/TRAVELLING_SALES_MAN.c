#include <stdio.h>
#include <math.h>
int min_cities[20];
double min_dist = INFINITY;
void swap(int string[], int a, int b)
{
    int f = string[a];
    string[a] = string[b];
    string[b] = f;
}
void permute(int cities[], int left, int right, int start, int distance[][right + 2])
{
    if (left == right)
    {
        int sum = 0;
        for (int i = 0; i < right; i++)
        {
            if (sum > min_dist )
            {
                break;
            }
            sum += distance[cities[i]][cities[i + 1]];
        }
        sum += distance[start][cities[0]];
        sum += distance[cities[right]][start];
        if (sum < min_dist )
        {
            min_dist = sum;
            for (int i = 0; i <= right; i++)
            {
                min_cities[i] = cities[i];
            }
        }
    }
    for (int i = left; i <= right; i++)
    {
        swap(cities, left, i);
        permute(cities, left + 1, right, start, distance);
        swap(cities, left, i);
    }
}
int main()
{
    int noOfCities;
    printf("\nEnter the no of citites : ");
    scanf("%d", &noOfCities);
    int distance[noOfCities][noOfCities];
    
    for (int i = 0; i < noOfCities; i++)
    {
        for (int j = i + 1; j < noOfCities; j++)
        {
            printf("distance between %d and %d : ", i + 1, j + 1);
            scanf("%d", &distance[i][j]);
            distance[j][i] = distance[i][j];
        }
    }
    printf("\nEnter the starting city : ");
    int arr[noOfCities - 1];
    int count = 0;
    int start;
    scanf("%d", &start);
    for(int i=0;i<noOfCities;i++)
    {
        if(i!=start-1)
        {
            arr[count++] = i;
        }
    }
    permute(arr, 0, noOfCities - 2, start - 1, distance);
    printf("\n%d->",start);
    for (int i = 0; i < noOfCities - 1; i++)
    {
        printf("%d->", min_cities[i] + 1);
    }
    printf("->%d",start);
    printf("\ndistance : %lf", min_dist);
    return 0;
}
