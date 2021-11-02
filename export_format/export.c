
#include <stdio.h>
#include <stdlib.h>
#include "export.h"

int main(){
    struct Man man_1 = {"Сергей", 20, "Москва"};
    struct Man man_2 = {"Паша", 30, "Киев"};
    struct Man man_3 = {"Магомед", 40, "Махачкала"};
    struct Man arr_people[] = {man_1, man_2, man_3};

    printf("Введите тип файла для экспорта(json, xml, yaml): ");

    char input_format[31] = "";   // value of input
    scanf("%30s", input_format);    // input of name format
    
    check_format(input_format, arr_people);
 
    return 0;
}
