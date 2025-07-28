#include<stdio.h>

int process[100];
int ar[100];
int burst1[100];
void sort(int n)
{
   int i,j;
    for(i=0;i<n-1;i++)
    {
        
         for(j=0;j<n-1-i;j++)
         {
            if(ar[j]>ar[j+1])
           {
           
               int temp=ar[j];
               ar[j]=ar[j+1];
               ar[j+1]=temp;

               
               temp=process[j];
               process[j]=process[j+1];
               process[j+1]=temp;
           
           
               temp=burst1[j];
               burst1[j]=burst1[j+1];
               burst1[j+1]=temp;
                
           }
         }
         
    }

}
int main()
{
    printf("enter number of process : ");
    int n;
    scanf("%d",&n);
    printf("\nenter process : \n");
    for(int i=0;i<n;i++)
    {
          scanf("%d",&process[i]);
    }
   printf("\nenter arrival time : \n");
    for(int i=0;i<n;i++)
    {
          scanf("%d",&ar[i]);
    }
        printf("\nenter burst time : \n");
    for(int i=0;i<n;i++)
    {
          scanf("%d",&burst1[i]);
    }
    
     sort(n);
    
      int comp[n];
      int turn[n];
      int wt[n];
      comp[0]=ar[0]+burst1[0];
      for(int i=1;i<n;i++)
      {
         if(comp[i-1]<ar[i])
         {
             comp[i]=ar[i]+burst1[i];
         }
         else
         {
             comp[i]=comp[i-1]+burst1[i];
         }
      }
      // calculation of turnaround time and waiting time
        double avgturn=0.0;
      double avgwt=0.0;
      for(int i=0;i<n;i++)
      {
         turn[i]=comp[i]-ar[i];
         wt[i]=turn[i]-burst1[i];
         avgturn+=turn[i];
         avgwt+=wt[i]; 
      }
    
      printf("Process\tturn_time\twaiting_time\n\n");
      for(int i=0;i<n;i++)
      {
          printf("%d\t %d\t\t%d\n",process[i],turn[i],wt[i]);
      }
      avgturn/=n;
      avgwt/=n;
      printf("average turnaround time : %.2lf\n",avgturn);
      printf("average waiting time : %.2lf\n",avgwt);

}


/*
5
100 500 200 300 600
4
212 417 112 426
*/