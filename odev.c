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

void dugum_olustur(dugum *kuyruk, char isim[], char soyisim[], long telefonNo, char eposta[])
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

void dugum_sil(dugum *bas, int sira)
{
	// oncekiDugum silinecek olan düğümden bir önceki düğümü gösterir
	dugum *silinecekDugum, *oncekiDugum;
	oncekiDugum = bas;
	for (int i = 0; i < sira - 1; i++)
	{
		oncekiDugum = oncekiDugum->sonraki;
	}
	silinecekDugum = oncekiDugum->sonraki;
	oncekiDugum->sonraki = oncekiDugum->sonraki->sonraki;
	free(silinecekDugum);
}

void butun_listeyi_yazdir(dugum *bas)
{
	dugum *gecici = (dugum *)malloc(sizeof(dugum));
	gecici->sonraki = bas->sonraki;
	if (gecici->sonraki == NULL)
	{
		printf("Rehber bos!\n");
		return;
	}
	else
	{
		for (int i = 1; gecici->sonraki != NULL; i++)
		{
			printf("%d.\nIsim: %s\nSoyisim: %s\nTelefon Numarası: %ld\nEposta: %s\n\n", i, gecici->sonraki->isim, gecici->sonraki->soyisim, gecici->sonraki->telefonNo, gecici->sonraki->eposta);
			gecici->sonraki = gecici->sonraki->sonraki;
		}
	}
}

void isimle_ara(dugum *bas, char isim[])
{
	dugum *gecici = bas;
	if (bas->sonraki == NULL)
	{
		printf("Rehber bos!\n\n");
	}
	else
	{
		short i = 0; // boolean gibi çalışacak i değişkeni. eğer while döngüsünde değeri 1 olursa aranan kişi(ler) bulunmuş demektir. 0 ise bulunamamış demektir.
		while (1)
		{
			if (strcmp(bas->sonraki->isim, isim) == 0)
			{
				i = 1;
				printf("\nIsim: %s\nSoyismi: %s\nTelefon numarasi: %ld\nEposta adresi: %s\n\n", bas->sonraki->isim, bas->sonraki->soyisim, bas->sonraki->telefonNo, bas->sonraki->eposta);
			}

			if (bas->sonraki->sonraki == NULL)
			{
				break;
			}

			bas->sonraki = bas->sonraki->sonraki;
		}
		if (i == 0)
		{
			printf("Aradiginiz kisi listede yok!\n\n");
		}
	}
	bas = gecici;
}

void soyisimle_ara(dugum *bas, char soyisim[])
{
	dugum *gecici = bas;
	if (bas->sonraki == NULL)
	{
		printf("Rehber bos!\n\n");
	}
	else
	{
		short i = 0; // boolean gibi çalışacak i değişkeni. eğer while döngüsünde değeri 1 olursa aranan kişi(ler) bulunmuş demektir. 0 ise bulunamamış demektir.
		while (1)
		{
			if (strcmp(bas->sonraki->soyisim, soyisim) == 0)
			{
				i = 1;
				printf("\nIsim: %s\nSoyismi: %s\nTelefon numarasi: %ld\nEposta adresi: %s\n\n", bas->sonraki->isim, bas->sonraki->soyisim, bas->sonraki->telefonNo, bas->sonraki->eposta);
			}

			if (bas->sonraki->sonraki == NULL)
			{
				break;
			}

			bas->sonraki = bas->sonraki->sonraki;
		}
		if (i == 0)
		{
			printf("\nAradiginiz kisi listede yok!\n\n");
		}
	}
	bas = gecici;
}

int main(void)
{
	// baş düğümü listenin ilk elemanını, kuyruk ise son elemanı gösterir
	dugum *bas, *kuyruk;
	bas = (dugum *)malloc(sizeof(dugum));

	// ilk veriyi girmeden önce geçici olarak kuyruk düğümü baş düğümünü işaret ediyor
	kuyruk->sonraki = bas;

	while (1)
	{
		printf("Yapmak istediginiz islemi seciniz.\n");
		printf("-1- Rehbere kisi ekle.\n");
		printf("-2- Rehberden kisi sil.\n");
		printf("-3- Kisileri listele.\n");
		printf("-4- Isimle arama yap.\n");
		printf("-5- Soyisimle arama yap.\n");
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
			while (1)
			{
				printf("Silmek istediginiz kisinin rehberdeki sira numarasini giriniz.\n");
				scanf("%d", &sira);
				if (sira <= 0)
				{
					printf("Lutfen bir sayma sayisi girin.\n");
					continue;
				}
				dugum_sil(bas, sira);
				break;
			}
		}
		else if (girdi == 3) // Kişileri listeleme
		{
			butun_listeyi_yazdir(bas);
		}
		else if (girdi == 4) // isimle arama yap
		{
			char arananIsim[25];
			printf("Aramak istediginiz kisinin ismini giriniz:\n");
			scanf("%s", &arananIsim);
			isimle_ara(bas, arananIsim);
		}
		else if (girdi == 5) // soyisimle arama
		{
			char arananSoyisim[25];
			printf("Aramak istediginiz kisinin soyismini giriniz:\n");
			scanf("%s", &arananSoyisim);
			soyisimle_ara(bas, arananSoyisim);
		}
		else if (girdi == 6)
		{
			break;
		}
	}
	return 0;
}