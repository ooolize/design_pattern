/*
 * @Description:
 * @Author: lize
 * @Date: 2024-06-16
 * @LastEditors: lize
 */
#include "prototype.h"

int main() {
  RepositorySptr repo = std::make_shared<Repository>();
  // 初始化仓库
  repo->addCommotity(CommodityType::MAIDONG,
                     std::make_shared<Drink>("maidong", maidong_price));
  repo->addCommotity(CommodityType::PEPSI,
                     std::make_shared<Drink>("pepsi", pepsi_price));
  repo->addCommotity(CommodityType::ADCA,
                     std::make_shared<Drink>("adCa", adCa_price));
  repo->addCommotity(
    CommodityType::SHREDDED,
    std::make_shared<Snack>("shredded", shredded_price, false));

  Box::BoxUPtr snack_box = std::make_unique<SnackBox>(3, 3, repo);
  Box::BoxUPtr drink_box = std::make_unique<DrinkBox>(3, 3, repo);
  // snack_box->init(repo);
  // drink_box->init(repo);

  for (int i = 0; i < 3; ++i) {
    repo->addBox(snack_box->clone());
    repo->addBox(drink_box->clone());
  }

  repo->show();
  return 0;
}