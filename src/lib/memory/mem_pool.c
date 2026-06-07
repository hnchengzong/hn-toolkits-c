#include "../include/memory/mem_pool.h"
#include <stdlib.h>
#include <string.h>

mem_pool *mem_pool_new(void) {
  mem_pool *pool = malloc(sizeof(mem_pool));
  if (!pool) {
    return NULL;
  }
  pool->head = malloc(sizeof(mem_pool_block));
  if (!pool->head) {
    free(pool);
    return NULL;
  }
  pool->head->next = NULL;
  pool->head->used = 0;

  pool->current = pool->head;
  return pool;
}

void *mem_pool_alloc(mem_pool *pool, size_t size) {
  if (!pool || !size) {
    return NULL;
  }
  size_t aligned_size =
      (size + MEM_POOL_ALIGNMENT - 1) & ~(MEM_POOL_ALIGNMENT - 1);
  if (aligned_size > MEM_POOL_BLOCK_SIZE) {
    return NULL;
  }
  if (pool->current->used + aligned_size > MEM_POOL_BLOCK_SIZE) {
    mem_pool_block *new_block = malloc(sizeof(mem_pool_block));
    if (!new_block) {
      return NULL;
    }
    new_block->next = NULL;
    new_block->used = 0;
    pool->current->next = new_block;
    pool->current = new_block;
  }
  void *ptr = pool->current->data + pool->current->used;
  pool->current->used += aligned_size;
  return ptr;
}

void mem_pool_free(mem_pool *pool) {
  if (!pool) {
    return;
  }
  mem_pool_block *current_free = pool->head;
  while (current_free) {
    mem_pool_block *next = current_free->next;
    free(current_free);
    current_free = next;
  }
  free(pool);
}