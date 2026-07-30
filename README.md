# Simuladores de escalonamento de processos

Projeto acadêmico da disciplina de Sistemas Operacionais com implementações, em C, de quatro estratégias de escalonamento de CPU.

## Algoritmos

| Arquivo | Estratégia | Comportamento demonstrado |
| --- | --- | --- |
| `src/fcfs.c` | FCFS | Ordena por chegada e calcula conclusão, espera e retorno |
| `src/sjf.c` | SJF simplificado | Ordena por chegada e usa o menor burst como desempate |
| `src/roundrobin.c` | Round Robin | Percorre uma lista circular e desconta um quantum por ciclo |
| `src/priority.c` | Prioridade | Executa primeiro a menor prioridade numérica |

## Tecnologias e conceitos

- Linguagem C;
- estruturas, arrays e ponteiros;
- lista encadeada circular;
- alocação dinâmica;
- tempo de espera e turnaround;
- visualização textual de execução.

## Como compilar e executar

Requisitos: compilador compatível com C99, como GCC.

```bash
git clone https://github.com/felipeand-dev/Projeto_Escalonamento_SO.git
cd Projeto_Escalonamento_SO
```

Compile o algoritmo desejado:

```bash
gcc -std=c99 -Wall -Wextra src/fcfs.c -o fcfs
gcc -std=c99 -Wall -Wextra src/sjf.c -o sjf
gcc -std=c99 -Wall -Wextra src/roundrobin.c -o roundrobin
gcc -std=c99 -Wall -Wextra src/priority.c -o priority
```

Execute, por exemplo:

```bash
./fcfs
```

No Windows, use o executável correspondente, como `fcfs.exe`.

## Limitações didáticas

- FCFS e SJF usam arrays com capacidade para até 10 processos;
- o SJF implementado é uma versão simplificada, sem reavaliar dinamicamente a fila;
- as simulações recebem dados pelo terminal e não persistem resultados;
- os programas priorizam a demonstração dos algoritmos, não uma simulação completa de kernel.

## Equipe

| Algoritmo | Responsável |
| --- | --- |
| FCFS | Felipe Andrade dos Santos Carvalho |
| SJF | Marcos Henrique Brito Souza |
| Round Robin | Daniel da Silva Oliveira |
| Prioridade | Arthur Guimarães Miranda Prates |

Projeto do curso de Análise e Desenvolvimento de Sistemas do IF Baiano — Campus Guanambi.

