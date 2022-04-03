/************************************************
* file name    : shmacro.h
* create date  : 2022.04.01
* update date  : 2022.04.02
* writer       : 95kim1 (sunghee.k)
* last updater : 95kim1 (sunghee.k)
* description  : macro functions
*
*************************************************/

#ifndef _SH_MACRO_H_
#define _SH_MACRO_H_

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

#define sh_swap(self, node_a, node_b)       ( (self)->swap(self, node_a, node_b) )

#endif