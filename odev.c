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
	dugum *sonuc = (dugum *)malloc(sizeof(dugum));
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
			printf("Hatali girdi. Lutfen tekrar sayi girin.\n\n");
			continue;
		}
		else if (girdi == 1) // Kişi ekleme
		{
			dugum *gecici;
			gecici = (dugum *)malloc(sizeof(dugum));
			printf("\nEklemek istediginiz kisinin ismini giriniz:\n");
			scanf("%s", gecici->isim);

			printf("Eklemek istediginiz kisinin soyismini giriniz:\n");
			scanf("%s", gecici->soyisim);

			printf("Eklemek istediginiz kisinin telefon numarasini giriniz:\n");
			long geciciTelNo;
			scanf("%ld", &geciciTelNo);
			gecici->telefonNo = geciciTelNo;

			printf("Eklemek istediginiz kisinin e-posta adresini giriniz:\n");
			scanf("%s", gecici->eposta);

			dugum_olustur(kuyruk, gecici->isim, gecici->soyisim, gecici->telefonNo, gecici->eposta);

			printf("\nEklediginiz kisinin ismi: %s\nSoyismi: %s\nTelefon numarasi: %ld\nEposta adresi: %s\n\n", gecici->isim, gecici->soyisim, gecici->telefonNo, gecici->eposta);
			free(gecici);
		}

		else if (girdi == 2) // Kişi silme
		{
			int sira;
			dugum *geciciX = (dugum *)malloc(sizeof(dugum));
			geciciX->sonraki = bas->sonraki; // SAÇMA HATA
			printf("Silmek istediginiz kisinin rehberdeki sira numarasini giriniz.\n");
			scanf("%d", &sira);
			if (sira <= 0)
			{
				// DİKKAT
				printf("Lutfen bir sayma sayisi girin.\n");
			}
		}
		else if (girdi == 3) // Kişileri listeleme
		{
			dugum *gecici;
			gecici->sonraki = bas->sonraki;
			int i = 1;
			while (gecici->sonraki != NULL)
			{
				printf("%d.\nIsim: %s\nSoyisim: %s\nTelefon Numarası: %ld\nEposta: %s\n\n", i, gecici->sonraki->isim, gecici->sonraki->soyisim, gecici->sonraki->telefonNo, gecici->sonraki->eposta);
				i++;
				gecici->sonraki = gecici->sonraki->sonraki;
			}
		}
		// else if (girdi == 4)
		//{
		// }
		// else if (girdi == 5)
		//{
		// }
		else if (girdi == 6)
		{
			break;
		}
	}
	return 0;
}