
#pragma once

#include "mydependency_export.h"

#include <typeinfo>
#include <cassert>

template <typename T>
T* registerType();

MYDEPENDENCY_EXPORT void* registerTypeInternal(const std::type_info & typeinfo, void* def);

MYDEPENDENCY_EXPORT void* lookupTypeInternal(const std::type_info & typeinfo);

template <typename T>
inline T* registerType()
{
   void* ptr = lookupTypeInternal(typeid(T));

   if (ptr == nullptr)
   {
      ptr = registerTypeInternal(typeid(T), new T);
      assert (ptr != nullptr);
   }

   return static_cast<T*>(ptr);
}
