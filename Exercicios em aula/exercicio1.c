#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void exibirMeunu();
void adicionarNome(char **buffer);
void removerNome(char **buffer);
void listarNome(const char *buffer);

int main(){

    char *buffer = NULL; // ARMAZENA TUDO EM UMA UNICA STRING   
    int opcao;

    do{
        exibirMeunu();
        printf("opcao");
        scanf("%d", &opcao);

        switch (opcao)
        {
            case 1:
                adicionarNome(&buffer);
                break;

            case 2:
                removerNome(&buffer);
                break;

            case 3:
                listarNome(buffer);
                break;

            case 4:
            printf("\nEncerrando o programa...\n");
                if (buffer != NULL) {
                    free(buffer); // Libera a memória ao encerrar
                    buffer = NULL;
                }
                break;
                default:
                printf("\nOpcao invalida!\n");
        }
        }while (opcao != 4);
    }


void exibirMeunu(){

    printf("=======Menu========\n");
    printf("1: adicionar nome\n");
    printf("2: remover nome\n");
    printf("3: listar nome\n");
    printf("4: sair\n");
    printf("===================\n");
}
void adicionarNome(char **buffer){
    char novonome[50];

    printf("\nInforme o nome que deseja adicionar\n");
    scanf(" %[^\n]", novonome);

    int tamNovo = strlen(novonome)+1; // +1 por causa do \0
    int tamAtual = 0;

    if(*buffer != NULL){
        tamAtual = strlen(*buffer);
        // Verifica se já existe uma string e obtém seu tamanho atual
    }

    char *temp = (char*)realloc(*buffer,tamAtual+tamNovo+1);
    // Realoca o buffer para aumentar o espaco de memoria e armazena o novo endereco em tem

    if(temp == NULL){
        printf("erro ao alocar memoria\n");
        return ;
        // Se temp for NULL, significa que não foi possível alocar a memória solicitada
    }

    *buffer = temp;
    //ponteiro original passa a apontar para a nova area
    //antes:*buffer ---> memória antiga
    //temp ---> nova memoria
    // buffer ---> nova memoria

    if(tamAtual == 0){
        (*buffer)[0] = '\0';
        // Se o buffer estiver vazio, coloca o caractere '\0'
    // na primeira posição para indicar o final da string
    }

    //strcat liga o final de uma string em outra
    strcat(*buffer, novonome);
    strcat(*buffer, ";");
     // exemplo joao;maria

    printf("Nome adiconado com sucesso\n");

}
void removerNome(char **buffer){

    if(*buffer == NULL || strlen(*buffer)== 0){
        //*buffer == NULL igual a não existe memoria
        // strlem(*buffer)== 0 igual a existe uma string vazia

        printf("nenhum nome cadastrado\n");
    }

    char busca[50];
    printf("informe o numero que deseja remover\n");
    scanf(" %[\n]", busca);

    //strstr()procura uma string dentro de outra string
    char *posicao = strstr(*buffer, busca);

    if(posicao == NULL || posicao[strlen(busca)] != ';'){
        // posicao == NULL igual a o nome nao foi encontrado
    }

    int tamRemover = strlen(busca)+1;
    // Calcula o tamanho do texto a ser removido, incluindo o '\0'

    int i;

    for( i = 0; posicao[i + tamRemover] != '\0'; i++){
           // Desloca os caracteres para a esquerda, sobrescrevendo o texto removido 
        posicao[i] = posicao[i + tamRemover];
    }

    // Calcula o novo tamanho da string após a remoção
    int novoTamanho = strlen(*buffer);

    if(novoTamanho == 0){

        //free libera de memoria 
        free(*buffer);

        // Define o buffer como NULL, indicando que n�o h� mem�ria alocada
        *buffer = NULL;
    }else{
    
    // Redimensiona a memória do buffer para o novo tamanho da string
    *buffer = (char *) realloc(*buffer, novoTamanho + 1);
    }

    printf("Nome '%s1' removido com sucesso!\n",busca);
}
void listarNome(const char *buffer){

    // Verifica se o buffer nao existe ou se a string esta vazia
    if(buffer == NULL || strlen(buffer)==0){
        //buffer == NULL verifica se o ponteiro não aponta para uma memória válida
        //strlen(buffer) == 0  verifica se a string está vazia
        printf("\nNenhum nome cadastrado\n");
        return;


    }

    printf("\n--- Lista de Nomes ---\n");
    int contador = 1;
    printf("%d - ", contador);

    for (int i = 0; buffer[i] != '\0'; i++) {
         // Percorre a string at� encontrar o final '\0'
        if (buffer[i] == ';') {
             // Quando encontra ';', verifica se ainda existem caracteres depois
            if (buffer[i + 1] != '\0') {
                   // Conta o pr�ximo nome e exibe sua numera��o
                contador++;
                printf("\n%d - ", contador);
            }
        } else {
            // Exibe na tela o caractere atual do buffer
            printf("%c", buffer[i]);
        }
    }
    printf("\n");
}

