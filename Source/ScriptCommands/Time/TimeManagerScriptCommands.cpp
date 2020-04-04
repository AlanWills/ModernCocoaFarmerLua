#include "Lua/ScriptCommands/Time/TimeManagerScriptCommands.h"
#include "UtilityHeaders/ScriptCommandHeaders.h"

#include "Time/TimeManager.h"

using namespace MCF::Time;


namespace sol
{
  template <>
  struct is_to_stringable<TimeManager> : std::false_type {};
}

namespace MCF::Lua::Time::TimeManagerScriptCommands
{
  namespace Internals
  {
    //------------------------------------------------------------------------------------------------
    void pause(TimeManager& timeManager)
    {
      timeManager.setPaused(true);
    }

    //------------------------------------------------------------------------------------------------
    void play(TimeManager& timeManager)
    {
      timeManager.setPaused(false);
    }
  }

  //------------------------------------------------------------------------------------------------
  void initialize()
  {
    Celeste::Lua::registerScriptableObjectUserType<TimeManager>(
      TimeManager::type_name(),
      sol::base_classes, sol::bases<Celeste::ScriptableObject>(),
      "setDataStore", &TimeManager::setDataStore,
      "getCurrentDay", &TimeManager::getCurrentDay,
      "getCurrentMonth", &TimeManager::getCurrentMonth,
      "getCurrentYear", &TimeManager::getCurrentYear,
      "pause", &Internals::pause,
      "play", &Internals::play,
      "isPaused", &TimeManager::isPaused,
      "update", &TimeManager::update);
  }
}