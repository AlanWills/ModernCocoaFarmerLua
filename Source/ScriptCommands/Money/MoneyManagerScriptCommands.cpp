#include "Lua/ScriptCommands/Money/MoneyManagerScriptCommands.h"
#include "ScriptCommands/ScriptCommandUtils.h"
#include "Money/MoneyManager.h"
#include "Stats/Modifier.h"
#include "sol/sol.hpp"

using namespace MCF::Money;


namespace sol
{
  template <>
  struct is_to_stringable<MoneyManager> : std::false_type {};
}

namespace MCF::Lua::Money::MoneyManagerScriptCommands
{
  //------------------------------------------------------------------------------------------------
  void initialize()
  {
    Celeste::Lua::registerScriptableObjectUserType<MoneyManager>(
      MoneyManager::type_name(),
      sol::base_classes, sol::bases<Celeste::ScriptableObject>(),
      "setDataStore", &MoneyManager::setDataStore,
      "getMoney", &MoneyManager::getMoney,
      "setMoney", &MoneyManager::setMoney,
      "applyMoneyModifier", &MoneyManager::applyMoneyModifier);
  }
}