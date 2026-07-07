#include <stdio.h>
struct Student{
    int score[3];
    float avg;
};
int main(void){
    struct Student st[5];
    FILE *fp;
    int i,j;
    float sum;
    for(i=0;i<5;i++){
        printf("请输入第%d个学生3门成绩：",i+1);
        scanf("%d %d %d",&st[i].score[0],&st[i].score[1],&st[i].score[2]);
        sum=0;
        for(j=0;j<3;j++)
            sum += st[i].score[j];
        st[i].avg = sum/3.0f;
    }
    if((fp=fopen("stud","w"))==NULL){
        printf("文件打开失败！\n");
        return 1;
    }
    for(i=0;i<5;i++){
        fprintf(fp,"%d %d %d %.2f\n",st[i].score[0],st[i].score[1],st[i].score[2],st[i].avg);
    }
    fclose(fp);
    return 0;
}
