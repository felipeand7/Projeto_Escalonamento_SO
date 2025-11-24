#include <stdio.h>

struct Processo {
    int id;      
    int chegada; 
    int burst;   
};

int main() {
    int n;
    printf("Quantos processos? ");
    scanf("%d", &n);

    struct Processo p[10]; 

    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        printf("\nProcesso P%d\n", p[i].id);
        printf(" Tempo de chegada: ");
        scanf("%d", &p[i].chegada);
        printf(" Tempo de burst: ");
        scanf("%d", &p[i].burst);
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int troca = 0;

            if (p[j].chegada < p[i].chegada) {
                troca = 1;
            } else if (p[j].chegada == p[i].chegada &&
                       p[j].burst < p[i].burst) {
                troca = 1;
            }

            if (troca) {
                struct Processo temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    printf("\nOrdem de execucao (SJF simplificado): ");
    for (int i = 0; i < n; i++) {
        printf("P%d ", p[i].id);
    }
    printf("\n");


    printf("\nID\tCheg.\tBurst\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\n", p[i].id, p[i].chegada, p[i].burst);
    }

    return 0;
}
