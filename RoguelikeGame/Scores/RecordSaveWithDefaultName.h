#pragma once
#include "IRecordSaveStrategy.h"

namespace RoguelikeSpace
{
    class RecordSaveWithDefaultName : public IRecordSaveStrategy
    {
    public:
        void Save(RecordManager& manager, int score) override
        {
            manager.SaveRecord("XYZ", score);
        }
    };
}