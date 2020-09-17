#include "player.h"

MoveManager::MoveManager(std::shared_ptr<Player>& player, std::shared_ptr<Map>& map) : m_map(map), m_player(player) {}

void MoveManager::processInputAndMove(const std::string& inputStr) {
    std::regex r("([rldue]){1}");
    std::smatch result;
    if (std::regex_match(inputStr, result, r)) {
        if (*(result.begin()) == "r" && ((m_player->posX() + 1) < m_map->width())) {
            m_player->movePlayer(MoveManager::Direction::Right);
        } else if (*(result.begin()) == "l" && (int)(m_player->posX() - 1) > (int)-1) {
            m_player->movePlayer(MoveManager::Direction::Left);
        } else if (*(result.begin()) == "u" && (int)(m_player->posY() - 1) > (int) -1) {
            m_player->movePlayer(MoveManager::Direction::Up);
        } else if (*(result.begin()) == "d" && (int)(m_player->posY() + 1) < (int)m_map->height()) {
            m_player->movePlayer(MoveManager::Direction::Down);
        } else {
            std::cout << "invalid direction\n";
            return;
        }
    } else {
        std::cout << "invalid direction\n";
        return;
    }
    m_map->outputMap();
}
