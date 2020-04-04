#include "Lua/ScriptCommands/MCFScriptCommands.h"
#include "Lua/ScriptCommands/Animation/ScriptCommands.h"
#include "Lua/ScriptCommands/Locations/LocationsScriptCommands.h"
#include "Lua/ScriptCommands/GameEvents/GameEventsScriptCommands.h"
#include "Lua/ScriptCommands/Notifications/NotificationsScriptCommands.h"
#include "Lua/ScriptCommands/Family/FamilyScriptCommands.h"
#include "Lua/ScriptCommands/Money/MoneyScriptCommands.h"
#include "Lua/ScriptCommands/Stats/StatsScriptCommands.h"
#include "Lua/ScriptCommands/Persistence/PersistenceScriptCommands.h"
#include "Lua/ScriptCommands/Time/TimeScriptCommands.h"


namespace MCF::Lua::MCFScriptCommands
{
  //------------------------------------------------------------------------------------------------
  void initialize()
  {
    Animation::ScriptCommands::initialize();
    Locations::ScriptCommands::initialize();
    GameEvents::ScriptCommands::initialize();
    Notifications::ScriptCommands::initialize();
    Family::ScriptCommands::initialize();
    Money::ScriptCommands::initialize();
    Stats::ScriptCommands::initialize();
    Persistence::ScriptCommands::initialize();
    Time::ScriptCommands::initialize();
  }
}