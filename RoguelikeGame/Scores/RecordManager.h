#pragma once
#include <string>
#include <vector>

#include "../Menu/LeaderboardMenu.h"

namespace RoguelikeSpace
{
    class RecordManager
    {
    public:
        bool IsNewRecord(int score);
        void SaveRecord(const std::string& name, int score);
    private:
        std::vector<SLeaderboard> records;
        void Load();
        void Save() const;
    };
}
