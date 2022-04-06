# Queue

## 1. Description

```c
sh_queue {
    sh_list list;
    
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
```

---

Data stored in this queue shoud be dynamically allocated.  
(queue is a wrapping structure of the list)

## 2. Functions

### 2-0. Init
you must call "init_sh_queue" function to use sh_queue.  
(call it before using member functions)

- void init_sh_queue(sh_queue\* shqueue);
    + call init_sh_list(&shqueue->list)
    + assign functions to member function(function pointer)


### 2-1. Capacity
---
#### empty
- bool empty(struct sh_queue\* self);
	+ if list is empty, then return true
	+ else return false

#### size
- unsigned int size(struct queue\* self);
	+ return the number of nodes of queue

### 2-2. Access
---
- void* _sh_queue_front(sh_queue\* self);
    + return data stored at the front of a queue

### 2-3. Modifiers
---
#### insert
- bool _sh_queue_push(sh_queue* self, void* pdata);
    + insert data at the back of a queue

#### delete
- bool _sh_queue_pop(sh_queue* self);
    + delete data at the front of a queue

- void _sh_queue_clear(sh_queue* self);
    + delete all data stored in a queue

- void _sh_queue_free(sh_queue* self);
    + clear and free


## 3. Build ( gcc )
gcc test.c shqueue.c ../list/shlist.c -o test
