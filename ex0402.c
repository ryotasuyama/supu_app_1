#include <stdio.h>
#define SIZE 100

int main(void)
{
    int n, i, sum = 0, sc[SIZE];

    printf("人数を入力していください");
    scanf("%d", &n);
    
    for(i = 0; i < n; i++)
    {
        printf("%d人目の成績を入力しなさい", i+1);
        scanf("%d", &sc[i]);

        if(sc[i] <= -2 || sc[i] >= 101)
        {
            printf("数値が間違っています\n");
            return 1;
        }
    }

    int s = 0, a = 0, b = 0, c = 0, d = 0, f = 0, max = sc[0], min = sc[0];

    for(i = 0; i < n; i++)
    {
        if(sc[i] >=90 && sc[i] <= 100)
        {
            s += 1;
        }
        if(sc[i] < 90 && sc[i] >=80)
        {
            a += 1;
        }
        if(sc[i] < 80 && sc[i] >=70)
        {
            b += 1;
        }
        if(sc[i] < 70 && sc[i] >=60)
        {
            c += 1;
        }
        if(sc[i] < 60 && sc[i] >=0)
        {
            d += 1;
        }
        if(sc[i] == -1)
        {
            f += 1;
        }
        if(sc[i] != -1)
        {
            if(sc[i] >= max)
            {
                max = sc[i];
            }
            if(sc[i] <= min)
            {
                min = sc[i];
            }
            sum += sc[i];
        }
        if(max == -1 && min == -1)
        {
            max = 0;
            min = 0;
            sum = 0;
        }
    }
    if(n == f)
    {
        printf("=======成績の内訳=======\n");
        printf("受講者数 0 名\n");
        printf("合格者数 0 名 （合格率 0 ％)\n");
        printf("平均点 0 点\n最高点 0 点\n最低点 0 点\n");
        printf("-----------------\n     秀 %d 名\n     優 %d 名\n     良 %d 名\n     可 %d 名\n   不可 %d 名\n 評価しない %d 名\n", s, a, b, c, d, f);
        printf("======================\n");
    }
    else
    {
        printf("=======成績の内訳=======\n");
        printf("受講者数 %d 名\n", n);
        printf("合格者数 %d 名 （合格率 %d ％)\n", s + a + b + c, 100 * (s + a + b + c) / n);
        printf("平均点 %.1f 点\n最高点 %d 点\n最低点 %d 点\n", (double)sum / (n - f), max, min);
        printf("-----------------\n     秀 %d 名\n     優 %d 名\n     良 %d 名\n     可 %d 名\n   不可 %d 名\n 評価しない %d 名\n", s, a, b, c, d, f);
        printf("======================\n");
    }
}













