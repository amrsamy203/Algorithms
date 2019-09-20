struct node {
    int val = 0, lazy = -1;
    int st, ed;
    node *left = 0, *right = 0;

    node(int s, int e, int v) {
        st = s, ed = e, val = v;
    }

    void extend() {
        if(!left && st < ed) {
            int md = (st + ed) >> 1;
            left = new node(st, md, 0);
            right = new node(md+1, ed, 0);
        }
    }

    void propagate() {
        extend();
        if(lazy != -1) {
            if(left) {
                left->lazy = lazy;
                right->lazy = lazy;
            }
            val = lazy * (ed-st+1);
            lazy = -1;
        }
    }

    int get(int l, int r) {
        if (r < st || l > ed) return 0;
        propagate();
        if (l <= st && r >= ed) return val;
        return left->get(l, r) + right->get(l, r);
    }

    void update(int l, int r, int v) {
        if (r < st || l > ed) return;
        propagate();
        if (l <= st && r >= ed) {
            lazy = v;
            propagate();
            return;
        }
        left->update(l, r, v);
        right->update(l, r, v);
        val = left->val + right->val;
    }
};
