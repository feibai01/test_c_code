#include <stdio.h>          // 引入标准输入输出头文件，用于printf、scanf
#include <string.h>         // 引入字符串处理头文件，用于strcpy、strcmp

#define MAXSIZE 100         // 定义顺序表最大容量，最多存100个联系人

// 定义联系人结构体：存储一条通讯录信息
typedef struct {
    char name[20];          // 联系人姓名
    char phone[15];         // 联系电话
} Contact;

// 顺序表结构体
typedef struct {
    Contact data[MAXSIZE];  // 数组，存放所有联系人（顺序表核心）
    int length;             // 当前顺序表中实际联系人数量
} SeqList;

// 初始化通讯录（顺序表）
void InitList(SeqList *L)
{
    L->length = 0;          // 初始联系人个数置0，空表
}

// 添加联系人到通讯录尾部
int AddContact(SeqList *L, char *name, char *phone)
{
    if(L->length >= MAXSIZE)// 判断顺序表是否已满
    {
        printf("通讯录已满，无法新增！\n");
        return 0;            // 添加失败返回0
    }
    strcpy(L->data[L->length].name, name);   // 复制姓名到顺序表数组
    strcpy(L->data[L->length].phone, phone);// 复制号码到顺序表数组
    L->length++;            // 实际长度+1
    return 1;               // 添加成功返回1
}

// 按姓名删除联系人（顺序表删除，元素前移）
int DelContact(SeqList *L, char *name)
{
    int i,j;
    for(i = 0; i < L->length; i++) // 遍历查找联系人
    {
        if(strcmp(L->data[i].name, name) == 0) // 找到同名联系人
        {
            // 后面元素全部向前移动一位（顺序表删除核心）
            for(j = i; j < L->length - 1; j++)
            {
                L->data[j] = L->data[j+1];
            }
            L->length--;    // 总数量减一
            printf("删除成功\n");
            return 1;
        }
    }
    printf("未找到该联系人\n");
    return 0;
}

// 遍历打印全部通讯录
void ShowAll(SeqList *L)
{
    int i;
    if(L->length == 0)      // 判断通讯录是否为空
    {
        printf("通讯录为空\n");
        return;
    }
    printf("====通讯录列表====\n");
    for(i = 0; i < L->length; i++) // 循环输出每一条联系人
    {
        printf("姓名：%s，电话：%s\n",L->data[i].name,L->data[i].phone);
    }
}

// 查找联系人，输入姓名检索
void SearchContact(SeqList *L, char *name)
{
    int i;
    for(i=0; i<L->length; i++)
    {
        if(strcmp(L->data[i].name,name)==0)
        {
            printf("找到：姓名:%s 电话:%s\n",L->data[i].name,L->data[i].phone);
            return;
        }
    }
    printf("查无此人\n");
}

// 主函数，程序入口
int main()
{
    SeqList con;            // 创建顺序表变量，代表通讯录
    InitList(&con);         // 初始化通讯录

    // 测试添加联系人
    AddContact(&con,"张三","136xxxxxxxx");
    AddContact(&con,"李四","139xxxxxxxx");

    ShowAll(&con);          // 显示全部联系人

    SearchContact(&con,"张三"); // 查找张三

    DelContact(&con,"李四");   // 删除李四

    ShowAll(&con);          // 删除后再次展示

    return 0;               // 程序正常结束
}

