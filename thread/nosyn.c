#include <stdio.h>
#include <pthread.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

void* func(void* arg) {
  int threadno = *(int*)arg;
  for(int i = 0; i < 10; i ++) {
    printf("%d, thread %d\n", threadno, i);
    sleep(1);
  }
  return NULL;
}

int main() {
  pthread_t t1, t2;
  int i1 = 1;
  int i2 = 2;

  pthread_create(&t1, NULL, func, &i1);
  pthread_create(&t2, NULL, func, &i2);

  pthread_join(t1, NULL);
  pthread_join(t2, NULL);

  printf("主线程退出\n");
  return 0;
}
