
#include <stdio.h>
#include <math.h>

int main(){
  double a, b, c, d, e, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, ans;
  int p[2], q[2], r[2];
  pipe(p); 
  pipe(q); 
  pipe(r);

  scanf("%f %f %f %f %f", &a, &b, &c, &d, &e);

  if(!fork()){     //Child code
    t1 = b + 3; sleep(1);
    write(p[1], &t1, sizeof(t1));
    return 0;
  }
  if (!fork()) {
    t3 = c + 2; sleep(1);
    write(q[1], &t3, sizeof(t3));
    return 0;
  }
  if (!fork()) {
    t5 = d * 2; sleep(1);
    t6 = 3 + t5; sleep(1);
    write(r[1], &t6, sizeof(t6));
    return 0;
  }
  if (!fork()) {
    t7 = d - 1; sleep(1);
    t8 = t7 / e; sleep(1);
    t9 = 1 + t8; sleep(1);
    write(p[1], &t9, sizeof(t9));
    return 0;
  }

  read(p[0], &t1, sizeof(t1));
  read(q[0], &t3, sizeof(t3));
  read(r[0], &t6, sizeof(t6));
  read(p[0], &t9, sizeof(t9));

  t2 = a * t1; sleep(1);
  t4 = t2 / t3; sleep(1);

  t10 = pow(t6, t9); sleep(1);
  ans = t4 + t10; sleep(1);

  printf("(%.1f * (%.1f + 3)) / (%.1f + 2) + ((3 + %.1f * 2) ^ (1 + (%.1f - 1) / %.1f)) = %.3f\n", a, b, c, d, d, e, ans);
  return 0;
}
