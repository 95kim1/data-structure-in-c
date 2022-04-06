/************************************************
* file name    : test.c
* create date  : 2022.04.06
* update date  : 2022.04.06
* writer       : 95kim1 (sunghee.k)
* last updater : 95kim1 (sunghee.k)
* description  : test source file for queue
*
*************************************************/

#include <stdio.h>
#include <stdlib.h>

#include "shqueue.h"

typedef struct Pos {
    int x;
    int y;
} Pos;

int main(void) {
    sh_queue queue;
    init_sh_queue(&queue);

    // 1. empty
    printf("\n####### 1. EMPTY #######\n");
    if (queue.empty(&queue)) printf("EMPTY\n");
    else printf("NON-EMPTY\n");

    // 2. push & size & front
    printf("\n####### 2. PUSH & SIZE & FRONT #######\n");
    for (int i = 0; i < 10; i++) {
        Pos* pos = (Pos*)malloc(sizeof(Pos));
        pos->x = i;
        pos->y = i;

        queue.push(&queue, pos);

        pos = queue.front(&queue);

        printf("front, size: (%d, %d), %d\n", pos->x, pos->y, queue.size(&queue));

    }

    // 3. pop & size & front
    printf("\n####### 3. POP & SIZE & FRONT #######\n");
    while (!queue.empty(&queue)) {
        Pos* pos = queue.front(&queue);

        printf("front, size: (%d, %d), %d\n", pos->x, pos->y, queue.size(&queue));

        queue.pop(&queue);
    }

    // 4. clear
    printf("\n####### 4. CLEAR #######\n");
    for (int i = 0; i < 10; i++) {
        Pos* pos = (Pos*)malloc(sizeof(Pos));
        pos->x = i;
        pos->y = i;

        queue.push(&queue, pos);
    }

    if (queue.empty(&queue)) printf("EMPTY\n");
    else printf("NON-EMPTY\n");

    queue.clear(&queue);

    if (queue.empty(&queue)) printf("EMPTY\n");
    else printf("NON-EMPTY\n");

    return 0;
}