// Função que remove os parênteses mais externos de cada bloco válido.
// Lógica principal: Usa um contador de "profundidade" para saber se 
// o parêntese atual é uma borda (profundidade 0) ou parte do miolo.
char* removeOuterParentheses(char* s) {
    
    // 1. Descobre o tamanho da string original para sabermos até onde ler
    int len = strlen(s);

    // 2. Aloca memória dinâmica para a nova string. 
    // O "+ 1" garante o espaço para o '\0' (terminador de string em C).
    char* res = (char*)malloc((len + 1) * sizeof(char));

    // 3. Variáveis de controle:
    // 'profundidade': Controla quantas "caixas" estão abertas. 0 = lado de fora.
    int profundidade = 0;
    
    // 'j': Índice exclusivo para a nova string (res). 
    // Como vamos pular as bordas, 'j' vai andar mais devagar que o 'i'.
    int j = 0;

    // 4. Percorre a string original caractere por caractere
    for(int i = 0; i < len ; i++){

        // Caso A: Encontramos uma abertura de parêntese
        if(s[i] == '('){
             // Se profundidade > 0, já passamos da borda inicial. É o miolo!
             if(profundidade > 0){
                res[j] = s[i];   // Copia o caractere
                j++;             // Avança a posição na string nova
             }
          
             // Registra que "entramos" em mais uma camada
             profundidade++;
             
        // Caso B: Encontramos um fechamento de parêntese
        }else if(s[i] == ')'){
            // Registra que "saímos" de uma camada
            profundidade--;
            
            // Se a profundidade ainda for > 0, significa que NÃO fechamos 
            // a caixa mais externa. Logo, é o miolo e devemos copiar!
            if(profundidade > 0){
                res[j] = s[i];
                j++;
            }
        }
    }

    // 5. Coloca o terminador nulo na última posição escrita
    // Isso avisa ao C que a string acabou aqui, evitando "lixo de memória"
    res[j] = '\0';
    
    // Retorna a nova string tratada
    return res;
}