#pragma once
#include "../Scores/RecordManager.h"

namespace RoguelikeSpace
{
    class IRecordSaveStrategy
    {
    public:
        virtual ~IRecordSaveStrategy() = default;
        virtual void Save(RecordManager& manager, int score) = 0;
    };
}