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
    dugum *gecici = kuyruk->sonraki;
    while (gecici != NULL)
    {
        printf("%d - ", gecici->veri);
        gecici = gecici->onceki;
    }
}

void *dugum_olustur(dugum *bas, dugum *kuyruk, int veri)
{
    dugum *sonuc = malloc(sizeof(dugum));
    sonuc->veri = veri;
    sonuc->sonraki = NULL;
    sonuc->onceki = NULL;
    kuyruk->sonraki->sonraki = sonuc;
    if (bas == kuyruk->sonraki)
    {
        sonuc->onceki = NULL;
        kuyruk->sonraki = sonuc;
    }
    else
    {
        sonuc->onceki = kuyruk->sonraki;
        kuyruk->sonraki = sonuc;
    }
}

int main()
{
    dugum *bas, *kuyruk;
    bas = (dugum *)malloc(sizeof(dugum));
    kuyruk = (dugum *)malloc(sizeof(dugum));
    kuyruk->sonraki = bas;
    int girdi;
    while (1)
    {
        printf("Lutfen bir sayi giriniz. (-1 cikis yapar.)\n");
        scanf("%d", &girdi);
        if (girdi == -1)
            break;
        dugum_olustur(bas, kuyruk, girdi);
    }
    bastan_yazdir(bas);
    printf(" \n");
    sondan_yazdir(kuyruk);
    printf(" \n");

    return 0;
}