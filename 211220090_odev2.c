//
//  211220090_odev2.c
//  
//
//  Created by Muammer on 28.10.2022.
//

#include "211220090_odev2.h"
#include <stdio.h>
#include <stdlib.h>

int *dizi = NULL;
int boyut = 2;
int tepe =0;

int pop(){
    if(tepe <= boyut/4){
        // Diziden pop islemi yapinca, eger dizinin eleman sayisi dizinin boyutunun 4te 1ine dusmusse; hafiza tasarrufu yapmak icin diziyi, dizinin yarisi  uzunlukta bir diziye aktarip eski uzun diziyi siliyoruz.
        int *dizi2 = (int*)malloc(sizeof(int) *(boyut/2));
        for(int i = 0; i<boyut; i++){
            dizi2[i] = dizi[i];
        }
        free(dizi);
        dizi = dizi2;
        boyut /= 2;
    }
    return dizi[--tepe];
}

void push(int a){
    
    if (tepe >= boyut){
        //Diziye push islemi yapinca, eger dizi dolduysa; diziyi, dizinin 2 kati uzunlukta bir diziye aktarip, eski kisa diziyi hafizada bosu bosuna yer kaplamamasi icin siliyoruz.
        int *dizi2 = (int*)malloc(sizeof(int)*boyut*2);
        for (int i = 0; i<boyut; i++){
            dizi2[i] = dizi[i];
        }
        free(dizi);
        dizi = dizi2;
        boyut *= 2;
    }
        dizi[tepe++] = a;
    
}

void yazdir(){
    for(int i = 0; i<tepe;i++){
        printf("%d\t",dizi[i]);
    }
}


int main(){
    dizi = (int*)malloc(sizeof(int)*2);
    printf("boyut : %d\n",boyut);
    push(10);
    yazdir();
    printf("boyut : %d\n",boyut);
    push(20);
    yazdir();
    printf("boyut : %d\n",boyut);
    push(30);
    yazdir();
    printf("boyut : %d\n",boyut);
    push(40);
    yazdir();
    printf("boyut : %d\n",boyut);
    push(50);
    yazdir();
    printf("boyut : %d\n",boyut);
    yazdir();
    printf("\npopped %d\n",pop());
    printf("boyut : %d\n",boyut);
    yazdir();
    printf("\npopped %d\n",pop());
    printf("boyut : %d\n",boyut);
    yazdir();
    printf("\npopped %d\n",pop());
    printf("boyut : %d\n",boyut);
    yazdir();
    printf("\npopped %d\n",pop());
    printf("boyut : %d\n",boyut);
    yazdir();
    printf("\npopped %d\n",pop());
    printf("boyut : %d\n",boyut);
    yazdir();
    //printf("popped %d\n",pop());
}
