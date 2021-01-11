//
//  main.c
//  largesizeprogramming.c
//
//  Created by revanthAVS on 02/08/20.
//  Copyright © 2020 revanthAVS. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    //WHAT YOU WANT TO DO?
    unsigned long r = 3849327482;
    unsigned long e = 1234567891;
    
    unsigned long result = (r*e);
    
    printf("The result of r * e = %lu\n",result);
    
    e = result/9;
    
    printf("the result of r / 9 = %lu\n", e);
    return 0;
}
