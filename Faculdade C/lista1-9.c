#include <stdio.h>

float calcularMedia(float nota1, float nota2, float nota3, char tipoMedia);

int main() {
    float nota1, nota2, nota3;
    char tipoMedia;
    float media;

    printf("Digite as tres notas do aluno: ");
    scanf("%f %f %f", &nota1, &nota2, &nota3);

    printf("Digite 'A' para media aritmetica ou 'P' para media ponderada: ");
    scanf(" %c", &tipoMedia);

    media = calcularMedia(nota1, nota2, nota3, tipoMedia);

    if (media >= 0) {
        printf("A media do aluno e: %.2f\n", media);
    }

    return 0;
}

float calcularMedia(float nota1, float nota2, float nota3, char tipoMedia) {
    float media;

    if (tipoMedia == 'A') {
        
        media = (nota1 + nota2 + nota3) / 3;
    } else if (tipoMedia == 'P') {
        
        media = (5 * nota1 + 3 * nota2 + 2 * nota3) / (5 + 3 + 2);
    } else {
    
        printf("Tipo de media desconhecido. Use 'A' para media aritmetica ou 'P' para media ponderada.\n");
        media = -1;
    }

    return media;
}
