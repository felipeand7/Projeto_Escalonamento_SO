#include <stdio.h>
#include <stdlib.h>

typedef struct processo {
    int id;
    double tempo_execucao;
    double tempo_original;
    struct processo *proximo;
} processo;

// Prototipos das funcoes
void inserir_processo(processo **inicio, int id, double tempo);
int contar_processos(processo *inicio);
void simular_rr(processo *inicio, double quantum);

int main() {
    processo *inicio = NULL;
    int num_processos;
    double quantum, tempo;
    
    printf("====| SIMULADOR DE ESCALONAMENTO ROUND ROBIN |====\n");
    printf("Quantidade de processos: ");
    scanf("%d", &num_processos);
    
    printf("\n=== Cadastro de Processos ===\n");
    for (int i = 1; i <= num_processos; i++) {
        printf("\nProcesso %d:\n", i);
        printf("  Tempo de execucao (em segundos): ");
        scanf("%lf", &tempo);
        inserir_processo(&inicio, i, tempo);
        printf("  Processo %d cadastrado com %.3f segundos\n", i, tempo);
    }
    
    printf("\n");
    printf("Defina o tempo do Quantum (em segundos): ");
    scanf("%lf", &quantum);
    
    simular_rr(inicio, quantum);
    
    return 0;
}

// Insere processo na lista circular
void inserir_processo(processo **inicio, int id, double tempo) {
    processo *novo = (processo*)malloc(sizeof(processo));
    novo->id = id;
    novo->tempo_execucao = tempo;
    novo->tempo_original = tempo;
    
    if (*inicio == NULL) {
        *inicio = novo;
        novo->proximo = novo;
    } else {
        processo *atual = *inicio;
        while (atual->proximo != *inicio) {
            atual = atual->proximo;
        }
        atual->proximo = novo;
        novo->proximo = *inicio;
    }
}

// conta quantos processos ainda estao ativos tempo > 0
int contar_processos(processo *inicio) {
    if (inicio == NULL) return 0;
    int count = 0;
    processo *atual = inicio;
    do {
        if (atual->tempo_execucao > 0) {
            count++;
        }
        atual = atual->proximo;
    } while (atual != inicio);
    
    return count;
}

// Simula o escalonamento Round Robin
void simular_rr(processo *inicio, double quantum) {
    int clock = 0;
    
    printf("===|INICIANDO SIMULACAO ROUND ROBIN|===\n");
    printf("Quantum: %.3f segundos\n\n", quantum);
    
    while (contar_processos(inicio) > 0) {
        clock++;
        printf("\n===== Clock %d =====\n", clock);
        
        processo *atual = inicio;
        processo *primeiro = inicio;
        
        do {
            if (atual->tempo_execucao > 0) {
                printf("Processo ID %d: %.3fs -> ", atual->id, atual->tempo_execucao);
                // Subtrai o quantum
                atual->tempo_execucao -= quantum;
                if (atual->tempo_execucao <= 0) {
                    printf("0.00s [FINALIZADO]\n");
                } else {
                    printf("%.3fs\n", atual->tempo_execucao);
                }
            }
            atual = atual->proximo;
        } while (atual != primeiro);
    }
    
    printf("\n========================================\n");
    printf("TODOS OS PROCESSOS FINALIZADOS\n");
    printf("Total de clocks: %d\n", clock);
    printf("========================================\n");
}