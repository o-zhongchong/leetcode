func lexicalOrder(n int) []int {
    var nums []int
    dfs(0, n, &nums)
    return nums
}

func dfs(c int, n int, nums *[]int) {
    for i :=0; i < 10; i++ {
        s := c * 10 + i
        if s >= 1 && s <= n {
            *nums = append(*nums, s)
            dfs(s, n, nums)
        }
    }
}