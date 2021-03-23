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
}x;
void up(char * temp) {
  char * name;
  name = strtok(temp,":");
  char *s = name;
  while (*s) {
    *s = toupper((unsigned char) *s);
    s++;
  }
}
  void low(char * temp) {
  char * name;
  name = strtok(temp,":");
  char *s = name;
  while (*s) {
    *s = tolower((unsigned char) *s);
    s++;

}
  }
int main()
{
    char c, brandname[21], chiptype[10], gpumodel[50];

    FILE* fp;
    fp= fopen("GPUfile.c", "r");

    printf("If you want to see all the GPU's, press ~ 1 ~ :\n");
    printf("If you want to search for a GPU brand, press ~ 2 ~ :\n");
    printf("If you want to search for a GPU chipset type, press ~ 3 ~ :\n");
    printf("If you want to search for a GPU model, press ~ 4 ~ :\n");
    printf("If you want to add a GPU, press ~ 5 ~ :\n");
    printf("If you want to delete a GPU, press ~ 6 ~ :\n");
    printf("If you want to modify a GPU's spec list, press ~ 7 ~ :\n");

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
    }
    else
        if(value == 2)
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
    }
    else
    if(value == 3)
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
    }
    else
        if(value == 4)
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
    }
   /* else
    {
        fclose(fp);
        if(value == 5)
         {
              printf("Input the brand: \n");
              scanf("%c", &x.brand);
              up(x.brand);

              printf("Input the chipset: \n");
              scanf("%c", &x.chipset);
              up(x.chipset);

              printf("Input the model: \n");
              scanf("%c", &x.model);
              up(x.model);

              printf("Input the cooling type: \n");
              scanf("%c", &x.cooling);
              low(x.cooling);

              printf("Input the price: \n");
              scanf("%c", &x.price);

              printf("Input the stock: \n");
              scanf("%c", &x.stock);

              fp= fopen("GPUfile.c", "a"); /


         }
    }*/





    return 0;
}
