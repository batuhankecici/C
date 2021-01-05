#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <dos.h>



struct ogrenci
{
	char adi[20];
	char soyadi[20];
	int numarasi;
	int dogumyili;
	char bolumu[25];
}ogrencinin;

struct ogrenci ogrenciler[100];

void OgrencilerAta()
{
	FILE *fp = fopen("ogrencikayit.txt","r");
	int sayac=0;
	if(fp==NULL)
	{
		printf("Dosya acilamadi");
	}
	
	while(!feof(fp))
	{
		
		fscanf(fp,"%s",&ogrenciler[sayac].adi);
		fscanf(fp,"%s",&ogrenciler[sayac].soyadi);
		fscanf(fp,"%d",&ogrenciler[sayac].numarasi);
		fscanf(fp,"%d",&ogrenciler[sayac].dogumyili);
		fscanf(fp,"%s",&ogrenciler[sayac].bolumu);
		sayac++;
	}
}

void YeniOgrenciKayit()
{
	int no,x,dogumyili;
	char bolum[30],ad[40],soyad[30];
	printf("1) Yeni ogrenci kayit");
	printf("\n\tOgrencinin adini giriniz:");
	scanf("%s",ad);
	printf("\n\tOgrencinin soyadini giriniz:");
	scanf("%s",soyad);
	printf("\n\tOgrencinin numarasini giriniz:");
	scanf("%d",&no);
	printf("\n\tOgrencinin dogum yilini giriniz:");
	scanf("%d",&dogumyili);
	printf("\n\tOgrencinin bolumunu giriniz:");
	scanf("%s",bolum);
	printf("\n\tOgrenci basariyla kayit edildi.");
	
	char dosya[100]="ogrencikayit.txt";
	FILE *fp = fopen("ogrencikayit.txt","a");
	fprintf(fp, "%s \t  ",ad);
	fprintf(fp, "%s \t ",soyad);
	fprintf(fp,"%d \t",no);
	fprintf(fp,"%d \t",dogumyili);
	fprintf(fp,"%s \t \n",bolum);
	fclose(fp);
	
	printf("\nAna menuye donmek icin bir sayi girin --->");
	scanf("%d",&x);
}
void MevcutOgrenciKayitGuncelleme()
{
	int no,x;
	printf("\n\t2) Mevcut ogrenci kayit guncelleme\n");
	printf("Guncellemek istediginiz ogrencinin numarasini giriniz:");
	scanf("%d",&no);
		for(int i=0;i<100;i++)
	{
		if(ogrenciler[i].numarasi==no)
		{
		printf("\nOgrenci Bilgileri: %s %s %d %d %s \n",ogrenciler[i].adi,ogrenciler[i].soyadi,ogrenciler[i].numarasi,ogrenciler[i].dogumyili,ogrenciler[i].bolumu);	
		}
		}
			FILE *fp = fopen("ogrencikayit.txt","w");
	for(int i=0;i<100;i++)
	{
		if(ogrenciler[i].numarasi!=no && strlen(ogrenciler[i].adi)!=0)
		{
			fprintf(fp,"%s %s %d %d %s\n",ogrenciler[i].adi,ogrenciler[i].soyadi,ogrenciler[i].numarasi,ogrenciler[i].dogumyili,ogrenciler[i].bolumu);
			
		}
	}
	fclose(fp);
		printf("Ogrencinin yeni bilgilerini giriniz:");
			int dogumyili;
	char bolum[30],ad[40],soyad[30];
	printf("\n\tOgrencinin adini giriniz:");
	scanf("%s",ad);
	printf("\n\tOgrencinin soyadini giriniz:");
	scanf("%s",soyad);
	printf("\n\tOgrencinin numarasini giriniz:");
	scanf("%d",&no);
	printf("\n\tOgrencinin dogum yilini giriniz:");
	scanf("%d",&dogumyili);
	printf("\n\tOgrencinin bolumunu giriniz:");
	scanf("%s",bolum);	
	char dosya[100]="ogrencikayit.txt";
	FILE *fp2 = fopen("ogrencikayit.txt","a");
	fprintf(fp, "%s \t  ",ad);
	fprintf(fp, "%s \t ",soyad);
	fprintf(fp,"%d \t",no);
	fprintf(fp,"%d \t",dogumyili);
	fprintf(fp,"%s \t \n",bolum);
	fclose(fp);
	printf("Ogrenci kayit yenileme islemi basariyla gerceklesti");
	printf("\nAna menuye donmek icin bir sayi girin --->");
	scanf("%d",&x);
}
void OgrenciSilme()
{
	int no,x;
	printf("\n\t3) Ogrenci silme\n");
	printf("Silmek istediginiz ogrencinin numarasini giriniz:\n");
	scanf("%d",&no);
	FILE *fp = fopen("ogrencikayit.txt","w");
	for(int i=0;i<100;i++)
	{
		if(ogrenciler[i].numarasi!=no && strlen(ogrenciler[i].adi)!=0)
		{
			fprintf(fp,"%s %s %d %d %s\n",ogrenciler[i].adi,ogrenciler[i].soyadi,ogrenciler[i].numarasi,ogrenciler[i].dogumyili,ogrenciler[i].bolumu);
			
		}
	}
	printf("Silme islemi basariyla gerceklesti.");
	printf("\nAna menuye donmek icin bir sayi girin --->");
	scanf("%d",&x);
	
}
void TumOgrencileriListeleme()
{	
			
	printf("\n\t4) Tum ogrencileri listeleme\n");
	int x;
	for(int i=0;i<100;i++)
	{
		if(ogrenciler[i].numarasi!=0){
				printf("\t\t%s %s %d %d %s \n",ogrenciler[i].adi,ogrenciler[i].soyadi,ogrenciler[i].numarasi,ogrenciler[i].dogumyili,ogrenciler[i].bolumu);
		}
	}
	printf("Ogrenci listeleme islemi basariyla gerceklesti");
	printf("\nAna menuye donmek icin bir sayi girin --->");
	scanf("%d",&x);	
}
void OgrenciDersSecimiYapma()
{
	int no,x;
	char derskodu[10];
	char dersadi[30];
	printf("\n\t1) Ogrenci ders secimi yapma");
	printf("\nDers secimi yapmak istediginiz ogrencinin numarasini giriniz:");
	scanf("%d",&no);
	for(int i=0;i<100;i++)
	{
		if(ogrenciler[i].numarasi==no)
		{
		printf("\nOgrenci Bilgileri: %s %s %d %d %s \n",ogrenciler[i].adi,ogrenciler[i].soyadi,ogrenciler[i].numarasi,ogrenciler[i].dogumyili,ogrenciler[i].bolumu);	
		}
		}
		printf("---------------------------------------\n");
		FILE *fp = fopen ("dersler.txt","r");
		if(fp==NULL)
		{
			printf("Dosya acilamadi");
		}
		while(!feof(fp))
		{
			char onceki[15];
			fscanf(fp,"%s %s",derskodu,dersadi);
			if(strcmp(onceki,derskodu)!=0){
				printf("%s %s \n",derskodu,dersadi);
				strcpy(onceki,derskodu);
			}
			
		}
		fclose(fp);
		printf("Secmek istediginiz dersin kodunu giriniz:");
		scanf("%s",derskodu);
		fp = fopen("derssecimleri.txt","a");
		if(fp==	NULL)
		{
			printf("Dosya acilamadi");
		}
		else
		{
			fprintf(fp,"%d ",no);
			fprintf(fp,"%s\n",derskodu);
		}
		fclose(fp);
		printf("Ogrenci ders secimi yapma islemi basariyla gerceklesti");
		printf("\nAna menuye donmek icin bir sayi girin --->");
		scanf("%d",&x);	
}

