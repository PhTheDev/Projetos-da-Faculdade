#include <stdio.h>

float calcularesfera(float r);

int main(){

    float raio,esfera;

    printf("Digite o raio da esfera: ");
    scanf("%f",&raio);
    
    esfera = calcularesfera(raio);

    printf("Volume da esfera de raio %.1f: %.1f\n",raio,esfera);

    return 0;

}

float calcularesfera(float r){

    float e = (4/3)*3.14159*(r*r*r);

    return e;

}