# Double Linked List

## 1. Description

![list-description](/images/list-description.png "list-description")

<pre>
sh_list_node {
    void* prev;
    void* next;
    void* data;
}
</pre>

<pre>
sh_list {
    unsigned int len;
    sh_list_node* head;
    sh_list_node* tail;

    ... (member functions)
}
</pre>

## 2. Functions

### 2-0. Init
you must call "init_sh_list" function to use sh_list.  
(call it before using member functions)

- void init_sh_list(sh_list* shlist);
    + make two dummy nodes (head and tail)
    + connect head to tail
    + assign functions to member function(function pointer)


### 2-1. Capacity
---
#### empty
- bool empty(struct sh_list\* self);
	+ if list is empty, then return true
	+ else return false
    + O(1)

#### size
- unsigned int size(struct sh_list\* self);
	+ return the number of nodes of list
    + O(1)

### 2-2. Access
---
#### node pointer
- sh_list_node\* begin(struct sh_list\* self);
    + return node pointer of begin  (description)
    + O(1)

- sh_list_node\* end(struct sh_list\* self);
    + return node pointer of end  (description)
    + O(1)

- sh_list_node\* rbegin(struct sh_list\* self);
    + return node pointer of rbegin  (description)
    + O(1)
    
- sh_list_node\* rend(struct sh_list\* self);
    + return node pointer of rend  (desciption)
    + O(1)

- sh_list_node\* middle(struct sh_list\* self, int index);
    + return index-th node pointer  (description)
    + O(index) (O(n))

#### access to data (data pointer)
- void\* back(struct sh_list\* self);
    + return last data pointer
    + O(1)

- void\* front(struct sh_list\* self);
    + return first data pointer
    + O(1)

### 2-3. Modifiers
---
#### insert
- bool insert(struct sh_list\* self, sh_list_node\* node, void\* pdata);
    + insert node with pdata in front of node(2nd argument)
    + return true/false
    + O(1)
  
- bool push_front(struct sh_list\* self, void\* pdata);
    + return insert(self, self->head->next, pdata);
  
- bool push_back(struct sh_list\* self, void\* pdata);
    + return insert(self, self->tail, pdata);

- bool erase(struct sh_list\* self, sh_list_node\* node);
    + erase node(2nd argument) from the list(1st argument)
    + O(1)

#### delete
- bool erase_range(struct sh_list\* self, sh_list_node\* node_begin, sh_list_node\* node_end);
    + erase nodes between node_begin and node_end including node_begin (but node_end)
    + O(count of nodes)

- bool pop_front(struct sh_list\* self);
    + return erase(self, self->head->next);

- bool pop_back(struct sh_list\* self);
    + return erase(self, self->tail->prev);

- void clear(struct sh_list\* self);
    + return erase_range(self, self->begin(self), self->end(self));

- void free(struct sh_list\* self);
    + clear
    + free head and tail of the list


## 3. Macros

```c
#define sh_create_data(type)                ( (type*)malloc(sizeof(type)) )

#define sh_get_data_ptr(node, type)         ( (type*) ((node)->data) )
#define sh_get_data(node, type)             ( *((type*) ( (node)->data )) )

#define sh_get_size(self)                   ( (self)->size(self) )
#define sh_is_empty(self)                   ( (self)->empty(self) )

#define sh_get_begin(self)                  ( (self)->begin(self) )
#define sh_get_end(self)                    ( (self)->end(self) )
#define sh_get_rbegin(self)                 ( (self)->rbegin(self) )
#define sh_get_rend(self)                   ( (self)->rend(self) )
#define sh_get_middle(self, index)          ( (self)->middle(self, index) )

#define sh_get_front(self, type)            ( (type*) (self)->front(self) )
#define sh_get_back(self, type)             ( (type*) (self)->back(self) )

#define sh_insert(self, node, pdata)        ( (self)->insert(self, node, pdata) )
#define sh_push_back(self, pdata)           ( (self)->push_back(self, pdata) )
#define sh_push_front(self, pdata)          ( (self)->push_front(self, pdata) )

#define sh_erase(self, node)                ( (self)->erase(self, node) )
#define sh_erase_range(self, beg, end)      ( (self)->erase_range(self, beg, end) )
#define sh_pop_back(self)                   ( (self)->pop_back(self) ) 
#define sh_pop_front(self)                  ( (self)->pop_front(self) )

#define sh_clear(self)                      ( (self)->clear(self) )
#define sh_free(self)                       ( (self)->free(self) )
```
