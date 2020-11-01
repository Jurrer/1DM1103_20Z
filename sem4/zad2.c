#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main (int argc, char *argv[])
{
    FILE *fm = fopen("a.txt", "r");
    FILE *fw = fopen("wekt.txt", "r");

    int kolumny;
    int wiersze;
    int wiersze_w;
    int kolumna;
    
    fscanf(fm, "%d %d", &wiersze, &kolumny);

    float macierz[wiersze][kolumny];    

    for(int i = 0; i < wiersze; i++)
    {
        for(int j = 0; j < kolumny; j++)
        {
        fscanf(fm, "%f", &macierz[i][j]);
        }
    }
    
    fscanf(fw, "%d %d", &wiersze_w, &kolumna);

    float wektor[wiersze_w][kolumna];    

    for(int i = 0; i < wiersze_w; i++)
    {
        for(int j = 0; j < kolumna; j++)
        {
        fscanf(fm, "%f", &wektor[i][j]);
        }
    }

    float wynik[wiersze][kolumna];

printf("%d, %d, %d, %d\n", wiersze, kolumny, wiersze_w, kolumna);

    if(kolumny == wiersze_w)
    {
        for(int i = 0; i<wiersze; i++)
        {
            for(int j = 0; j < kolumna; j++)
            {    
                wynik[i][j]=0;
                for(int h = 0; h < wiersze_w; h++)
            {
                wynik[i][j] = wynik[i][j] + (macierz[i][h]*wektor[h][j]);
            }
            }
        }
        for(int i = 0; i<wiersze; i++)
        for(int j = 0; j < kolumna; j++)
        printf("%f ", wynik[i][j]);
        printf("\n");
    }
    else
    {
        printf("Nie da się wymnożyć");
    }
  
}
