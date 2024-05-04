func reversePrefix(word string, ch byte) string {
    var idx int = strings.IndexByte(word, ch)
    var sb strings.Builder
    if idx >= 0 {
        for i:=idx; i>=0; i-- {
        	sb.WriteByte(word[i])
        }
        for i:=idx+1; i<len(word); i++ {
        	sb.WriteByte(word[i])
        }
        return sb.String()
    }
    return word
}