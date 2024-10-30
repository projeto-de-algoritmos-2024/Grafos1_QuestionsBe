#include <stdio.h>

//struct para representar uma mediçao de anomalia 
typedef struct{
    int x , y; //Cordenada da mediçoes
    int anomalia; //Valor da anomalia;
} Mediçao; 

//struct para representar a consulta de anomalia
typedef struct{
    int x , y; // Cordenada da consulta 
} Consulta;



int main(){
    //variaveis que vao salvar as quantidades de consultas e mediçoes 
    int M,C;
    scanf("%d %d",&M,&C);

    // criando as structs 
    Mediçao medicoes[M];
    Consulta consultas[C];

    //leitura das medicoes
    for (int i=0; i<M; i++){
        int x,y,a;
        scanf("%d %d %d",&x,&y,&a);
        medicoes[i].x = x;
        medicoes[i].y = y;
        medicoes[i].anomalia = a;
    }

    for (int i=0;i<C;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        consultas[i].x = x;
        consultas[i].y = y;
    }
    
    
    return 0;



}