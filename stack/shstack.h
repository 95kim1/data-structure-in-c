/************************************************
* file name    : shstack.h
* create date  : 2022.04.06
* update date  : 2022.04.06
* writer       : 95kim1 (sunghee.k)
* last updater : 95kim1 (sunghee.k)
* description  : Stack's header file
*
*   stack structure
*       Wrapping list
*
*************************************************/

#ifndef _SH_STACK_H_
#define _SH_STACK_H_

#include "../list/shlist.h"

typedef struct sh_stack {
    sh_list list;
////////////
    
    // Capacity //
    bool (*empty)(struct sh_stack* self);
    unsigned int (*size)(struct sh_stack* self);
    
    // Access //
    void* (*top)(struct sh_stack* self);

    // Modifier //
    bool (*push)(struct sh_stack* self, void* pdata);
    
    bool (*pop)(struct sh_stack* self);

    void (*clear)(struct sh_stack* self);

    void (*free)(struct sh_stack* self);
} sh_stack;

// Initiallize //
void init_sh_stack(sh_stack* stack);

// Capacity //
bool _sh_stack_empty(sh_stack* self);
unsigned int _sh_stack_size(sh_stack* self);

// Access //
void* _sh_stack_top(sh_stack* self);

// Modifier //
bool _sh_stack_push(sh_stack* self, void* pdata);
bool _sh_stack_pop(sh_stack* self);
void _sh_stack_clear(sh_stack* self);
void _sh_stack_free(sh_stack* self);

#endif