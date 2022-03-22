#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>
struct proje {
    int id;
    char soru[500];
    char a[50];
    char b[50];
    char c[50];
    char d[50];
    char dogru[50];
};
struct sorular {
char soru[500];
char a[100];
char b[100];
char c[100];
char d[100];
char dogru[100];
}soru[30];
struct sk{
    int id;
    int skor;
    char ad[20];
};
struct skor{
    int skor;
    char ad[20];
}skorr[30];
void goster(void);
void gosteriki(void);
int secimGir(void);
void kayitGuncelle(void);
void yeniKayit(void);
void kayitSil(void);
int sorusayisi(void);
void oyunOyna(void);
void sorularDiziye(void);
int skorsayisi(void);
void skorlarDiziye(void);
void skorlariListele(void);
int sorusayisi(){
    FILE *pDosya;
    struct proje soruadedi;
    pDosya = fopen("Sorular.dat", "r+");
    int i = 0;
    while (!feof( pDosya )) {
         
        fread( &soruadedi, sizeof( struct proje ), 1, pDosya );
        i++;
        if (soruadedi.id!=i)
        {
            i--;
        }
    }
fclose(pDosya);
return i;
}
void sorularDiziye(){
    FILE *oku;
    oku=fopen("Sorular.dat","r");
    struct proje ekle={0,"","","","","",""};
     for (int i = 0; i < sorusayisi(); i++)
    {
        fread( &ekle, sizeof( struct proje ), 1, oku );
        strcpy(soru[i].soru,ekle.soru);
        strcpy(soru[i].a,ekle.a);
        strcpy(soru[i].b,ekle.b);
        strcpy(soru[i].c,ekle.c);
        strcpy(soru[i].d,ekle.d);
        strcpy(soru[i].dogru,ekle.dogru);
    }
    fclose(oku);
}
void skorlarDiziye(){
    FILE *oku;
    oku=fopen("Skorlar.dat","r");
    struct sk ekle={0,0,""};
    for (int i = 0; i < skorsayisi(); i++)
    {
        fread( &ekle, sizeof( struct sk ), 1, oku );
        skorr[i].skor=ekle.skor;
        strcpy(skorr[i].ad,ekle.ad);
    }
    fclose(oku);
}
void skorlariListele(){
    system("clear");
    skorlarDiziye();
    int i,gecici,tut;
    char ad[20];

    for(gecici=0;gecici<skorsayisi();gecici++)
       {
           for (i=0;i<skorsayisi() - 1;i++)
          {
            if (skorr[i].skor>skorr[i+1].skor)
            {
               tut=skorr[i].skor;
               strcpy(ad,skorr[i].ad);
               skorr[i].skor=skorr[i+1].skor;
               strcpy(skorr[i].ad,"");
               strcpy(skorr[i].ad,skorr[i+1].ad);
               skorr[i+1].skor=tut;
               strcpy(skorr[i+1].ad,"");
               strcpy(skorr[i+1].ad,ad);
            }
          }
       }
    printf("En büyük 3 skor\n---------------\n");
    int kontrol=0;
    for (i=skorsayisi()-1;i>=0;i--)
    {
        if (0<=kontrol&&kontrol<3)
        {
            printf("%s-->%d\n",skorr[i].ad,skorr[i].skor);
            kontrol++;
        }
    }
}
void oyunOyna(){
    system("clear");
    srand(time(NULL));
    char ad[30];
    char cevap[1]="";
    int k,sayi,skor=0;
    int oyunSorular[50];
    sorularDiziye();
    int dongu=1;
    while (dongu)
    {
            for (int i = 0; i <5; i++){
            while(1){
                            k = 1;
                            sayi = rand()%sorusayisi();
                            for(int j = 0; j < i; j++){
                                if(sayi==oyunSorular[j]){
                                    k = 0;
                                    break;
                                }
                            }
                            if(k){
                                oyunSorular[i] = sayi;
                                break;
                            }
                        }    
            printf("Soru:%s\n",soru[sayi].soru);
            printf("A:%s\n",soru[sayi].a);
            printf("B:%s\n",soru[sayi].b);
            printf("C:%s\n",soru[sayi].c);
            printf("D:%s\n",soru[sayi].d);
            printf("Cevap olan şıkkı girin(Büyük harf kullanın!):");
            scanf("%s",cevap);
            int dongukir=1;
            while (dongukir)
            {
                if (strcmp(cevap,"A")&&strcmp(cevap,"B")&&strcmp(cevap,"C")&&strcmp(cevap,"D"))
                {
                    system("clear");
                    printf("Soru:%s\n",soru[sayi].soru);
                    printf("A:%s\n",soru[sayi].a);
                    printf("B:%s\n",soru[sayi].b);
                    printf("C:%s\n",soru[sayi].c);
                    printf("D:%s\n",soru[sayi].d);
                    printf("Lütfen tanımlanan şıklardan birini girin(Büyük harf kullanın!):");
                    scanf("%s",cevap);
                    
                }
                else
                {
                    dongukir=0;
                }
            }
            system("clear");  
            int result;
            result = strcmp(soru[sayi].dogru, cevap);
            if (result==0)
            {
                skor++;
            }      
        }
        printf("Oynamaya devam etmek istiyorsan 1'e çıkmak istiyorsan 0'a basın:");
        scanf("%d",&dongu);
        int kir=1;
        while (kir)
        {
            if (dongu!=0&&dongu!=1)
            {
                system("clear");
                printf("Oynamaya devam etmek istiyorsan 1'e çıkmak istiyorsan 0'a basın:");
                scanf("%d",&dongu);
            }
            else
            {
                kir=0;
            }
        }
    system("clear");
}
    system("clear");
    printf("Skorunuz:%d\n",skor);
    FILE *y=fopen("Skorlar.dat","a+");
    struct sk yeniskor={0,0,""};
    printf("Adınızı girin:");
    gets(yeniskor.ad);
    gets(yeniskor.ad);
    yeniskor.id=skorsayisi()+1;
    yeniskor.skor=skor;
    fseek(y,(yeniskor.id-1)*sizeof(struct sk),SEEK_SET);
    fwrite(&yeniskor,sizeof(struct sk),1,y);
    system("clear");
    printf("Skor eklendi!\n");
    fclose(y);
}
int skorsayisi(){
    FILE *pDosya;
    struct sk skoradedi={0};
    pDosya = fopen("Skorlar.dat", "r+");
    int i = 0;
    while (!feof( pDosya )) { 
        fread( &skoradedi, sizeof( struct sk ), 1, pDosya );
        i++;
    }
    fclose(pDosya);
    return i-1;
}
int main(){
    setlocale(LC_ALL,"Turkish");
    system("clear");
    sorusayisi();
    int secim;
        while ((secim=secimGir())!=-1)
        {   
            switch (secim)
            {
                case 1:
                    yeniKayit();
                break;
                case 2:
                    kayitSil();
                break;
                case 3:
                    kayitGuncelle();
                break;
                case 4:
                    oyunOyna();
                break;
                case 5:
                    skorlariListele();
                break;
                case 6:
                    system("clear");
                    printf("Tekrar bekleriz:)\n");
                    exit(1);
                break;
                default:
                system("clear");
                printf("Lütfen tanımlanan aralıkta değer giriniz!\n");
                break;
            }
        }
    }
