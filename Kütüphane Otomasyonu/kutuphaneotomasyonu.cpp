#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <unistd.h>
#include <time.h>

void gotoxy(int x, int y)
{
COORD pos {0,0};
	pos.X=x;
	pos.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

struct kitaptarih
{
	int saat,dakika;
}kitaptarihi;

struct uyekitap
{

	int uyeno;
	char kitapkodu1[4];
	struct kitaptarih kk1verilenzaman;
	struct kitaptarih kk1alinacakzaman;
	char kitapkodu2[4];
	struct kitaptarih kk2verilenzaman;
	struct kitaptarih kk2alinacakzaman;
	char kitapkodu3[4];
	struct kitaptarih kk3verilenzaman;
	struct kitaptarih kk3alinacakzaman;
}uyeninkitaplari;

struct kitap
{
	char Adi[40];
	char Turu[25];
	char Kodu[6];	
}kitabin;

struct uye
{
	char adi[15];
	char soyadi[15];
	int dogumyili;
	int uyeno;
	char kullaniciadi[16];
	char sifre[15];
	char guvenliksorusu[50];
	char sorucevabi[20];
}uyenin;

struct uyekitap uyekitaplog[100]; 
struct kitap kitaplar[100];
struct uye uyeler[100];

void _password(char sifre[16])
{
	char ch;
	int x=33;
	for(int i=0;i<16;i++)    
	{
		ch=getch();
		if(ch==13)break;
		if(ch==8)
		{
			sifre[i-1]='\0';
			gotoxy(--x,9);
			printf(" ");
			i-=2;
		}
		else
		{
			sifre[i]=ch;
			gotoxy(x++,9);
			printf("*");
		}
	}
}
    void loaderanim()
{
int loader;
system("cls");
gotoxy(30,8);
printf("    YUKLENIYOR");
gotoxy(30,9);
printf("_________________");
gotoxy(30,10);
printf("|________________|");
gotoxy(25,12);
printf("Bu islem yaklasik 10 saniye surecek");


for(loader=30;loader<46;loader++)
{
sleep(1);
gotoxy(loader,10);
printf("\xB2\xB2");
}
}


void TumKitaplariGoruntule()
{
	gotoxy(13,5);
	printf("Kitap Kodu        Kitap Adi      Kitap Turu\n");
	printf("\t  ------------------------------------------------");
	printf("\n");
		for(int i=0;i<100;i++)
	{
		if(strlen(kitaplar[i].Kodu)!=0)
		{
			printf("\t        %s   \t         %s    \t%s\n",kitaplar[i].Kodu,kitaplar[i].Adi,kitaplar[i].Turu);
		}
	}
	printf("Ana menuye donmek icin bir tusa basin");
	getch();
}

void welcomemenu()
{
	
	printf("\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB");
	gotoxy(78,24);
	printf("%c",188);
	gotoxy(0,24);
	printf("%c",200);
	for(int i=1;i<24;i++)
	{
		gotoxy(0,i);
		printf("%c",186);
	}
	for(int i=1;i<24;i++) 
	{
		gotoxy(78,i);
		printf("%c",186);
	}
	gotoxy(1,24);
	printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
	    gotoxy(27,4); 
		printf("   KUTUPHANE PROGRAMI");
    gotoxy(25,5);
	 for(int i=0;i<27;i++) printf("%c",196);
    gotoxy(25,8);
	 printf("   Programi Tasarlayanlar:");
	 
    gotoxy(25,9);
	for(int i=0;i<27;i++)
	 printf("%c",196);
    gotoxy(33,11); 
	printf("Batuhan Kecici");
	 		 for(int i=19;i<62;i++)
			  {
			  	gotoxy(i,17);
			  	printf("%c",196);
			   } 
    gotoxy(17,16);
	 printf("   Programa giris yapmak icin bir tusa basin");
	 getch();
   
}



void UyeKitapAta()
{
	int sayac=0;
	FILE *fp = fopen ("uyekitaplog.txt","r");
	while(!feof(fp))
	{
		fscanf(fp,"%d",&uyekitaplog[sayac].uyeno);
		fscanf(fp,"%s",&uyekitaplog[sayac].kitapkodu1);
		fscanf(fp,"%s",&uyekitaplog[sayac].kitapkodu2);
		fscanf(fp,"%s",&uyekitaplog[sayac].kitapkodu3);
		sayac++;
	}
	
	fclose(fp);
} 



void KitaplarAta()
{
	FILE *fp = fopen("kitapkayit.txt","r");
	int sayac = 0;
	while(!feof(fp))
	{
		fscanf(fp,"%s",kitaplar[sayac].Adi);
		fscanf(fp,"%s",&kitaplar[sayac].Turu);
		fscanf(fp,"%s",&kitaplar[sayac].Kodu);
		sayac++;
	}	
	fclose(fp);
}
void UyelerAta()
{
	FILE *fp = fopen ("uyeler.txt","r");
	int sayac = 0 ;
	while(!feof(fp))
	{
		fscanf(fp,"%s",&uyeler[sayac].adi);
		fscanf(fp,"%s",&uyeler[sayac].soyadi);
		fscanf(fp,"%d",&uyeler[sayac].dogumyili);
		fscanf(fp,"%d",&uyeler[sayac].uyeno);
		fscanf(fp,"%s",&uyeler[sayac].kullaniciadi);
		fscanf(fp,"%s",&uyeler[sayac].sifre);
		fscanf(fp,"%s",&uyeler[sayac].guvenliksorusu);
		fscanf(fp,"%s",&uyeler[sayac].sorucevabi);
		sayac++;
	}
	fclose(fp);
}
void SistemKitapEkleme()
{
	char KitapAdi[40];
	char KitapTuru[25];
	char KitapKodu[4];
	gotoxy(13,3);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 KITAP EKLEME \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
	gotoxy(13,5);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Kitap Adi:");
	scanf("%s",KitapAdi);
	gotoxy(13,7);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Kitap Turu:");
	fflush(stdin);
	scanf("%s",KitapTuru);
	M:
	gotoxy(13,9);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Kitap Kodu:");
	scanf("%s",&KitapKodu);
	for(int i=0;i<100;i++)
	{
		if(strcmp(kitaplar[i].Kodu,KitapKodu)==0)
		{
			gotoxy(13,11);
			printf("Girdiginiz kitap kodu zaten sistemde bulunuyor!\n");
			gotoxy(13,12);
			printf("Lutfen farkli bir kitap kodu giriniz");
			getch();
			system("cls");
			goto M;
		}
	}
	gotoxy(13,11);
	printf(">> Kitap ekleme islemi basariyla gerceklesti.\n");
	FILE *fp = fopen("kitapkayit.txt","a");
	
	
	fprintf(fp,"%s ",KitapAdi);
	fprintf(fp,"%s ",KitapTuru);
	fprintf(fp,"%s\n",KitapKodu);
	fclose(fp);
	printf("Ana Menuye donmek icin bir tusa basin");
	getch();
}
void SistemKitapSilme()
{
	char KitapKodu[4];
    int count=0;
	gotoxy(13,3);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 KITAP SILME \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    gotoxy(13,6);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Kitap Kodu:");
	scanf("%s",&KitapKodu);
	for(int i=0;i<100;i++)
	{
		if(strcmp(kitaplar[i].Kodu,KitapKodu)==0)
		{
			count++;
				FILE *fp = fopen("kitapkayit.txt","w");
		for(int i=0;i<100;i++)
		{
			if(strcmp(KitapKodu,kitaplar[i].Kodu) && strlen(kitaplar[i].Adi)!=0)
			{
				fprintf(fp,"%s %s %s\n",kitaplar[i].Adi,kitaplar[i].Turu,kitaplar[i].Kodu);
			   		}
		
		}
		fclose(fp);
		gotoxy(13,8);
		printf(">> Kitap silme islemi basariyla gerceklesti.");
		printf("\nAna menuye donmek icin bir tusa basin");
   	 getch();
			}
		}
	
	if(count==0)
	{
		gotoxy(13,8);
		printf(">> Boyle bir kitap bulunamadi!");
		getch();
	}
}
void SistemKitapGuncelleme()
{
	int count=0;
	char KitapKodu[4];
	gotoxy(13,3);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 KITAP GUNCELLEME \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
	gotoxy(13,5);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Kitap Kodu:");
	scanf("%s",&KitapKodu);
	for(int i=0;i<100;i++)
	{
		if(strcmp(kitaplar[i].Kodu,KitapKodu)==0)
		{
			count++;
						FILE *fp = fopen("kitapkayit.txt","w");
	for(int i=0;i<100;i++)
	{
		if(strcmp(KitapKodu,kitaplar[i].Kodu) && strlen(kitaplar[i].Adi)!=0)
		{
			fprintf(fp,"%s %s %s\n",kitaplar[i].Adi,kitaplar[i].Turu,kitaplar[i].Kodu);
			
		}
	}
	fclose(fp);
	system("cls");
		printf("Kitabin yeni ozelliklerini giriniz:");
	char KitapAdi[40],KitapTuru[25];
	gotoxy(13,3);
		printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Kitap Adi:");
	fflush(stdin);
	scanf("%s",KitapAdi);
	gotoxy(13,6);
		printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Kitap Turu:");
	fflush(stdin);
	scanf("%s",KitapTuru);
	M:
		gotoxy(13,9);
		printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Kitap Kodu: ");
	scanf("%s",&KitapKodu);
	for(int i=0;i<100;i++)
	{
		if(strcmp(kitaplar[i].Kodu,KitapKodu)==0)
		{
			printf("Girdiginiz kitap kodu baska bir kitaba ait\n");
			printf("Lutfen baska bir kod giriniz!");
			getch();
			system("cls");
			goto M;
		}
	}
	FILE *fp2 = fopen("kitapkayit.txt","a");
	fprintf(fp,"%s ",KitapAdi);
	fprintf(fp,"%s ",KitapTuru);
	fprintf(fp,"%s\n",KitapKodu);
	fclose(fp2);
	gotoxy(13,11);
	printf(">> Kitap kayit yenileme islemi basariyla gerceklesti");
	printf("\nAna menuye donmek icin bir tusa basin.");
	getch();
		}
	}

	if(count==0)
	{
		gotoxy(13,7);
		printf(">> Boyle bir kitap bulunamadi!");
		getch();
	}
}
void UyeKitapEkleme()
{
	int count=0;
	int uyeno;
	char kitapkodu[4];
	char kitapadicek[20];
	char kitapturucek[15];
	char kitapkoducek[4];
	char onceki[20];
	gotoxy(13,3);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 UYE KITAP EKLEME \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
	gotoxy(13,5);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Uye No:");
	scanf("%d",&uyeno);
	gotoxy(13,6);
	printf("Kitap Kodu        Kitap Adi      Kitap Turu\n");
	printf("\t  ------------------------------------------------");
	printf("\n");
	for(int i=0;i<100;i++)
	{                       
		
		if(strlen(kitaplar[i].Kodu)!=0)
		{
			printf("\t        %s   \t         %s    \t%s\n",kitaplar[i].Kodu,kitaplar[i].Adi,kitaplar[i].Turu);
		
		}
	}
	
	K:
	printf("\n\t     \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Kitap Kodu:");
	scanf("%s",kitapkodu);
		for(int i=0;i<100;i++)
	{
		if(strcmp(kitaplar[i].Kodu,kitapkodu)==0)count++;
	}
	if(count==0)
	{
		
		printf("Girdiginiz kitap kodu bulunamadi.");
		getch();
		system("cls");
		goto K;
	}
	 time_t t;
     struct tm *saat;
 	 time (&t);
 	 saat = gmtime(&t);
	for(int i=0;i<100;i++)
	{
		if(uyeler[i].uyeno==uyeno)
		{
		
		  	
			if(strlen(uyekitaplog[i].kitapkodu1)==0)
			{	 	
			 uyekitaplog[i].uyeno = uyeno;
			 strcpy(uyekitaplog[i].kitapkodu1,kitapkodu);
			 uyekitaplog[i].kk1verilenzaman.saat = saat->tm_hour + 3;
			 uyekitaplog[i].kk1verilenzaman.dakika = saat->tm_min;	 
			 uyekitaplog[i].kk1alinacakzaman.saat = saat->tm_hour;
			 uyekitaplog[i].kk1alinacakzaman.dakika = saat->tm_min + 3;
			 printf(">> Kitap ekleme islemi basariyla gerceklesti");
			}
			else if(strlen(uyekitaplog[i].kitapkodu2)==0)
			{
			strcpy(uyekitaplog[i].kitapkodu2,kitapkodu);
			 uyekitaplog[i].kk2verilenzaman.saat = saat->tm_hour + 3;
			 uyekitaplog[i].kk2verilenzaman.dakika = saat->tm_min;	 
			 uyekitaplog[i].kk2alinacakzaman.saat = saat->tm_hour;
			 uyekitaplog[i].kk2alinacakzaman.dakika = saat->tm_min + 3;
			printf(">> Kitap ekleme islemi basariyla gerceklesti");
			}
			else if(strlen(uyekitaplog[i].kitapkodu3)==0)
			{
		   	 strcpy(uyekitaplog[i].kitapkodu3,kitapkodu);
			 uyekitaplog[i].kk3verilenzaman.saat = saat->tm_hour + 3;
			 uyekitaplog[i].kk3verilenzaman.dakika = saat->tm_min;	 
			 uyekitaplog[i].kk3alinacakzaman.saat = saat->tm_hour;
			 uyekitaplog[i].kk3alinacakzaman.dakika = saat->tm_min + 3;
		   	 printf(">> Kitap ekleme islemi basariyla gerceklesti");
			}
			else
			{	
				printf("Uye 3 kitaba sahip!");
			}
		}
	}
	
	FILE *fp5 = fopen ("uyekitaplog.txt","w");
	for(int i=0;i<100;i++)
	{
		if(uyekitaplog[i].uyeno!=0)
		fprintf(fp5,"%d %s %s %s\n",uyekitaplog[i].uyeno,uyekitaplog[i].kitapkodu1,uyekitaplog[i].kitapkodu2,uyekitaplog[i].kitapkodu3);
	}
	fclose(fp5);
	getch();
}

void UyeKitapSilme()
{
	char kitapkodu[4];
	int uyeno;
	int islem;
	int count=0;
	Z:
	gotoxy(13,3);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 UYE KITAP SILME \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
	gotoxy(13,5);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Uye No:");
	scanf("%d",&uyeno);

		for(int i=0;i<100;i++)
	{
		if(uyekitaplog[i].uyeno==uyeno)
		{
		gotoxy(13,6);
		printf("Uye No        Kitap1        Kitap2      Kitap3\n");
		printf("\t  ------------------------------------------------");
		printf("\n");
		printf("              %d             %s            %s       %s\n",uyekitaplog[i].uyeno,uyekitaplog[i].kitapkodu1,uyekitaplog[i].kitapkodu2,uyekitaplog[i].kitapkodu3);
		count++;
		printf("\n\t     \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 1-Kitapkodu\n");
		printf("\n\t     \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 2-Kitapkodu\n");
		printf("\n\t     \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 3-Kitapkodu\n");
		printf("\n\t     >> Silmek istediginiz kitapkodunun numarasini giriniz:");
		scanf("%d",&islem);
		}
	}
		if(count==0)
		{
				gotoxy(13,8);
				printf("Girdiginiz uyenin kitabi bulunmuyor lutfen yeni bir uye no giriniz!");
				getch();
				system("cls");
				goto Z;
		}
		
		switch(islem)
	{
		case 1:
			for(int i=0;i<100;i++)
			{
				if(uyekitaplog[i].uyeno==uyeno)
				strcpy(uyekitaplog[i].kitapkodu1,"");
			}
		break;
		
		case 2:
						for(int i=0;i<100;i++)
			{
				if(uyekitaplog[i].uyeno==uyeno)
				strcpy(uyekitaplog[i].kitapkodu2,"");
			}
		break;
			
		case 3:
						for(int i=0;i<100;i++)
			{
				if(uyekitaplog[i].uyeno==uyeno)
				strcpy(uyekitaplog[i].kitapkodu3,"");
			}
		break;
		
		default:
		printf(">> Lutfen 1,2,3 degerlerinden birini giriniz!");
	}
	FILE *fp = fopen("uyekitaplog.txt","w");
	for(int i=0;i<100;i++)
	{
		if(uyekitaplog[i].uyeno!=0)
		{
			fprintf(fp,"%d %s %s %s\n",uyekitaplog[i].uyeno,uyekitaplog[i].kitapkodu1,uyekitaplog[i].kitapkodu2,uyekitaplog[i].kitapkodu3);
		}
	}
	fclose(fp);
	printf("\n\t     >> Uye Silme islemi basariyla gerceklesti");
	UyeKitapAta();
	getch();
}
void UyeKitapGuncelleme()
{
	int count=0;
	char kitapkodu[4];
	char yenikitapkodu[4];
	char kitapadicek[20];
	char kitapturucek[15];
	char kitapkoducek[4];
	char onceki[20];
	int uyeno;
	int islem;
	Z:
	gotoxy(13,3);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 UYE KITAP GUNCELLEME \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
	gotoxy(13,5);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Uye No:");
	scanf("%d",&uyeno);	
	for(int i=0;i<100;i++)
	{
			if(uyekitaplog[i].uyeno==uyeno)
		{
		gotoxy(13,6);
		printf("Uye No        Kitap1        Kitap2      Kitap3\n");
		printf("\t  ------------------------------------------------");
		printf("\n");
		printf("              %d             %s            %s       %s\n",uyekitaplog[i].uyeno,uyekitaplog[i].kitapkodu1,uyekitaplog[i].kitapkodu2,uyekitaplog[i].kitapkodu3);
		count++;
		printf("\n\t     \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 1-Kitapkodu\n");
		printf("\n\t     \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 2-Kitapkodu\n");
		printf("\n\t     \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 3-Kitapkodu\n");
		printf("\n\t     >> Guncellemek istediginiz kitapkodunun numarasini giriniz:");
		scanf("%d",&islem);
		}
	}
	if(count==0)
	{
			gotoxy(13,8);
			printf("Girdiginiz uyenin kitabi bulunmuyor lutfen yeni bir uye no giriniz!");
			getch();
			system("cls");
			goto Z;
	}
	printf("             Kitap Kodu        Kitap Adi      Kitap Turu\n");
	printf("\t  ------------------------------------------------");
	printf("\n");
	for(int i=0;i<100;i++)
	{
		if(strlen(kitaplar[i].Kodu)!=0)
		{
			printf("\t        %s   \t         %s    \t%s\n",kitaplar[i].Kodu,kitaplar[i].Adi,kitaplar[i].Turu);
		}
	}
	K:
	printf("\n\t     \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Yeni Kitapkodu:");
	scanf("%s",yenikitapkodu);
	count =0;
	for(int i=0;i<100;i++)
	{
		if(strcmp(kitaplar[i].Kodu,yenikitapkodu)==0)count++;
	}
	if(count==0)
	{
		printf(">> Girdiginiz kitap kodu bulunamadi!");
		getch();
		goto K;
	}
 	switch(islem)
 	{
 		case 1:
 			for(int i=0;i<100;i++)
			{
				if(uyekitaplog[i].uyeno==uyeno)
				strcpy(uyekitaplog[i].kitapkodu1,yenikitapkodu);
			}
			break;
 			
 		case 2:
 						for(int i=0;i<100;i++)
		{
			if(uyekitaplog[i].uyeno==uyeno)
			strcpy(uyekitaplog[i].kitapkodu2,yenikitapkodu);
		}
				break;
 			
 		case 3:	
 			for(int i=0;i<100;i++)
			{
				if(uyekitaplog[i].uyeno==uyeno)
				strcpy(uyekitaplog[i].kitapkodu3,yenikitapkodu);
			}
			break;
 	}
 	FILE *fp = fopen("uyekitaplog.txt","w");
	for(int i=0;i<100;i++)
	{
		if(uyekitaplog[i].uyeno!=0)
		{
			fprintf(fp,"%d %s %s %s\n",uyekitaplog[i].uyeno,uyekitaplog[i].kitapkodu1,uyekitaplog[i].kitapkodu2,uyekitaplog[i].kitapkodu3);
		}
	}
	fclose(fp);
	UyeKitapAta();
 	printf(">> Kitap guncelleme islemi basariyla gerceklesti");
 	getch();
	 	
	
}
void UyeEkleme()
{
	char ad[15];
	char soyad[15];
	int dogumyili;
	int uyeno;
	char kullaniciadi[16];
	char sifre[15];
	char guvenliksorusu[50];
	char sorucevabi[20];
	
	gotoxy(13,3);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 UYE EKLEME \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
	gotoxy(13,5);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Ad:");
	scanf("%s",&ad);
	gotoxy(13,7);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Soyad:");
	scanf("%s",&soyad);
	gotoxy(13,9);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Dogum Yili:");
	scanf("%d",&dogumyili);
	M:
	gotoxy(13,11);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Uye Numarasi:");
	scanf("%d",&uyeno);
	
	for(int i=0;i<100;i++)
	{
		if(uyeler[i].uyeno==uyeno)
		{
			gotoxy(13,13);
			printf(">> Girdiginiz uye numarasi baska bir uyeye ait\n");
			gotoxy(13,14);
			printf(">> Lutfen baska bir uye numarasi veriniz!\n");
			goto M;
		}
	}
	
	gotoxy(13,13);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Kullanici adi:");
	scanf("%s",&kullaniciadi);
	gotoxy(13,15);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Sifre:");
	scanf("%s",&sifre);
	gotoxy(13,17);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Guvenlik Sorusu:");
	fflush(stdin);
	scanf("%s",guvenliksorusu);
	gotoxy(13,19);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Soru Cevabi:");
	fflush(stdin);
	scanf("%s",sorucevabi);
	gotoxy(13,20);
	printf(">> Uye ekleme islemi basariyla gerceklesti.\n");
	FILE *fp = fopen("uyeler.txt","a");
	
	fprintf(fp,"%s ",ad);
	fprintf(fp,"%s ",soyad);
	fprintf(fp,"%d ",dogumyili);
	fprintf(fp,"%d ",uyeno);
	fprintf(fp,"%s ",kullaniciadi);
	fprintf(fp,"%s ",sifre);
	fprintf(fp,"%s ",guvenliksorusu);
	fprintf(fp,"%s\n",sorucevabi);
	fclose(fp);
	printf("Ana menuye donmek icin bir tusa basin.");
	getch();
}
void UyeSilme()
{
	int uyeno;
	int count=0;
	gotoxy(13,3);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 UYE SILME \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
	gotoxy(13,6);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Uye No:");
	scanf("%d",&uyeno);
		for(int i=0;i<100;i++)
	{
		if(uyeler[i].uyeno==uyeno)
		{
			count++;
		FILE *fp = fopen ("uyeler.txt","w");
		for(int i=0;i<100;i++)
		{
			if(uyeler[i].uyeno!=uyeno && strlen(uyeler[i].adi)!=0)
			{
				fprintf(fp,"%s %s %d %d %s %s %s %s\n",uyeler[i].adi,uyeler[i].soyadi,uyeler[i].dogumyili,uyeler[i].uyeno,uyeler[i].kullaniciadi,uyeler[i].sifre,uyeler[i].guvenliksorusu,uyeler[i].sorucevabi);
			}
		}
		fclose(fp);
		gotoxy(13,9);
		printf(">> Uye silme islemi basariyla gerceklesti.");
		gotoxy(13,12);
		printf("Ana menuye donmek icin bir tusa basin.");
		getch();
		}
	}
	if(count==0)
	{
		gotoxy(13,9);
		printf(">> Boyle bir ogrenci bulunamadi!");
		gotoxy(13,12);
		printf("Ana Menuye donmek icin bir tusa basin");
		getch();
	}

}

void UyeBilgileriniGuncelleme()
{
	int count=0;
	int uyeno;
	char ad[15];
	char soyad[15];
	int dogumyili;
	char kullaniciadi[16];
	char sifre[15];
	char guvenliksorusu[50];
	char sorucevabi[20];
	gotoxy(13,3);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 UYE GUNCELLEME \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
	gotoxy(13,6);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Uye No:");
	scanf("%d",&uyeno);
	for(int i=0;i<100;i++)
	{
		if(uyeler[i].uyeno==uyeno)
		{
			count++;
				FILE *fp = fopen ("uyeler.txt","w");
		for(int i=0;i<100;i++)
		{
			if(uyeler[i].uyeno!=uyeno && strlen(uyeler[i].adi)!=0)
			{
				fprintf(fp,"%s %s %d %d %s %s %s %s\n",uyeler[i].adi,uyeler[i].soyadi,uyeler[i].dogumyili,uyeler[i].uyeno,uyeler[i].kullaniciadi,uyeler[i].sifre,uyeler[i].guvenliksorusu,uyeler[i].sorucevabi);
			}
		}
		fclose(fp);
		system("cls");
		printf("Uyenin yeni bilgilerini giriniz:");
		gotoxy(13,2);
		printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Ad:");
		scanf("%s",&ad);
		gotoxy(13,4);
		printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Soyad:");
		scanf("%s",&soyad);
		gotoxy(13,6);
		printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Dogum Yili:");
		scanf("%d",&dogumyili);
		M:
			gotoxy(13,8);
		printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Uye No:");
		scanf("%d",&uyeno);
		for(int i=0;i<100;i++)
		{
			if(uyeler[i].uyeno==uyeno)
			{
				gotoxy(13,10);
				printf(">> Girdiginiz numara baska bir uyeye ait\n");
				gotoxy(13,11);
				printf(">> Farkli bir numara giriniz");
				getch();
				goto M;
			}
		}
		gotoxy(13,10);
		printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Kullanici adi:");
		scanf("%s",&kullaniciadi);
		gotoxy(13,12);
		printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Sifre:");
		scanf("%s",&sifre);
		gotoxy(13,14);
		printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Guvenlik Sorusu:");
		fflush(stdin);
		scanf("%s",guvenliksorusu);
		gotoxy(13,16);
		printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Soru Cevabi:");
		fflush(stdin);
		scanf("%s",sorucevabi);
		gotoxy(13,17);
		printf(">> Uye ekleme islemi basariyla gerceklesti.\n");
		FILE *fp2 = fopen("uyeler.txt","a");
	
		fprintf(fp,"%s ",ad);
		fprintf(fp,"%s ",soyad);
		fprintf(fp,"%d ",dogumyili);
		fprintf(fp,"%d ",uyeno);
		fprintf(fp,"%s ",kullaniciadi);
		fprintf(fp,"%s ",sifre);
		fprintf(fp,"%s ",guvenliksorusu);
		fprintf(fp,"%s\n",sorucevabi);
		fclose(fp2);
		printf("Ana menuye donmek icin bir tusa basin.");
		getch();
			}
		}
	if(count==0)
	{
		gotoxy(13,8);
		printf(">> Boyle bir ogrenci bulunamadi\n");
		gotoxy(13,9);
		printf(">> Lutfen dogru bir ogrenci numarasi giriniz\n");
		printf("Ana menuye donmek icin bir tusa basin");
		getch();
	}
	
}
void HarftenKitapBulma()
{
	char aranan[10];
	int count;
	gotoxy(13,3);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 KITAP FILTRELEME \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
	gotoxy(13,6);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Aranan:");
	scanf("%s",&aranan);
	gotoxy(13,8);
	printf("Kitap Kodu        Kitap Adi      Kitap Turu\n");
	printf("\t  ------------------------------------------------");
	printf("\n");
	int boyut = strlen(aranan);
	for(int i=0;i<100;i++)
	{
		count=0;
		for(int j=0;j<boyut;j++)
		{
			if(kitaplar[i].Adi[j]==aranan[j])
			count++;
			if(count==boyut)
			printf("\t        %s   \t         %s    \t%s\n",kitaplar[i].Kodu,kitaplar[i].Adi,kitaplar[i].Turu);
		}
		printf("\n");
	}
		printf("Ana menuye donmek icin bir tusa basin");
		getch();
}
void TurdenKitapBulma()
{
	char kitapturu[15];
	int count=0;
	gotoxy(13,3);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 GIRIS MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
	gotoxy(13,6);
	printf("Aradiginiz kitabin turunu giriniz:");
	scanf("%s",&kitapturu);
	system("cls");
	gotoxy(13,3);
	printf("Aradiginiz kitaplar:\n");
	gotoxy(13,5);
	printf("Kitap Kodu        Kitap Adi      Kitap Turu\n");
	printf("\t  ------------------------------------------------");
	printf("\n");
	
	for(int i=0;i<100;i++)
	{                       
		
		if(strcmp(kitapturu,kitaplar[i].Turu)==0)
		{
			printf("\t        %s   \t         %s    \t%s\n",kitaplar[i].Kodu,kitaplar[i].Adi,kitaplar[i].Turu);
			count++;
		}
	
	}
	if(count==0)
	{
		system("cls");
		gotoxy(13,3);
		printf("Aradiginiz kitaplar:\n");
		gotoxy(13,5);
		printf(">> Aradiginiz turde bir kitap bulunamadi\n");
	}
	else
	{
		printf(">> %d tane kitap bulundu\n",count);
	}
	printf("Ana menuye donmek icin bir tusa basin");
	getch();
}
void KitapKontrol()
{
	 int zamankarsilastir;
 	 time_t t;
 	 struct tm *saat;
 	 time (&t);
 	 saat = gmtime(&t);
 	 zamankarsilastir = saat->tm_min;
 	gotoxy(13,3);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 KITAP KONTROL \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
 	printf("                        Uye No       Kitap Kodu\n");
	printf("\t          ----------------------------------");
	printf("\n");
 	 for(int i=0;i<100;i++)
 	 {
 	 	if(zamankarsilastir>=uyekitaplog[i].kk1alinacakzaman.dakika && uyekitaplog[i].uyeno!=0 && strlen(uyekitaplog[i].kitapkodu1)!=0)
 	 	{
 	 		printf("                           %d            %s\n",uyekitaplog[i].uyeno,uyekitaplog[i].kitapkodu1);
		}
 	 	
 	 	if(zamankarsilastir>=uyekitaplog[i].kk2alinacakzaman.dakika && uyekitaplog[i].uyeno!=0 && strlen(uyekitaplog[i].kitapkodu2)!=0)
 	 	{
 	 		printf("                           %d            %s\n",uyekitaplog[i].uyeno,uyekitaplog[i].kitapkodu2);;
	    }
 	 	
 	 	if(zamankarsilastir>=uyekitaplog[i].kk3alinacakzaman.dakika && uyekitaplog[i].uyeno!=0 && strlen(uyekitaplog[i].kitapkodu3)!=0)
 	 	{
 	 		printf("                           %d            %s\n",uyekitaplog[i].uyeno,uyekitaplog[i].kitapkodu3);
		  }
 	 	
	  }
 	 getch();
}
void UyelikSilme()
{
	char KullaniciAdi[20];
	char sifre[20];
	char cevap[20];
	int control = 0;
	gotoxy(13,3);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 UYELIK SILME \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
	printf("Uyeliginizi silmek icin lutfen bilgilerinizi giriniz:\n");
	gotoxy(13,6);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Kullanici Adi:");
	scanf("%s",&KullaniciAdi);
	gotoxy(13,9);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Sifre:");
	scanf("%s",sifre);
	for(int i=0;i<100;i++)
	{
		if(strcmp(KullaniciAdi,uyeler[i].kullaniciadi)==0 && strcmp(sifre,uyeler[i].sifre)==0)
		{
			gotoxy(13,11);
			printf("%s %s lutfen guvenlik sorunuzu cevaplayiniz",uyeler[i].adi,uyeler[i].soyadi);
			gotoxy(13,12);
			printf("Soru: ");
			
			printf("%s",uyeler[i].guvenliksorusu);
			control++;
		}
	}
	if(control==0)
	{
		gotoxy(13,11);
		printf(">> Kullanici adi ve sifre eslesmedi silme islemi basarisiz!");
		
	}
	else
	{
	gotoxy(13,13);
	printf("Cevap: ");
	scanf("%s",&cevap);
	for(int i=0;i<100;i++)
	{
		if(cevap==uyeler[i].sorucevabi)
		{
			gotoxy(13,14);
		printf(">> Cevabiniz eslesti");
		}
	}
	FILE *fp2 = fopen ("uyeler.txt","w");
	for(int i=0;i<100;i++)
	{
		if(strcmp(KullaniciAdi,uyeler[i].kullaniciadi)!=0 && strcmp(uyeler[i].sifre,sifre)!=0 && strcmp(uyeler[i].sorucevabi,cevap)!=0 && strlen(uyeler[i].adi)!=0)
		{
			fprintf(fp2,"%s %s %d %d %s %s %s %s\n",uyeler[i].adi,uyeler[i].soyadi,uyeler[i].dogumyili,uyeler[i].uyeno,uyeler[i].kullaniciadi,uyeler[i].sifre,uyeler[i].guvenliksorusu,uyeler[i].sorucevabi);
		}
	}
	fclose(fp2);
	gotoxy(13,15);
	printf(">> Silme islemi basariyla gerceklesti\n");
	}

	
	printf("Ana menuye donmek icin bir tusa basin");
	getch();

}
void SifreGuncelleme()
{
	char kullaniciadi[20];
	char eskisifre[20];
	char yenisifre[20];
	gotoxy(13,3);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 GIRIS MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
	gotoxy(13,6);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Kullanici Adi:");
	scanf("%s",&kullaniciadi);
	gotoxy(13,9);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Eski Sifre:");
	scanf("%s",&eskisifre);
	gotoxy(13,12);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Yeni Sifre:");
	scanf("%s",&yenisifre);
	FILE *fp = fopen ("uyeler2.txt","a");
	for(int i=0;i<100;i++)
	{
	if(strcmp(kullaniciadi,uyeler[i].kullaniciadi)!=0 && strcmp(eskisifre,uyeler[i].sifre)!=0 && strlen(uyeler[i].adi)!=0)
	{
	fprintf(fp,"%s %s %d %d %s %s %s %s\n",uyeler[i].adi,uyeler[i].soyadi,uyeler[i].dogumyili,uyeler[i].uyeno,uyeler[i].kullaniciadi,uyeler[i].sifre,uyeler[i].guvenliksorusu,uyeler[i].sorucevabi);
	}
	}

	fclose(fp);
	FILE *fp2 = fopen ("uyeler2.txt","a");
	for(int i=0;i<100;i++)
	{
			if(strcmp(kullaniciadi,uyeler[i].kullaniciadi)==0 && strcmp(eskisifre,uyeler[i].sifre)==0 && strlen(uyeler[i].adi)!=0)
			{
				fprintf(fp2,"%s %s %d %d %s %s %s %s\n",uyeler[i].adi,uyeler[i].soyadi,uyeler[i].dogumyili,uyeler[i].uyeno,kullaniciadi,yenisifre,uyeler[i].guvenliksorusu,uyeler[i].sorucevabi);
			}
	
	}
	fclose(fp2);
	remove("uyeler.txt");
	rename("uyeler2.txt","uyeler.txt");
	gotoxy(13,14);
	printf("Sifre guncelleme islemi basariyla gerceklesti");
	printf("\nAna menuye donmek icin bir tusa basin");
	getch();
}
void UyeGiris()
{
	char kullaniciadi[20];
	char sifre[20];
	int count=0;
	z:
	system("cls");
	gotoxy(13,3);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 UYE GIRIS \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
	gotoxy(13,6);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Kullanici adi:");
	scanf("%s",&kullaniciadi);
	gotoxy(13,9);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Sifre:");
	_password(sifre);
	for (int i=0;i<100;i++)
	{
		if(strcmp(kullaniciadi,uyeler[i].kullaniciadi)==0 && strcmp(sifre,uyeler[i].sifre)==0)
		{
			gotoxy(13,11);
		printf(">> Hosgeldiniz.Giris Basarili.\n");
		count++;
		gotoxy(13,13);
		printf(">> Devam etmek icin bir tusa basin.");
		getch();
		}
	}
	if(count==0)
	{
		gotoxy(13,11);
		printf(">>Kullanici adi ve sifreniz yanlis lutfen tekrar giriniz!\n");
		gotoxy(13,13);
		printf(">> Yeniden bilgilerinizi girmek icin bir tusa basin");
		getch();
		goto z;
	}

}

void YoneticiGiris()
{
	char kullaniciadi[5];
	char sifre[6];
	m:
	system("cls");
	gotoxy(13,3);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 YETKILI GIRIS \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
	gotoxy(13,6);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Kullanici adi:");
	scanf("%s",&kullaniciadi);
	gotoxy(13,9);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Sifre:");
	_password(sifre);
	if(strcmp(kullaniciadi,"admin")==0 && strcmp(sifre,"123456")==0)
	{
			printf("\n\n\n\n\t\t\t\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
            printf("\t\t\t\xBA Hosgeldiniz.Giris Basarili.       \xBA\n");
            printf("\t\t\t\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
            printf("\n\t\t\t\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
            printf("\t\t\t\xBA  Devam etmek icin bir tusa basin  \xBA\n");
            printf("\t\t\t\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
            getch();
		
	}
	
	else
	{
		gotoxy(13,12);
		printf(">> Kullanici adi ve sifreniz yanlis lutfen tekrar giriniz!");
		getch();
		goto m;
		
	}
}

int MenuDegerSecme()
{
	int deger;
	printf("\n\n>> Lutfen menuden bir deger giriniz:");
	scanf("%d",&deger);
	return deger;
}

int MenuKontrol(int GirisPanel,int AnaMenu, int GirisMenu, int AltMenu)
{
	UyelerAta();
	KitaplarAta();
	UyeKitapAta();
	int SuankiDeger = GirisPanel*1000 + AnaMenu*100 + GirisMenu*10 + AltMenu*1;
	switch(SuankiDeger)
	{
		case 0:
			system("cls");
			gotoxy(13,3);
			printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 GIRIS MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
			gotoxy(13,6);
			printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 1-Yonetici Girisi");
			gotoxy(13,9);
			printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 2-Uye Girisi");
			break;
		case 1000:
			YoneticiGiris();
			getch();
			MenuKontrol(1,1,0,0);
		case 1100:
			
			system("cls");
			gotoxy(13,3);
			printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 YONETICI MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
			gotoxy(13,6);
			printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 1-Kitap Islemleri");
			gotoxy(13,9);
			printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 2-Uye Islemleri");
			gotoxy(13,12);
			printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 3-Raporlama");
			gotoxy(13,15);
			printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 4-Hesaptan Cikis Yap");
			break;
			
			case 1110:
				system("cls");
				gotoxy(13,3);
				printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 KITAP ISLEMLERI \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
				gotoxy(13,6);
				printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 1-Sisteme Kitap Ekleme");
				gotoxy(13,9);
				printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 2-Sistemden Kitap Silme");
				gotoxy(13,12);
				printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 3-Sistemden Kitap Guncelleme");
				gotoxy(13,15);
				printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 4-Geri Dön");
				break;
				
				case 1111:
					system("cls");
					SistemKitapEkleme();
					MenuKontrol(1,1,0,0);
					break;
					
				case 1112:
					system("cls");
					SistemKitapSilme();
					MenuKontrol(1,1,0,0);
					break;
					
				case 1113:
					system("cls");
					SistemKitapGuncelleme();
					MenuKontrol(1,1,0,0);
					break;
				case 1114:
					MenuKontrol(1,1,0,0);
					break;	
				
			case 1120:
				system("cls");
				gotoxy(13,3);
				printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 UYE ISLEMLERI \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
				gotoxy(13,5);
				printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 1-Uye Kitap Ekleme");
				gotoxy(13,7);
				printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 2-Uye Kitap Silme");
				gotoxy(13,9);
				printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 3-Uye Kitap Guncelleme");
				gotoxy(13,11);
				printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 4-Uye Ekleme");
				gotoxy(13,13);
				printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 5-Uye Silme");
				gotoxy(13,15);
				printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 6-Uye Bilgilerini Guncelleme");
				gotoxy(13,17);
				printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 7-Geri Dön");
				break;
				
				case 1121:
					system("cls");
					UyeKitapEkleme();
					MenuKontrol(1,1,0,0);
					break;
					
				case 1122:
					system("cls");
					UyeKitapSilme();
					MenuKontrol(1,1,0,0);
					break;
					
				case 1123:
					system("cls");
					UyeKitapGuncelleme();
					MenuKontrol(1,1,0,0);
					break;
					
				case 1124:
					system("cls");
					UyeEkleme();		
					MenuKontrol(1,1,0,0);	
					break;			
			
				case 1125:
					system("cls");
					UyeSilme();
					MenuKontrol(1,1,0,0);
					break;
					
				case 1126:
					system("cls");
					UyeBilgileriniGuncelleme();
					MenuKontrol(1,1,0,0);
					break;
				
				case 1127:
					MenuKontrol(1,1,0,0);
					break;	
				
			case 1130:
				system("cls");
				gotoxy(13,3);
				printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 RAPORLAMA \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
				gotoxy(13,6);
				printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 1-Harften Kitap Bulma");
				gotoxy(13,9);
				printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 2-Turden Kitap Bulma");
				gotoxy(13,12);
				printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 3-Kitap Kontrol");
				gotoxy(13,15);
				printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 4-Geri Dön");
				break;
				
				case 1131:
					system("cls");
					HarftenKitapBulma();
					MenuKontrol(1,1,0,0);
					break;
				
				case 1132:
					system("cls");
					TurdenKitapBulma();
					MenuKontrol(1,1,0,0);
					break;
					
				case 1133:
					system("cls");
					KitapKontrol();
					MenuKontrol(1,1,0,0);
					break;
			
				case 1134:
					MenuKontrol(1,1,0,0);
					break;
			
			case 1140:
				printf("Hesabinizdan cikmak icin enter'a basin");
				getch();
				MenuKontrol(0,0,0,0);
				break;
			case 2000:
				UyeGiris();
				MenuKontrol(2,2,0,0);
		case 2200: 
			
			system("cls");
			gotoxy(13,3);
			printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 UYE MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
			gotoxy(13,6);
			printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 1-Raporlama");
			gotoxy(13,9);
			printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 2-Ayarlar");
			gotoxy(13,12);
			printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 3-Hesaptan Cikis Yap");
			break;
			
			case 2210:
				system("cls");
				gotoxy(13,3);
				printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 RAPORLAMA \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
				gotoxy(13,6);
				printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 1-Harften Kitap Bulma");
				gotoxy(13,9);
				printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 2-Turden Kitap Bulma");
				gotoxy(13,12);
				printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 3-Tum Kitaplari Listele");
				gotoxy(13,15);
				printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 4-Geri Dön");
				break;
				
				case 2211:
					system("cls");
					HarftenKitapBulma();
					MenuKontrol(2,2,0,0);
					break;
					
				case 2212:
					system("cls");
					TurdenKitapBulma();
					MenuKontrol(2,2,0,0);
					break;
					
				case 2213:
					system("cls");
					TumKitaplariGoruntule();
					MenuKontrol(2,2,0,0);
					break;	
					
				case 2214:
					MenuKontrol(2,2,0,0);	
			case 2220:
				system("cls");
				gotoxy(13,3);
				printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 AYARLAR \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
				gotoxy(13,6);
				printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 1-Uyelik Silme");
				gotoxy(13,9);
				printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 2-Sifre Guncelleme");
				gotoxy(13,12);
				printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 3-Geri Dön");
				break;
				
				case 2221:
					system("cls");
					UyelikSilme();
					MenuKontrol(2,2,0,0);
					break;
					
				case 2222:
					system("cls");
					SifreGuncelleme();
					MenuKontrol(2,2,0,0);
					break;
				
				case 2223:
					MenuKontrol(2,2,0,0);
					break;
				
				case 2230:
				printf("Hesabinizdan cikmak icin enter'a basin");
				getch();
				MenuKontrol(0,0,0,0);
				break;
			default:
			printf("Lutfen menumuzde olan bir deger giriniz!");
			
			if(GirisPanel==3 || GirisPanel==4 || GirisPanel==5 || GirisPanel==6 || GirisPanel==7 || GirisPanel==8 || GirisPanel==9)
			MenuKontrol(0,0,0,0);
			else if(GirisPanel == 1 && GirisMenu == 4 || GirisMenu == 5 || GirisMenu == 6 || GirisMenu == 7 || GirisMenu == 8 || GirisMenu == 9 )
			MenuKontrol(1,1,0,0);
			else if(GirisPanel == 2 && GirisMenu == 4 || GirisMenu == 5 || GirisMenu == 6 || GirisMenu == 7 || GirisMenu == 8 || GirisMenu == 9 )
			MenuKontrol(2,2,0,0);
			break;	
	}
	
	if(AltMenu == 0)
	{

		int secim = MenuDegerSecme();
		if(SuankiDeger==0)
		GirisPanel = secim;
		if(SuankiDeger == 1100 || SuankiDeger == 2200)
		GirisMenu = secim;
		if(SuankiDeger == 1110 || SuankiDeger == 1120 || SuankiDeger == 1130 || SuankiDeger == 2210 || SuankiDeger == 2220)
		AltMenu = secim;
		MenuKontrol(GirisPanel,AnaMenu,GirisMenu,AltMenu);
		
	}

	
	
}


int main(void)
{
	welcomemenu();
	loaderanim();
	MenuKontrol(0,0,0,0);	
	
	getch();
	return 0;
}
