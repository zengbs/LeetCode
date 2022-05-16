#gcc -DMERGE_SORT main.c merge-sort-0.c  && ./a.out
#gcc -DMERGE_SORT main.c merge-sort-1.c && ./a.out
#gcc -DMERGE_SORT main.c merge-sort-2.c && ./a.out
#gcc -DQUICK_SORT main.c quick-sort-hoare-cormen-0.c && ./a.out
#gcc -DQUICK_SORT main.c quick-sort-hoare-cormen-1.c && ./a.out
#gcc -DQUICK_SORT main.c quick-sort-hoare-gayle-0.c && ./a.out
#gcc -DQUICK_SORT main.c quick-sort-hoare-gayle-1.c && ./a.out
#gcc -DQUICK_SORT main.c quick-sort-lomuto-0.c && ./a.out
#gcc -DQUICK_SORT main.c quick-sort-lomuto-1.c && ./a.out


gcc -g -DQUICK_SORT main.c $1 getPivot.c && ./a.out
