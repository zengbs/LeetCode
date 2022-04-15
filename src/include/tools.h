#define CHECK_NULL( x )                                   \
        if ( x == NULL ){                                 \
            printf("line:%d null is found!\n", __LINE__); \
            exit(0);                                      \
        }

#define PRINT_LOCATION printf("line: %d\n", __LINE__)
