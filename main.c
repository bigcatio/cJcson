#include <stdio.h>
#include "cJSON.h"

struct DATA
{
    char name[50];
    int numberArray[20];
    int number;
};

struct DATA data = {
    .name = "Li Ming",
    .numberArray = {1, 2, 3, 4, 5},
    .number = 100,
};

cJSON *root;
cJSON *result;
int main()
{
    root = cJSON_CreateObject(); //创建一个json对象

    cJSON_AddItemToObject(root, "name", cJSON_CreateString(data.name));
    cJSON_AddItemToObject(root, "numberArray", cJSON_CreateIntArray(data.numberArray, sizeof(data.numberArray) / sizeof(data.numberArray[0])));
    cJSON_AddItemToObject(root, "number", cJSON_CreateNumber(data.number));
    printf("构建的JSON:\n%s\n", cJSON_Print(root)); // 打印cJson

    result = cJSON_CreateObject();
    //result构建

    cJSON_AddItemToObject(result, "timestamp", cJSON_CreateString("ok"));
    //等效于下面
    //    cJSON_AddStringToObject(result, "timestamp", "ok");

    cJSON_AddItemToObject(result, "datetime_1", cJSON_CreateString("2019-07-21 10:46:57"));
    cJSON_AddItemToObject(result, "datetime_2", cJSON_CreateString("2019年07月21日 10时46分57秒"));
    cJSON_AddItemToObject(result, "week_1", cJSON_CreateString("0"));
    cJSON_AddItemToObject(result, "week_2", cJSON_CreateString("星期日"));
    cJSON_AddItemToObject(result, "week_3", cJSON_CreateString("周日"));
    cJSON_AddItemToObject(result, "week_4", cJSON_CreateString("Sunday"));
    cJSON_AddItemToObject(root, "result", result);

    cJSON *data; //包含多个数组
    cJSON *table, *data_bj, *data_sh, *data_js, *data_tj;

    const char *bj_str[5] = {"北京", "6.78", "7.21", "8.19", "6.45"};
    const char *sh_str[5] = {"上海", "6.74", "7.17", "7.87", "6.39"};
    const char *js_str[5] = {"江苏", "6.75", "7.18", "8.06", "6.37"};
    const char *tj_str[5] = {"天津", "6.77", "7.15", "8.07", "6.41"};
    const char *talbe_str[5] = {"地区", "92号汽油", "95号汽油", "98号汽油", "0号柴油"};

    data_bj = cJSON_CreateStringArray(bj_str, 5); //只包含5个字符串的数组
    data_sh = cJSON_CreateStringArray(sh_str, 5);
    data_js = cJSON_CreateStringArray(js_str, 5);
    data_tj = cJSON_CreateStringArray(tj_str, 5);
    table = cJSON_CreateStringArray(talbe_str, 5);

    data = cJSON_CreateArray();
    cJSON_AddItemToArray(data, table);
    cJSON_AddItemToArray(data, data_bj);
    cJSON_AddItemToArray(data, data_sh);
    cJSON_AddItemToArray(data, data_js);
    cJSON_AddItemToArray(data, data_tj);

    cJSON_AddItemToObject(root, "data", data);

    cJSON *forceast;
    cJSON *day1, *day2, *day3; //数组

    day1 = cJSON_CreateObject();
    day2 = cJSON_CreateObject();
    day3 = cJSON_CreateObject();

    cJSON_AddStringToObject(day1, "date", "2019-07-21"); //日期
    cJSON_AddStringToObject(day1, "cond_txt", "多云");   //天气状况
    cJSON_AddStringToObject(day1, "cond_code", "101");   //天气代码
    cJSON_AddStringToObject(day1, "hum", "23");          //湿度
    cJSON_AddStringToObject(day1, "tmp_H", "31");        //最高温度
    cJSON_AddStringToObject(day1, "tmp_L", "25");        //最低温度

    cJSON_AddStringToObject(day2, "date", "2019-07-22");
    cJSON_AddStringToObject(day2, "cond_txt", "晴");
    cJSON_AddStringToObject(day2, "cond_code", "100");
    cJSON_AddStringToObject(day2, "hum", "20");
    cJSON_AddStringToObject(day2, "tmp_H", "33");
    cJSON_AddStringToObject(day2, "tmp_L", "26");

    cJSON_AddStringToObject(day3, "date", "2019-07-23");
    cJSON_AddStringToObject(day3, "cond_txt", "阵雨");
    cJSON_AddStringToObject(day3, "cond_code", "107");
    cJSON_AddStringToObject(day3, "hum", "45");
    cJSON_AddStringToObject(day3, "tmp_H", "32");
    cJSON_AddStringToObject(day3, "tmp_L", "25");

    forceast = cJSON_CreateArray();
    //注意顺序，索引依次递增
    cJSON_AddItemToArray(forceast, day1); //元素0
    cJSON_AddItemToArray(forceast, day2); //元素1
    cJSON_AddItemToArray(forceast, day3); //元素2

    cJSON_AddItemToObject(root, "weather", forceast);

    printf("构建的JSON:\n%s\n", cJSON_Print(root)); // 打印cJson
    cJSON_Delete(root);
    printf("hello world!\n");
    return 0;
}