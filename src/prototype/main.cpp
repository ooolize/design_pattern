/*
 * @Description:
 * @Author: lize
 * @Date: 2024-06-16
 * @LastEditors: lize
 */
#include "prototype.h"

Repository repo{};
int main() {
  // 初始化仓库
  repo.addCommotity(CommodityType::MAIDONG,
                    std::make_shared<Drink>("maidong", 4.5));
  repo.addCommotity(CommodityType::PEPSI,
                    std::make_shared<Drink>("pepsi", 3.5));
  repo.addCommotity(CommodityType::ADCA, std::make_shared<Drink>("adCa", 5.5));
  repo.addCommotity(CommodityType::SHREDDED,
                    std::make_shared<Snack>("shredded", 3.5, 3));

  Box::BoxUPtr snack_box = std::make_unique<SnackBox>(3, 3);
  Box::BoxUPtr drink_box = std::make_unique<DrinkBox>(3, 3);
  for (int i = 0; i < 3; ++i) {
    repo.addBox(snack_box->clone());
    repo.addBox(drink_box->clone());
  }

  repo.show();
  return 0;
}