void OgrenciDersSecimiSilme()
{
	int no,x;
	char derskodu[10],derskodu2[20];
	printf("\n\t2) Ogrenci ders secimi silme");
	printf("\nDersini silmek istediginiz ogrencinin numarasini giriniz:");
	scanf("%d",&no);
	for(int i=0;i<100;i++)
	{
		if(ogrenciler[i].numarasi==no)
		{
		printf("\nOgrenci Bilgileri: %s %s %d %d %s \n",ogrenciler[i].adi,ogrenciler[i].soyadi,ogrenciler[i].numarasi,ogrenciler[i].dogumyili,ogrenciler[i].bolumu);	
		}
		}
		printf("---------------------------------------\n");
		FILE *fp = fopen ("derssecimleri.txt","r");
		if(fp==NULL)
		{
			printf("Dosya acilamadi");
		}
		while(!feof(fp))
		{
			char onceki[15],gecici[20];
			fscanf(fp,"%s",gecici);
			fscanf(fp,"%s",derskodu);
			if(strcmp(onceki,derskodu)!=0 && atoi(gecici)==no){
				printf("%s \n",derskodu);
				strcpy(onceki,derskodu);
			}	
		}
		fclose(fp);
		printf("--------------------------\n");
		printf("Silmek istediginiz dersin kodunu giriniz:");
		scanf("%s",derskodu2);
		
		FILE *fp2 = fopen("derssecimleri2.txt","w");
		fp= fopen ("derssecimleri.txt","r");
		while(!feof(fp))
		{
				char gecici[20];
			fscanf(fp,"%s",gecici);
			fscanf(fp,"%s",derskodu);
			if(strcmp(derskodu,derskodu2)==0 && atoi(gecici)==no){}
			else{
				fprintf(fp2,"%s %s\n",gecici,derskodu);
				
		}}
		fclose(fp);
		fclose(fp2);
		remove("derssecimleri.txt");
		rename("derssecimleri2.txt","derssecimleri.txt");
		printf("Ogrenci silme islemi basariyla gerceklesti.");
		printf("\nAna menuye donmek icin bir sayi girin --->");
		scanf("%d",&x);	
		
}
void OgrenciDersNotuGirisi()
{
	int no,x,dersnotu;
	char derskodu[20];
	char dersadi[30];
	printf("\n\t3) Ogrenci ders notu girisi");
	printf("\nDers secimi yapmak istediginiz ogrencinin numarasini giriniz:\n");
	scanf("%d",&no);

	for(int i=0;i<100;i++)
	{
		if(ogrenciler[i].numarasi==no)
		{
		printf("\nOgrenci Bilgileri: %s %s %d %d %s \n",ogrenciler[i].adi,ogrenciler[i].soyadi,ogrenciler[i].numarasi,ogrenciler[i].dogumyili,ogrenciler[i].bolumu);	
		}
		}
		printf("---------------------------------------\n");
				FILE *fp = fopen ("dersler.txt","r");
		if(fp==NULL)
		{
			printf("Dosya acilamadi");
		}
		while(!feof(fp))
		{
			char onceki[15];
			fscanf(fp,"%s %s",derskodu,dersadi);
			if(strcmp(onceki,derskodu)!=0){
				printf("%s %s \n",derskodu,dersadi);
				strcpy(onceki,derskodu);
			}
			
		}
		fclose(fp);
		printf("--------------------------");
		fclose(fp);
		printf("Notunu girmek istediginiz dersin kodunu giriniz:");
		scanf("%s",derskodu);
		printf("Ogrencinin notunu giriniz:");
		scanf("%d",&dersnotu);
		fp =fopen("notlar.txt","a");
		if(fp==NULL)
		{
			printf("Dosya acilamadi");
		}
		else {
			fprintf(fp,"%d ",no);
			fprintf(fp,"%s ",derskodu);
			fprintf(fp,"%d\n",dersnotu);
			printf("Ogrenci ders notu girisi basariyla gerceklesti");
		}
		fclose(fp);
			printf("\nAna menuye donmek icin bir sayi girin --->");
			scanf("%d",&x);	
}

