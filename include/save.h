#ifndef SAVE_H
#define SAVE_H

#include <vector>

#include "shop.h"
#include "item.h"


void save(shop);
shop load();

void saveInventory(shop);
std::vector<item> loadInventory();
#endif // SAVE_H
