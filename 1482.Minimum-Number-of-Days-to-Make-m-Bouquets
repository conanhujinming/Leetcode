func available(bloomDay []int, mid int, m int, k int) bool{
    total_cnt := 0
    cur_cnt := 0
    for _, day := range bloomDay {
        if day <= mid {
            cur_cnt++
        } else {
            cur_cnt = 0
        }
        if cur_cnt == k {
            total_cnt++
            cur_cnt = 0
            if total_cnt == m {
                return true
            }
        }
    }
    return false
}

func minDays(bloomDay []int, m int, k int) int {
    n := len(bloomDay)
    if n < m * k {
        return -1
    }
    l := 0
    r := 0
    for _, val := range bloomDay {
        if val > r {
            r = val
        }
    }
    for l < r {
        mid := (l + r) / 2
        if available(bloomDay, mid, m, k) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}
