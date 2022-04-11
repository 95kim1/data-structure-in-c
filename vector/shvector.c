/************************************************
* file name    : shvector.c
* create date  : 2022.04.10
* update date  : 2022.04.10
* writer       : 95kim1 (sunghee.k)
* last updater : 95kim1 (sunghee.k)
* description  : Dynamic Array's source file
*
*   sh_vector's definitions of member functions
*
*************************************************/

#include "shvector.h"


  /////////////////
 // Initiallize //
/////////////////

void init_sh_vector(sh_vector* vec) {
    vec->_size = 0;
    vec->_capaticty = 0;
    vec->_data = NULL;

    // Capacity
    vec->size = _sh_size;
    vec->capacity = _sh_capacity;
    vec->reserve = _sh_reserve;
    
    // Access
    vec->get = _sh_get;
    vec->front = _sh_front;
    vec->back = _sh_back;

    // Modifier
    vec->insert = _sh_insert;
    vec->push_back = _sh_push_back;
    
    vec->erase = _sh_erase;
    vec->erase_range = _sh_erase_range;
    vec->pop_back = _sh_pop_back;

    vec->resize = _sh_resize;

    vec->clear = _sh_clear;
    vec->free = _sh_free;

    // Operation
    vec->find = _sh_find;
    vec->swap = _sh_swap;
    vec->reverse = _sh_reverse;
    vec->merge = _sh_merge;
    vec->sort = _sh_sort;
    vec->remove_if = _sh_remove_if;
}
void init_sh_vector_n(sh_vector* vec,  int capacity) {
    init_sh_vector(vec);
    vec->_capacity = capacity;
}


  //////////////
 // Capacity //
//////////////

int _sh_size(struct sh_vector* self)  {
    return self->_size;
}
int _sh_capacity(struct sh_vector* self)  {
    return self->_capacity;
}
void reserve(struct sh_vector* self, int count) {
    
}


  ////////////
 // Access //
////////////

void* _sh_get(struct sh_vector* self,  int index)  {
    return (index > 0 && self->_size > index) ? self->_data[index] : NULL;
}
void* _sh_front(struct sh_vector* self)  {
    return _sh_get(self, 0);
}
void* _sh_back(struct sh_vector* self)  {
    return _sh_get(self, self->_size - 1);
}


  //////////////
 // Modifier //
//////////////

bool _sh_insert(struct sh_vector* self, void* data,  int index)  {
    
}
bool _sh_push_back(struct sh_vector* self, void* data)  {

}

bool _sh_erase(struct sh_vector* self,  int index)  {

}
bool _sh_erase_range(struct sh_vector* self,  int start,  int end)  {

}
bool _sh_pop_back(struct sh_vector* self)  {

}

void _sh_clear(struct sh_vector* self)  {

}
void _sh_free(struct sh_vector* self)  {

}
void resize(struct sh_vector* self, int size) {

}


  ///////////////
 // Operation //
///////////////

int _sh_find(struct sh_vector* self, void* data, bool compare(void*, void*))  {

}
void _sh_swap(struct sh_vector* self, int a, int b)  {

}
void _sh_reverse(struct sh_vector* self)  {

}
void _sh_merge(struct sh_vector* self, struct sh_vector* other)  {

}
void _sh_sort(struct sh_vector* self)  {

}
void _sh_remove_if(struct sh_vector* self, void* data, bool compare(void*, void*))  {

}

