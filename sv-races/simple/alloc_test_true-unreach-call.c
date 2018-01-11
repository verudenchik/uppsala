typedef unsigned long size_t;
extern int __VERIFIER_nondet_int();

extern void* malloc(size_t size);

typedef unsigned long int pthread_t;
typedef union
{
  char __size[56];
  long int __align;
} pthread_attr_t;
typedef struct __pthread_internal_list
{
  struct __pthread_internal_list *__prev;
  struct __pthread_internal_list *__next;
} __pthread_list_t;

typedef union
{
  struct __pthread_mutex_s
  {
    int __lock;
    unsigned int __count;
    int __owner;
    unsigned int __nusers;
    int __kind;
    int __spins;
    __pthread_list_t __list;
  } __data;
  char __size[40];
  long int __align;
} pthread_mutex_t;

extern int pthread_create (pthread_t *__restrict __newthread,
      __const pthread_attr_t *__restrict __attr,
      void *(*__start_routine) (void *),
      void *__restrict __arg) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 3)));
extern int pthread_join (pthread_t __th, void **__thread_return);

void ldv_assert(int expr )
{
  if (expr == 0) {
    __VERIFIER_error();
  }
  return;
}

int writer(void* arg) {
	int* a = malloc(sizeof(int));
	
	if(__VERIFIER_nondet_int()) {
	  *a = 1;
	  ldv_assert(*a == 1);
	} else {
	  *a = 2;
	  ldv_assert(*a == 2);
	}
}

int main() {
	pthread_t thread1, thread2;
	
	pthread_create(&thread1, 0, writer, 0);
	pthread_create(&thread2, 0, writer, 0);
	
	return 0;
}
