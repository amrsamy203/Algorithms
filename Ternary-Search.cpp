typedef long long ll;

ll func(int x) {
    // return some value
}

ll ts(int l, int r) { //ternary search for finding min in O(log n).
    int l1, r1;
    while(l+3 <= r) {
        l1 = l+(r-l)/3;
        r1 = r-(r-l)/3;
        if(func(l1) < func(r1)) { // < for min
            r = r1;
        } else {
            l = l1;
        }
    }
    int x = l;
    for(int i = l; i <= r; i++) {
        if(func(i) < func(x)) { // < for min
            x = i;
        }
    }
    return func(x);
}
///////////////////////
double func(double x) {
    // here func
}

double ts(double l, double r) {
    double l1, r1;
    for(int i = 0; i < 200; i++) {
        l1 = l+(r-l)/3;
        r1 = r-(r-l)/3;
        if(func(l1) < func(r1)) {
            r = r1;
        } else {
            l = l1;
        }
    }
    return func(l);
}
