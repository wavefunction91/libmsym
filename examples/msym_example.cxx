//
//  msym_example.cxx
//  libmsym
//
//  Created by David Williams-Young (26/8/2016) 
//
//  Distributed under the MIT License ( See LICENSE file or copy at http://opensource.org/licenses/MIT )
//

#include <stdio.h>
#include "example.hpp"

int main(int argc, const char * argv[]) {
    int ret = 1;
    if(argc == 2){
        ret = example_cxx(argv[1],NULL);
        fflush(stdout);
    } else {
        printf("usage msym_example <xyz-file>");
    }
    return ret;
}
