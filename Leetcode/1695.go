func maximumUniqueSubarray(nums []int) int {
    var left, right int = 0, 0
    var ans, score int = 0, 0
    set := make(map[int]bool)
    for ; right < len(nums) ; right++ {
        for set[nums[right]] {
            set[nums[left]] = false
            score -= nums[left]
            left++
        }
        set[nums[right]] = true
        score += nums[right]
        if score > ans {
            ans = score
        }
    }
    return ans
}