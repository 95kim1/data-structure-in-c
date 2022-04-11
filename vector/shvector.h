/************************************************
* file name    : shvector.h
* create date  : 2022.04.10
* update date  : 2022.04.10
* writer       : 95kim1 (sunghee.k)
* last updater : 95kim1 (sunghee.k)
* description  : Dynamic Array's header file
*
*   sh_vector structure
*   sh_vector's prototypes of member functions
*
*************************************************/

#ifndef _SH_VECTOR_H_
#define _SH_VECTOR_H_

#include <stdlib.h>
#include <stdbool.h>

typedef struct sh_vector {
     int _capacity;
     int _size;
    void** _data;
///////
    // Capacity
    int size(struct sh_vector* self);
    int capacity(struct sh_vector* self);
    void reserve(struct sh_vector* self, int count);
    
    // Access
    void* get(struct sh_vector* self,  int index);
    void* front(struct sh_vector* self);
    void* back(struct sh_vector* self);

    // Modifier
    bool insert(struct sh_vector* self, void* data,  int index);
    bool push_back(struct sh_vector* self, void* data);
    
    bool erase(struct sh_vector* self,  int index);
    bool erase_range(struct sh_vector* self,  int start,  int end);
    bool pop_back(struct sh_vector* self);

    void resize(struct sh_vector* self, int size);

    void clear(struct sh_vector* self);
    void free(struct sh_vector* self);

    // Operation
    int find(struct sh_vector* self, void* data, bool compare(void*, void*));
    void swap(struct sh_vector* self, int a, int b);
    void reverse(struct sh_vector* self);
    void merge(struct sh_vector* self, struct sh_vector* other);
    void sort(struct sh_vector* self);
    void remove_if(struct sh_vector* self, void* data, bool compare(void*, void*));
} sh_vector;

// Initiallize
void init_sh_vector(sh_vector* vec);
void init_sh_vector_n(sh_vector* vec,  int capacity);

// Capacity
int _sh_size(struct sh_vector* self);
int _sh_capacity(struct sh_vector* self);
void _sh_reserve(struct sh_vector* self, int count);

// Access
void* _sh_get(struct sh_vector* self,  int index);
void* _sh_front(struct sh_vector* self);
void* _sh_back(struct sh_vector* self);

// Modifier
bool _sh_insert(struct sh_vector* self, void* data,  int index);
bool _sh_push_back(struct sh_vector* self, void* data);

bool _sh_erase(struct sh_vector* self,  int index);
bool _sh_erase_range(struct sh_vector* self,  int start,  int end);
bool _sh_pop_back(struct sh_vector* self);

void _sh_resize(struct sh_vector* self, int size);

void _sh_clear(struct sh_vector* self);
void _sh_free(struct sh_vector* self);

// Operation
int _sh_find(struct sh_vector* self, void* data, bool compare(void*, void*));
void _sh_swap(struct sh_vector* self, int a, int b);
void _sh_reverse(struct sh_vector* self);
void _sh_merge(struct sh_vector* self, struct sh_vector* other);
void _sh_sort(struct sh_vector* self);
void _sh_remove_if(struct sh_vector* self, void* data, bool compare(void*, void*));


#endif