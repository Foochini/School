int main() {
    int t1, t2, t3, t4, t5, ans;
    int p[2], q[2];
    pipe(p); 
    pipe(q);

    if(!fork()) { // Child One
    t4 = four();
    t5 = five() + t4;
    write(p[1], &t5, sizeof(int));
    return 0;
    }

    t3 = three();

    if(!fork()) { // Child Two
    t2 = two();
    write(q[1], &t2, sizeof(int));
    return 0;
    }

    t1 = one();
    t3 = t3 + t1;

    read(q[0], &t2, sizeof(int));

    t3 = t3 + t2;

    read(p[0], &t5, sizeof(int));

    ans = t3 + t5;
    
    printf("The answer is - %d\n", ans);
    return 0;
   }