#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int menu1 (){ //menu para selecionar o tipo de calculo desejado 
    int y;
    printf("\t BEM VINDO !!\n");
    printf("\t MENU...\n");
    printf("\t DIGITE UM COMANDO\n");
    printf("\t DIGITE 1 PARA CALCULOS COM A 1 LEI DE OHM E 2 PARA A 2\n");
    scanf("%d",&y);
    return y;
}
int menu2(int y){//menu para selecionar qual variavel devera ser calculada 
    int x;
    if (y ==1 )
    {
        printf(" 1. Descobrir a resistencia\n");
        printf(" 2. Descobrir a corrente\n");
        printf(" 3. Descobrir a tensao\n");
        printf(" 4. Descobrir a potencia\n");
        scanf("%d",&x);
        return x;
    }
    else {
        printf(" 1. Descobrir a resistencia do fio\n");
        printf(" 2. Descobrir a resistividade do material\n");
        printf(" 3. Descobrir o comprimento do fio\n");
        printf(" 4. Descobrir a espessura do fio\n");
        scanf("%d",&x);
        return x;
    } 
}
double somares(int quant ){ //função para calculos com mais uma resistencia 
    int x = 0,y;
    double soma = 0;
    do
    {
        double res =0;
        printf("DIGITE 1 PARA RESISTENCIA EM SERIE E 2 PARA EM PARALELO\n");
        scanf("%d",&y);
        printf("DIGITE O VALOR DA RESISTENCIA\n");
        scanf("%lf",&res);
        if (y ==1)
        {
            soma = soma +res;
        }
        else {
            soma = soma + 1/res;
        }
        x++;
    } while (x<quant);
   return soma;
}
//Funções para a 1° lei de Ohm
double resistencia(){ // função descobre resistencia 
    double c,t,r;
    
        printf("DIGITE O VALOR DA CORRENTE E DA TENSAO RESPECTIVAMENTE\n");
        scanf("%lf %lf",&c, &t);
        r = t / c ;
        return r;
}
double potencia(){// função descobre potencia 
    double c,t,p;
    
        printf("DIGITE O VALOR DA CORRENTE E DA TENSAO RESPECTIVAMENTE\n");
        scanf("%lf %lf",&c, &t);
        p = t * c ;
        return p;
}
double corrente(){ // função descobre corrente 
    double c,t,r, result =0;
    int x,quant;
    printf("DIGITE 1 CASO SO TENHA 1 RESISTENCIA E 2 PARA MAIS  \n");
    scanf("%d",&x);
    switch (x)
    {
    case 1: // caso so tenha uma resistencia vai direto para o codigo padrão 
        printf("DIGITE O VALOR DA RESISTENCIA E DA TENSAO RESPECTIVAMENTE\n");
        scanf("%lf %lf",&r, &t);
        c = t / r ;
        return c;
        break;
    case 2: // caso tenha mais de uma vai para a função que soma as resistencias 
        printf("DIGITE A QUANTIDADE DE RESISTECIAS \n");
        scanf("%d",&quant);
        result = somares(quant);
        printf("DIGITE O VALOR DA TENSAO\n");
        scanf("%lf", &t);
        c = t /result ;
        return c;
        break;
    default:
        return 1;
        break;
    }

}

double tensao(){ // função descobre tensão 
    double c,t,r, result =0;
    int x,quant;
    printf("DIGITE 1 CASO SO TENHA 1 RESISTENCIA E 2 PARA MAIS  \n");
    scanf("%d",&x);
    switch (x)
    {
    case 1:
        printf("DIGITE O VALOR DA RESISTENCIA E DA CORRENTE RESPECTIVAMENTE\n");
        scanf("%lf %lf",&r, &c);
        t = c *r ;
        return t;
        break;
    case 2:
        printf("DIGITE A QUANTIDADE DE RESISTECIAS \n");
        scanf("%d",&quant);
        result = somares(quant);
        printf("DIGITE O VALOR DA CORRENTE \n");
        scanf("%lf", &t);
        t = c * result ;
        return t;
        break;
    default:
        return 1;
        break;
    }
}
//Funções para a segunda lei 
double resistenciaf(){
    double rf,rs,c,e;
    printf("DIGITE O VALOR DA RESISTIVDADE,COMPRIMENTO E ESPESSURA RESPECTIVAMENTE\n");
    scanf("%lf %lf %lf",&rs,&c, &e);
    rf = (rs * c)/e; // formula
    return rf;
}
double espessura(){
    double rf,rs,c,e;
    printf("DIGITE O VALOR DA RESISTIVDADE,COMPRIMENTO E RESISTENCIA RESPECTIVAMENTE\n");
    scanf("%lf %lf %lf",&rs,&c, &rf);
    e = (rs * c)/rf; //formula 
    return e;
}
double comprimento(){
    double rf,rs,c,e;
    printf("DIGITE O VALOR DA RESISTIVDADE,ESPESSURA E RESISTENCIA RESPECTIVAMENTE\n");
    scanf("%lf %lf %lf",&rs,&e, &rf);
    c = (rf * e)/rs; //formula
    return c;
}

double resistividade(){
    double rf,rs,c,e;
    printf("DIGITE O VALOR DA COMPRIMENTO,ESPESSURA E RESISTENCIA RESPECTIVAMENTE\n");
    scanf("%lf %lf %lf",&c,&e, &rf);
    rs = (rf * e)/c;//formula
    return rs;
}

// Função main que chama as demais funçãoes e imprime o resultado 
int main(){
    int y,x;
    double result =0;
    y = menu1();//chama o menu que seleciona qual lei será usada 
    x = menu2(y);// chama o menu que seleciona qual será a incógnita 
    if (y ==1)//caso seja a primeira lei
    {
        switch (x)
        {
        case 1:
            result= resistencia();
            printf(" %lf ohms",result);
            break;
        case 2:
            result= corrente();
            printf(" %lf amperes",result);
            break;

        case 3:
            result= tensao();
            printf(" %lf volts",result);
            break;
        case 4:
            result= potencia();
            printf(" %lf watts",result);
            break;
        default:
            break;
        }
    }
    
    else if (y ==2) // caso seja a segunda lei
    {
        switch (x)
        {
        case 1:
            result= resistenciaf();
            printf(" %lf ohms",result);
            break;
        case 2:
            result= resistividade();
            printf(" %lf ohms.metro",result);
            break;

        case 3:
            result= comprimento();
            printf(" %lf metros ",result);
            break;

        case 4:
            result= espessura();
            printf(" %lf metros quadrados ",result);
            break;
        default:
            break;
        }
    }
return 0;    
}