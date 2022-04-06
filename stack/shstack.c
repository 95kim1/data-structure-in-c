/************************************************
* file name    : shstack.c
* create date  : 2022.04.06
* update date  : 2022.04.06
* writer       : 95kim1 (sunghee.k)
* last updater : 95kim1 (sunghee.k)
* description  : Stack's source file
*
*   definitions of stack functions
*
*************************************************/

#include "shstack.h"

// Initiallize //
void init_sh_stack(sh_stack* shstack) {
    init_sh_list(&shstack->list);
    
    shstack->empty = _sh_stack_empty;
    shstack->size = _sh_stack_size;
    shstack->top = _sh_stack_top;
    shstack->push = _sh_stack_push;
    shstack->pop = _sh_stack_pop;
    shstack->clear = _sh_stack_clear;
    shstack->free = _sh_stack_free;
}

// Capacity //
bool _sh_stack_empty(sh_stack* self) {
    return self->list.empty(&self->list);
}

unsigned int _sh_stack_size(sh_stack* self) {
    return self->list.size(&self->list);
}

// Access //
void* _sh_stack_top(sh_stack* self) {
    return self->list.back(&self->list);
}

// Modifier //
bool _sh_stack_push(sh_stack* self, void* pdata) {
    return self->list.push_back(&self->list, pdata);
}
bool _sh_stack_pop(sh_stack* self) {
    return self->list.pop_back(&self->list);
}
void _sh_stack_clear(sh_stack* self) {
    return self->list.clear(&self->list);
}
void _sh_stack_free(sh_stack* self) {
    return self->list.free(&self->list);
}

