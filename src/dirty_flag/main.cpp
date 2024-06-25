/*
 * @Description:
 * @Author: lize
 * @Date: 2024-06-16
 * @LastEditors: lize
 */
#include "dirty_flag.h"

int main() {
  GraphNode::GraphNodeSPtr root = std::make_shared<GraphNode>(0);
  root->init(2);
  root->updateSum(0, false);
  root->print();

  root->setChildValue(0, 100);
  root->updateSum(0, false);
}
