#include <winsock2.h>   // winsock必须放在windows.h前面
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma comment(lib,"ws2_32.lib")

//==================== 【模块1：数据结构定义】 ====================
#define MAX_ORDER 8500
#define STR_LEN 64
#define HTTP_PORT 8080

typedef struct {
    char order_id[STR_LEN];
    char order_date[STR_LEN];
    char user_id[STR_LEN];
    char ship_type[STR_LEN];
    char region[STR_LEN];
    char province[STR_LEN];
    char cate[STR_LEN];
    char sub_cate[STR_LEN];
    char maker[STR_LEN];
    char prod_name[STR_LEN];
    int quantity;
    float sales;
} Order;

Order order_list[MAX_ORDER];
int order_cnt = 0;

//==================== 【模块2：CSV文件读写】 ====================
int load_csv(const char *filepath)
{
    FILE *fp = fopen(filepath, "r");
    if (!fp)
    {
        printf("无法打开文件 %s\n", filepath);
        return -1;
    }
    char buf[1024];
    fgets(buf, sizeof(buf), fp); //跳过表头
    order_cnt = 0;
    while (fgets(buf, sizeof(buf), fp) != NULL && order_cnt < MAX_ORDER)
    {
        char *p = strtok(buf, ",");
        if (!p) continue;
        strncpy(order_list[order_cnt].order_id, p, STR_LEN - 1);

        p = strtok(NULL, ","); strncpy(order_list[order_cnt].order_date, p, STR_LEN - 1);
        p = strtok(NULL, ","); strncpy(order_list[order_cnt].user_id, p, STR_LEN - 1);
        p = strtok(NULL, ","); strncpy(order_list[order_cnt].ship_type, p, STR_LEN - 1);
        p = strtok(NULL, ","); strncpy(order_list[order_cnt].region, p, STR_LEN - 1);
        p = strtok(NULL, ","); strncpy(order_list[order_cnt].province, p, STR_LEN - 1);
        p = strtok(NULL, ","); strncpy(order_list[order_cnt].cate, p, STR_LEN - 1);
        p = strtok(NULL, ","); strncpy(order_list[order_cnt].sub_cate, p, STR_LEN - 1);
        p = strtok(NULL, ","); strncpy(order_list[order_cnt].maker, p, STR_LEN - 1);
        p = strtok(NULL, ","); strncpy(order_list[order_cnt].prod_name, p, STR_LEN - 1);
        p = strtok(NULL, ","); order_list[order_cnt].quantity = atoi(p);
        p = strtok(NULL, ","); order_list[order_cnt].sales = (float)atof(p);

        order_cnt++;
    }
    fclose(fp);
    return 0;
}

int save_csv(const char *filepath)
{
    FILE *fp = fopen(filepath, "w");
    if (!fp) return -1;
    fprintf(fp, "订单ID,订单日期,用户ID,邮寄方式,地区,省/自治区,商品类别,子类别,制造商,产品名称,订单量,销售额\n");
    for (int i = 0; i < order_cnt; i++)
    {
        fprintf(fp, "%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%d,%.2f\n",
            order_list[i].order_id,
            order_list[i].order_date,
            order_list[i].user_id,
            order_list[i].ship_type,
            order_list[i].region,
            order_list[i].province,
            order_list[i].cate,
            order_list[i].sub_cate,
            order_list[i].maker,
            order_list[i].prod_name,
            order_list[i].quantity,
            order_list[i].sales);
    }
    fclose(fp);
    return 0;
}

//==================== 【模块3：业务逻辑功能模块 只计算，不输出】 ====================
//按订单ID查询 0成功 -1未找到
int query_by_orderid(char *oid, Order *res)
{
    for (int i = 0; i < order_cnt; i++)
    {
        if (strcmp(order_list[i].order_id, oid) == 0)
        {
            *res = order_list[i];
            return 0;
        }
    }
    return -1;
}

//新增订单 0成功 -1数组满
int add_order(Order new_ord)
{
    if (order_cnt >= MAX_ORDER) return -1;
    order_list[order_cnt] = new_ord;
    order_cnt++;
    return 0;
}

