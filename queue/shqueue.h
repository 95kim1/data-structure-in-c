/************************************************
* file name    : shqueue.h
* create date  : 2022.04.06
* update date  : 2022.04.06
* writer       : 95kim1 (sunghee.k)
* last updater : 95kim1 (sunghee.k)
* description  : Queue's header file
*
*   queue structure
*       Wrapping list
*
*************************************************/

#ifndef _SH_QUEUE_H_
#define _SH_QUEUE_H_

#include "../list/shlist.h"

typedef struct sh_queue {
    sh_list list;
////////////
    
    // Capacity //
    bool (*empty)(struct sh_queue* self);
    unsigned int (*size)(struct sh_queue* self);
    
    // Access //
    void* (*front)(struct sh_queue* self);

    // Modifier //
    bool (*push)(struct sh_queue* self, void* pdata);
    
    bool (*pop)(struct sh_queue* self);

    void (*clear)(struct sh_queue* self);

    void (*free)(struct sh_queue* self);
} sh_queue;

// Initiallize //
void init_sh_queue(sh_queue* queue);

// Capacity //
bool _sh_queue_empty(sh_queue* self);
unsigned int _sh_queue_size(sh_queue* self);

// Access //
void* _sh_queue_front(sh_queue* self);

// Modifier //
bool _sh_queue_push(sh_queue* self, void* pdata);
bool _sh_queue_pop(sh_queue* self);
void _sh_queue_clear(sh_queue* self);
void _sh_queue_free(sh_queue* self);

#endif