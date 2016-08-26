//
//  example.cxx
//  libmsym
//
//
//  Distributed under the MIT License ( See LICENSE file or copy at http://opensource.org/licenses/MIT )
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "example.hpp"


int example_cxx(const char* in_file, msym_thresholds_t *thresholds){
   msym_element_t *elements_ptr;

   int length = read_xyz(in_file, &elements_ptr); 
   std::vector<msym_element_t> elements(elements_ptr,elements_ptr+length);
   free(elements_ptr); elements_ptr = NULL;

   MSym msym(elements);
   return 0;
}

int read_xyz(const char *name, msym_element_t **ratoms) {
    FILE *fp = fopen(name,"r");
    msym_element_t *a;
    int l;
    char buf[1024];
    if(NULL == fp){
        fprintf(stderr, "could not open file: %s\n",name);
        return -1;
    }
    if (NULL == fgets(buf, sizeof(buf), fp) || sscanf(buf," %d ",&l) != 1){
        fprintf(stderr,"Unable to read file %s\n",name);
        fclose(fp);
        return -1;
    }
    if(l < 300000) {
//      a = malloc(l*sizeof(msym_element_t));
        a = new msym_element_t[l];
        memset(a,0,l*sizeof(msym_element_t));
    } else {
        fprintf(stderr, "Too many elements in file %d\n",l);
        fclose(fp);
        return -1;
    }
    
    //char * fgets ( comment, sizeof(comment), fp );
    if(NULL != fgets(buf, sizeof(buf), fp)){
        printf("Comment: %.*s", (int)sizeof(buf), buf);
    }
    
    for (int i = 0; i < l && fgets(buf, sizeof(buf), fp) && sscanf(buf, "%s %lf %lf %lf", a[i].name, &(a[i].v[0]),  &(a[i].v[1]),  &(a[i].v[2])) == 4 && i < l; i++) {}
    *ratoms = a;
    fclose(fp);
    return l;
    
}
