/************************************************
* file name    : test.c
* create date  : 2022.04.01
* update date  : 2022.04.02
* writer       : 95kim1 (sunghee.k)
* last updater : 95kim1 (sunghee.k)
* description  : test source file of Double Linked List
*
*************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "shlist.h"
#include "shmacro.h"

typedef struct _Pos {
    int x;
    int y;
} Pos;

void print(sh_list* list) {
    sh_list_node* curr;
    sh_list_node* end = sh_get_end(list);
    Pos* p = NULL;

    printf("=======BEGIN=======\n");
    for (curr = sh_get_begin(list); curr != end; curr = curr->next) {
       p = sh_get_data_ptr(curr, Pos);
       printf("[%d, %d]\n", p->x, p->y);
    }
    if (!p) printf("EMPTY!!\n");
    printf("========END========\n\n");
}

void print_inverse(sh_list* list) {
    sh_list_node* curr;
    sh_list_node* rend = sh_get_rend(list);
    Pos* p = NULL;

    printf("=======BEGIN=======\n");
    printf("======INVERSE======\n");
    for (curr = sh_get_rbegin(list); curr != rend; curr = curr->prev) {
       p = sh_get_data_ptr(curr, Pos);
       printf("[%d, %d]\n", p->x, p->y);
    }
    if (!p) printf("EMPTY!!\n");
    printf("========END========\n\n");
}

int main(void) {
    Pos* temp_data;
    Pos* temp_data2;
    sh_list list1;
    init_sh_list(&list1);

    // 1. empty
    printf("####### 1. EMPTY #######\n");
    if (sh_is_empty(&list1)) printf("empty\n");
    else printf("non-empty\n");
    // or list1.empty(&list1)

    // 2. size
    printf("####### 2. SIZE #######\n");
    printf("size: %d\n", sh_get_size(&list1));
    // or list1.size(&list1)

    // 3. push_back
    printf("####### 3. PUSH_BACK #######\n");
    for (int x = 0; x < 4; x++) {
        printf("create\n");
        temp_data = sh_create_data(Pos);
        temp_data->x = x;
        temp_data->y = 0;
        printf("-----\n");
        list1.push_front(&list1, temp_data);
        // or sh_push_front(&list1, temp_data);
        printf("push\n\n");
    }
    print(&list1);

    // 4. pop_back
    printf("####### 4. POP_BACK #######\n");
    for (int i = 1; !sh_is_empty(&list1); i++) {
        list1.pop_back(&list1);
        // or sh_pop_back(&list1);
        
        printf("%d ", i);
        print(&list1);
    }

    // 5. push_front
    printf("####### 5. PUSH_FRONT #######\n");
    for (int x = 0; x < 4; x++) {
        printf("create\n");
        temp_data = sh_create_data(Pos);
        temp_data->x = x;
        temp_data->y = 0;
        printf("-----\n");
        list1.push_front(&list1, temp_data);
        // or sh_push_front(&list1, temp_data);
        printf("push\n\n");
    }
    print(&list1);
    
    
    // 6. pop_front
    printf("####### 6. POP_FRONT #######\n");
    
    for (int i = 1; !sh_is_empty(&list1); i++) {
        list1.pop_front(&list1);
        // or sh_pop_front(&list1);
        
        printf("%d ", i);
        print(&list1);
    }
    

    // 7. insert
    printf("####### 7. INSERT #######\n");
    for (int x = 0; x < 4; x++) {
        printf("create\n");
        temp_data = sh_create_data(Pos);
        temp_data->x = x;
        temp_data->y = 0;
        printf("-----\n");
        list1.push_front(&list1, temp_data);
        // or sh_push_front(&list1, temp_data);
        printf("push\n\n");
    }

    print(&list1);

    temp_data = sh_create_data(Pos);
    temp_data->x = 999;
    temp_data->y = 999;
    list1.insert(&list1, sh_get_middle(&list1, 2), temp_data);
    temp_data = sh_create_data(Pos);
    temp_data->x = 998;
    temp_data->y = 998;
    list1.insert(&list1, sh_get_end(&list1), temp_data);

    print(&list1);
    print_inverse(&list1);

    
    // 8. erase
    printf("####### 8. ERASE #######\n");
    list1.erase(&list1, sh_get_middle(&list1, 2));
    print(&list1);
    list1.erase(&list1, sh_get_middle(&list1, 0));
    print(&list1);
    list1.erase(&list1, sh_get_middle(&list1, 3));
    print(&list1);
    print_inverse(&list1);
    printf("len: %d\n", sh_get_size(&list1));


    // 9. erase_range
    printf("####### 9. ERASE_RANGE #######\n");
    print(&list1);
    list1.erase_range(&list1, sh_get_begin(&list1), sh_get_end(&list1)->prev);
    print(&list1);


    // 10. clear
    printf("####### 10. CLEAR #######\n");
    for (int x = 0; x < 4; x++) {
        temp_data = sh_create_data(Pos);
        temp_data->x = x;
        temp_data->y = 0;
        list1.push_front(&list1, temp_data);
        // or sh_push_front(&list1, temp_data);
    }
    print(&list1);

    sh_clear(&list1);
    //or list1.clear(&list1);
    print(&list1);


    // 11. free
    printf("####### 11. FREE #######\n");
    for (int x = 0; x < 4; x++) {
        temp_data = sh_create_data(Pos);
        temp_data->x = x;
        temp_data->y = 0;
        list1.push_front(&list1, temp_data);
        // or sh_push_front(&list1, temp_data);
    }
    print(&list1);
    
    sh_free(&list1);

    print(&list1);
    printf("head, tail : %p, %p\n", list1.head, list1.tail);


    // 12. swap
    init_sh_list(&list1);

    printf("####### 12. SWAP #######\n");
    for (int x = 0; x < 4; x++) {
        temp_data = sh_create_data(Pos);
        temp_data->x = x;
        temp_data->y = 0;
        list1.push_front(&list1, temp_data);
        // or sh_push_front(&list1, temp_data);
    }

    temp_data = sh_create_data(Pos);
    temp_data->x = 999;
    temp_data->y = 999;
    list1.insert(&list1, sh_get_middle(&list1, 2), temp_data);
    temp_data = sh_create_data(Pos);
    temp_data->x = 998;
    temp_data->y = 998;
    list1.insert(&list1, sh_get_end(&list1), temp_data);

    print(&list1);
    print_inverse(&list1);

    list1.swap(&list1, sh_get_middle(&list1, 2), sh_get_rbegin(&list1));

    print(&list1);
    print_inverse(&list1);

    sh_swap(&list1, sh_get_middle(&list1, 2), sh_get_middle(&list1, 3));
    // or list1.swap(sh_get_middle(&list1, 2), sh_get_middle(&list1, 3));
    
    print(&list1);
    print_inverse(&list1);


    // 13. reverse
    printf("####### 13. REVERSE #######\n");
    print(&list1);
    print_inverse(&list1);

    list1.reverse(&list1);
    // or sh_reverse(&list1);

    print(&list1);
    print_inverse(&list1);

    return 0;
}