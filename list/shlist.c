#include "shlist.h"

void init_sh_list(sh_list* shlist) {
    shlist->len = 0;

    shlist->head = (sh_list_node*)calloc(1, sizeof(sh_list_node));
    shlist->tail = (sh_list_node*)calloc(1, sizeof(sh_list_node));

    shlist->head->next = shlist->tail;
    shlist->tail->prev = shlist->head;

///////////////////////
    shlist->empty       = _sh_list_empty;
    shlist->size        = _sh_list_size;
    
    shlist->begin       = _sh_list_begin;
    shlist->end         = _sh_list_end;
    shlist->rbegin      = _sh_list_rbegin;
    shlist->rend        = _sh_list_rend;

    shlist->back        = _sh_list_back;
    shlist->front       = _sh_list_front;
    shlist->middle      = _sh_list_middle;
    
    shlist->insert      = _sh_list_insert;
    shlist->push_front  = _sh_list_push_front;
    shlist->push_back   = _sh_list_push_back;

    shlist->erase       = _sh_list_erase;
    shlist->erase_range = _sh_list_erase_range;
    shlist->pop_front   = _sh_list_pop_front;
    shlist->pop_back    = _sh_list_pop_back;

    shlist->clear       = _sh_list_clear;

    shlist->free        = _sh_list_free;
}

////////////
bool _sh_list_empty(sh_list* self) {
    return (self->len == 0) ? true : false;
}
unsigned int _sh_list_size(sh_list* self) {
    return self->len;
}

sh_list_node* _sh_list_begin(sh_list* self) {
    return self->head->next;
}
sh_list_node* _sh_list_end(sh_list* self) {
    return self->tail;
}
sh_list_node* _sh_list_rbegin(sh_list* self) {
    return self->tail->prev;
}
sh_list_node* _sh_list_rend(sh_list* self) {
    return self->head;
}
sh_list_node* _sh_list_middle(sh_list* self, int index) {
    if (index < 0 || index >= self->size(self)) return self->end(self);

    sh_list_node* curr = self->head;
    int i = -1;

    while (i++ < index) {
        curr = curr->next;
    }

    return curr;
}

void* _sh_list_back(sh_list* self) {
    return (self->rbegin(self))->data;
}
void* _sh_list_front(sh_list* self) {
    return (self->begin(self))->data;
}


bool _sh_list_insert(sh_list* self, sh_list_node* node, void* pdata) {
    sh_list_node* prev = node->prev;
    sh_list_node* next = node;

    if (!prev) return false;

    sh_list_node* new_node = (sh_list_node*)malloc(sizeof(sh_list_node));
    
    if (!new_node) return false;

    new_node->data = pdata;

    prev->next = new_node;
    next->prev = new_node;

    new_node->prev = prev;
    new_node->next = next;

    self->len++;

    return true;
}
bool _sh_list_push_front(sh_list* self, void* pdata) {
    return _sh_list_insert(self, self->head->next, pdata);
}
bool _sh_list_push_back(sh_list* self, void* pdata) {
    return _sh_list_insert(self, self->tail, pdata);
}

bool _sh_list_erase(sh_list* self, sh_list_node* node) {
    sh_list_node* prev = node->prev;
    sh_list_node* next = node->next;

    if (!prev || !next) return false;

    prev->next = next;
    next->prev = prev;

    free(node->data);
    free(node);

    self->len--;

    return true;
}
bool _sh_list_erase_range(sh_list* self, sh_list_node* node_begin, sh_list_node* node_end) {
    sh_list_node* prev = node_begin->prev;
    sh_list_node* next = node_end;
    
    sh_list_node* curr = node_begin;

    if (!prev || !next) return false;

    prev->next = next;
    next->prev = prev;

    while (curr != node_end) {
        next = curr->next;

        free(curr->data);
        free(curr);

        self->len--;

        curr = next;
    }

    return true;
}
bool _sh_list_pop_front(sh_list* self) {
    return _sh_list_erase(self, self->head->next);
}
bool _sh_list_pop_back(sh_list* self) {
    return _sh_list_erase(self, self->tail->prev);    
}

void _sh_list_clear(sh_list* self) {
    self->erase_range(self, self->begin(self), self->end(self));
}

void _sh_list_free(sh_list* self) {
    self->clear(self);
    free(self->head);
    free(self->tail);
}