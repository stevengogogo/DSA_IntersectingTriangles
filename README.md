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

**Ref**: https://www.csie.ntu.edu.tw/~sprout/algo2016/ppt_pdf/divide_and_conquer.pdf



### Merge sort


## Draft

![](img/note_20210423.jpeg)