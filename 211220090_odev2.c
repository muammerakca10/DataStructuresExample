//
//  211220090_odev2.c
//  
//
//  Created by Muammer on 28.10.2022.
//

#include "211220090_odev2.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct s {
    int boyut;
    int tepe;
    char *dizi[10];
} ;

typedef struct s stack;


stack* tanimla(){
    stack *s = (stack*)malloc(sizeof(stack));
    s->boyut = 2;
    s-> tepe = 0;
    s->dizi = NULL;
    return s;
}



int pop(stack *s){
    if(s->tepe <= 0 || s->dizi == NULL){
        printf("Dizi bos, pop islemi yapilamaz. Hata kodu -1");
        return -1;
    }
    
    if(s->tepe <= s->boyut/4){
        
        // Diziden pop islemi yapinca, eger dizinin eleman sayisi dizinin boyutunun 4te 1ine dusmusse; hafiza tasarrufu yapmak icin diziyi, dizinin yarisi  uzunlukta bir diziye aktarip eski uzun diziyi siliyoruz.
        int *sYeni = (int*)malloc(sizeof(int) *(s->boyut/2));
        for(int i = 0; i<s->tepe; i++){
            sYeni[i] = s->dizi[i];
        }
        free(s->dizi);
        s->dizi = sYeni;
        s->boyut /= 2;
    }
    return s->dizi[--(s->tepe)];
}

void push(int a, stack *s){
    if(s->dizi == NULL){
        s->dizi = (int*)malloc(sizeof(int)*2);
    }
    if (s->tepe >= s->boyut-1){
        //Diziye push islemi yapinca, eger dizi dolduysa; diziyi, dizinin 2 kati uzunlukta bir diziye aktarip, eski kisa diziyi hafizada bosu bosuna yer kaplamamasi icin siliyoruz.
        int *sYeni = (int*)malloc(sizeof(int)*(s->boyut*2));
        for (int i = 0; i<s->boyut; i++){
            sYeni[i] = s->dizi[i];
        }
        free(s->dizi);
        s->dizi = sYeni;
        s->boyut *= 2;
    }
    s->dizi[s->tepe++] = a;
}

void yazdir(stack *s){
    printf("Tepe : %d\n", s->tepe);
    printf("Boyut : %d\n", s->boyut);
    for(int i = 0; i<s->tepe;i++){
        printf("%d,",s->dizi[i]);
    }
    printf("\n");
}

int main(){
    char text[30];
    printf("Enter String\n");
    
    
    stack *s1 = tanimla();
    stack *s2 = tanimla();
/*
    for(int i = 0; i<10;i++){
        push(i*10, s1);
    }
    printf("10 eleman s1'e push edildikten sonra:\n");
    yazdir(s1);
    
    for(int i = 0; i<8; i++){
        push(pop(s1),s2);
    }
    printf("s1'den s2'ye aktarma isleminden sonra s1:\n");
    yazdir(s1);
    printf("s1'den s2'ye aktarma isleminden sonra s2:\n");
    yazdir(s2);
*/

}
