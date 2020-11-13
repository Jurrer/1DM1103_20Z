#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _student {
    char imie[25];
    char nazwisko[50];
    char nr_albumu[10];
    char kod_przed[10];
    char nazwa_przed[255];
    float ocena;
    int ects;
} student, *pstudent;


int wczytaj(student dane[100], char *fnazwa) {
    FILE * fin = fopen(fnazwa, "r");
    int cnt, i;
    char bufor[1024];
    char *w;

    fgets(bufor, 1023, fin);
    sscanf(bufor, "%d", &cnt);
 
    for (i=0; i<cnt; i++) {
        fgets(bufor, 1023, fin);
        // printf("%s", bufor);
        w = strtok(bufor, "|");
        strncpy(dane[i].imie, w, 24);

        w = strtok(NULL, "|");
        strncpy(dane[i].nazwisko, w, 49);
        
        w = strtok(NULL, "|");
        strncpy(dane[i].nr_albumu, w, 9);

        w = strtok(NULL, "|");
        strncpy(dane[i].kod_przed, w, 9);

        w = strtok(NULL, "|");
        strncpy(dane[i].nazwa_przed, w, 254);

        w = strtok(NULL, "|");
        dane[i].ocena = atof(w);

        w = strtok(NULL, "|");
        dane[i].ects = atoi(w);
    }

    fclose(fin);
    return cnt;
}


//void wypisz(student dane[100], int n) {
//    int i;
//    for (i=0; i<n;i++) {
//        printf("{ Student: %s - %s %s, z przedmiotu: [%s] %s za ECTS: %d otrzymał %.1f\n",
//            dane[i].nr_albumu, dane[i].imie, dane[i].nazwisko,
//            dane[i].kod_przed, dane[i].nazwa_przed,
//            dane[i].ects, dane[i].ocena
//        );
//    }
//}


int znajdz(char *szukany_nr, char kod_przed[100][10], int n) {
    int i;
    for (i=0; i<n; i++) {
        if (strcmp(szukany_nr, kod_przed[i]) == 0)
            return i;
    }
    return -1;
}


int znajdz_przedmioty(char kod_przed[100][10], student dane[100], int n) {
    int ile_znalazlem = 0;
    int i;

    for (i=0; i <n; i++) {
        if (znajdz(dane[i].kod_przed, kod_przed, ile_znalazlem) == -1) {
            strncpy(kod_przed[ile_znalazlem], dane[i].kod_przed, 9);
            ile_znalazlem++;
            }
    }
    return ile_znalazlem;
}


void najtrudniejszy_p(student dane[100], int ile_rekordow) {
    //char nr_albumow[100][10];
    char nazwa_p[100][100];
    int ile_przedmiotow;
    char kod_przed[100][10];
    int ile_dod[100];
    float srednie[100];
    int i = 0;
    int pozycja;
    int najlepsza_pozycja;
    float najlepsza;
        
        for(int x = 0; x<100; x++){
        srednie[x] = 0;
        ile_dod[x] = 0;
        }

    ile_przedmiotow = znajdz_przedmioty(kod_przed, dane, ile_rekordow);

    for (i=0; i < ile_rekordow; i++) {
        pozycja = znajdz( dane[i].kod_przed, kod_przed, ile_przedmiotow);
        // if (pozycje >= 0)
        strcpy(nazwa_p[pozycja], dane[i].nazwa_przed);
        ile_dod[pozycja]++;
        srednie[pozycja] += dane[i].ocena;
    }    

    for (i=0; i < ile_przedmiotow; i++) {
        srednie[i] = srednie[i]/ile_dod[i];
    }   
    

    //for (i=0;i<ile_przedmiotow; i++) 
    //    printf("Student [%d]: %s - %f:%d - %f \n", i+1, nr_albumow[i], 
    //    sumy_wazonych_ocen[i], sumy_ects[i], sumy_wazonych_ocen[i] / sumy_ects[i]);

    for (i=0; i < ile_przedmiotow; i++) {
        if (najlepsza > srednie[i]) {
            najlepsza = srednie[i];
            najlepsza_pozycja = i;
        }
    }

    printf("Najgorsza srednia: ");
    printf("%s - %s: %.2f \n", kod_przed[najlepsza_pozycja], 
    nazwa_p[najlepsza_pozycja], srednie[najlepsza_pozycja]
    );
}


void najlatwiejszy_p(student dane[100], int ile_rekordow) {
    //char nr_albumow[100][10];
    char nazwa_p[100][100];
    int ile_przedmiotow;
    char kod_przed[100][10];
    int ile_dod[100];
    float srednie[100];
    int i = 0;
    int pozycja;
    int najlepsza_pozycja;
    float najlepsza;
        
        for(int x = 0; x<100; x++){
        srednie[x] = 0;
        ile_dod[x] = 0;
        }

    ile_przedmiotow = znajdz_przedmioty(kod_przed, dane, ile_rekordow);

    for (i=0; i < ile_rekordow; i++) {
        pozycja = znajdz( dane[i].kod_przed, kod_przed, ile_przedmiotow);
        // if (pozycje >= 0)
        strcpy(nazwa_p[pozycja], dane[i].nazwa_przed);
        ile_dod[pozycja]++;
        srednie[pozycja] += dane[i].ocena;
    }    

    for (i=0; i < ile_przedmiotow; i++) {
        srednie[i] = srednie[i]/ile_dod[i];
    }   
    

    //for (i=0;i<ile_przedmiotow; i++) 
    //    printf("Student [%d]: %s - %f:%d - %f \n", i+1, nr_albumow[i], 
    //    sumy_wazonych_ocen[i], sumy_ects[i], sumy_wazonych_ocen[i] / sumy_ects[i]);

    for (i=0; i < ile_przedmiotow; i++) {
        if (najlepsza < srednie[i]) {
            najlepsza = srednie[i];
            najlepsza_pozycja = i;
        }
    }

    printf("Najlepsza srednia: ");
    printf("%s - %s: %.2f \n", kod_przed[najlepsza_pozycja], 
    nazwa_p[najlepsza_pozycja], srednie[najlepsza_pozycja]
    );
}


int main() {
    student dane[100];
    int ile;
    ile = wczytaj(dane, "studenci.txt");
    //wypisz(dane, ile);

    najlatwiejszy_p(dane, ile);
    najtrudniejszy_p(dane, ile);

    return 0;
}