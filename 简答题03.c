#include <stdio.h>
int main() {
    float f = 80, c;
    c = 5 * (f - 32) / 9;
    printf("%.0f华氏度对应的摄氏度为%.2f\n", f, c);
    return 0;
}
