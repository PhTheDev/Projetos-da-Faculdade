#include <stdio.h>

float calcularIMC(float p,float h);

int main(){

    float peso,altura,IMC;

    printf("Digite o peso(quilos) e a altura(metros) de uma pessoa: ");
    scanf("%f%f",&peso,&altura);

    IMC = calcularIMC(peso,altura);

    printf("o IMC ideal dessa pessoa e: %.1f",IMC);

    return 0;
}

float calcularIMC(float p,float h){

    float imc = p/(h*h);

    return imc;

}