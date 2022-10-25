#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
struct record {
 char name[64]; 
 char surname[32];  
 char gender; 
 char email[32];
 char phone_number[16];
 char address[32];
 char level_of_education[8];
 unsigned int income_level; 
 unsigned int expenditure; 
 char currency_unit[16];
 char currentMood[32];
 float height;
 unsigned int weight;
};

uint32_t converter(uint32_t val)
{
    uint32_t be = __builtin_bswap32(val);
    return be;
}



int main()
{
   
    

    struct record *Employee;

    Employee = (struct record *)malloc(55*sizeof(struct record));
    
    FILE *dat;
    dat = fopen("records.dat", "rb");
    int i;
    i=0;
    while (fread(&Employee[i], sizeof(struct record), 1, dat))
    {
        i++;
    }
    
    FILE  *XML;
    XML = fopen("Bin2XML.xml", "w"); 

    fprintf(XML, "<records>\n");

    int counter=1;
    while (counter<51)
    {
      fprintf(XML, "\t<row id= \"%d\">\n", counter);
        fprintf(XML, "\t\t<%s>%s</%s>\n", "name", Employee[counter].name,"name" );
        fprintf(XML, "\t\t<%s>%s</%s>\n", "surname", Employee[counter].surname, "surname");
        fprintf(XML, "\t\t<%s>%c</%s>\n", "gender", Employee[counter].gender, "gender");
        fprintf(XML, "\t\t<%s>%s</%s>\n", "email", Employee[counter].email,"email" );
        fprintf(XML, "\t\t<%s>%s</%s>\n","phone_number", Employee[counter].phone_number, "phone_number");
        fprintf(XML, "\t\t<%s>%s</%s>\n", "address", Employee[counter].address, "address");
        fprintf(XML, "\t\t<%s>%s</%s>\n", "level_of_education", Employee[counter].level_of_education, "level_of_education");
        fprintf(XML, "\t\t<%s '%u'>%u</%s>\n", "income_level",converter(Employee[counter].income_level),Employee[counter].income_level, "income_level");
        fprintf(XML, "\t\t<%s '%u'>%u</%s>\n", "expenditure",Employee[counter].expenditure,converter(Employee[counter].expenditure), "expenditure");
        fprintf(XML, "\t\t<%s>%s</%s>\n", "currency_unit", Employee[counter].currency_unit, "currency_unit");
        fprintf(XML, "\t\t<%s>%s</%s>\n", "currentMood", Employee[counter].currentMood,"currentMood");
        fprintf(XML, "\t\t<%s>%f</%s>\n", "height", Employee[counter].height, "height");
        fprintf(XML, "\t\t<%s>%u</%s>\n", "weight", Employee[counter].weight, "weight");
        fprintf(XML, "\t</row>\n");

        ++counter;
    }
    
    
    fprintf(XML, "</records>\0");
    free(Employee);
    fclose(dat);
    fclose(XML);
    
}

