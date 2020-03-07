#include <stdio.h>
#include <limits.h>
void swap(unsigned long long *prve, unsigned long long *druhe){
   int swap;
   swap  = *druhe;
   *druhe = *prve;
   *prve = swap;
}
int main()
{
    unsigned long long service_length,x[1000]; // ULLONG NECH SA TO POPASUJE SO VSETKYM (OKREM ZAPORNYCH CISIEL ALE TIE V TOMTO PRIPADE NEPOTREBUJEME)
    int i,j,count=0;                       //S ULLONG MOZU NIEKTORE COMPILERY VYHADZOVAT WARNING. JA SOM ICH v ONLINEGDB.COM NEMAL. AK BY VAROVALO PROGRAM BY AJTAK MAL FUNGOVAT
    char division,enter,y[1000];

    for(i=0;i<1000;i++)
        x[i]=ULLONG_MAX; //ULLONG_MAX = 4294967295 z <limits.h> TOTO JE PEVNY LIMIT PROGRAMU

    i=0;//CITANIE CELEHO STDIN
    while(scanf("%c%llu%c", &division, &service_length,&enter)==3){
        if((division=='A' || division=='a')){
            y[i]='A';
            x[i++]=service_length;
            count++;
        }
        else if(division=='B' || division=='b'){
            y[i]='B';
            x[i++]=service_length;
            count++;
        }

        if(enter=='\n')
            break;
    }

    for(i=0;i<count;i++) //BUBBLE SORT VOJAKOV
        for(j=0;j<count;j++)
            if(((y[i]=='A'&& y[j]=='A') || (y[i]=='B'&& y[j]=='B'))&& x[i]<=x[j])
               swap(&x[i],&x[j]);

    for(i=0;i<count;i++){
        printf("%c",y[i]);
        printf("%llu ",x[i]);
    }

    return 0;
}

