type Trie struct {
    childs map[string]*Trie
    isExist bool
}

func removeSubfolders(folder []string) []string {
    root := &Trie {
        childs: make(map[string]*Trie),
        isExist: false,
    }
    ans := make([]string, 0)
    sort.Strings(folder)
    for _, path := range folder {
        v := strings.Split(path, "/")
        cur := root
        for i, n := range v {
            if n == "" {
                continue
            }
            if _, ok := cur.childs[n]; !ok {
                cur.childs[n] = &Trie {
                    childs: make(map[string]*Trie),
                    isExist: false,
                }
            } else {
                if cur.childs[n].isExist {
                    break
                }
            }
            cur = cur.childs[n]
            if i == len(v) - 1 {
                cur.isExist = true
                ans = append(ans, path)
            }
        }
    }
    return ans
}