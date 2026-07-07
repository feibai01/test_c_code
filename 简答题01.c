#include <stdio.h>
int main() {
    float a, b, h, area;
    scanf("%f %f %f", &a, &b, &h);
    area = (a + b) * h / 2;
    printf("%f\n", area);
    return 0;
}
