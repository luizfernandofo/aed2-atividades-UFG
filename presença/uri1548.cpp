#include<iostream>

#define MAX 1000

void swapAlunos(int *a1, int *a2){

    int temp;

    temp = *a1;
    *a1 = *a2;
    *a2 = temp;

    return;

}


int main(void){

    int alunos[MAX], alunos2[MAX];

    int i, j, k, cases, fila, trocados; //counters

    std::cin >> cases;

    for( i = 0; i < cases; i++){

        std::cin >> fila;
        trocados = 0;

       for( j = 0; j < fila; j++){
            std::cin >> alunos[j];
            alunos2[j] = alunos[j];
       }

       for( j = 0; j < fila - 1; j++){
           for( k = j + 1; k < fila; k++){

               if(alunos[j] < alunos[k]) swapAlunos(&(alunos[j]), &(alunos[k]));
           
            }
        }

        for( j = 0; j < fila; j++){
            if(alunos[j] == alunos2[j]) trocados++;
        }

        std::cout << trocados << std::endl;   

    }
    
    return 0;
}