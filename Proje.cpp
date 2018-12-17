#include<stdio.h>
#include<locale.h>
#include<windows.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>

int p=0;

void menu();
void dosyayaYaz();
void filmEkle();
void filmListe();
void ListeFilmEkle();


struct filmarsivi{
	char filmadi[100];
	int yayinyil;
	char yonetmen[100];
	char senarist[100];
	char basrol[10];
}filmler[BUFSIZ];



int main(){
	
	
		FILE *filmarsivi;                                            
		filmarsivi = fopen("filmarsivi.txt","r");
		setlocale(LC_ALL, "Turkish");
	
	
		if (filmarsivi == NULL)		
			printf("G�sterilicek herhangi bir�ey yok\n"); 
					
		else{	
			int x=0;
			while (!feof(filmarsivi)){ 
			fscanf(filmarsivi,"%s\t%s\t%s\t%s\t%s\n",&filmler[x].filmadi, &filmler[x].yayinyil, &filmler[x].yonetmen, &filmler[x].senarist, &filmler[x].basrol);
           	x++;
           
	             	}
	           	p=x;
				fclose(filmarsivi);
				}	
					
		char cikis = 'h';

	while(cikis == 'h')
	{
		system("CLS");
		menu();
		char secenek=0; 
		char devamEt = 'e'; 
		secenek = getch();

		if(secenek == '1')  
		{
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
		else if (secenek == '2')  
		{
				system("CLS");
				filmListe();
				printf("\nMen�ye D�nmek ��in Herhangi Bir Tu�a Bas�n!");
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
			
			printf("Ar�iv Kapan�yor");
			Sleep(800); printf("."); Sleep(800); printf("."); Sleep(800); printf(".");
			Sleep(250); printf("\n��kmak i�in herhangi bir tu�a bas�n!");
			cikis = 'h';
		}
		else
		{
			printf("L�tfen do�ru tu�a bast���n�zdan emin olun!");
			Sleep(800);
			system("CLS");
		}
}
return 0;
}
		
			
			
	


void menu()
{
	
	printf("==================Men�============================\n");
	printf("= 1. Film ekle                                   =\n");
	printf("= 2. Filmleri listele                        	 =\n");
	printf("= 3. Film g�ncelle                               =\n");
	printf("= 4. Film sil                                    =\n");
	printf("= 5. Film ara                                    =\n");
	printf("==================================================\n");
	printf("Bir i�lem se�iniz: ");
	
}


void dosyayaYaz()  
{
	FILE *kayit;
	kayit = fopen("filmarsivi.txt","w");

	if(kayit==NULL)
    	printf("Dosya Bulunamadi...");

    else
	{
		for (int i = 0; i < p; i++)
		{
			fprintf(kayit,"%s\t%s\t%s\t%s\t%s\t\n",filmler[i].filmadi,filmler[i].yayinyil,filmler[i].yonetmen,filmler[i].senarist,filmler[i].basrol);
		}
	}
	fclose(kayit);
}



void filmEkle()
{
	
		printf("Filmin Ad�: ");
		scanf("%s",&filmler[p].filmadi);
		printf("Yayin y�l�: ");
		scanf("%d",&filmler[p].yayinyil);
		printf("y�netmeni: ");
		scanf("%s",&filmler[p].yonetmen);
		printf("senaristi: ");
		scanf("%s",&filmler[p].senarist);
		printf("ba�rol oyuncusu: ");
		scanf("%s",&filmler[p].basrol);
		printf("\nFilmin Ad�:%s, Yay�n y�l�:%d, Y�netmeni:%s, Senaristi:%s ve Ba�rol oyuncusu:%s \n\t\t\tBa�ar�yla Eklenmi�tir! \n",filmler[p].filmadi,filmler[p].yayinyil,filmler[p].yonetmen,filmler[p].senarist,filmler[p].basrol);
}

void filmListe()
{
	
int q;
if(p == 0)
	{
		int secim;
		printf("�uan Hi� Film Bulunmamaktad�r. Ekleme yapmak icin [E/H] tusuna basiniz : ");
		secim = getch();
		if(secim == 'e' || secim == 'E')
		{
			printf("---> Film ekleme ekran�na y�nlendiriliyorsunuz.");
			Sleep(750); printf("."); Sleep(500); printf("."); Sleep(500); printf(".");Sleep(750);
			system("CLS");
			ListeFilmEkle();
			
		}
	}
	else
	{
	for(int i = 0; i < p; i++)
	printf("%d.Film",q++);
	printf("Film ad�       :%s\n",filmler[q].filmadi);
	printf("Yay�nlanma y�l�:%d\n",filmler[q].yayinyil);
	printf("Y�netmen       :%s\n",filmler[q].yonetmen);
	printf("Senarist       :%s\n",filmler[q].senarist);
	printf("Ba�rol Oyuncusu:%s\n",filmler[q].basrol);
	}
}

void ListeFilmEkle()
{
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




