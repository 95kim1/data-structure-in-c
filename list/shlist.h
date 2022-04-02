#ifndef _SH_LIST_H_
#define _SH_LIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct sh_list_node{
    void* prev;
    void* next;
    void* data;
} sh_list_node;

typedef struct sh_list{
    unsigned int len;
    sh_list_node* head;
    sh_list_node* tail;
///////////////////////
    bool (*empty)(struct sh_list* self);
    unsigned int (*size)(struct sh_list* self);
    
    sh_list_node* (*begin)(struct sh_list* self);
    sh_list_node* (*end)(struct sh_list* self);
    sh_list_node* (*rbegin)(struct sh_list* self);
    sh_list_node* (*rend)(struct sh_list* self);
    sh_list_node* (*middle)(struct sh_list* self, int index);

    void* (*back)(struct sh_list* self);
    void* (*front)(struct sh_list* self);

    bool (*insert)(struct sh_list* self, sh_list_node* node, void* pdata);
    bool (*push_front)(struct sh_list* self, void* pdata);
    bool (*push_back)(struct sh_list* self, void* pdata);
    
    bool (*erase)(struct sh_list* self, sh_list_node* node);
    bool (*erase_range)(struct sh_list* self, sh_list_node* node_begin, sh_list_node* node_end);
    bool (*pop_front)(struct sh_list* self);
    bool (*pop_back)(struct sh_list* self);

    void (*clear)(struct sh_list* self);

    void (*free)(struct sh_list* self);
} sh_list;

void init_sh_list(sh_list* shlist);



////////////////////////////////////
bool _sh_list_empty(sh_list* self);
unsigned int _sh_list_size(sh_list* self);

sh_list_node* _sh_list_begin(sh_list* self);
sh_list_node* _sh_list_end(sh_list* self);
sh_list_node* _sh_list_rbegin(sh_list* self);
sh_list_node* _sh_list_rend(sh_list* self);
sh_list_node* _sh_list_middle(sh_list* self, int index);

void* _sh_list_back(sh_list* self);
void* _sh_list_front(sh_list* self);

bool _sh_list_insert(sh_list* self, sh_list_node* node, void* pdata);
bool _sh_list_push_front(sh_list* self, void* pdata);
bool _sh_list_push_back(sh_list* self, void* pdata);

bool _sh_list_erase(sh_list* self, sh_list_node* node);
bool _sh_list_erase_range(sh_list* self, sh_list_node* node_begin, sh_list_node* node_end);
bool _sh_list_pop_front(sh_list* self);
bool _sh_list_pop_back(sh_list* self);

void _sh_list_clear(sh_list* self);

void _sh_list_free(sh_list* self);

#endif