void OgrenciDersNotuGoruntuleme()
{
	int no,x;
	char derskodu[10];
	int notu;
	printf("\n\t4) Ogrenci ders notu goruntuleme\n");
	printf("Notunu goruntulemek istediginiz ogrencinin numarasini giriniz:");
	scanf("%d",&no);
		for(int i=0;i<100;i++)
	{
		if(ogrenciler[i].numarasi==no)
		{
		printf("\nOgrenci Bilgileri: %s %s %d %d %s \n",ogrenciler[i].adi,ogrenciler[i].soyadi,ogrenciler[i].numarasi,ogrenciler[i].dogumyili,ogrenciler[i].bolumu);	
		}
		}
		printf("---------------------------------------\n");
	FILE *fp = fopen ("notlar.txt","r");
	if(fp==NULL)
	{
		printf("Dosya acilamadi");
	}
	while(!feof(fp))
	{
		fscanf(fp,"%d %s %d",&no,derskodu,&notu);
		
	}
	printf("%d %s %d",no,derskodu,notu);
	printf("\nAna menuye donmek icin bir sayi girin --->");
	scanf("%d",&x);	
}

void BirBolumdekiOgrencileriGoruntuleme()
{
	int no,dogumyili,x;
	char bolum[30];
	char ad[20];
	char soyad[20];
	printf("\n\t1) Bir bolumdeki ogrencileri listeleme\n");
	printf("Goruntulemek istediginiz ogrencilerin bolumunu yaziniz:");
	scanf("%s",bolum);
		for(int i=0;i<100;i++)
	{
		if(strcmp(ogrenciler[i].bolumu,bolum)==0)
		{
			
			printf("%s %s %d %d \n",ogrenciler[i].adi,ogrenciler[i].soyadi,ogrenciler[i].numarasi,ogrenciler[i].dogumyili);
		}
	}
		printf("\nAna menuye donmek icin bir sayi girin --->");
		scanf("%d",&x);	

}

