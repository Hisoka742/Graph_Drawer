#ifndef FRUCHTERMAN_REINGOLD_H
#define FRUCHTERMAN_REINGOLD_H

#include <vector>
#include "graph.h"

void fruchterman_reingold(std::vector<Point>& positions, const std::vector<std::pair<int, int>>& edges);

#endif // FRUCHTERMAN_REINGOLD_H
