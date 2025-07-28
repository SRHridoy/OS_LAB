#include<stdio.h>
int process[100],arr[100],burst[100];
void sort(n)
 {

       for(int i=0;i<n-1;i++)
       {
          for(int j=0;j<n-1-i;j++)
          {
               if(arr[j]>arr[j+1])
               {
                    int temp=burst[j];
                    burst[j]=burst[j+1];
                    burst[j+1]=temp;

                    temp=process[j];
                    process[j]=process[j+1];
                    process[j+1]=temp;
                    temp=arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=temp;
               }
          }
       }
 }

int main()
{
      printf("enter number of process : ");
      int n,i;
       scanf("%d",&n);
       int check[n];
       int brr[n];
       int burstemp[n];
      printf("enter process , arrival time burst time : \n");
      for(i=0;i<n;i++)

      {

         scanf("%d%d%d",&process[i],&arr[i],&burst[i]);
         check[i]=process[i];
         brr[i]=arr[i];
         burstemp[i]=burst[i];
      }

      sort(n);
      int j=0;
      int time=0;
      int com[n],turn[n],wt[n];
      int ansproces[n];
      int prev=0;

      while(j<n)
      {

          int indx=-1;
          int ans=0;
        for(i=0;i<n;i++)
        {
             if(check[i]==-1) continue;
             if(arr[i]>time) continue;
             if(indx==-1) {ans=burst[i]; indx=i;}
             else
             {
                  if(ans>burst[i]){ ans=burst[i]; indx=i;}
             }
        }

        if(indx==-1) {time++;prev=time;continue;}

      ansproces[j]=process[indx];
       com[j]=prev+burst[indx];
        prev=com[j];
        time=prev;
        check[indx]=-1;
       j++;
      }

      double averageturn=0.0;
      double averagewaiting=0.0;
      for(i=0;i<n;i++)
      {
         turn[i]=com[i]-brr[ansproces[i]-1];
         averageturn+=(double)turn[i];
         wt[i]=turn[i]-burstemp[ansproces[i]-1];
          averagewaiting+=(double)wt[i];
      }

      printf("Process\t\tturn around time\t\t\waiting time\n");
      for(i=0;i<n;i++)
      {
         printf("%d\t\t\t%d\t\t\t\t%d\n",ansproces[i],turn[i],wt[i]);
      }
    averageturn/=n;
    averagewaiting/=n;
    printf("average turn around time : %.2lf\n",averageturn);
    printf("average waiting around time : %.2lf\n",averagewaiting);
    return 0;
}