#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct alanlar
{
    char alan_tipi[100];
} alan;

struct noktalar
{
    int line_count;
} count;

struct sayi_degeri
{
    int deger;

} sayi;

struct three_member_array
{
    double x;
    double y;
    double z;

} coordinat_xyz[200000];

struct six_member_array
{
    double x;
    double y;
    double z;
    int r;
    int g;
    int b;

} coordinat_xyzrgb[85000];

void alan_kontrol(FILE *veriler)
{
    int line_count = 0;
    int adet;
    char b, data[10000], line[1000];

    while(!feof(veriler))
    {
        b = fgetc(veriler);
        if(b == '\n')
            line_count++;

        if(line_count == 2)
        {

            fgets(alan.alan_tipi, 100, veriler);
            line_count++;

        }
        if(line_count == 3)
        {
            fscanf(veriler, "%s%d", &data, &adet);


        }


    }
    line_count = line_count - 5;
    printf("\n%s\n", alan.alan_tipi);
    printf("%d\t%d\n", line_count, adet);
    if(adet != line_count)
    {
        printf("Dosyadaki nokta sayisi gecerli degildir.");
        system ("pause");
    }
    else
        printf("Dosyadaki nokta sayisi gecerlidir");


}

int alan_deger()
{
    char data_type1[]="ALANLAR x y z r g b\n";
    char data_type2[]="ALANLAR x y z\n";
    if(strcmp(alan.alan_tipi,data_type1) == 0)
    {
        return 6;
    }
    if(strcmp(alan.alan_tipi,data_type2) == 0)
    {
        return 3;
    }


}

void nokta_kaydetme(FILE *veriler)
{
    char a;
    veriler = fopen("veriler2.nkt","r");
    long line_count = 0, i = 0;
    char p;
    //coordinat_xyz *p;

    while(!feof(veriler))
    {
        a = fgetc(veriler);
        if(a == '\n')
           line_count++;

        if(line_count > 4)
        {


            if(sayi.deger == 3)
            {

                fscanf(veriler, "%lf %lf %lf", &coordinat_xyz[i].x, &coordinat_xyz[i].y, &coordinat_xyz[i].z);
               // printf("\n%lf %lf %lf", coordinat_xyz[i].x, coordinat_xyz[i].y, coordinat_xyz[i].z);

            }
            if(sayi.deger == 6)
            {

                fscanf(veriler,"%lf %lf %lf %d %d %d", &coordinat_xyzrgb[i].x, &coordinat_xyzrgb[i].y, &coordinat_xyzrgb[i].z, &coordinat_xyzrgb[i].r, &coordinat_xyzrgb[i].g, &coordinat_xyzrgb[i].b);
                //printf("\n%lf %lf %lf d %d %d \n",  &coordinat_xyzrgb[i].x, &coordinat_xyzrgb[i].y, &coordinat_xyzrgb[i].z, &coordinat_xyzrgb[i].r, &coordinat_xyzrgb[i].g, &coordinat_xyzrgb[i].b);

            }
            i++;

        }

    }

}


int main()
{

    FILE *veriler;
    int deger;
    veriler = fopen("veriler2.nkt","r");
    alan_kontrol(veriler);
    deger = alan_deger();
    sayi.deger = deger;
    printf("\n%d jhbh", deger);
    nokta_kaydetme(veriler);


    fclose(veriler);

    return 0;
}
