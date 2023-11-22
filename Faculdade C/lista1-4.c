#include <stdio.h>

float calcularvolume(float h,float r);

int main(){

    float altura,raio;

    printf("Digite a altura e o raio do cilindro: ");
    scanf("%f%f",&altura,&raio);

    float volume = calcularvolume(altura,raio);

    printf("Volume do cilindro: %.1f",volume);

    return 0;
}

float calcularvolume(float h,float r){

    float V=3.14159*(r*r)*h;
    return V;
    
}