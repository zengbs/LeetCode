#include<stdio.h>
#include<limits.h>
#include"../include/array.h"

int maxProfit(int* prices, int pricesSize){

   int buy  = 0;
   int sell = 0;

   int maxProfit = 0;
   int profit;

   while( sell < pricesSize ){

      profit = prices[sell] - prices[buy];

      if ( maxProfit < profit ) maxProfit = profit;

      if ( profit < 0 ) buy = sell;

      sell++;
   }

   return maxProfit;
}


int main(){

   int nums[] = {7,6,4,3,1, 94, 5};

   int numsSize = sizeof(nums)/sizeof(nums[0]);

   printf("%d\n", maxProfit(nums, numsSize));

   return 0;
}
