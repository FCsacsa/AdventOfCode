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
  FILE *f = fopen(path, "r");
  int x_dist1;
  int x_dist2;
  int y_speed;
  int y_dist2;
  fscanf(f, "%d", &x_dist1);
  fscanf(f, "%d", &x_dist2);
  fscanf(f, "%d", &y_speed);
  fscanf(f, "%d", &y_dist2);
  y_speed = -y_speed;

  int h = 0;
  for (int i = 1; i < y_speed; i++) {
    if (logger == 1) printf("%d\n", h);
    h += i;
  }
  printf("The highest hight: %d\n", h);

  fclose(f);
}

void _second_half(char *path){

    FILE *f = fopen(path, "r");
    int x_dist1;
    int x_dist2;
    int y_dist1;
    int y_dist2;
    fscanf(f, "%d", &x_dist1);
    fscanf(f, "%d", &x_dist2);
    fscanf(f, "%d", &y_dist1);
    fscanf(f, "%d", &y_dist2);
    int y_speed = -y_dist1;


    int x_travel = 0;
    int x_speed;
    for (int i = 1; i < x_dist1; i++){
      x_travel += i;
      if (x_travel >= x_dist1 && x_travel <= x_dist2 && i <= y_speed){
        x_speed = i;
        break;
      }
    }
    if (logger == 1) printf("%d\n", x_speed);

    int count = 0;
    for (int y = -y_speed; y < y_speed; y++) {
      for (int x = x_speed; x <= x_dist2; x++) {
        for (int i = 1; i <= 2 * y_speed; i++) {
          int x_end = i * x - (i * (i - 1)) / 2;
          if (i > x) x_end = x * x -  (x * (x - 1)) / 2;
          int y_end = i * y - (i * (i - 1)) / 2;
          if (x_dist1 <= x_end && x_end <= x_dist2 && y_dist1 <= y_end && y_end <= y_dist2 ){
            if (logger == 1) printf("%2d,%3d --in %2d steps---> %2d,%3d\n", x, y, i, x_end, y_end);
            count++;
            break;
          }
        }
      }
    }

    printf("Possibilities: %d\n", count);

}
