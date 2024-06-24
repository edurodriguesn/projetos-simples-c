# Objetivo do programa
A função de Ackermann é um exemplo clássico de uma função recursiva não primitiva, que significa que ela não pode ser expressa usando apenas recursão primitiva (um tipo mais simples de recursão). É usada para testar limites de algoritmos de recursão e para ilustrar a complexidade de diferentes tipos de funções recursivas.

## Funções auxiliares
- A função de Ackermann, A(m,n), é definida por três regras diferentes, dependendo dos valores de m e n:
1. Se m=0: A função simplesmente retorna n+1. Isso é uma condição de parada direta.
2. Se m>0 e n=0: A função chama a si mesma com m diminuído em 1 e n igual a 1.
3. Se m>0 e n>0: A função chama a si mesma duas vezes. Primeiro, com os mesmos valores de m e n diminuído em 1, e então usa o resultado dessa chamada como o segundo argumento em uma nova chamada, com m diminuído em 1.

## Melhorias a serem feitas
- 