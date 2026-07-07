#include <stdio.h>
struct Student {
    int score[3];
    float avg;
};
int main(){
    struct Student st[5], temp;
    FILE *fp1, *fp2;
    int i, j;
    fp1 = fopen("stud", "r");
    for (i = 0; i < 5; i++){
        fscanf(fp1, "%d%d%d%f", &st[i].score[0], &st[i].score[1], &st[i].score[2], &st[i].avg);
    }
    fclose(fp1);
    for (i = 0; i < 4; i++){
        for (j = 0; j < 4 - i; j++){
            if (st[j].avg > st[j+1].avg){
                temp = st[j];
                st[j] = st[j+1];
                st[j+1] = temp;
            }
        }
    }
    fp2 = fopen("stu_sort", "w");
    for (i = 0; i < 5; i++){
        fprintf(fp2, "%d %d %d %.2f\n", st[i].score[0], st[i].score[1], st[i].score[2], st[i].avg);
    }
    fclose(fp2);

    printf("排序完成，数据存入stu_sort\n");
    return 0;
}
