#include <stdio.h>
#include <stdlib.h>

typedef struct dugum
{
    int veri;
    struct dugum *sonraki;
    struct dugum *onceki;
} dugum;

void bastan_yazdir(dugum *bas)
{
    dugum *gecici = bas->sonraki;
    while (gecici != NULL)
    {
        printf("%d - ", gecici->veri);
        gecici = gecici->sonraki;
    }
}

void sondan_yazdir(dugum *kuyruk)
{
    dugum *gecici = kuyruk;
    while (gecici != NULL)
    {
        printf("%d - ", gecici->veri);
        gecici = gecici->onceki;
    }
}

void *dugum_olustur(dugum *kuyruk, int veri)
{
    dugum *sonuc = malloc(sizeof(dugum));
    sonuc->veri = veri;
    sonuc->sonraki = NULL;
    sonuc->onceki = NULL;
}

int main()
{
    dugum *bas, *kuyruk;
    kuyruk->sonraki = bas;
    int girdi;
    while (1)
    {
        printf("Lutfen bir sayi giriniz. (-1 cikis yapar.)\n");
        scanf("%d", &girdi);
        if (girdi == -1)
        {
            break;
        }
        dugum_olustur(kuyruk, girdi);
    }
    bastan_yazdir(bas);
    printf(" \n");
    sondan_yazdir(kuyruk);

    return 0;
}