#define CHECK_NULL( x )                                   \
        if ( x == NULL ){                                 \
            printf("line:%d null is found!\n", __LINE__); \
            exit(0);                                      \
        }