void kayitGuncelle(){
    FILE *g=fopen("Sorular.dat","r+");
    system("clear");
    int gid,id;
    struct proje soru={0,"","","","","",""};
    gosteriki();
    printf("Güncellenecek sorunun id'sini girin(çıkmak için 0 girin!):");
    scanf("%d",&gid);
    if (gid==0)
    {
        main();
    }
    if (gid<0)
    {
        system("clear");
        printf("Lütfen pozitif değer giriniz.\n");
    }
    else
    {   
        system("clear");
        fseek(g,(gid-1)*sizeof(struct proje),SEEK_SET);
        fread(&soru,sizeof(struct proje),1,g);
        id=soru.id;
        if (soru.id==0)
        {
            system("clear");
            printf("Soru %d bulunamadı!\n",gid);
        }
        else
        {
            printf("Soru:");
            gets(soru.soru);
            gets(soru.soru);
            int dongukir=1;
            while (dongukir)
            {
                if (strcmp(soru.soru,"")==0)
                {
                    system("clear");
                    printf("Lütfen soru giriniz:");
                    gets(soru.soru);
                    
                }
                else
                {
                    dongukir=0;
                }
            }
            int d=1;
            system("clear");
            printf("Soru:%s\n",soru.soru);
            printf("A:");
            gets(soru.a);
            while (d)
            {
                if (strcmp(soru.a,"")==0)
                {
                    system("clear");
                    printf("Soru:%s\n",soru.soru);
                    printf("Lütfen A şıkkını giriniz:");
                    gets(soru.a);
                    
                }
                else
                {
                    d=0;
                }
            }
            system("clear");
            printf("Soru:%s\n",soru.soru);
            printf("A:%s\n",soru.a);
            printf("B:");
            gets(soru.b);
            int dd=1;
            while (dd)
            {
                if (strcmp(soru.b,"")==0)
                {
                    system("clear");
                    printf("Soru:%s\n",soru.soru);
                    printf("A:%s\n",soru.a);
                    printf("Lütfen B şıkkını giriniz:");
                    gets(soru.b);
                    
                }
                else
                {
                    dd=0;
                }
            }
            system("clear");
            printf("Soru:%s\n",soru.soru);
            printf("A:%s\n",soru.a);
            printf("B:%s\n",soru.b);
            printf("C:");
            gets(soru.c);
            int ddd=1;
             while (ddd)
            {
                if (strcmp(soru.c,"")==0)
                {
                    system("clear");
                    printf("Soru:%s\n",soru.soru);
                    printf("A:%s\n",soru.a);
                    printf("B:%s\n",soru.b);
                    printf("Lütfen C şıkkını giriniz:");
                    gets(soru.c);
                    
                }
                else
                {
                    ddd=0;
                }
            }
            system("clear");
            printf("Soru:%s\n",soru.soru);
            printf("A:%s\n",soru.a);
            printf("B:%s\n",soru.b);
            printf("C:%s\n",soru.c);
            printf("D:");
            gets(soru.d);
            int dddd=1;
             while (dddd)
            {
                if (strcmp(soru.d,"")==0)
                {
                    system("clear");
                    printf("Soru:%s\n",soru.soru);
                    printf("A:%s\n",soru.a);
                    printf("B:%s\n",soru.b);
                    printf("C:%s\n",soru.c);
                    printf("Lütfen D şıkkını giriniz:");
                    gets(soru.d);
                    
                }
                else
                {
                    dddd=0;
                }
            }
            system("clear");
            printf("Soru:%s\n",soru.soru);
            printf("A:%s\n",soru.a);
            printf("B:%s\n",soru.b);
            printf("C:%s\n",soru.c);
            printf("D:%s\n",soru.d);
            printf("Doğru-cevap:");
            gets(soru.dogru);
            int ddddd=1;
            while (ddddd)
            {
                if (strcmp(soru.dogru,"A")&&strcmp(soru.dogru,"B")&&strcmp(soru.dogru,"C")&&strcmp(soru.dogru,"D"))
                {
                    system("clear");
                    printf("Soru:%s\n",soru.soru);
                    printf("A:%s\n",soru.a);
                    printf("B:%s\n",soru.b);
                    printf("C:%s\n",soru.c);
                    printf("D:%s\n",soru.d);
                    printf("Lütfen doğru cevabı tanımlanan şıklardan seçiniz(Büyük karakter kullanınız!):");
                    gets(soru.dogru);
                    
                }
                else
                {
                    ddddd=0;
                }
            }
            soru.id=id;
            fseek(g,(gid-1)*sizeof(struct proje),SEEK_SET);
            fwrite(&soru,sizeof(struct proje),1,g);
            system("clear");
            printf("Soru güncellendi!\n");
        }
        fclose(g);
    }
}
void kayitSil(){
    FILE *s=fopen("Sorular.dat","r+");
    system("clear");
    goster();
    struct proje soru,bossoru={0,"","","","","",""};
    struct proje bos={0,"","","","","",""};
    int ide;
    printf("Silinecek sorunun id'sini girin(çıkmak için 0 girin!):");
    scanf("%d",&ide);
    if (ide==0)
    {
        main();
    }
    
    if (ide<0)
    {
        system("clear");
        printf("Lütfen pozitif değer giriniz!.\n");
    }
    else
    {
        fseek(s,(ide-1)*sizeof(struct proje),SEEK_SET);
        fread(&soru,sizeof(struct proje),1,s);
        if (ide!=soru.id){
        system("clear");
        printf("Soru %d bulunamadı!\n",ide);
        }
        else
        {
            if (ide==sorusayisi())
            {
                fseek(s,(ide-1)*sizeof(struct proje),SEEK_SET);
                fwrite(&bos,sizeof(struct proje),1,s);
                system("clear");
                printf("Soru silindi!\n");
            }
            else
            {
                for (int i = ide; i <= sorusayisi(); i++)
                {
                    fseek(s,(i)*sizeof(struct proje),SEEK_SET);
                    fread(&soru,sizeof(struct proje),1,s);
                    bossoru.id=soru.id-1;
                    strcpy(bossoru.soru,soru.soru);
                    strcpy(bossoru.a,soru.a);
                    strcpy(bossoru.b,soru.b);
                    strcpy(bossoru.c,soru.c);
                    strcpy(bossoru.d,soru.d);
                    strcpy(bossoru.dogru,soru.dogru);
                    fseek(s,(i-1)*sizeof(struct proje),SEEK_SET);
                    fwrite(&bossoru,sizeof(struct proje),1,s);
                    system("clear");
                    printf("Soru silindi!\n");
                }
            }
        }
    fclose(s);
    }
}
void yeniKayit(){
    system("clear");
    FILE *y=fopen("Sorular.dat","r+");
    struct proje yenisoru={0,"","","","","",""};
  
            printf("Soru:");
            gets(yenisoru.soru);
            gets(yenisoru.soru);
            int dongukir=1;
            while (dongukir)
            {
                if (strcmp(yenisoru.soru,"")==0)
                {
                    system("clear");
                    printf("Lütfen soru giriniz:");
                    gets(yenisoru.soru);
                    
                }
                else
                {
                    dongukir=0;
                }
            }
            system("clear");
            printf("Soru:%s\n",yenisoru.soru);
            printf("A:");
            gets(yenisoru.a);
            int dk=1;
            while (dk)
            {
                if (strcmp(yenisoru.a,"")==0)
                {
                    system("clear");
                    printf("Soru:%s\n",yenisoru.soru);
                    printf("Lütfen A şıkkını giriniz:");
                    gets(yenisoru.a);
                }
                else
                {
                    dk=0;
                }
            }
            system("clear");
            printf("Soru:%s\n",yenisoru.soru);
            printf("A:%s\n",yenisoru.a);
            printf("B:");
            gets(yenisoru.b);
            int dkk=1;
             while (dkk)
            {
                if (strcmp(yenisoru.b,"")==0)
                {
                    system("clear");
                    printf("Soru:%s\n",yenisoru.soru);
                    printf("A:%s\n",yenisoru.a);
                    printf("Lütfen B şıkkını giriniz:");
                    gets(yenisoru.b);
                }
                else
                {
                    dkk=0;
                }
            }
            system("clear");
            printf("Soru:%s\n",yenisoru.soru);
            printf("A:%s\n",yenisoru.a);
            printf("B:%s\n",yenisoru.b);
            printf("C:");
            gets(yenisoru.c);
            int dkkk=1;
             while (dkkk)
            {
                if (strcmp(yenisoru.c,"")==0)
                {
                    system("clear");
                    printf("Soru:%s\n",yenisoru.soru);
                    printf("A:%s\n",yenisoru.a);
                    printf("B:%s\n",yenisoru.b);
                    printf("Lütfen C şıkkını giriniz:");
                    gets(yenisoru.c);
                }
                else
                {
                    dkkk=0;
                }
            }
            system("clear");
            printf("Soru:%s\n",yenisoru.soru);
            printf("A:%s\n",yenisoru.a);
            printf("B:%s\n",yenisoru.b);
            printf("C:%s\n",yenisoru.c);
            printf("D:");
            gets(yenisoru.d);
            int dkkkk=1;
             while (dkkkk)
            {
                if (strcmp(yenisoru.d,"")==0)
                {
                    system("clear");
                    printf("Soru:%s\n",yenisoru.soru);
                    printf("A:%s\n",yenisoru.a);
                    printf("B:%s\n",yenisoru.b);
                    printf("C:%s\n",yenisoru.c);
                    printf("Lütfen D şıkkını giriniz:");
                    gets(yenisoru.d);
                }
                else
                {
                    dkkkk=0;
                }
            }
            system("clear");
            printf("Soru:%s\n",yenisoru.soru);
            printf("A:%s\n",yenisoru.a);
            printf("B:%s\n",yenisoru.b);
            printf("C:%s\n",yenisoru.c);
            printf("D:%s\n",yenisoru.d);
            printf("Doğru şıkkı girin(Büyük harf kullanın!):");
            gets(yenisoru.dogru);
            int dd=1;
            while (dd)
            {
                if (strcmp(yenisoru.dogru,"A")&&strcmp(yenisoru.dogru,"B")&&strcmp(yenisoru.dogru,"C")&&strcmp(yenisoru.dogru,"D"))
                {
                    system("clear");
                    printf("Soru:%s\n",yenisoru.soru);
                    printf("A:%s\n",yenisoru.a);
                    printf("B:%s\n",yenisoru.b);
                    printf("C:%s\n",yenisoru.c);
                    printf("D:%s\n",yenisoru.d);
                    printf("Lütfen doğru cevabı tanımlanan şıklardan seçiniz(Büyük karakter kullanınız!):");
                    gets(yenisoru.dogru);
                    
                }
                else
                {
                    dd=0;
                }
            }
            yenisoru.id=sorusayisi()+1;
            fseek(y,(yenisoru.id-1)*sizeof(struct proje),SEEK_SET);
            fwrite(&yenisoru,sizeof(struct proje),1,y);
            system("clear");
            printf("Soru eklendi!\n");
    fclose(y);
}
int secimGir(void){
    int menuSec;
    printf("\n**********Test-Oyunu**********\n"
    "1.Soru ekle\n"
    "2.Soru sil\n"
    "3.Soruları göster ve güncelle\n"
    "4.Oyun oyna\n"
    "5.En yüksek üç skoru göster\n"
    "6.Çık\n");
    printf("---------------------");
    printf("\nToplam soru sayısı:%d\n",sorusayisi());
    printf("---------------------");
    printf("\nLütfen [1-6] aralığından seçiniz:");
    scanf("%d",&menuSec);
    return menuSec;
}
void goster(){
    FILE *oku;
    oku=fopen("Sorular.dat","r");
    struct proje gs={0,""};
    printf("%-25s %-13s\n","İd","Soru");
    printf("---  -----------------------------------------------\n");
    for (int i = 0; i < sorusayisi(); i++)
    {
        fread( &gs, sizeof( struct proje ), 1, oku );
        if (gs.id>0)
        {
            printf("%-2d-->%-13s\n",gs.id,gs.soru);
        }
    }
    printf("-------------------------------------------------------\n");
fclose(oku);
}
void gosteriki(){
    FILE *oku;
    oku=fopen("Sorular.dat","r");
    struct proje gs={0,"","","","","",""};
    for (int i = 0; i <sorusayisi(); i++)
    {
        fread( &gs, sizeof( struct proje ), 1, oku );
        if (gs.id>0)
        {
            printf("-------------------------------------------------------\n");
            printf("İd:%d\n",gs.id);
            printf("Soru:%s\n",gs.soru);
            printf("A şıkkı:%s\n",gs.a);
            printf("B şıkkı:%s\n",gs.b);
            printf("C şıkkı:%s\n",gs.c);
            printf("D şıkkı:%s\n",gs.d);
            printf("Doğru şık:%s\n",gs.dogru);
        }
    }
    printf("-----------------------------------------------------------\n");        
    fclose(oku);
}