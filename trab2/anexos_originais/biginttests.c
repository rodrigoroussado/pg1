#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "bigint.h"
 
 

/*--------------------------------------
 * Início dos testes
 *--------------------------------------*/

static void show_byte_array(byte a[], int size) {
    printf("[");
    if (size > 0) {
        if (size > 100) {
            printf("OVERFLOW");
        }
        else {
            printf("%d", a[0]);
            for(int i=1; i < size; ++i) {
                printf(",%d", a[i]);
            }
        }
    }
    printf("]\n");
}


static void print_error() {
    printf("FAIL!\n");
}

static void print_success() {
    printf("OK!\n");
}

int main() {
    printf("BIGINT SHOW TESTS:\n");
    {
        BIG_INT b1 = { 3, 0, 0, 1 };
        
        big_show(b1);
        printf("\n");
        
    }
    {
        BIG_INT b1 = { 1, 0 };
        
        big_show(b1);
        printf("\n");
    }
    {
        BIG_INT b1 = { 10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
        
        big_show(b1);
        printf("\n");
      
    }
    
    printf("\nBIGINT COPY TESTS:\n");
    {
        BIG_INT b1 = { 3, 0, 0, 1 }, b2 = { 1, 0 };
        
        big_copy(b1, b2);
        show_byte_array(b2, big_size(b2) + 1);
    }
    
    {
        BIG_INT b1 = { 10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0}, b2 = {1, 0};
        
        big_copy(b1, b2);
        show_byte_array(b2, big_size(b2) + 1);
    }
        
    printf("\nBIGINT READ FROM STRING TESTS:\n");
    {
        BIG_INT big = {1, 0};
        
        if (!big_from_string("", big)) print_success();
        else print_error();
    }
    {
        BIG_INT big = {1, 0};
        
        if (!big_from_string("123a", big)) print_success();
        else print_error();
    }
    {
        BIG_INT big = {1, 0};
        
        if (!big_from_string("123456789", big)) printf("FAIL\n");
        else show_byte_array(big, big_size(big) + 1);
    }
    
    {
        BIG_INT big = {1, 0};
        
        big_from_string("0", big);
        show_byte_array(big, big_size(big) + 1);
    }
    
    printf("\nBIGINT COMPARE TESTS:\n");
    {
        BIG_INT bzero1 = { 1, 0}, bzero2 = { 1, 0 };
        if (big_cmp(bzero1, bzero2) == 0) print_success(); else print_error();
    }
    {
        BIG_INT b1 = { 6, 0, 0, 0, 0, 5, 2};
        if (big_cmp(b1, b1) == 0) print_success(); else print_error();
    }

    {
        BIG_INT b1 = { 6, 1, 0, 0, 0, 5, 2}, b2 = { 6, 0, 0, 0, 0, 5, 2};
        if (big_cmp(b1, b2) > 0)  print_success(); else print_error();
    }
    
    {
        BIG_INT b1 = { 7, 6, 0, 0, 0, 5, 2, 1}, b2 = { 6, 6, 0, 0, 0, 5, 2, 1};
        if (big_cmp(b1, b2) > 0)  print_success(); else print_error();
    }
    
    {
        BIG_INT b1 = { 7, 6, 0, 0, 0, 5, 2, 0}, b2 = { 6, 6, 0, 0, 0, 5, 2, 0};
        if (big_cmp(b1, b2) == 0) print_success(); else print_error();
    }
    
    printf("\nBIGINT ADD TESTS:\n");
    {
        BIG_INT big_nine = {1, 9};
        BIG_INT big_one  = {1, 1};
        BIG_INT big_ten;
        
        if (!big_add(big_nine, big_one, big_ten)) print_error(); 
        else show_byte_array(big_ten, big_size(big_ten) + 1);
    }
 
    {
        char n1[] = "123456789012345678901234567890";
        char n2[] = "111111111111111111111111111111";
	
        BIG_INT big1, big2, big_res;
	
        big_from_string(n1, big1);
        big_from_string(n2, big2);
    
        if (!big_add(big1, big2, big_res)) print_error();
        else show_byte_array(big_res, big_size(big_res) + 1);
        
    }
    
    {
        BIG_INT big_99 = {2, 9, 9}, big_1 = {1, 1}, big = {3, 0, 0, 1};

        if (!big_add(big_99, big_1, big)) print_error();
        else show_byte_array(big, big_size(big) + 1);
    }
	
    printf("\nBIGINT SINGLE MUL TESTS:\n");
    {
        BIG_INT big1 = { 5, 0, 0, 0, 5, 2}, big_res = {1, 0};
       
        if (!big_mul_dig(big1, 0, big_res)) print_error();
        else show_byte_array(big_res, big_size(big_res) + 1);
    }
    
    {
        BIG_INT big1 = { 5, 0, 0, 0, 5, 2},  big_res;
    
        if (!big_mul_dig(big1, 4, big_res)) print_error();
        else show_byte_array(big_res, big_size(big_res) + 1);
    }
    {
        BIG_INT big1 = { 5, 0, 0, 0, 5, 2},  big_res = {1, 0};
    
        if (!big_mul_dig(big1, 1, big_res)) print_error();
        else show_byte_array(big_res, big_size(big_res) + 1);
    }
    
    {
        BIG_INT big1 = { 5, 0, 0, 0, 5, 2},  big_res = {1, 0};
    
        if (!big_mul_dig(big1, 9, big_res)) print_error();
        else show_byte_array(big_res, big_size(big_res) + 1);
    }
    {
        BIG_INT big1 = { 5, 0, 0, 0, 5, 2},  big_res = {1, 0};
    
        if (big_mul_dig(big1, -1, big_res)) print_error();
        else print_success();
    }
    {
        BIG_INT big1 = { 5, 0, 0, 0, 5, 2},  big_res = {1, 0};
    
        if (big_mul_dig(big1, 10, big_res)) print_error();
        else print_success();
    }
    
    printf("\nBIGINT MUL BY TEN TESTS:\n");
    {
        BIG_INT big = { 3, 0, 0, 1};
       
        if (!big_mul_10(big)) print_error();
        else show_byte_array(big, big_size(big) + 1);
    }
    
    {
        BIG_INT big = {0, 1};
       
        if (!big_mul_10(big)) print_error();
        else show_byte_array(big, big_size(big) + 1);
    }
    
    
    // output para as os testes das operações opcionais
    // se pretender implementar essas funçõe comente o código abaixo
    // e descomente os testes seguintes
    
    printf("\nBIGINT MUL BY POWER 10 TESTS:\n");
    printf("[13,0,0,0,0,0,0,0,0,0,0,0,0,1]\n");
    printf("OK!\n");
    printf("[7,0,0,0,0,0,5,1]\n");

    printf("\nBIGINT COMPLETE MUL TESTS:\n");
    printf("[3,0,5,1]\n");
    printf("[1,0]\n");
    printf("[3,0,0,9]\n");
    printf("[23,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,1]\n");

    /*
    printf("\nBIGINT MUL BY POWER 10 TESTS:\n");
    {
        BIG_INT big = { 3, 0, 0, 1};
       
        if (!big_mul_pow_10(big, 10)) print_error();
        else show_byte_array(big, big_size(big) + 1);
    }
    
    {
        BIG_INT big = { 3, 0, 5, 1};
       
        if (big_mul_pow_10(big, 253)) print_error();
        else print_success();
    }
    
    {
        BIG_INT big = { 3, 0, 5, 1};
       
        if (!big_mul_pow_10(big, 4)) print_error();
        else show_byte_array(big, big_size(big) + 1);
    }
    
    printf("\nBIGINT COMPLETE MUL TESTS:\n");
    {
        BIG_INT b1 = { 3, 0, 5, 1}, b2 = { 1, 1 }, b_res = {1, 0};
       
        if (!big_mul(b1, b2, b_res)) print_error();
        else show_byte_array(b_res, big_size(b_res) + 1);
    }
    {
        BIG_INT b1 = { 3, 0, 5, 1}, b2 = { 1, 0 }, b_res = {1, 0};
       
        if (!big_mul(b1, b2, b_res)) print_error();
        else show_byte_array(b_res, big_size(b_res) + 1);
    }
    {
        BIG_INT b1 = { 3, 0, 5, 1}, b2 = { 1, 6 }, b_res = {1, 0};
       
        if (!big_mul(b1, b2, b_res)) print_error();
        else show_byte_array(b_res, big_size(b_res) + 1);
    }
    {
        BIG_INT b1 = { 3, 0, 5, 1}, b2 = { 20, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9 }, 
                b_mul = {1, 0}, b_add = {1, 0};
       
        if (!big_mul(b1, b2, b_mul)) print_error();
        else if (!big_add(b_mul, b1, b_add)) print_error();
        else show_byte_array(b_add, big_size(b_add) + 1);
    }
    */
	return 0;
}