void OgrenciDersListeleme()
{
	int no,x;
	char derskodu[20];
	printf("\n\t2) Ogrencinin aldigi dersleri listeleme\n");
	printf("Derslerini goruntulemek istediginiz ogrencinin numarasini giriniz:");
	scanf("%d",&no);
		for(int i=0;i<100;i++)
	{
		if(ogrenciler[i].numarasi==no)
		{
		printf("\nOgrenci Bilgileri: %s %s %d %d %s \n",ogrenciler[i].adi,ogrenciler[i].soyadi,ogrenciler[i].numarasi,ogrenciler[i].dogumyili,ogrenciler[i].bolumu);	
		}
		}
		printf("---------------------------------------\n");
	FILE *fp = fopen ("derssecimleri.txt","r");
	if(fp==NULL)
	{
		printf("Dosya acilamadi");
	}
	while(!feof(fp))
	{
		fscanf(fp,"%s",derskodu);
		
	}
	printf("%s",derskodu);
	printf("\nAna menuye donmek icin bir sayi girin --->");
	scanf("%d",&x);	
}
void OgrenciTranskriptGoruntuleme()
{
	int no,x,notu;
	char derskodu[10],gecici[10];
	printf("\n\t3) Ogrenci transkripti goruntuleme");
	printf("\nTranskriptini goruntulemek istediginiz ogrencinin numarasini giriniz:");
	scanf("%d",&no);
		for(int i=0;i<100;i++)
	{
		if(ogrenciler[i].numarasi==no)
		{
		printf("\nOgrenci Bilgileri: %s %s %d %d %s \n",ogrenciler[i].adi,ogrenciler[i].soyadi,ogrenciler[i].numarasi,ogrenciler[i].dogumyili,ogrenciler[i].bolumu);	
		}
		}
		printf("---------------------------------------\n");
		FILE *fp = fopen("notlar.txt","r");
		if(fp==NULL)
		{
			printf("Dosya acilamadi");
		}
		while(!feof(fp))
		{
			fscanf(fp,"%s %s %d",gecici,derskodu,&notu);
		}
		fclose(fp);
		printf("%s %d",derskodu,notu);
		printf("\nAna menuye donmek icin bir sayi girin --->");
		scanf("%d",&x);		
}

