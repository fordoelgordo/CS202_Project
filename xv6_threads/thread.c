/*
 * Author: FSt. J
 * Details: implementation of atomic spinlock and thread_create()
 *
*/

#include "types.h"
#include "user.h"
#include "x86.h"
#include "mmu.h"
#include "thread.h"

// Atomic spin lock functions
void lock_init(struct lock_t* lk)
{
  lk->locked = 0;
}

void lock_acquire(struct lock_t* lk)
{
  while(xchg(&lk->locked, 1) != 0); // Spin while waiting to acquire the lock
}

void lock_release(struct lock_t* lk)
{
  xchg(&lk->locked, 0); // Set the lock to 0 in order to release it
}

// thread_create() implementation
void thread_create(void* (*start_routine)(void*), void* arg)
{
  void* stack = malloc(PGSIZE);
  int pid; 

  pid = clone(stack, PGSIZE);

  if (pid == 0) {
    (*start_routine)(arg);
    exit();
  }
}
