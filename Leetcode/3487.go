func maxSum(nums []int) int {
    if len(nums) == 0 { return 0 }
    m := make(map[int]bool)
    ans := nums[0]
    for _, n := range nums {
        m[n] = true
        if n > ans {
            ans = n
        }
    }
    if ans < 0 { 
        return ans 
    } else {
        ans = 0
    }
    for k, _ := range m {
        if k > 0 {
            ans += k
        }
    }
    return ans
}