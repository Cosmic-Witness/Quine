#include <stdio.h>

/*
 * s is the data part of the program. It contains a template
 * of the entire source code, with format specifiers (%c and %s)
 * where the data needs to be inserted.
 */
char *s = "#include <stdio.h>%c%c/*%c * s is the data part of the program. It contains a template%c * of the entire source code, with format specifiers (%%c and %%s)%c * where the 
data needs to be inserted.%c */%cchar *s = %c%s%c;%c%cint main(void) {%c    /* This is the code part that prints the data and itself. 
*/%c    printf(s, 10, 10, 10, 10, 10, 10, 10, 34, s, 34, 10, 10, 10, 10, 10, 10, 10);%c    return 0;%c}%c";

int main(void) {
    /* This is the code part that prints the data and itself. */
    printf(s, 10, 10, 10, 10, 10, 10, 10, 34, s, 34, 10, 10, 10, 10, 10, 10, 10);
    return 0;
}
