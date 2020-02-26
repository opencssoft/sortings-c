#include <stdio.h>
#include <stdlib.h>

#define N 1000

int quickits(int a[],int n)
{
    int i=0,j=n-1;
    int refcnt = a[0];
    int flag = 0;
    int temp =0;

    int refstartpos = 0;
    int refendpos = 0;

    if(n<=1){
        return 0;
    }

    if(n==2 && a[0] == a[1])
        return 0;

    printf("input data list====>\n");

    for(int jj=0; jj<n; ++jj)
    {
        printf("%-5d ",a[jj]);
    }
    printf("\n\n");

    while(i < j)
    {
        if(a[j] < refcnt)
        {
               temp = a[i];
               a[i] = a[j];
               a[j] = temp;
        }

        if(a[j] == refcnt)
        {
            {
                if(refstartpos == 0)
                {
                    refstartpos = j;
                    refendpos = j;
                }
                else
                {
                    refendpos = j;
                }
                j--;
            }
        }
        else if(a[j] > refcnt)// && j > i)
        {
            if(refstartpos != 0)
            {
                temp = a[refstartpos];
                a[refstartpos] = a[j];
                a[j] = temp;
                refstartpos--;
                refendpos--;
            }
            else
            {
                flag = 1;
                j--;
            }
        }
        
        if(a[i] < refcnt && i<j)
        {
            i++;
            flag=1;
        }

        if(a[i] > refcnt && i == refendpos-1)
        {
            if(refstartpos != 0)
            {
                temp = a[refstartpos];
                a[refstartpos] = a[i];
                a[i] = temp;
                refstartpos--;
                refendpos--;
            }
        }

        if(i!=j && flag == 1 && a[i] > a[j] )
        {
            if(refstartpos != 0)
            {
                temp = a[i];
                a[i] = a[refstartpos];
                a[refstartpos] = temp;
                refstartpos--;
                if(refendpos > refstartpos)
                {
                    refstartpos = 0;
                    refendpos = 0;
                }
            }
            else
            {
                temp = a[i];
                 a[i] = a[j];
                 a[j] = temp;
            }
        }

        if(a[i] == refcnt &&  a[j] == refcnt){
            if(j == i+1 )
                break;}

        flag = 0;
    }

    printf("sorting steps =====>\n");

    for(j=0; j<n; ++j)
    {
        printf("%-5d ",a[j]);
    }

    printf("\n\n");

    if(i==j)
        return 0;

    if(refstartpos != 0)
    {
        i = refstartpos;
    }

    if(i>0)
        quickits(a,i);
    if(n-i-1>0)
        quickits(a+i+1,n-i-1);

    return 0;
}

int main()
{
    int counter = 0;
    int a[10001];
    char char2num[1000] = {'\0'};

    int n, i, j = 0, t;

    printf("starting sort the number list.\n");

    FILE * fp;    
    char str[N + 1];
    //判断文件是否打开失败
    if ( (fp = fopen("numbers.txt", "rt")) == NULL ) {
        puts("Fail to open file!");
        exit(0);
    }

    while( fgets(str, N, fp) != NULL ) 
    {

        for(i = 0; i < N;i++)
        {
            char chartemp = str[i];
            if(chartemp >= '0' && chartemp <= '9')
            {
                char2num[counter] = chartemp;
                counter++;
            }
            else if(counter > 0)
            {
                char2num[counter] ='\0';
                a[j] = atoi(char2num);
                j++;
                n++;
                counter = 0;
          }
            if(chartemp == '\0')
                break;
        }

        printf("%s", str);
    }
    printf("\n");

    //操作结束后关闭文件
    fclose(fp);

    quickits(a,n);

    printf("sorted result============>\n\n");

    for(j=0; j<n; ++j)
    {
        printf("%-5d ",a[j]);
    }

    printf("\n\n");

    return 0;
}
