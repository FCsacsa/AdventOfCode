//
// Created by farkas13 on 16-12-2021.
//
#include "../../lib/adventLib.h"
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void _first_half(char *path);

void _second_half(char *path);

int main(int arg_c, char *arg_v[]) {
    if (arg_c < 2) return 1;
    if (arg_c > 2) logger = 1;

    printf("First part: \n");
    _first_half(arg_v[1]);
    printf("Second part:\n");
    _second_half(arg_v[1]);
}

void _first_half(char *path){

}

void _second_half(char *path){

}