//删除订单 0成功 -1找不到
int del_order(char *oid)
{
    int idx = -1;
    for (int i = 0; i < order_cnt; i++)
    {
        if (strcmp(order_list[i].order_id, oid) == 0)
        {
            idx = i;
            break;
        }
    }
    if (idx == -1) return -1;
    for (int i = idx; i < order_cnt - 1; i++)
    {
        order_list[i] = order_list[i + 1];
    }
    order_cnt--;
    return 0;
}

//修改订单，0成功 -1找不到
int modify_order(char *oid, Order new_info)
{
    for (int i = 0; i < order_cnt; i++)
    {
        if (strcmp(order_list[i].order_id, oid) == 0)
        {
            order_list[i] = new_info;
            return 0;
        }
    }
    return -1;
}

//按销售额降序冒泡排序，直接修改内存数组
void sort_by_sales(void)
{
    for (int i = 0; i < order_cnt - 1; i++)
    {
        for (int j = 0; j < order_cnt - 1 - i; j++)
        {
            if (order_list[j].sales < order_list[j + 1].sales)
            {
                Order t = order_list[j];
                order_list[j] = order_list[j + 1];
                order_list[j + 1] = t;
            }
        }
    }
}

//时间筛选，输出匹配结果到out，返回匹配数量；日期字符串对比
int filter_by_date(char *start, char *end, Order out[], int max_out)
{
    int cnt = 0;
    for (int i = 0; i < order_cnt && cnt < max_out; i++)
    {
        if (strcmp(order_list[i].order_date, start) >= 0 && strcmp(order_list[i].order_date, end) <= 0)
        {
            out[cnt++] = order_list[i];
        }
    }
    return cnt;
}

//==================== 【模块4 主控调度模块 】 ====================
//控制台打印单条订单
void print_one_ord(Order o)
{
    printf("订单ID:%s 日期:%s 用户:%s 地区:%s 产品:%s 订单量:%d 销售额:%.2f\n",
        o.order_id, o.order_date, o.user_id, o.region, o.prod_name, o.quantity, o.sales);
}

