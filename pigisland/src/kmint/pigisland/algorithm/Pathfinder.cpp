#include "Pathfinder.h"

int kmint::pigisland::Pathfinder::get_lowest(kmint::map::map_graph &graph, const std::vector<int> &closedList,
                                             std::map<int, double> &distances) const
{
    int min = std::numeric_limits<int>::max();
    int node_id = 0;
    for (auto i = node_id; i < graph.num_nodes(); i++) {
        if (std::find(closedList.begin(), closedList.end(), graph[i].node_id()) == closedList.end() && distances[graph[i].node_id()] <= min) {
            min = distances[graph[i].node_id()];
            node_id = graph[i].node_id();
        }
    }

    return node_id;
}

std::vector<int>
kmint::pigisland::Pathfinder::reconstruct_path(std::map<int, int> &cameFrom, int current, int destination) const
{
    int cur = destination;
    std::vector<int> path;
    while(cur != current) {
        cur = cameFrom[cur];
        path.emplace_back(cur);
    }

    return path;
}