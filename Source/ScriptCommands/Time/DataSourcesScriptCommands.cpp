#include "ScriptCommands/Time/TimeManagerScriptCommands.h"
#include "ScriptCommands/ScriptCommandUtils.h"

#include "Time/DataSources.h"

using namespace MCF::Time;


namespace MCF::Lua::Time::DataSourcesScriptCommands
{
  //------------------------------------------------------------------------------------------------
  void initialize(sol::state& state)
  {
    sol::table dataSources = state.create_named_table("TimeDataSources");
    dataSources["CURRENT_MONTH"] = DataSources::CURRENT_MONTH;
  }
}