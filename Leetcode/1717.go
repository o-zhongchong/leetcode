func maximumGain(s string, x int, y int) int {
    var s1, s2 string = "ab", "ba"
    if x < y {
        x, y = y, x
        s1, s2 = s2, s1
    }
    str := []byte(s)
    f := func(t string, w int) int {
        var ans, j int = 0, 0
        for _, c := range str {
            str[j] = c; j++
            //fmt.Printf("%s\n", str[:j])
            if j > 1 && str[j-2] == t[0] && str[j-1] == t[1] {
                ans += w
                j -= 2
            }
        }
        str = str[:j]
        //fmt.Printf("ans:%d str:%s\n", ans, str)
        return ans
    }
    return f(s1, x) + f(s2, y)
}