/************************************************
* file name    : test.c
* create date  : 2022.04.06
* update date  : 2022.04.06
* writer       : 95kim1 (sunghee.k)
* last updater : 95kim1 (sunghee.k)
* description  : test source file for Stack
*
*************************************************/

#include <stdio.h>
#include <stdlib.h>

#include "shstack.h"
//#include "shmacro.h"

typedef struct Pos {
    int x;
    int y;
} Pos;

int main(void) {
    sh_stack stack;
    init_sh_stack(&stack);

    // 1. empty
    printf("\n####### 1. EMPTY #######\n");
    if (stack.empty(&stack)) printf("EMPTY\n");
    else printf("NON-EMPTY\n");

    // 2. push & size & top
    printf("\n####### 2. PUSH & SIZE & TOP #######\n");
    for (int i = 0; i < 10; i++) {
        Pos* pos = (Pos*)malloc(sizeof(Pos));
        pos->x = i;
        pos->y = i;

        stack.push(&stack, pos);

        pos = stack.top(&stack);

        printf("top, size: (%d, %d), %d\n", pos->x, pos->y, stack.size(&stack));

    }

    // 3. pop & size & top
    printf("\n####### 3. POP & SIZE & TOP #######\n");
    while (!stack.empty(&stack)) {
        Pos* pos = stack.top(&stack);

        printf("top, size: (%d, %d), %d\n", pos->x, pos->y, stack.size(&stack));

        stack.pop(&stack);
    }

    // 4. clear
    printf("\n####### 4. CLEAR #######\n");
    for (int i = 0; i < 10; i++) {
        Pos* pos = (Pos*)malloc(sizeof(Pos));
        pos->x = i;
        pos->y = i;

        stack.push(&stack, pos);
    }

    if (stack.empty(&stack)) printf("EMPTY\n");
    else printf("NON-EMPTY\n");

    stack.clear(&stack);

    if (stack.empty(&stack)) printf("EMPTY\n");
    else printf("NON-EMPTY\n");

    return 0;
}