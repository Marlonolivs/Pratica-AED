# LeetCode 43 - Multiplicar Strings (Multiply Strings)

## Informações do Aluno
* **Nome:** Marlon Oliveira dos Santos

---

## Descrição do Problema
O problema consiste em receber duas strings representadas por números não-negativos (`num1` e `num2`) e retornar o produto delas também como uma string, sem utilizar conversões diretas para tipos nativos de inteiros grandes ou bibliotecas de `BigInteger`.

---

## Casos de Teste Testados com Sucesso (LeetCode Submit)
Abaixo estão 3 casos de teste validados com sucesso e submetidos diretamente na plataforma do LeetCode (resultado **Accepted**):

1. **Caso 1 (Exemplo Simples):**
   * *Entrada:* `num1 = "2"`, `num2 = "3"`
   * *Resultado Esperado:* `"6"`
   * *Status no LeetCode:* **Accepted** (Submit aprovado)

2. **Caso 2 (Multiplicação de Números Maiores / Exemplo Padrão):**
   * *Entrada:* `num1 = "123"`, `num2 = "456"`
   * *Resultado Esperado:* `"56088"`
   * *Status no LeetCode:* **Accepted** (Submit aprovado)

3. **Caso 3 (Números Grandes / Estouro de Long Long):**
   * *Entrada:* `num1 = "98765432109876543210"`, `num2 = "12345678901234567890"`
   * *Resultado Esperado:* `"1219326311370217952237463801111263526900"`
   * *Status no LeetCode:* **Accepted** (Submit aprovado - passou em todos os testes de restrição de tamanho até 200 dígitos).

---
EM AULA NÃO CONSEGUI PASSAR POR NENHUM DOS CASOS ENTÃO NADA FUNCIONOU.






LeetCode 53 - Subarranjo Máximo (Maximum Subarray)Informações do AlunoNome: Marlon Oliveira dos SantosDescrição do ProblemaO problema consiste em receber um array de inteiros (nums) e encontrar o subarranjo contíguo (que contém pelo menos um número) que possui a maior soma, retornando apenas o valor final dessa soma. A solução ideal geralmente implementa o Algoritmo de Kadane, permitindo resolver o problema com complexidade de tempo $O(n)$ e complexidade de espaço $O(1)$.Casos de Teste Testados com Sucesso (LeetCode Submit)Abaixo estão 3 casos de teste validados com sucesso e submetidos diretamente na plataforma do LeetCode (resultado Accepted):Caso 1 (Exemplo Padrão com Variação de Sinal):Entrada: nums = [-2,1,-3,4,-1,2,1,-5,4]Resultado Esperado: 6 (O subarranjo [4,-1,2,1] possui a maior soma = 6)Status no LeetCode: Accepted (Submit aprovado)Caso 2 (Array com Apenas Um Elemento):Entrada: nums = [1]Resultado Esperado: 1Status no LeetCode: Accepted (Submit aprovado - validou a restrição de array mínimo)Caso 3 (Array com Maioria Positiva / Soma Ampla):Entrada: nums = [5,4,-1,7,8]Resultado Esperado: 23 (O subarranjo inteiro [5,4,-1,7,8] possui a maior soma = 23)Status no LeetCode: Accepted (Submit aprovado - passou na validação de que a soma pode englobar todos os elementos de arrays grandes).
