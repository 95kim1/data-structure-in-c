/************************************************
* file name    : test.c
* create date  : 2022.04.01
* update date  : 2022.04.04
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

void print(sh_list* list);
void print_inverse(sh_list* list);
bool compare_lt(void* a, void* b);
bool compare_gt(void* a, void* b);

int main(void) {
    Pos* temp_data;
    Pos* temp_data2;
    sh_list list1;
    init_sh_list(&list1);

    // 1. empty
    printf("\n####### 1. EMPTY #######\n");
    if (sh_is_empty(&list1)) printf("empty\n");
    else printf("non-empty\n");
    // or list1.empty(&list1)

    // 2. size
    printf("\n####### 2. SIZE #######\n");
    printf("size: %d\n", sh_get_size(&list1));
    // or list1.size(&list1)

    // 3. push_back
    printf("\n####### 3. PUSH_BACK #######\n");
    for (int x = 0; x < 4; x++) {
        temp_data = sh_create_data(Pos);
        temp_data->x = x;
        temp_data->y = 0;
        list1.push_front(&list1, temp_data);
        // or sh_push_front(&list1, temp_data);
    }
    print(&list1);

    // 4. pop_back
    printf("\n####### 4. POP_BACK #######\n");
    for (int i = 1; !sh_is_empty(&list1); i++) {
        list1.pop_back(&list1);
        // or sh_pop_back(&list1);
        
        printf("%d ", i);
        print(&list1);
    }

    // 5. push_front
    printf("\n####### 5. PUSH_FRONT #######\n");
    for (int x = 0; x < 4; x++) {
        temp_data = sh_create_data(Pos);
        temp_data->x = x;
        temp_data->y = 0;
        list1.push_front(&list1, temp_data);
        // or sh_push_front(&list1, temp_data);
    }
    print(&list1);
    
    
    // 6. pop_front
    printf("\n####### 6. POP_FRONT #######\n");
    
    for (int i = 1; !sh_is_empty(&list1); i++) {
        list1.pop_front(&list1);
        // or sh_pop_front(&list1);
        
        printf("%d ", i);
        print(&list1);
    }
    

    // 7. insert
    printf("\n####### 7. INSERT #######\n");
    for (int x = 0; x < 4; x++) {
        temp_data = sh_create_data(Pos);
        temp_data->x = x;
        temp_data->y = 0;
        list1.push_front(&list1, temp_data);
        // or sh_push_front(&list1, temp_data);
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
    //print_inverse(&list1);

    
    // 8. erase
    printf("\n####### 8. ERASE #######\n");
    list1.erase(&list1, sh_get_middle(&list1, 2));
    print(&list1);
    list1.erase(&list1, sh_get_middle(&list1, 0));
    print(&list1);
    list1.erase(&list1, sh_get_middle(&list1, 3));
    print(&list1);
    //print_inverse(&list1);
    printf("len: %d\n", sh_get_size(&list1));


    // 9. erase_range
    printf("\n####### 9. ERASE_RANGE #######\n");
    print(&list1);
    list1.erase_range(&list1, sh_get_begin(&list1), sh_get_end(&list1)->prev);
    print(&list1);


    // 10. clear
    printf("\n####### 10. CLEAR #######\n");
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
    printf("\n####### 11. FREE #######\n");
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

    printf("\n####### 12. SWAP #######\n");
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
    // /print_inverse(&list1);

    list1.swap(&list1, sh_get_middle(&list1, 2), sh_get_rbegin(&list1));

    print(&list1);
    //print_inverse(&list1);

    sh_swap(&list1, sh_get_middle(&list1, 2), sh_get_middle(&list1, 3));
    // or list1.swap(sh_get_middle(&list1, 2), sh_get_middle(&list1, 3));
    
    print(&list1);
    //print_inverse(&list1);


    // 13. reverse
    printf("\n####### 13. REVERSE #######\n");
    print(&list1);
    //print_inverse(&list1);

    list1.reverse(&list1);
    // or sh_reverse(&list1);

    print(&list1);
    //print_inverse(&list1);

    // 14. sort
    printf("\n####### 14. SORT #######\n");
    
    for (int i = 100; i >= 0; i--) {
        temp_data = sh_create_data(Pos);
        temp_data->x = i;
        temp_data->y = 0;
        list1.push_back(&list1, temp_data);
    }

    print(&list1);

    printf("##########################\n");
    printf("non-decreasing sorting....\n");
    list1.sort(&list1, compare_lt);
    printf("##########################\n\n");

    print(&list1);

    printf("##########################\n");
    printf("non-increasing sorting....\n");
    list1.sort(&list1, compare_gt);
    printf("##########################\n\n");

    print(&list1);

    // 15. merge - 1
    printf("\n####### 15-1. MERGE (compare==NULL) #######\n");

    list1.clear(&list1);

    for (int i = 0; i < 10; i++) {
        temp_data = sh_create_data(Pos);
        temp_data->x = i;
        temp_data->y = i;
        list1.push_back(&list1, temp_data);
    }

    sh_list list2;
    init_sh_list(&list2);

    for (int i = 10; i < 20; i++) {
        temp_data = sh_create_data(Pos);
        temp_data->x = i;
        temp_data->y = i;
        list2.push_back(&list2, temp_data);
    }

    list1.merge(&list1, &list2, NULL);

    printf("LIST_1_\n");
    print(&list1);
    printf("\nLIST_2_\n");
    print(&list2);

    // 15. merge - 2
    printf("\n####### 15-2. MERGE (compare!=NULL) #######\n");

    list1.clear(&list1);

    for (int i = 0; i < 10; i++) {
        temp_data = sh_create_data(Pos);
        temp_data->x = 2*i+1;
        temp_data->y = 2*i+1;
        list1.push_back(&list1, temp_data);
    }

    for (int i = 0; i < 10; i++) {
        temp_data = sh_create_data(Pos);
        temp_data->x = 2*i;
        temp_data->y = 2*i;
        list2.push_back(&list2, temp_data);
    }

    printf("LIST_1_\n");
    print(&list1);
    printf("\nLIST_2_\n");
    print(&list2);

    list1.merge(&list1, &list2, compare_lt);

    printf("LIST_1_\n");
    print(&list1);
    printf("\nLIST_2_\n");
    print(&list2);

    return 0;
}

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

bool compare_lt(void* a, void* b) {
    Pos* pos_a = (Pos*)a;
    Pos* pos_b = (Pos*)b;

    if (pos_a->x < pos_b->x) return true;
    if (pos_a->x == pos_b->x && pos_a->y < pos_b->y) return true;
    return false;
}

bool compare_gt(void* a, void* b) {
    Pos* pos_a = (Pos*)a;
    Pos* pos_b = (Pos*)b;

    if (pos_a->x > pos_b->x) return true;
    if (pos_a->x == pos_b->x && pos_a->y > pos_b->y) return true;
    return false;
}

