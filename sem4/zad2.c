#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main (int argc, char *argv[])
{
    FILE *fm = fopen(argv[1], "r");
    FILE *fw = fopen(argv[2], "r");

    int kolumny;
    int wiersze;
    int wiersze_w;
    int kolumna;
    //wczytuje macierz
    fscanf(fm, "%d %d", &wiersze, &kolumny);

    float macierz[wiersze][kolumny];    

    for(int i = 0; i < wiersze; i++)
    {
        for(int j = 0; j < kolumny; j++)
        {
        fscanf(fm, "%f", &macierz[i][j]);
        }
    }
    //wczytuje wektor
    fscanf(fw, "%d %d", &wiersze_w, &kolumna);

    float wektor[wiersze_w][kolumna];    

    for(int i = 0; i < wiersze_w; i++)
    {
        for(int j = 0; j < kolumna; j++)
        {
        fscanf(fw, "%f", &wektor[i][j]);
        }
    }
//tworzę tabele na wynik
    float wynik[wiersze][kolumna];
 
    if(kolumny == wiersze_w)
    {
        for(int i = 0; i<wiersze; i++)
        {
            for(int j = 0; j < kolumna; j++)
            {    
                for(int h = 0; h < wiersze_w; h++)
            {
                wynik[i][j] = wynik[i][j] + (macierz[i][h]*wektor[h][j]);
            }
            }
        }   
        for(int i = 0; i<wiersze; i++)
        {
        for(int j = 0; j < kolumna; j++)
        {
        printf("|%f|", wynik[i][j]);
        printf("\n");
        }
        }
    }
    else
    {
        printf("Nie da się wymnożyć");
    }
  
}
