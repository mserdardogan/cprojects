#include <stdio.h>
#include <stdlib.h>

struct dugum
{
    int veri;
    struct dugum *sonraki;
};
typedef struct dugum dugum;

void bastan_yazdir(dugum *bas)
{
    dugum *gecici = bas->sonraki;
    while (gecici != NULL)
    {
        printf("%d - ", gecici->veri);
        gecici = gecici->sonraki;
    }
}

void *dugum_olustur(dugum *kuyruk, int veri)
{
    dugum *sonuc = malloc(sizeof(dugum));
    sonuc->veri = veri;
    sonuc->sonraki = NULL;
    kuyruk->sonraki->sonraki = sonuc;
    kuyruk->sonraki = sonuc;
}

int main()
{
    // baş düğümü listenin ilk elemanını, kuyruk ise son elemanı gösterir
    dugum *bas, *kuyruk;
    bas = (dugum *)malloc(sizeof(dugum));
    kuyruk = (dugum *)malloc(sizeof(dugum));

    // ilk veriyi girmeden önce geçici olarak kuyruk düğümü baş düğümünü işaret ediyor
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

    printf("\n");
    return 0;
}