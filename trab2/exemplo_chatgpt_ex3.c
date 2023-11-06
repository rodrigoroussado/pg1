#include <stdio.h>
#include <string.h>

int main() {
    FILE *file1, *file2, *output;
    char line[1000];
    
    file1 = fopen("subtitle1.srt", "r");
    file2 = fopen("subtitle2.srt", "r");
    output = fopen("merged_subtitle.srt", "w");

    if (file1 == NULL || file2 == NULL || output == NULL) {
        printf("Erro ao abrir os arquivos.\n");
        return 1;
    }

    int subtitle_number = 1;
    
    while (1) {
        char c = fgetc(file1);
        if (c == EOF) break;
        
        // Read and write subtitle number
        fprintf(output, "%d\n", subtitle_number);
        
        // Read and write the timecodes
        fgets(line, sizeof(line), file1);
        fputs(line, output);
        
        // Read and write the subtitle text
        while (fgets(line, sizeof(line), file1) && strcmp(line, "\n") != 0) {
            fputs(line, output);
        }
        
        // Repeat the above process for the second subtitle file
        c = fgetc(file2);
        if (c == EOF) break;
        
        fprintf(output, "%d\n", subtitle_number);
        
        fgets(line, sizeof(line), file2);
        fputs(line, output);
        
        while (fgets(line, sizeof(line), file2) && strcmp(line, "\n") != 0) {
            fputs(line, output);
        }
        
        // Add an empty line between subtitles
        fputs("\n", output);
        
        subtitle_number++;
    }
    
    fclose(file1);
    fclose(file2);
    fclose(output);
    
    printf("Arquivos mesclados com sucesso.\n");
    
    return 0;
}
