#include <stdio.h>
#include <string.h>

/*
 * s is the data part of the program. It contains a template
 * of the entire source code. When printed, the trojan function
 * below will replace the word "right" with "wrong".
 */
char *s = "#include <stdio.h>%c#include <string.h>%c%c/*%c * s is the data part of the program. It contains a template%c * of the entire source code. When printed, the trojan function%c * below will replace the word %cright%c with %cwrong%c.%c */%cchar *s = %c%s%c;%c%cstatic void check(const char *t) {%c    const char *n = %cright%c;%c    for (int i = 0; t[i]; ) {%c        if (!strncmp(&t[i], n, 10)) {%c            printf(%cwrong%c);%c            i += 10;%c        } else {%c            putchar(t[i++]);%c        }%c    }%c}%c%cint main(void) {%c    char b[2048];%c    sprintf(b, s, 10, 10, 10, 10, 10, 10, 34, 34, 34, 34, 10, 10, 34, s, 34, 10, 10, 10, 34, 34, 10, 10, 10, 34, 34, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10);%c    check(b);%c    return 0;%c}%c";

static void check(const char *t) {
    const char *n = "right";
    for (int i = 0; t[i]; ) {
        if (!strncmp(&t[i], n, 5)) {
            printf("wrong");
            i += 5;
        } else {
            putchar(t[i++]);
        }
    }
}

int main(void) {
    char b[2048];
    sprintf(b, s, 10, 10, 10, 10, 10, 10, 34, 34, 34, 34, 10, 10, 34, s, 34, 10, 10, 10, 34, 34, 10, 10, 10, 34, 34, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10);
    check(b);
    return 0;
}
