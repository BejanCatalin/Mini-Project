#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct GPU
{
    char brand[21];
    char chipset[10];
    char model[50];
    char cooling[10];
    int price;
    int stock;
};
void up(char * temp)
{
    char * name;
    name = strtok(temp,":");
    char *s = name;
    while (*s)
    {
        *s = toupper((unsigned char) *s);
        s++;
    }
}
void low(char * temp)
{
    char * name;
    name = strtok(temp,":");
    char *s = name;
    while (*s)
    {
        *s = tolower((unsigned char) *s);
        s++;

    }
}

void addToFile(FILE* fp, struct GPU* input)
{
    fp = fopen("GPUfile.c", "a");
    sprintf(&input, "%s, %s, %s, %s, %d, %d", input->brand, input->chipset, input->model, input->cooling, input->price, input->stock);
    fwrite(&input, sizeof(char), strlen(&input), fp);
    fclose(fp);

}
int addGPU(struct GPU* choice)
{
    char c;
    char line[1024]= {0,};
    FILE* fp;
    fp = fopen("GPUfile.c","r");
    printf("Input the brand, chipset, model, cooling, price, stock:\n");
    scanf("%s", &choice->brand);
    up(&choice->brand);
    scanf("%s", &choice->chipset);
    up(&choice->chipset);
    scanf("%s", &choice->model);
    up(&choice->model);
    scanf("%s", &choice->cooling);
    scanf("%d", &choice->price);
    scanf("%d", &choice->stock);
    fclose(fp);
    return choice;
}

void deleteLine(FILE *fp, FILE *tempFile, char br[21], char chi[21], char mode[50])
{
    char line[200];
    fp = fopen("GPUfile.c", "r");
    tempFile = fopen("delete_line_tmp", "w");

    while ((fgets(line, 200, fp)) != NULL)
    {
        if ((strstr(line,br) == NULL) && (strstr(line,chi) == NULL) && (strstr(line,mode) == NULL))
            fputs(line, tempFile);
    }
    fclose(fp);
    fclose(tempFile);
}

int main()
{
    char c, brandname[21], chiptype[10], gpumodel[50];
    char br[21], chi[21], mode[50];

    FILE* fp;
    FILE* tempFile;
    fp = fopen("GPUfile.c", "r");

    printf("If you want to see all the GPU's, press ~ 1 ~ :\n");
    printf("If you want to search for a GPU brand, press ~ 2 ~ :\n");
    printf("If you want to search for a GPU chipset type, press ~ 3 ~ :\n");
    printf("If you want to search for a GPU model, press ~ 4 ~ :\n");
    printf("If you want to add a GPU, press ~ 5 ~ :\n");
    printf("If you want to delete a GPU, press ~ 6 ~ :\n");

    int value;
    scanf("%d", &value);

    if(value == 1)
    {
        c = fgetc(fp);
        while (c != EOF)
        {
            printf ("%c", c);
            c = fgetc(fp);
        }
        fseek(fp, 0, SEEK_SET);
        printf("\n");
    }
    else if(value == 2)
    {
        printf("Input the brand name:\n");
        scanf("%s", &brandname);
        up(brandname);
        const size_t line_size = 100;
        char* line = malloc(line_size);
        while (fgets(line, line_size, fp) != NULL)
        {
            if(strstr(line, brandname) != NULL )
                printf(line);
        }
        free(line);
        fseek(fp, 0, SEEK_SET);
        printf("\n");
    }
    else if(value == 3)
    {
        printf("Input the chipset type:\n");
        scanf("%s", &chiptype);
        up(chiptype);
        const size_t line_size = 100;
        char* line = malloc(line_size);
        while (fgets(line, line_size, fp) != NULL)
        {
            if(strstr(line, chiptype) != NULL )
                printf(line);
        }
        free(line);
        fseek(fp, 0, SEEK_SET);
        printf("\n");
    }
    else if(value == 4)
    {
        printf("Input the model(use the format |series_number|(ex: rtx_2060)):\n");
        scanf("%s", &gpumodel);
        up(gpumodel);
        const size_t line_size = 100;
        char* line = malloc(line_size);
        while (fgets(line, line_size, fp) != NULL)
        {
            if(strstr(line, gpumodel) != NULL )
                printf(line);
        }
        free(line);
        fseek(fp, 0, SEEK_SET);
        fclose(fp);
        printf("\n");
    }

    else if(value == 5)
    {
        struct GPU input;
        addGPU(&input);
        addToFile(fp, &input);
        printf("\n");
    }
    else if(value == 6)
    {
        printf("Input the brand of the gpu you want to delete:\n");
        scanf("%s", &br);
        up(br);

        printf("Input the chipset of the gpu you want to delete:\n");
        scanf("%s", &chi);
        up(chi);

        printf("Input the model of he gpu you want to delete:\n");
        scanf("%s", &mode);
        up(mode);

        //fp = fopen("GPUfile.c", "r");
        //tempFile = fopen("delete_line_tmp", "w");

        //rewind(fp);
        fseek(fp, 0, SEEK_SET);
        deleteLine(fp, tempFile, br, chi, mode);

        // fclose(fp);
        //fclose(tempFile);

        remove("GPUfile.c");
        rename("delete_line_tmp", "GPUfile.c");
        printf("\n");

    }
    else
        printf("Wrong choice, please try again.\n");

    return 0;
}
