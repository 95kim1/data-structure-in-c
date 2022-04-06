/************************************************
* file name    : shqueue.c
* create date  : 2022.04.06
* update date  : 2022.04.06
* writer       : 95kim1 (sunghee.k)
* last updater : 95kim1 (sunghee.k)
* description  : Queue's source file
*
*   definitions of queue functions
*
*************************************************/

#include "shqueue.h"

// Initiallize //
void init_sh_queue(sh_queue* shqueue) {
    init_sh_list(&shqueue->list);
    
    shqueue->empty = _sh_queue_empty;
    shqueue->size = _sh_queue_size;
    shqueue->front = _sh_queue_front;
    shqueue->push = _sh_queue_push;
    shqueue->pop = _sh_queue_pop;
    shqueue->clear = _sh_queue_clear;
    shqueue->free = _sh_queue_free;
}

// Capacity //
bool _sh_queue_empty(sh_queue* self) {
    return self->list.empty(&self->list);
}

unsigned int _sh_queue_size(sh_queue* self) {
    return self->list.size(&self->list);
}

// Access //
void* _sh_queue_front(sh_queue* self) {
    return self->list.front(&self->list);
}

// Modifier //
bool _sh_queue_push(sh_queue* self, void* pdata) {
    return self->list.push_back(&self->list, pdata);
}
bool _sh_queue_pop(sh_queue* self) {
    return self->list.pop_front(&self->list);
}
void _sh_queue_clear(sh_queue* self) {
    return self->list.clear(&self->list);
}
void _sh_queue_free(sh_queue* self) {
    return self->list.free(&self->list);
}

