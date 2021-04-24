# Intersecting Triangles


## Strategy

```cpp
int counting(left, right)
    if (left+1 == right)
        return 0
    mid = (left + right) / 2
    cnt = counting(left, mid)
    cnt += counting(mid,left)

    r = mid
    for l = left to mid
        while (r<right && A[l]>A[r]) //l<r
            r++
        cnt += r-mid

    return cnt
```

1. Convert `Q`, and `R` to `max` and `min`
2. Sort `P` along with `max`, `min`
3. Sort `max` and `min` at the same time with sorted P




## How to know two triangles have intersection(s)?

Let points on two distinct triangles be `(P,Q,R)` and `(P',Q',R')`.

- No intersection happens when
  - `P` > `P'` and `min(Q',R') > max(Q,R)`
- Intersection happens: Otherwise


## Range of `Int`

- `Int`: 4 bytes
  - 32 bit (1 byte = 8 bit)
  - Range: -2^31 ~ 2^31-1
- Belongs to the range  

**Ref**: https://www.tutorialspoint.com/cprogramming/c_data_types.htm


## Hints

### 排序

1. 排序 `P`
2. 左邊 `max`
3. 右邊 `min`
4. 

### 逆序述對 

- 定義
  - `A[i] > A[j]`
  - `i<j`
![](img/def_inversion.png)

- 計算逆序數對
![](img/code_inversion.png)

**Ref**: 
- https://www.csie.ntu.edu.tw/~sprout/algo2016/ppt_pdf/divide_and_conquer.pdf
- https://medium.com/@ssbothwell/counting-inversions-with-merge-sort-4d9910dc95f0


### Merge sort

```c
#include <stdio.h>
#include <stdlib.h>


// Merge two subarrays of A[].
// First subarray is arr[head..mid]
// Second subarray is arr[mid+1..tail]
void merge(int arr[], int head, int mid, int tail){
  int lenA = mid - head + 1;
  int lenB = tail - (mid + 1) + 1;
  int A[lenA];
  int B[lenB];

  //Copy data to temp arrays A[] and B[]
  int i, j, k;
  for(i = 0; i < lenA; i++){
    A[i] = arr[head + i];
  }
  for(j = 0; j < lenB; j++){
    B[j] = arr[mid + 1 + j];
  }

  // Merge two temp arrays back into arr[head..tail]
  i = 0;
  j = 0;
  k = head;
  //while array A and B haven't finished scanning
  while(i < lenA && j < lenB){
    if(A[i] < B[j]){
      arr[k] = A[i];
      i++;
    }
    else{
      arr[k] = B[j];
      j++;
    }
    k++;
  }

  //Copy the remaing elements into arr[], if A[] haven't finished scanning
  while(i < lenA){
    arr[k] = A[i];
    i++;
    k++;
  }
  //Copy the remaing elements into arr[], if B[] haven't finished scanning
  while(j < lenB){
    arr[k] = B[j];
    j++;
    k++;
  }
}

void merge_sort(int arr[], int head, int tail){
  if(head < tail){
    int mid = (head + tail) / 2;
    merge_sort(arr, head, mid);
    merge_sort(arr, mid+1, tail);
    merge(arr, head, mid, tail);
  }
}


int main(){
  int count, i;
  scanf("%d", &count);

  int list[count];
  printf("Numbers to be sorted: ");
  for(i = 0; i<count; i++){
    scanf("%d", &list[i]);
    printf("%d ", list[i]);
  }
  printf("\n");

  merge_sort(list, 0, count-1);

  printf("Numbers Sorted: ");
  for(i = 0; i<count; i++){
    printf("%d ", list[i]);
  }

  return 0;
}
```

**Ref**: 
- https://kopu.chat/2017/08/10/%E5%90%88%E4%BD%B5%E6%8E%92%E5%BA%8F-merge-sort/


## Draft

![](img/note_20210423.jpeg)