type Trie struct {
    childs map[string]*Trie
    serial string
}

func deleteDuplicateFolder(paths [][]string) [][]string {
    var root *Trie = &Trie {
        childs: make(map[string]*Trie),
    }
    // build a trie tree
    for _, path := range paths {
        cur := root
        for _, node := range path {
            if _, ok := cur.childs[node]; !ok {
                cur.childs[node] = &Trie {
                    childs: make(map[string]*Trie),
                }
            }
            cur = cur.childs[node]
        }
    }
    // caculate the serialized reprezentation of each node
    freq := make(map[string]int)
    var dfs func(*Trie)
    dfs = func(node *Trie) {
        if len(node.childs) <= 0 {
            return
        }
        v := make([]string, 0, len(node.childs))
        for folder, child := range node.childs {
            dfs(child)
            s := fmt.Sprintf("%s(%s)", folder, child.serial)
            v = append(v, s)
        }
        sort.Strings(v)
        node.serial = strings.Join(v, ",")
        freq[node.serial]++
    }
    dfs(root)
    // delete duplicate folder
    ans := make([][]string, 0)
    path := make([]string, 0)
    var operate func(*Trie)
    operate = func(node *Trie) {
        if len(node.childs)>0 && freq[node.serial]>1 {
            return
        }
        if len(path) > 0 {
            tmp := make([]string, len(path))
            copy(tmp, path)
            ans = append(ans, tmp)
        }
        for folder, child := range node.childs {
            path = append(path, folder)
            operate(child)
            path = path[:len(path)-1]
        }
    }
    operate(root)
    return ans
}

func dfs(node *Trie, freq map[string]int) {
    if len(node.childs) <= 0 {
        return
    }
    v := make([]string, 0, len(node.childs))
    for folder, child := range node.childs {
        dfs(child, freq)
        s := fmt.Sprintf("%s(%s)", folder, child.serial)
        v = append(v, s)
    }
    sort.Strings(v)
    node.serial = strings.Join(v, ",")
    freq[node.serial]++
}
