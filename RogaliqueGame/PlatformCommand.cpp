#include "PlatformCommand.h"
#include "Platform.h"

namespace RogaliqueGame
{

    void IncreaseSizeCommand::Execute(Platform& platform)
    {
        platform.ApplySizeBonus(factor, duration);
    }

    void DecreaseSizeCommand::Execute(Platform& platform)
    {
        platform.ApplySizeBonus(factor, duration);
    }

}