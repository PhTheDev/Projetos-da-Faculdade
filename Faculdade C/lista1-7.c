#include <stdio.h>

int horarioParaSegundos(int horas, int minutos, int segundos);

int main() {
    int horas, minutos, segundos;

    printf("Digite as horas: ");
    scanf("%d", &horas);
    printf("Digite os minutos: ");
    scanf("%d", &minutos);
    printf("Digite os segundos: ");
    scanf("%d", &segundos);

    int totalSegundos = horarioParaSegundos(horas, minutos, segundos);

    printf("O horario convertido em segundos e: %d segundos\n", totalSegundos);

    return 0;
}

int horarioParaSegundos(int horas, int minutos, int segundos) {
    int totalSegundos = 0;

    totalSegundos += horas * 3600;
    totalSegundos += minutos * 60;
    totalSegundos += segundos;

    return totalSegundos;
}
