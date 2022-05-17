gcc -DMERGE_SORT main.c merge-sort-0.c  && ./a.out
gcc -DMERGE_SORT main.c merge-sort-1.c && ./a.out
gcc -DMERGE_SORT main.c merge-sort-2.c && ./a.out
gcc -DQUICK_SORT main.c quick-sort-hoare-cormen-0.c getPivot.c && ./a.out
gcc -DQUICK_SORT main.c quick-sort-hoare-cormen-1.c getPivot.c && ./a.out
gcc -DQUICK_SORT main.c quick-sort-hoare-gayle-0.c && ./a.out
gcc -DQUICK_SORT main.c quick-sort-hoare-gayle-1.c && ./a.out
gcc -DQUICK_SORT main.c quick-sort-lomuto-0.c && ./a.out
gcc -DINSERTION_SORT  main.c  insertion-sort.c && ./a.out
