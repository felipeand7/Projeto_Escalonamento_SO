#include <stdio.h>
#include <string.h>

int main() {
    int num_processos, i, j;
    int tempo_chegada[10], tempo_execucao[10], tempo_espera[10];
    int tempo_retorno[10], tempo_conclusao[10];
    float media_espera = 0, media_retorno = 0;
    char nome_processo[10][10];
    
    printf("\n=== ALGORITMO FCFS - FIRST COME FIRST SERVED ===\n");
    printf("\nDigite o numero de processos (max 10): ");
    scanf("%d", &num_processos);
    
    // Entrada de dados
    for(i = 0; i < num_processos; i++) {
        printf("\n--- Processo %d ---", i+1);
        printf("\nNome do processo: ");
        scanf("%9s", nome_processo[i]);
        printf("Tempo de chegada: ");
        scanf("%d", &tempo_chegada[i]);
        printf("Tempo de execucao (burst): ");
        scanf("%d", &tempo_execucao[i]);
    }
    
    // ORDENAR por tempo de chegada (FCFS = First Come First Served)
    for(i = 0; i < num_processos - 1; i++) {
        for(j = i + 1; j < num_processos; j++) {
            if(tempo_chegada[i] > tempo_chegada[j]) {
                // Trocar tempo_chegada
                int temp = tempo_chegada[i];
                tempo_chegada[i] = tempo_chegada[j];
                tempo_chegada[j] = temp;
                
                // Trocar tempo_execucao
                temp = tempo_execucao[i];
                tempo_execucao[i] = tempo_execucao[j];
                tempo_execucao[j] = temp;
                
                // Trocar nome
                char temp_nome[10];
                strcpy(temp_nome, nome_processo[i]);
                strcpy(nome_processo[i], nome_processo[j]);
                strcpy(nome_processo[j], temp_nome);
            }
        }
    }
    
    // Cálculo dos tempos
    tempo_conclusao[0] = tempo_chegada[0] + tempo_execucao[0];
    tempo_retorno[0] = tempo_conclusao[0] - tempo_chegada[0];
    tempo_espera[0] = tempo_retorno[0] - tempo_execucao[0];
    
    for(i = 1; i < num_processos; i++) {
        // Se processo chega depois que anterior termina
        if(tempo_conclusao[i-1] < tempo_chegada[i]) {
            tempo_conclusao[i] = tempo_chegada[i] + tempo_execucao[i];
        } else {
            tempo_conclusao[i] = tempo_conclusao[i-1] + tempo_execucao[i];
        }
        
        tempo_retorno[i] = tempo_conclusao[i] - tempo_chegada[i];
        tempo_espera[i] = tempo_retorno[i] - tempo_execucao[i];
    }
    
    // Exibir Gantt Chart
    printf("\n\n========== GANTT CHART ==========\n");
    printf("|");
    for(i = 0; i < num_processos; i++) {
        printf("  %-6s  |", nome_processo[i]);
    }
    printf("\n");
    
    // Linha de tempo
    printf("%d", tempo_chegada[0]);
    for(i = 0; i < num_processos; i++) {
        printf("       %3d", tempo_conclusao[i]);
    }
    printf("\n==================================\n");
    
    // Tabela de resultados
    printf("\n==============================================================================\n");
    printf("%-10s\t%-8s\t%-8s\t%-8s\t%-8s\t%-10s\n", 
           "Processo", "Chegada", "Execucao", "Espera", "Retorno", "Conclusao");
    printf("==============================================================================\n");
    
    for(i = 0; i < num_processos; i++) {
        printf("%-10s\t%-8d\t%-8d\t%-8d\t%-8d\t%-10d\n", 
               nome_processo[i],
               tempo_chegada[i],
               tempo_execucao[i],
               tempo_espera[i],
               tempo_retorno[i],
               tempo_conclusao[i]);
        
        media_espera += tempo_espera[i];
        media_retorno += tempo_retorno[i];
    }
    
    printf("==============================================================================\n");
    
    // Médias
    media_espera = media_espera / num_processos;
    media_retorno = media_retorno / num_processos;
    
    printf("\n*** METRICAS DE DESEMPENHO ***\n");
    printf("Tempo medio de espera: %.2f\n", media_espera);
    printf("Tempo medio de retorno: %.2f\n", media_retorno);
    printf("\n");
    
    return 0;
}
