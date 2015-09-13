//#include <android/log.h>
#include <time.h>
#include <stdio.h>
#include <string.h>

//#define  LOG_TAG   "bench"

//#define  LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
//#define  LOGE(...)  __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

clock_t begin, end;
double time_spent;

const int LOOP_BOUND = 1000000000;

static void work(int x, int y) {
    int sum;
    unsigned long *sum_container;

    for (int i=0; i<LOOP_BOUND; ++i) {
        sum = x + y;
#if VIOLATE_STRICT_ALIASING
	sum_container = *(unsigned long*)&sum;
#else
	memcpy(&sum_container, &sum, sizeof(int));
#endif
    }
    //return sum;
}

int main(int argc, char* argv[]) {
    //int result;
    begin = clock();
    work(*argv[1], *argv[2]);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("time: %f\n", time_spent);
    //LOGD("time: %f\n", time_spent);
    return 0;
}
