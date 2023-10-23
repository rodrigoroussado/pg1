/**
 * strtests.c
 * Este programa contém um conjunto de testes para validar as implementações
 * presentes no ficheiro "strutils.c".
 * 
 * ISEL, outubro de 2022
 * 
 * Build : gcc -Wall  -o strtests strtests.c strutils.c  
 * Execute : strtests
 *---------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

 
#include <limits.h>
#include "strutils.h"


static void print_error() {
    printf("FAIL!\n");
}

static void print_success() {
    printf("OK!\n");
}
 
static void show_word_array(word_t words[], int size) {
    printf("[");
    if (size > 0) {
        printf("'%s'", words[0]);
        for(int i=1; i < size; ++i) {
            printf(",'%s'",words[i]);
        }
    }
    printf("]");
}

 
// Snake to camel tests

 

int main() {
    
    printf("TRIM TESTS:\n");
    
     {  // an already empty string
       
        char line[] = "";
        char strimmed_line[20] = {0};
        str_trim(line, strimmed_line);
        
        if (strimmed_line[0] == 0) print_success();
        else print_error();
    }
    {  // a string with just spaces give an empty string
       
        char line[] = "     ";
        char strimmed_line[20];
        str_trim(line, strimmed_line);
        
        if (strimmed_line[0] == 0) print_success();
        else print_error();
    }
    
    {
        char line[] = "     hello", strimmed_line[10] = {0};
        str_trim(line, strimmed_line);
    
        printf("'%s'\n", strimmed_line);
    }
    {
        char line[] = "     hello    ", strimmed_line[10] = {0};
        str_trim(line, strimmed_line);
        printf("'%s'\n", strimmed_line);
    }
    
    // a more complete strim test
    {
        char line[] = "     hello,     world!   ", strimmed_line[20] = {0};
        str_trim(line, strimmed_line);
        printf("'%s'\n", strimmed_line);
    }
    
    printf("\nSNAKE TO CAMEL CASE TESTS:\n");
    {
        char snake_str[] = "some_var", camel_str[10] = {0};
        snake_2_camel_case(snake_str, camel_str);
        printf("'%s'\n", camel_str);
    }
    {
        char snake_str[] = "__", camel_str[3];
        snake_2_camel_case(snake_str, camel_str);
        printf("'%s'\n", camel_str); 
    }
    {
        char snake_str[] = "__var_start_end__with_underscores__", camel_str[20];
        snake_2_camel_case(snake_str, camel_str);
        printf("'%s'\n", camel_str);
    }

    printf("\nSPLIT TESTS:\n");
    { 
        char line[] = "";
        
        word_t words[5];
         
        int split_size = str_split(line, words, 5);
        if (split_size==0) {
            show_word_array(words, split_size);
            printf("\n");
        }
        else print_error();
    }
    { 
        char line[] = "one";
        
        word_t words[5];
         
        int split_size = str_split(line, words, 5);
        if (split_size==1) {
            show_word_array(words, split_size);
            printf("\n");
        }
        else print_error();
    }
    { 
        char line[] = "   a  simple    line    ";
        
        word_t words[5];
         
        int split_size = str_split(line, words, 5);
        if (split_size==3) {
            show_word_array(words, split_size);
            printf("\n");
        }
        else print_error();
    }
    { 
        char line[] = "   a  new simple    line    ";
        
        word_t words[5];
         
        int split_size = str_split(line, words, 5);
        if (split_size==4) {
            show_word_array(words, split_size);
            printf("\n");
        }
        else print_error();
    }
    
    printf("\nMIDDLE COMPRESSED TESTS:\n");
    {
        char orig[] = "      ";
        char result[100];
        
        if (!name_middle_compressed(orig, result)) print_success();
        else   print_error();
    }
    {
        char orig[] = "  pedro    ";
        char result[100];
        
        if (!name_middle_compressed(orig, result)) print_success();
        else   print_error();
    }
    {
        char orig[] = "  pedro manuel  de  rodrigues  ";
        char result[100];
        
        if (!name_middle_compressed(orig, result)) print_error();
        else   printf("'%s'\n", result);
    }
    
    {
        char orig[] = "  pedro manuel  vieira  rodrigues  ";
        char result[100];
        
        if (!name_middle_compressed(orig, result)) print_error();
        else   printf("'%s'\n", result);
    }
    {
        char orig[] = "  pedro     rodrigues  ";
        char result[100];
        
        if (!name_middle_compressed(orig, result)) print_error();
        else   printf("'%s'\n", result);
    }
    
    printf("\nANAGRAM TESTS:\n");
    {
        char str1[] = " amor";
        char str2[] = "ROMA";
        
        if (anagram(str1,str2)) print_success();
        else print_error();
    }
    {
        char str1[] = " setimo ANDAR";
        char str2[] = "desmontaria";
        
        if (anagram(str1,str2)) print_success();
        else print_error();
    }
    
    {
        char str1[] = "    rota1   ";
        char str2[] = "ator";
        
        if (!anagram(str1,str2)) print_success();
        else print_error();
    }
  
    {
        char str1[] = "";
        char str2[] = "";
        
        if (!anagram(str1,str2)) print_success();
        else print_error();
    }
  
    {
        char str1[] = "a";
        char str2[] = "A";
        
        if (!anagram(str1,str2)) print_success();
        else print_error();
    }
    {
        char str1[] = "aa";
        char str2[] = "AA";
        
        if (anagram(str1,str2)) print_success();
        else print_error();
    }
	return 0;
}
	


