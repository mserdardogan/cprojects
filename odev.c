#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dugum
{
	char isim[25];
	char soyisim[25];
	long telefonNo;
	char eposta[320]; // tutarlı bir mail adresinin maksimum uzunluğu 320 olarak belirtilmiş.
	struct dugum *sonraki;
};
typedef struct dugum dugum;

void *dugum_olustur(dugum *kuyruk, char isim[], char soyisim[], long telefonNo, char eposta[])
{
	dugum *sonuc = malloc(sizeof(dugum));
	strcpy(sonuc->isim, isim);
	strcpy(sonuc->soyisim, soyisim);
	sonuc->telefonNo = telefonNo;
	strcpy(sonuc->eposta, eposta);
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
	while (1)
	{
		printf("Yapmak istediginiz islemi seciniz.\n");
		printf("-1- Rehbere kisi ekle.\n");
		printf("-2- Rehberden kisi sil.\n");
		printf("-3- Kisileri listele.\n");
		printf("-4- Isme gore sirala.\n");
		printf("-5- Soyisime gore sirala.\n");
		printf("-6- Cikis.\n");

		int girdi;
		scanf("%d", &girdi);

		if (girdi <= 0 || girdi >= 7)
		{
			/* code */
		}
		else if (girdi == 1)
		{
			/* code */
		}
		// TODO: while döngüsü tamamlanacak
	}

	return 0;
}