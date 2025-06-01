#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
enum {
    BEGINL = 257, ENDL, IFL, THENL, WHILEL, DOL,
    RETRL, READL, PRITL, INTL, CONSTL, IDEN, NUMB
};
int nst = 0;
int lval, lex;
static char nch = '\n';
FILE *PF, *padres;
void get(void);
void number(void);
void word(void);
char* add(char *nm);
char TNM[400];
char *ptn = TNM;
int main() {
    PF = fopen("d:\\2021\\I_curs\\var2.s", "r");
    padres = fopen("getrez.dan", "w");
    if (!PF) {
        puts("File var2.s isn't open");
        return 1;
    }
    get();
    fclose(PF);
    fclose(padres);
    return 0;
}
void get() {
    nch = getc(PF);
    while (nch != EOF) {
        while (isspace(nch)) {
            if (nch == '\n') nst++;
            nch = getc(PF);
        }
        if (isdigit(nch)) {
            number();
        } else if (isalpha(nch)) {
            word();
        } else if (nch == '{' || nch == '}') {
            lex = (nch == '{') ? BEGINL : ENDL;
            nch = getc(PF);
        } else if (nch == '(' || nch == ')' || nch == ',' || nch == ';' ||
                   nch == '=' || nch == '+' || nch == '-' || nch == '*' ||
                   nch == '/' || nch == '%') {
            lex = nch;
            nch = getc(PF);
        } else {
            puts("Invalid symbol");
            return;
        }
    }
    lex = EOF;
}
void number() {
    lval = 0;
    while (isdigit(nch)) {
        lval = lval * 10 + (nch - '0');
        nch = getc(PF);
    }
    lex = NUMB;
}
void word() {
    static int cdl[] = {
        IFL, THENL, WHILEL, DOL, RETRL, READL,
        PRITL, INTL, CONSTL
    };
    static char* serv[] = {
        "if", "then", "while", "do", "return",
        "read", "print", "int", "const"
    };
    char tx[40];
    char *p = tx;
    while (isalpha(nch) || isdigit(nch)) {
        *p++ = nch;
        nch = getc(PF);
    }
    *p = '\0';
    for (int i = 0; i < 9; i++) {
        if (strcmp(tx, serv[i]) == 0) {
            lex = cdl[i];
            return;
        }
    }
    lex = IDEN;
    lval = (int)add(tx);

    printf("Address for %s = %p\n", tx, (void*)lval);
    fprintf(padres, "Address for %s = %p\n", tx, (void*)lval);
}
char* add(char *nm) {
    char *p;
    for (p = TNM; p < ptn; p += strlen(p) + 1) {
        if (strcmp(p, nm) == 0)
            return p;
    }
    if (ptn + strlen(nm) + 1 >= TNM + 400) {
        puts("Overload of TNM");
        exit(1);
    }
    strcpy(ptn, nm);
    p = ptn;
    ptn += strlen(nm) + 1;
    return p;
}
