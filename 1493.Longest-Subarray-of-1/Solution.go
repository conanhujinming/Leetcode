func Max(a, b int) int {
    if a > b {
        return a
    }
    return b
}

func longestOne(nums []int, k int) int {
    i := 0
    j := 0
    res := 0
    for ; j < len(nums); j++ {
        if nums[j] == 0 {
            k--
        }
        for k < 0 {
            if nums[i] == 0 {
                k++
            }
            i++
        }
        res = Max(res, j - i)
    }
    return res
}

func longestSubarray(nums []int) int {
    return longestOne(nums, 1)
}
