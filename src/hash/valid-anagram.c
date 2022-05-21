#include<stdio.h>
#include<stdbool.h>




bool isAnagram(char *s, char *t){

   int hashTable[26] = {0};

   for (int sIdx=0; s[sIdx] != '\0';  s++){
      hashTable[s[sIdx]-'a']++;
   }

   for (int tIdx=0; t[tIdx] != '\0';  t++){
      hashTable[t[tIdx]-'a']--;
   }


   for (int i=0;i<26;i++){
      if (hashTable[i] != 0) return false;
   }

   return true;
}


int main(){



   char s[] = "lissen";
   char t[] = "silent";

   printf("%d\n", isAnagram(s, t));

   return 0;
}
