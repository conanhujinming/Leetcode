func canArrange(arr []int, k int) bool {
    hash_map := make([]int, k)
    for _, v := range arr {
        mod := (v % k + k) % k
        other_num := k - mod
        if mod == 0 {
            other_num = 0
        }
        if hash_map[other_num] > 0 {
            hash_map[other_num]--
        } else {
            hash_map[mod]++
        }
    }
    for _, v := range hash_map {
        if v != 0 {
            return false
        }
    }
    return true
}
