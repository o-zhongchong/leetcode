type Solution struct {
    shuffle []int
    original []int
}

func Constructor(nums []int) Solution {
    var s Solution
    s.original = nums
    s.shuffle = make([]int, len(s.original))
    copy(s.shuffle, s.original)
    return s
}

func (this *Solution) Reset() []int {
    return this.original
}

func (this *Solution) Shuffle() []int {
    //rand.Seed(time.Now().UnixNano())
    length := len(this.shuffle)
    for i, _ := range this.shuffle {
        j := rand.Intn(length - i)
        this.shuffle[i], this.shuffle[j] = this.shuffle[j], this.shuffle[i]
    }
    return this.shuffle
}

/**
 * Your Solution object will be instantiated and called as such:
 * obj := Constructor(nums);
 * param_1 := obj.Reset();
 * param_2 := obj.Shuffle();
 */