int MenuDegerSecme()
{
	int deger;
	printf("\nLutfen girmek istediginiz menunun degerini giriniz:");
	scanf("%d",&deger);
	return deger;
}

int MenuKontrol(int AnaMenu , int AltMenu)
{
	OgrencilerAta();
	system("cls");
	int SuankiDeger = AnaMenu*100 + AltMenu*10;
	switch(SuankiDeger)
	{
		case 0:
			
			printf("Ogrenci Otomasyonu Projesi");
			printf("\n1.Ogrenci");
			printf("\n2.Dersler");
 			printf("\n3.Raporlar");
 			break;
 			
 		case 100:
 			printf("Ogrenci Menusu");
 			printf("\n\t1) Yeni ogrenci kayit");
 			printf("\n\t2) Mevcut ogrenci kayit guncelleme");
 			printf("\n\t3) Ogrenci silme");
 			printf("\n\t4) Tum ogrencileri listeleme");
 			
 			break;
 			case 110:
 				YeniOgrenciKayit();
 				MenuKontrol(0,0);
 			
 				break;
 			case 120:
 				MevcutOgrenciKayitGuncelleme();
 				MenuKontrol(0,0);
 				break;
 			case 130:
 				OgrenciSilme();
 				MenuKontrol(0,0);
 				break;
 			case 140:
 				TumOgrencileriListeleme();
 				MenuKontrol(0,0);
 				
 				break;
 				
 			case 200:
 				printf("Dersler Menusu");
 				printf("\n\t1) Ogrenci ders secimi yapma");
 				printf("\n\t2) Ogrenci ders secimi silme");
		    	printf("\n\t3) Ogrenci ders notu girisi");
 				printf("\n\t4) Ogrenci ders notu goruntuleme");
 				break;
 			case 210:
 				OgrenciDersSecimiYapma();
 				MenuKontrol(0,0);
 				break;
 			case 220:
 				OgrenciDersSecimiSilme();
 				MenuKontrol(0,0);
 				break;
 			case 230:
 				OgrenciDersNotuGirisi();
 				MenuKontrol(0,0);
 				break;
 			case 240:
 				OgrenciDersNotuGoruntuleme();
 				MenuKontrol(0,0);
 				break;
 				case 300:
 				printf("Raporlar Menusu");
 				printf("\n\t1) Bir bolumdeki ogrencileri listeleme");
 				printf("\n\t2) Ogrencinin aldigi dersleri listeleme");
 				printf("\n\t3) Ogrenci transkripti goruntuleme");
 				break;
 				case 310:
 				BirBolumdekiOgrencileriGoruntuleme();
 				MenuKontrol(0,0);
 				break;
 				case 320:
 				OgrenciDersListeleme();
 				MenuKontrol(0,0);
 				break;
 				case 330:
 				OgrenciTranskriptGoruntuleme();
 				MenuKontrol(0,0);
 				break;
 				default:
 				printf("Lutfen menumuzde olan bir deger giriniz !");
 				break;
	}
	if(AltMenu ==0)
	{
		int secim = MenuDegerSecme();
		if (SuankiDeger == 0)
		AnaMenu = secim;
		if (SuankiDeger == 100 || SuankiDeger == 200 || SuankiDeger ==300)
		AltMenu = secim;
		MenuKontrol(AnaMenu,AltMenu);
	}
	
}

int main(void)
{
	MenuKontrol(0,0);	
	getch();
	return 0;
}
