type TreeAncestor struct {
    parents [][]int
}


func Constructor(n int, parent []int) TreeAncestor {
    tree := TreeAncestor{}
    tree.parents = make([][]int, n)
    for i := 0; i < n; i++ {
        tree.parents[i] = make([]int, 20)
    }
    for i := 0; i < n; i++ {
        tree.parents[i][0] = parent[i]
    }
    for j := 1; j < 20; j++ {
        for i := 0; i < n; i++ {
            if tree.parents[i][j - 1] == -1 {
                tree.parents[i][j] = -1
            } else {
                tree.parents[i][j] = tree.parents[tree.parents[i][j - 1]][j - 1]
            }
        }
    }
    return tree
}


func (this *TreeAncestor) GetKthAncestor(node int, k int) int {
    for i := 0; i < 20; i++ {
        if ((k >> i) & 1) != 0 {
            node = this.parents[node][i]
            if node == -1 {
                return -1
            }
        }
    }
    return node
}


/**
 * Your TreeAncestor object will be instantiated and called as such:
 * obj := Constructor(n, parent);
 * param_1 := obj.GetKthAncestor(node,k);
 */
