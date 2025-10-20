#pragma once

namespace RoguelikeSpace
{
    class IScoreStrategy
    {
    public:
        virtual ~IScoreStrategy() = default;
        virtual int GetScore() const = 0;
    };

}