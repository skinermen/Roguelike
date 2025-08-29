﻿#pragma once
#include "../Scores/RecordManager.h"

namespace RogaliqueGame
{
    class IRecordSaveStrategy
    {
    public:
        virtual ~IRecordSaveStrategy() = default;
        virtual void Save(RecordManager& manager, int score) = 0;
    };
}