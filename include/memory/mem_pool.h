#pragma once

#include <stddef.h>

#define MEM_POOL_BLOCK_SIZE 4096
#define MEM_POOL_ALIGNMENT 16
typedef struct mem_pool_block {
  struct mem_pool_block *next;
  size_t used;
  char data[MEM_POOL_BLOCK_SIZE];
} mem_pool_block;

typedef struct mem_pool {
  mem_pool_block *head;
  mem_pool_block *current;
} mem_pool;
extern mem_pool *mem_pool_new(void);
extern void *mem_pool_alloc(mem_pool *pool, size_t size);
extern void mem_pool_free(mem_pool *pool);