#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dugum
{
	char isim[25];
	char soyisim[25];
	int yas;
	long telefonNo;
	struct dugum *sonraki;
};
typedef struct dugum dugum;

void *dugum_olustur(dugum *kuyruk, char isim[], char soyisim[], int yas, long telefonNo)
{
	dugum *sonuc = malloc(sizeof(dugum));
	strcpy(sonuc->isim, isim);
	strcpy(sonuc->soyisim, soyisim);
	sonuc->yas = yas;
	sonuc->telefonNo = telefonNo;
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

	return 0;
}