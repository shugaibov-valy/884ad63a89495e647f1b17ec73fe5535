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
    printf("Файл files/export.json создан!\n");
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
    printf("Файл files/export.xml создан!\n");
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
    printf("Файл files/export.yaml создан!\n");
}


void check_format(char *input_format, struct Man *array){
    if (strcmp(input_format,  "json") == 0){
        FILE *file = fopen("files/export.json", "w");
        export_json(array, file);
    }
    else if (strcmp(input_format, "xml") == 0){
        FILE *file = fopen("files/export.xml", "w");
        export_xml(array, file);
    }
    else if (strcmp(input_format, "yaml") == 0){
        FILE *file = fopen("files/export.yaml", "w");
        export_yaml(array, file);
    }
    else
        printf("Такого формата не существует!\n");

}

