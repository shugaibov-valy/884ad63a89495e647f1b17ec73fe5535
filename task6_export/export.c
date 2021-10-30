#include <stdio.h>
#include <string.h>
// Object of man
struct Man {
    char name[255];
    int age;
    char address[255];
};

// export for json file
void export_json(struct Man *array, FILE *file){
    int i;
    fprintf(file, "{\n");
    // sizeof - размер массива
    for (i=0; i<sizeof(array) - 1; i++){
        fprintf(file, "    'Man_%d': {\n", i+1); 
        fprintf(file, "       'name': '%s',\n", array[i].name);
        fprintf(file, "       'age': %d,\n", array[i].age);
        fprintf(file, "       'address': '%s'\n", array[i].address);
        fprintf(file, "    },\n");
    }
    fprintf(file, "}\n");
    fclose(file);      // close file
    printf("Файл export.json создан!\n");
}

// export for xml file
void export_xml(struct Man *array, FILE *file){
    fprintf(file, "<?xml version=\"1.0\" enconding=\"utf-8\"?>\n");
    int i;
    // sizeof - размер массива
    for (i=0; i<sizeof(array) - 1; i++){
        fprintf(file, "<Man_%d>\n", i+1);
        fprintf(file, "    <name>%s</name>\n", array[i].name);
        fprintf(file, "    <age>%d</age>\n", array[i].age);
        fprintf(file, "    <address>%s</address>\n", array[i].address);
        fprintf(file, "</Man_%d>\n", i+1);
    }
    fclose(file);     // close file
    printf("Файл export.xml создан!\n");
}

// export for yaml file
void export_yaml(struct Man *array, FILE *file){
    fprintf(file, "#YAML\n");
    int i;
    // sizeof - размер массива
    for (i=0; i<sizeof(array) - 1; i++){
        fprintf(file, "  Man_%d:\n", i+1);
        fprintf(file, "  name: %s\n", array[i].name);
        fprintf(file, "  age: %d\n", array[i].age);
        fprintf(file, "  address: %s\n\n", array[i].address);
    }
    fclose(file);    // close file
    printf("Файл export.yaml создан!\n");
}

int main(){
    struct Man man_1 = {"Сергей", 20, "Москва"};
    struct Man man_2 = {"Паша", 30, "Киев"};
    struct Man man_3 = {"Магомед", 40, "Махачкала"};
    struct Man arr_people[] = {man_1, man_2, man_3};

    printf("Введите тип файла для экспорта(json, xml, yaml): ");

    char input_format[31] = "";   // value of input
    scanf("%30s", input_format);    // input of name format

    if (strcmp(input_format,  "json") == 0){
        FILE *file = fopen("export.json", "w");
        export_json(arr_people, file);
    }
    else if (strcmp(input_format, "xml") == 0){
        FILE *file = fopen("export.xml", "w");
        export_xml(arr_people, file);
    }
    else if (strcmp(input_format, "yaml") == 0){
        FILE *file = fopen("export.yaml", "w");
        export_yaml(arr_people, file);
    }
    else
        printf("Такого формата не существует!\n");

    return 0;
}
