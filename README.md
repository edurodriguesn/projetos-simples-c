# Projetos simples em C/C++ feitos durante a faculdade de Ciência da Computação na UNIFAP

## Como executar
- **Caso esteja no sistema Windows é necessário executar o seguinte passo:**
1. **Baixe o MinGW**: Vá para o [site oficial do MinGW](http://www.mingw.org/), baixe e execute o instalador.

2. **Adicione o MinGW ao Path**:
   - Adicione o diretório `bin` do MinGW ao PATH do sistema:
     - Abra o Painel de Controle > Sistema > Configurações avançadas do sistema > Variáveis de ambiente.
     - Na seção "Variáveis do sistema", encontre a variável "Path" e clique em "Editar".
     - Adicione o caminho para o diretório `bin` do MinGW (por exemplo, `C:\MinGW\bin`).

- Após isso abra o terminal, caminhe até a pasta do arquivo e execute os seguintes comandos:
1. **Compilação do código**
```bash
gcc -o Programa CodigoFonte.c
```
- No Windows deve ser adicionado .exe ao nome do programa após o "-o"

2. **Execução do programa compilado**

No Linux:
```bash
./Programa
```
No Windows:
```bash
Programa.exe
```

- Lembre-se de alterar os nomes de `Programa` e `CodigoFonte.c` ou `CodigoFonte.cpp` para os nomes verdadeiros.

