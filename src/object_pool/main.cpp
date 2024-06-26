/*
 * @Description:
 * @Author: lize
 * @Date: 2024-06-16
 * @LastEditors: lize
 */
#include "object_pool.h"

int main() {
  BoxPool box_pool;
  Box::BoxSPtr box1 = box_pool.getBox(1, 2, 3);
  Box::BoxSPtr box2 = box_pool.getBox(4, 5, 6);
  Box::BoxSPtr box3 = box_pool.getBox(7, 8, 9);
  Box::BoxSPtr box4 = box_pool.getBox(10, 11, 12);
  box_pool.print();

  box_pool.recycleBox(box2);
  box2 = box_pool.getBox(11, 22, 33);
  box_pool.print();
  return 0;
}
