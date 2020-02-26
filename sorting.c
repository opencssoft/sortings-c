#include <stdio.h>
#include <stdlib.h>

#define N 1000

int main()
{
    int counter = 0;
    int a[10001];
    char char2num[1000] = {'\0'};

    int n = 0, i, j = 0, t;

    printf("init data list to be sorted======>\n");

    FILE * fp = fopen("numbers.txt", "rt");
    char str[N + 1];
    //判断文件是否打开失败
    if ( fp == NULL ) 
    {
        puts("Fail to open file!");
        exit(0);
    }
    //循环读取文件的每一行数据
    while(fgets(str, N, fp) != NULL ) 
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

    printf("the count numbers of the data is: %d\n",n);
    printf("=========starting sort the data list!======>\n");
   
    //操作结束后关闭文件
    fclose(fp);

    for (i = 0; i < n-1; ++i)
    {
        for(j = 0; j < n-i-1;++j)
        {
            if(a[j] > a[j+1])
            {
                t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;  
            }
        }

        for(j = 0; j < n; ++j)
        {
            printf("%-5d ",a[j]);
        }

        printf("\n\n");
    }

    return 0;
}
