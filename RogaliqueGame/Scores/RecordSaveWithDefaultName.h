#pragma once
#include "IRecordSaveStrategy.h"

namespace RogaliqueGame
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