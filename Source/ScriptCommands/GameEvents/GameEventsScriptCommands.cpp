#include "ScriptCommands/GameEvents/GameEventsScriptCommands.h"
#include "ScriptCommands/GameEvents/GameEventManagerScriptCommands.h"
#include "ScriptCommands/GameEvents/GameEventScriptCommands.h"


namespace MCF::Lua::GameEvents::ScriptCommands
{
  //------------------------------------------------------------------------------------------------
  void initialize(sol::state& state)
  {
    GameEventManagerScriptCommands::initialize(state);
    GameEventScriptCommands::initialize(state);
  }
}