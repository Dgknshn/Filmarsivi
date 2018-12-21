#include <stdio.h>
#include <stdlib.h>
#include<locale.h>
#include<windows.h>
#include <conio.h>
#include <ctype.h>

int p=0;
void menu();
void filmEkle();
void dosyayaYaz();
void filmListe();
void listeFilmEkle();

struct filmarsivi{
	char filmadi[100];
	 int yayinyil;
	char yonetmen[100];
	char senarist[100];
	char basrol[10];
}film[BUFSIZ];	

int main(){
		FILE *dosya;                                            
		dosya = fopen("Filmarsivi.txt","r");
		
		
		setlocale(LC_ALL, "Turkish");
	
	
		if (dosya == NULL)
			{
			printf("Gösterilicek herhangi birşey yok\n"); 
			}
		else
			{	
			int x=0;
			while (!feof(dosya))
				{ 
				fscanf(dosya,"%s\t%s\t%s\t%s\t%s\n",&film[x].filmadi, &film[x].yayinyil, &film[x].yonetmen, &film[x].senarist, &film[x].basrol);
           		x++;
	       		}
	       	p=x;
			fclose(dosya);
			}
			
			
	char cikis = 'a';
	while(cikis == 'a')
	{
		system("CLS");
		
		menu();
		char secenek=0; 
		secenek = getch();
		
		char devamEt = 'e'; 		
		
		if(secenek == '1')  
		{
			while(devamEt == 'e' || devamEt == 'E')
			{
				system("CLS");
				filmEkle();
				dosyayaYaz();
				Sleep(1500);
				system("CLS");
				printf("Film eklemeye devam etmek ister misin [E/H]\n");
				devamEt = getch();
			}	
		}
		else if (secenek == '2')  
		{
				system("CLS");
				filmListe();
				printf("\nMenüye Dönmek İçin Herhangi Bir Tuşa Basın!");
				getch();
		}	
		else if (secenek == '3')
		{
			
		}
		else if (secenek == '4')
		{
			
		}
		else if (secenek == '5')
		{
			
		}
		else if (secenek == '6')
		{
			
			printf("Arşiv Kapanıyor");
			Sleep(600); printf("."); Sleep(600); printf("."); Sleep(600); printf(".");
			Sleep(250); printf("\nÇıkmak için herhangi bir tuşa basın!");
			cikis = 'a';
		}
		else
		{
			printf("Lütfen doğru tuşa bastığınızdan emin olun!");
			Sleep(800);
			system("CLS");
		}
}
	return 0;
}

void menu()
{
	printf("==================Menü============================\n");
	printf("= 1. Film ekle                                   =\n");
	printf("= 2. Filmleri listele                        	 =\n");
	printf("= 3. Film güncelle                               =\n");
	printf("= 4. Film sil                                    =\n");
	printf("= 5. Film ara                                    =\n");
	printf("= 6. Çıkış                                       =\n");
	printf("==================================================\n");
	printf("Bir işlem seçiniz: ");
}
void filmEkle(){
		printf("     FİLM EKLEME\n");
		printf("Filmin Adı     : ");
		scanf("%s",&film[p].filmadi);
		printf("Yayin yılı     : ");
		scanf("%d",&film[p].yayinyil);
		printf("Yönetmeni      : ");
		scanf("%s",&film[p].yonetmen);
		printf("Senaristi      : ");
		scanf("%s",&film[p].senarist);
		printf("Başrol Oyuncusu: ");
		scanf("%s",&film[p].basrol);
		printf("\nFilmin Adı:%s, Yayın yılı:%d, Yönetmeni:%s, Senaristi:%s ve Başrol oyuncusu:%s \n\t\t\tBaşarıyla Eklenmiştir! \n",film[p].filmadi,film[p].yayinyil,film[p].yonetmen,film[p].senarist,film[p].basrol,p++);
}
void dosyayaYaz(){
	FILE *dosya;
	dosya = fopen("Filmarsivi.txt","w");
		int i = 0;
		for (i; i <= p; i++)
		{
			fprintf(dosya,"%s\t%s\t%s\t%s\t%s\t\n",film[i].filmadi,film[i].yayinyil,film[i].yonetmen,film[i].senarist,film[i].basrol);
		}

	fclose(dosya);
}
void filmListe(){
	int q;
if(p == 0)
	{
		int secim;
	
		printf("Şuan Hiç Film Bulunmamaktadır. Ekleme yapmak icin [E/H] tusuna basiniz : ");
		secim = getch();
	
		if(secim == 'e' || secim == 'E')
		{
			printf("---> Film ekleme ekranına yönlendiriliyorsunuz.");
			Sleep(750); printf("."); Sleep(500); printf("."); Sleep(500); printf(".");Sleep(750);
			system("CLS");
			listeFilmEkle();
		}
	}
	else
	{
		int i = 0;
		for(i; i < p; i++)
			printf("%d.Film\n",q++);
			printf("Film adı       :%s\n",film[q].filmadi);
			printf("Yayınlanma yılı:%d\n",film[q].yayinyil);
			printf("Yönetmen       :%s\n",film[q].yonetmen);
			printf("Senarist       :%s\n",film[q].senarist);
			printf("Başrol Oyuncusu:%s\n",film[q].basrol);
	}
}
void listeFilmEkle(){
	char devamEt = 'e'; 
		while(devamEt == 'e' || devamEt == 'E')
			{
				system("CLS");
				filmEkle();
				dosyayaYaz();
				Sleep(1000);
				system("CLS");
				
				printf("Film eklemeye devam etmek ister misin [E/H]\n");
				devamEt = getch();
			}
}


