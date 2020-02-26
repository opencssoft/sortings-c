#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 1000

int merge(int a[],int medium[],int startpos,int m,int endpos)
{
    int i = startpos;
    int j = m;
    int curpos = startpos;
    int num = endpos - startpos;;

    while(curpos < endpos)
    {
        if(a[i] < a[j])
        {
            medium[curpos] = a[i];
            i++;
        }
        else
        {
            medium[curpos] = a[j];
            j++;
        }
        curpos++;

        if(i > m-1)
        {
            for(int jj =0;jj + startpos < curpos; jj++)
            {
                 a[startpos + jj] = medium[startpos + jj];    
            }

            return 0;
        }

        if(j > endpos)
        {
            int jj = 0;
            while( i < m )
            {
                medium[curpos] = a[i];
                i++;
                curpos++;
            }

            for(jj =startpos; jj <= endpos; jj++ )
            {
                a[jj] = medium[jj];
            }

            return 0;
        }
    }
    return 0;
}

int mergeprepare(int a[],int n)
{
    int j=0;
    int temp = 0;
    printf("mergeprepare result =====>\n");

    for(j=0;j+1<n;)
    {
        if(a[j]>a[j+1])
        {
            temp = a[j];
            a[j] = a[j+1];
            a[j+1]=temp;
        }
        j = j + 2;
    }

    for(j=0; j<n; ++j)
    {
        printf("%-5d ",a[j]);
    }

    printf("\n\n");

    return 0;
}

int main()
{
    int counter = 0;
    int a[10001];
    int med[1001];
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

    mergeprepare(a,n);

    for(i = 0;i+3 < n;)
    {
        merge(a,med,0,i+2,i+3);
        printf("sorting ======round %d======>\n\n",i/2);

        for(j=0; j<i+4; ++j)
        {
            printf("%-5d ",a[j]);
        }

        printf("\n\n");
        i = i+2;
    }
    printf("================last sorting round.=========>\n");
    merge(a,med,0,i+2,i+2);

    for(j=0; j<n; ++j)
    {
        printf("%-5d ",a[j]);
    }

    printf("\n\n");

    printf("=======sorted result============>\n\n");

    for(j=0; j<n; ++j)
    {
        printf("%-5d ",a[j]);
    }

    printf("\n\n");

    return 0;
}
