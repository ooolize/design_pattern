/*
 * @Description:
 * @Author: lize
 * @Date: 2024-06-16
 * @LastEditors: lize
 */
#include "flyweight.h"

int main() {
  Box box(3, 3);
  box.randomDisplay();
  box.show();
  box.getDrink(1, 1);
  return 0;
}