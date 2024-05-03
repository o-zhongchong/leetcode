func findMaxK(nums []int) int {
    var hashTable [2001]int32
    for _,v := range nums {
        hashTable[v + 1000] = 1
    }
    for i:=2000; i>=0; i-- {
        if hashTable[i] >= 1 && hashTable[2000-i] >= 1 {
            //fmt.Printf("%d %d\n", i, hashTable[i])
            return i - 1000
        }
    }
    return -1
}