
#include "mydependency.h"

#include <iostream>
#include <map>
#include <unordered_map>
#include <typeindex>

std::map<std::type_index, void*> mapping;

void* registerTypeInternal(const std::type_info& typeinfo, void* def)
{
   mapping.insert(std::make_pair(std::type_index(typeinfo), def));
   
   return def;
}

void* lookupTypeInternal (const std::type_info & typeinfo)
{
   auto it = mapping.find(std::type_index(typeinfo));
   auto it_end = mapping.end();

   return (it != it_end) ? it->second : nullptr;
}
