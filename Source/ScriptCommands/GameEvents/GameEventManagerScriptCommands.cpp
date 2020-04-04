#include "ScriptCommands/GameEvents/GameEventManagerScriptCommands.h"
#include "ScriptCommands/ScriptCommandUtils.h"

#include "GameEvents/GameEventManager.h"
#include "GameEvents/GameEvent.h"
#include "Time/TimeManager.h"
#include "Money/MoneyManager.h"
#include "Family/FamilyManager.h"
#include "Locations/LocationsManager.h"

using namespace MCF::GameEvents;


namespace sol
{
  template <>
  struct is_to_stringable<GameEventManager> : std::false_type {};
}

namespace MCF::Lua::GameEvents::GameEventManagerScriptCommands
{
  namespace Internals
  {
    //------------------------------------------------------------------------------------------------
    void registerGameEvent(GameEventManager& gameEventManager, const std::string& prefabPath)
    {
      auto gameEvent = Celeste::ScriptableObject::load<GameEvent>(prefabPath);
      ASSERT(gameEvent != nullptr);

      if (gameEvent != nullptr)
      {
        gameEventManager.registerGameEvent(std::unique_ptr<const GameEvent>(gameEvent.release()));
      }
    }
  }

  //------------------------------------------------------------------------------------------------
  void initialize(sol::state& state)
  {
    Celeste::Lua::registerScriptableObjectUserType<GameEventManager>(
      state,
      GameEventManager::type_name(),
      sol::base_classes, sol::bases<Celeste::ScriptableObject>(),
      "setFamilyManager", &GameEventManager::setFamilyManager,
      "setMoneyManager", &GameEventManager::setMoneyManager,
      "setTimeManager", &GameEventManager::setTimeManager,
      "setLocationsManager", &GameEventManager::setLocationsManager,
      "setNotificationManager", &GameEventManager::setNotificationManager,
      "registerGameEvent", &Internals::registerGameEvent);
  }
}