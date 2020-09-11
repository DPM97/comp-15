#include "Square.h"

Square::Square(int newLength) {
  sideLength = newLength;
}

int Square::area() {
  return sideLength * sideLength;
}