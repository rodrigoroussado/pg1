#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file1, *file2, *output;
    char line[1000];

    // Abre os dois arquivos .srt para leitura
    file1 = fopen("padrinho2_1.srt", "r");
    file2 = fopen("padrinho2_2.srt", "r");

    if (file1 == NULL || file2 == NULL) {
        perror("Erro ao abrir um dos arquivos.");
        exit(EXIT_FAILURE);
    }

    // Abre o arquivo de saída para escrita
    output = fopen("output.srt", "w");
    if (output == NULL) {
        perror("Erro ao abrir o arquivo de saída.");
        exit(EXIT_FAILURE);
    }

    // Processa o primeiro arquivo .srt
    while (fgets(line, sizeof(line), file1) != NULL) {
        fprintf(output, "%s", line);

        // Verifica se a linha contém o número da legenda e o tempo
        if (sscanf(line, "%*d:%*d:%*d,%*d --> %*d:%*d:%*d,%*d") == 0) {
            // Incrementa o número da legenda
            int number;
            sscanf(line, "%d", &number);
            
        }
    }

    // Adiciona uma linha em branco para separar os conteúdos
    fprintf(output, "\n");

    // Processa o segundo arquivo .srt
    while (fgets(line, sizeof(line), file2) != NULL) {
        fprintf(output, "%s", line);

        // Verifica se a linha contém o número da legenda e o tempo
        if (sscanf(line, "%*d:%*d:%*d,%*d --> %*d:%*d:%*d,%*d") == 0) {
            // Incrementa o número da legenda
            int number;
            sscanf(line, "%d", &number);
            
        }
    }

    // Fecha os arquivos
    fclose(file1);
    fclose(file2);
    fclose(output);

    printf("Arquivos .srt combinados com sucesso!\n");

    return 0;
}
