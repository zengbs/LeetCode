#include<stdio.h>
#include<limits.h>
#include"../include/array.h"

int maxProfit(int* prices, int pricesSize){

   int buy = 0;
   int sell = 0;

   int profit;
   int maxProfit = 0;

   while( sell < pricesSize ){

      profit = prices[sell] - prices[buy];

      if (profit < 0) { buy = sell; profit = 0; }

      if ( maxProfit < profit ) maxProfit = profit;

      sell++;
   }

   return maxProfit;
}



int main(){

   int nums[] = {7,6,4,3,1};

   int numsSize = sizeof(nums)/sizeof(nums[0]);

   printf("%d\n", maxProfit(nums, numsSize));

   return 0;
}
