#pragma once

namespace RogaliqueGame
{
    class IScoreStrategy
    {
    public:
        virtual ~IScoreStrategy() = default;
        virtual int GetScore() const = 0;
    };

}