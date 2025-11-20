#include <stdio.h>

int main() {
    int n;

    printf("Quantidade de processos: ");
    scanf("%d", &n);

    int burstTime[n];       // tempo de execução (CPU burst)
    int prioridade[n];      // prioridade de cada processo
    int ID[n];      // identificador do processo (P1, P2, P3...)
    int waitingTime[n];     // tempo de espera de cada processo
    int turnaround[n];      // tempo de retorno (WT + BT)

    // entrar com os valores
    for (int i = 0; i < n; i++) {
        ID[i] = i + 1; 

        printf("Burst time do Processo %d: ", i + 1);
        scanf("%d", &burstTime[i]);

        printf("Prioridade do Processo %d: ", i + 1);
        scanf("%d", &prioridade[i]);
    }

    // Ordenação por prioridade (menor número = maior prioridade)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (prioridade[j] > prioridade[j + 1]) {

                // trocando prioridade
                int temp = prioridade[j];
                prioridade[j] = prioridade[j + 1];
                prioridade[j + 1] = temp;

                // trocando burst time
                temp = burstTime[j];
                burstTime[j] = burstTime[j + 1];
                burstTime[j + 1] = temp;

                // trocando processoID
                temp = ID[j];
                ID[j] = ID[j + 1];
                ID[j + 1] = temp;
            }
        }
    }

    // Calcula o tempo de espera
    waitingTime[0] = 0; // primeiro processo nunca espera, por isso comeca em 0.

    for (int i = 1; i < n; i++){
        waitingTime[i] = waitingTime[i - 1] + burstTime[i - 1];
    }

    // Calcula o tempo de retorno
    for (int i = 0; i < n; i++){
        turnaround[i] = waitingTime[i] + burstTime[i];
    }
    
   // Imprime o resultado
    printf("\nProcesso | Prioridade | Burst | Espera | Turnaround\n");
    printf("------------------------------------------------------\n");

    for (int i = 0; i < n; i++) {
        printf("P%-7d | %-10d | %-5d | %-6d | %-10d\n",
            ID[i],
            prioridade[i],
            burstTime[i],
            waitingTime[i],
            turnaround[i]);
    }

    return 0;
}