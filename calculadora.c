#include <stdio.h>
#include <string.h>
#include <stdint.h>
void decimal(int numero, char *binario){
    if(numero>1){
        decimal(numero/2, binario);
    }
    char digito[2];
    sprintf(digito, "%d", numero % 2);
    strcat(binario,digito);
    printf("%d (porque %d %% 2 = %d)\n", numero % 2, numero, numero % 2); 
}

void octa(int numero, char *octal){
    if(numero>7){
        octa(numero/8, octal);
    }
    char digito[2];
    sprintf(digito, "%d", numero%8);
    strcat(octal, digito);
    printf("%d (porque %d %% 8 = %d)\n", numero % 8, numero, numero % 8);
}

void hexa(int numero, char *hexal){
    if(numero>15){
        hexa(numero/16, hexal);
    }
    int r = numero % 16;
    char digito[2];
    if(r<10){
        sprintf(digito, "%d", r);
        printf("%d (porque %d %% 16 = %d)\n", r, numero, r);
    }else{
        sprintf(digito, "%c", r - 10 + 'A');
        printf("%c (porque %d %% 16 = %d e mapeia para %c)\n", r - 10 + 'A', numero, r, r - 10 + 'A');
    }
    strcat(hexal, digito);
}
int Bits(int numero){
    int binario = 0, base =1;
    while(numero>0){
        binario+=(numero%2)*base;
        numero/=2;
        base*=10;
        
    }
    return binario;
}
void BCD(int numero, char *BCD2){
    if(numero ==0){
        return;
    }
    BCD(numero/10, BCD2);
    int digito = numero %10;
    char BCD3[5];
    sprintf(BCD3, "%04d", Bits(digito));
    strcat(BCD2, BCD3);
    printf("Convertendo o dígito %d para BCD: %04d\n", digito, Bits(digito));

}

void impressao(int16_t numero){
    printf("Passo a passo para %d em complemento a 2 com 16 bits:\n", numero);

    for(int i = 15; i >= 0; i--){
        int bit = (numero >> i) & 1;
        printf("Bit %d (2^%d): %d\n", 15 - i, i, bit);
    }

    printf("Representação final em 16 bits: ");
    for(int i = 15; i >= 0; i--){
        printf("%d", (numero >> i) & 1);
    }
    printf("\n");
}

int main(void){
    system("CLS");
    int numero, e=4;
    int16_t numero2;

    while(e!=0){
        printf("Digite sua escolha [1/2/3/0]: ");
        scanf("%d",&e);

        if(e==0){
            printf("Saindo");
            break;
        }

        else if(e==1){
        printf("Digite um numero: ");
        scanf("%d", &numero);
        char binario[64] = "";
        char octal[64] = "";
        char hexal[64] = "";
        char bcd[256] = "";
        printf("O numero %d em binário e:\n ", numero);
        decimal(numero, binario);
        printf("\n");
        printf("O numero %d em octa e:\n ", numero);
        octa(numero, octal);
        printf("\n");
        printf("O numero %d em hexa e:\n ", numero);
        hexa(numero, hexal);
        printf("\n");
        printf("O numero %d em BCD e:\n ", numero);
        BCD(numero,bcd);
        printf("\n");

        printf("Resultados Finais: \n");
        printf("Binário: %s\n", binario);
        printf("Octal: %s\n", octal);
        printf("Hexadecimal: %s\n", hexal);
        printf("BCD: %s\n", bcd);

        }
        else if(e==2){
            printf("Digite um numero decimal parar ser convertido em 16 bits: ");
            scanf("%hd", &numero2);
            impressao(numero2);
            printf("\n");
        }
        else if(e==3){


        }
        else{
            printf("Opção invalida");
        }

    }
    return 0;
}