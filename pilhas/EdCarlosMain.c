#include "Stack.h"
#include <stdio.h>

int main() {
    Stack* estacionamentoPrincipal = create();
    Stack* estacionamentoSecundario = create();
    // Criados os dois estacionamentos
    int id;
    char comando;

    printf("Insira os comandos (i-inserir ou r-remoção) e IDs (ex: i 10, r 9). Finalize com f:\n");
    while (1) {
        // Lê o comando
        if (scanf(" %c", &comando) != 1) {
            printf("Erro ao ler comando. Finalizando...\n");
            break;
        }

        // Verifica se o comando é para finalizar
        if (comando == 'f') {
            printf("Finalizando o programa.\n");
            break;
        }

        // Processa o comando:
        if (comando == 'i') {
            // Lê o ID do carro a ser inserido
            if (scanf("%d", &id) != 1) {
                printf("Erro ao ler ID. Finalizando...\n");
                break;
            }
            if (!push(estacionamentoPrincipal, id)) {
                printf("Overflow, não foi possível inserir o id %d\n", id);
            }
        } else if (comando == 'r') {
            // Lê o ID do carro a ser removido
            if (scanf("%d", &id) != 1) {
                printf("Erro ao ler ID. Finalizando...\n");
                break;
            }
            if(!remover_carro(estacionamentoPrincipal,estacionamentoSecundario, id)){
                printf("Estacionamento errado!\n");
            }
            else{
                printf("Removendo o carro com ID %d .\n", id);
            }
        } else {
            printf("Comando inválido: %c\n", comando);
        }
    }
    printf("A pilha ficou:\n");
    print_stack(estacionamentoPrincipal);
    destroy(estacionamentoPrincipal);
    destroy(estacionamentoSecundario);
    return 0;
}
