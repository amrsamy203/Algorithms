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
// return min
double ternary_search(double l, double r) {
    //double eps = 1e-9;
    for(int i = 0; i < 100; i++) {
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;
        double f1 = f(m1);
        double f2 = f(m2);
        //ans = min(ans, min(f1, f2));
        if (f1 < f2)
            r = m2;
        else
            l = m1;
    }
    return f(r);
}
//return MAX
double ternary_search(double l, double r) {
    double eps = 1e-9;              //set the error limit here
    while (r - l > eps) {
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;
        double f1 = f(m1);      //evaluates the function at m1
        double f2 = f(m2);      //evaluates the function at m2
        if (f1 < f2)
            l = m1;
        else
            r = m2;
    }
    return f(l);                    //return the maximum of f(x) in [l, r]
}
