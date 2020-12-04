// Spinlock implementation
struct lock_t
{
  uint locked;
};

// Spin lock functions
void lock_init(struct lock_t*);
void lock_acquire(struct lock_t*);
void lock_release(struct lock_t*);

// thread_create() user function
void thread_create(void* (*start_routine)(void*), void* arg);
