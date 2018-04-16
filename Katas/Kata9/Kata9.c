#include <stdlib.h>
#include <stdio.h>

int put(int key, int indx, int index[], int size, int array[]) {
  int k;
  for(k = key % size; array[k % size] != -1; k++){
  }
  array[k] = key;
  index[k] = indx;
  return key;
}

int get(int key, int index[], int size, int array[]){
  for(int k = key % size; array[k % size] != -1; k++){
    if(array[k] == key){
      return index[k];
    }
  }
  return -1;
}

int* twoMovies(int* nums, int numsSize, int target) {

  int complement;
  int size = numsSize * 3;
  int keys[size];
  int index[size];
  int k, i;
  int num = -1;


  for(k = 0; k< size; k++){
    keys[k] = -1;
    index[k] = -2;
  }

  for(k = 0; k< numsSize; k++){

    complement = target - nums[k];
    num = get(complement, index, size, keys);

    if (num != -1){
      int *ans = malloc( sizeof(int) * 2 );
      ans[0] = num;
      ans[1] = k;

      return 1;

    } else {
      put(nums[k], k, index, size, keys);
    }
  }
  return 0
}

int main(int argc, char const *argv[]) {
  int nms[] = {3,2,4};
  int ans = twoMovies(nms, 3, 6);
  if (ans) {
    printf("TRUE\n");
    /* code */
  }else{
    printf("FALSE\n");
  }
  return 0;
}