//控制台菜单外壳
void run_console_menu(void)
{
    int sel;
    while (1)
    {
        printf("\n=====控制台订单管理=====\n");
        printf("1按ID查询 2新增订单 3删除订单 4修改订单\n");
        printf("5按销售额排序 6按时间筛选 7保存 0退出\n");
        printf("请选择：");
        scanf("%d", &sel);
        if (sel == 0)
        {
            printf("退出控制台模式\n");
            break;
        }
        else if (sel == 1)
        {
            char oid[STR_LEN];
            Order res;
            printf("输入要查询订单ID：");
            scanf("%s", oid);
            int r = query_by_orderid(oid, &res);
            if (r == 0) print_one_ord(res);
            else printf("未找到该订单\n");
        }
        else if (sel == 2)
        {
            Order newo = { 0 };
            printf("订单ID:"); scanf("%s", newo.order_id);
            printf("订单日期(2018/1/1):"); scanf("%s", newo.order_date);
            printf("用户ID:"); scanf("%s", newo.user_id);
            printf("邮寄方式:"); scanf("%s", newo.ship_type);
            printf("地区:"); scanf("%s", newo.region);
            printf("省:"); scanf("%s", newo.province);
            printf("商品类别:"); scanf("%s", newo.cate);
            printf("子类别:"); scanf("%s", newo.sub_cate);
            printf("制造商:"); scanf("%s", newo.maker);
            printf("产品名称:"); scanf("%s", newo.prod_name);
            printf("订单量:"); scanf("%d", &newo.quantity);
            printf("销售额:"); scanf("%f", &newo.sales);
            int r = add_order(newo);
            if (r == 0) printf("新增成功(内存，记得保存)\n");
            else printf("新增失败，数组已满\n");
        }
        else if (sel == 3)
        {
            char oid[STR_LEN];
            printf("输入待删除订单ID："); scanf("%s", oid);
            int r = del_order(oid);
            if (r == 0) printf("删除成功(内存，记得保存)\n");
            else printf("未找到订单\n");
        }
        else if (sel == 4)
        {
            char oid[STR_LEN];
            Order newo = { 0 };
            printf("输入待修改订单ID："); scanf("%s", oid);
            Order tmp;
            if (query_by_orderid(oid, &tmp) != 0)
            {
                printf("找不到该订单\n");
                continue;
            }
            printf("输入新订单日期:"); scanf("%s", newo.order_date);
            printf("输入新用户ID:"); scanf("%s", newo.user_id);
            printf("邮寄方式:"); scanf("%s", newo.ship_type);
            printf("地区:"); scanf("%s", newo.region);
            printf("省:"); scanf("%s", newo.province);
            printf("商品类别:"); scanf("%s", newo.cate);
            printf("子类别:"); scanf("%s", newo.sub_cate);
            printf("制造商:"); scanf("%s", newo.maker);
            printf("产品名称:"); scanf("%s", newo.prod_name);
            printf("订单量:"); scanf("%d", &newo.quantity);
            printf("销售额:"); scanf("%f", &newo.sales);
            strcpy(newo.order_id, oid);
            int r = modify_order(oid, newo);
            if (r == 0) printf("修改成功(内存，记得保存)\n");
        }
        else if (sel == 5)
        {
            sort_by_sales();
            printf("已按销售额降序完成内存排序，保存才会写入csv\n");
        }
        else if (sel == 6)
        {
            char st[STR_LEN], ed[STR_LEN];
            Order out[200];
            printf("输入开始日期(2018/1/1):"); scanf("%s", st);
            printf("输入结束日期(2018/9/1):"); scanf("%s", ed);
            int n = filter_by_date(st, ed, out, 200);
            printf("共找到%d条记录\n", n);
            for (int i = 0; i < n; i++) print_one_ord(out[i]);
        }
        else if (sel == 7)
        {
            if (save_csv("store_cleaned.csv") == 0)
                printf("保存成功！写入store_cleaned.csv\n");
            else printf("保存失败！\n");
        }
    }
}

//解析GET参数
void get_param(char *url, char *key, char *val)
{
    char *p = strstr(url, key);
    val[0] = '\0';
    if (!p) return;
    p += strlen(key);
    while (*p != 0 && *p != '&' && *p != ' ')
    {
        *val++ = *p++;
    }
    *val = '\0';
}

/**
 * build_html：只负责拼接网页，参数全部由上层http_run传入
 * html：输出缓冲区
 * op：操作指令
 * msg：提示信息
 */
void build_html(char *html, const char *op, const char *msg)
{
    html[0] = '\0';
    strcat(html, "<html><head><meta charset='utf-8'><title>订单管理系统</title></head>");
    strcat(html, "<body><h2>订单管理系统【网页演示模式】</h2>");
    if (msg && strlen(msg) > 0)
    {
        char tmp[512];
        sprintf(tmp, "<div style='color:red'>提示：%s</div><br>", msg);
        strcat(html, tmp);
    }
    strcat(html, "<p>网页仅演示排序、保存；完整增删改查请切换控制台模式</p>");
    strcat(html, "<a href='?op=sort'><button>按销售额降序排序</button></a> ");
    strcat(html, "<a href='?op=save'><button>保存数据</button></a>");
    strcat(html, "<hr><table border='1'>");
    strcat(html, "<tr><th>订单ID</th><th>日期</th><th>用户ID</th><th>地区</th><th>产品</th><th>订单量</th><th>销售额</th></tr>");

    //展示前120条，防止html过大
    for (int i = 0; i < order_cnt && i < 120; i++)
    {
        char row[1024];
        sprintf(row, "<tr><td>%s</td><td>%s</td><td>%s</td><td>%s</td><td>%s</td><td>%d</td><td>%.2f</td></tr>",
            order_list[i].order_id, order_list[i].order_date, order_list[i].user_id, order_list[i].region,
            order_list[i].prod_name, order_list[i].quantity, order_list[i].sales);
        strcat(html, row);
    }
    strcat(html, "</table>");
    strcat(html, "<p>⚠网页仅演示，修改后点保存才写入csv；全部业务功能请使用控制台模式</p>");
    strcat(html, "</body></html>");
}

