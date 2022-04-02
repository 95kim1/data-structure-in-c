# Double Linked List
---

## 1. Description
---
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
---
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



