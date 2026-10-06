#include <stdio.h>
#include <windows.h>
int main() {
    SetConsoleOutputCP(65001);
    float f = 80, c;
    c = 5 * (f - 32) / 9;
    printf("%.0f���϶ȶ�Ӧ�����϶�Ϊ%.2f\n", f, c);
    return 0;
}