//http服务循环
int http_run(void)
{
    WSADATA wsa;
    WSAStartup(MAKEWORD(2, 2), &wsa);
    SOCKET serv = socket(AF_INET, SOCK_STREAM, 0);
    if (serv == INVALID_SOCKET)
    {
        printf("socket创建失败\n");
        return -1;
    }
    //补全struct，修复MinGW编译错误
    struct sockaddr_in sin;
    sin.sin_family = AF_INET;
    sin.sin_port = htons(HTTP_PORT);
    sin.sin_addr.S_un.S_addr = INADDR_ANY;

    if (bind(serv, (struct sockaddr*)&sin, sizeof(struct sockaddr_in)) == SOCKET_ERROR)
    {
        printf("bind绑定端口%d失败，端口被占用\n", HTTP_PORT);
        closesocket(serv);
        WSACleanup();
        return -1;
    }
    listen(serv, 5);
    printf("====网页模式已启动，请浏览器访问 http://127.0.0.1:%d ====\n", HTTP_PORT);
    char recv_buf[4096];

    while (1)
    {
        SOCKET client = accept(serv, NULL, NULL);
        if (client == INVALID_SOCKET) continue;
        ZeroMemory(recv_buf, sizeof(recv_buf));
        recv(client, recv_buf, sizeof(recv_buf) - 1, 0);

        char *url_start = strstr(recv_buf, "GET ");
        char url[2048] = { 0 };
        char op[64] = { 0 };
        char msg[256] = { 0 };

        if (url_start)
        {
            sscanf(url_start, "GET %s ", url);
            get_param(url, "op=", op);
            if (strcmp(op, "sort") == 0)
            {
                sort_by_sales();
                strcpy(msg, "已完成内存按销售额降序排序，请点击保存写入CSV");
            }
            else if (strcmp(op, "save") == 0)
            {
                if (save_csv("store_cleaned.csv") == 0)
                    strcpy(msg, "保存成功");
                else strcpy(msg, "保存失败");
            }
        }
        //堆上分配32KB缓冲区，杜绝栈溢出段错误
        char *html_buf = (char*)malloc(32*1024);
        if(html_buf == NULL){
            closesocket(client);
            continue;
        }
        build_html(html_buf, op, msg);

        char send_header[1024];
        sprintf(send_header, "HTTP/1.1 200 OK\r\nContent-Type:text/html;charset=utf-8\r\nConnection:close\r\n\r\n");
        send(client, send_header, (int)strlen(send_header), 0);
        send(client, html_buf, (int)strlen(html_buf), 0);

        free(html_buf);
        closesocket(client);
    }
    closesocket(serv);
    WSACleanup();
    return 0;
}

//==================== main入口 ====================
int main(void)
{
    if (load_csv("store_cleaned.csv") != 0)
    {
        printf("读取store_cleaned.csv失败，请确认文件放在程序同目录！\n");
        system("pause");
        return -1;
    }
    printf("成功载入订单，总条数：%d\n", order_cnt);
    printf("========订单管理系统启动========\n");
    printf("1 — 网页HTTP模式(浏览器访问127.0.0.1:8080)【仅演示排序保存】\n");
    printf("2 — 控制台备用模式【完整全部功能】\n");
    printf("请输入选择：");
    int sel;
    scanf("%d", &sel);
    if (sel == 1)
    {
        int ret = http_run();
        if (ret != 0)
        {
            char ch;
            printf("\n网页启动失败，是否切换控制台模式(y/n):");
            scanf(" %c", &ch);
            if (ch == 'y' || ch == 'Y')
            {
                run_console_menu();
            }
        }
    }
    else if (sel == 2)
    {
        run_console_menu();
    }
    system("pause");
    return 0;
}
