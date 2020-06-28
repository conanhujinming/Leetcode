import (
    "fmt"
    "sort"
)

const MOD = 1e9 + 7

func quickPower(base int, power int) int {
    ans := 1
    for power != 0 {
        if (power & 1) != 0 {
            ans *= base
            ans %= MOD
        }
        base = base * base % MOD
        power >>= 1
    }
    return ans
}

func numSubseq(nums []int, target int) int {
    nums_ := nums[:]
    sort.Ints(nums_)
    ans := 0
    i := 0
    j := len(nums_) - 1
    for ; i <= j;{
        for ; (j >= 0) && (nums_[j] + nums_[i] > target); j-- {}
        if i > j {
            break
        }
        ans += quickPower(2, j - i)
        ans %= MOD
        i++
    }
    return ans
}
