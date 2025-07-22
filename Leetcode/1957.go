func makeFancyString(s string) string {
    var left, count int = 0, 0
    str := []byte(s)
    for right, _ := range str {
        if count >= 2 && str[right] == str[left-1] {
            continue
        }
        if count > 0 && str[right] != str[left-1] {
            count = 1
        } else {
            count++
        }
        str[left] = str[right]
        left++
    }
    return string(str[:left])
}