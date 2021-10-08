#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<conio.h>
void antet()
{
    printf("__________________________\n1 adaugare\n");
    printf("2 lista\n");
    printf("3 stergere\n");
    printf("4 afisare\n");
    printf("0 iesire\n__________________________\n");

}
void meniu(int op,char path[])
{
    if(op==1)
        adaugare(path);
    if(op==2)
        lista(path);
    if(op==3)
        stergere(path);
    if(op==4)
        afisare(path);
    if(op>4 || op<1)
        printf("Optiunea aleasa nu se gaseste in meniu.");
}
void adaugare(char path[])
{
    FILE * fp;
    fp = fopen(path, "a");
 char cod[20];
 char nume[20], model[20], marca[20];
 char data[20];
 printf("Numele dumneavoastra este: ");
 fflush(stdin);
 scanf("%[^\n]",nume);
 printf("Marca autoturismului pe care doriti sa-l inchiriati: ");
 scanf("%s",marca);
 fflush(stdin);
 printf("Modelul autoturismului dorit disponibil: ");
 scanf("%s",model);
 printf("Codul masini respective: ");
 scanf("%s",&cod);
 fflush(stdin);
 printf("Ziua in care doriti sa-l inchiriati urmata de luna.\n");
 printf("Introducerea zilei se face in felul urmator:zi/luna.\n");
 fflush(stdin);
 scanf("%s",data);
 if(fp == NULL)
 {
     printf("Erroare, va rugam reveniti mai tarziu!");
 }
 else
 {
   fprintf(fp,"%s %s %s %s\n",nume,marca,model,data);
   fclose(fp);
 }
 stergerel(cod);
}
void lista()
{
  FILE *fp;
  fp=fopen("lista.txt","r");
  if(fp == NULL)
  {
      printf( "Fisierul nu poate fi accesat.\n" ) ;
  }
  else
  {   printf("COD MARCA    MODEL   SUMA/ZI\n");
      char c = fgetc(fp);
        while (c != EOF)
        {
            printf ("%c", c);
            c = fgetc(fp);
        }

        fclose(fp);
        printf("\n");
  }
}
void stergere(char path[])
{
    printf("Daca doriti sa renuntati la rezervare, intorduceti 1");
    printf("\n");
    int ok;
    printf("Introduceti valoarea: ");
    scanf("%d",&ok);
    if(ok==1)
 {
    char nume[20];
    printf("Introdu numele\n");
    getchar();
    scanf("%[^\n]",nume);

    FILE * filePointer;
    filePointer = fopen("fisier.txt", "r");

    FILE * tempPointer;
    tempPointer = fopen("temp.txt", "a");

    char linie[50];

    if ( filePointer == NULL )
    {
        printf( "Fisierul nu poate fi accesat." ) ;
    }
    else
    {
        while (fgets (linie, 50, filePointer)) {
            char t_nume[20];
            char t_marca[20],t_model[20],t_cod[20],t_data[20];
            sscanf(linie, "%s &s &s &s", t_nume, t_model,t_marca,t_data);
            if(strcmp(nume,t_nume)!=0)
                fprintf(tempPointer, "%s", linie);
        }
        fclose(filePointer) ;
        fclose(tempPointer) ;
        remove(path);
        rename("temp.txt", path);
    }
 }
}
void stergerel(char cod[])
{
  FILE *rp;
  rp=fopen("rezervate.txt","a");
  FILE *fp;
  fp=fopen("lista.txt","r");
  FILE *tp;
  tp=fopen("temp.txt","a");
  char linie[100];
  if(fp == NULL)
  {
      printf("Fisierul nu poate fi gasit");
  }
  else
  {
      while(fgets(linie,100,fp))
      {

         char t_cod[20];
         char t_marca[20],t_model[20],t_bani[20];
         sscanf(linie, "%s &s &s &s", t_cod,t_marca,t_model,t_bani);
         if(strcmp(cod,t_cod)!=0)
            fprintf(tp, "%s", linie);
            else
                fprintf(rp,"%s",linie);


      }
      fclose(rp);
      fclose(fp);
      fclose(tp);
      remove("lista.txt");
      rename("temp.txt", "lista.txt");
  }
}
void afisare()
{
  printf("Lista cu clineti nostri: ");
  printf("\n");
  FILE *fp;
  fp=fopen("fisier.txt","r");
  if(fp == NULL)
  {
      printf( "Fisierul nu poate fi accesat.\n" ) ;
  }
  else
  {
      char c = fgetc(fp);
        while (c != EOF)
        {
            printf ("%c", c);
            c = fgetc(fp);
        }

        fclose(fp);
        printf("\n");
  }
}

int main()
{
    int opt;
    char path[]="fisier.txt";
    printf("Pentru a putea vizualiza ce masini avem, va rugam sa selectati optiunea 2.");
    printf("\n");
    do
    {

        antet();
        printf("\n");
        printf("Optiunea dumneavoastra este=");
        scanf("%d", &opt);
        printf("\n");
        meniu(opt,path);
    }
    while(opt>=1 && opt<=4);
}

