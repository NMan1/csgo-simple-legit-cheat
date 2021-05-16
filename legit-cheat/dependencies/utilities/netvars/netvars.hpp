#pragma once
#include <windows.h>
#include <SDKDDKVer.h>
#include <string.h>
#include <vadefs.h>
#include <stdio.h>
#include <xstring>
#include <Psapi.h>
#include <thread>
#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <string>
#include <vector>
#include <time.h>
#include <winuser.h>
#include <random>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <set>
#include <map>
#include <unordered_map>
#include <memory>
#include <thread>
#include <array>
#include <assert.h>
#include <deque>
#include <intrin.h>
#include <atomic>
#include <mutex>
#include <stdint.h>
#include <stdlib.h>
#include <process.h>
#include <Wincon.h>
#include <cstdint>
#include <chrono>
#include <Shlobj.h>
#include <future>
#include <Lmcons.h>
#include <tchar.h>
#include "../../../source-sdk/classes/recv_props.hpp"
#include "../../../source-sdk/classes/client_class.hpp"
#include "../../utilities/fnv.hpp"

#define NETVAR(table, prop, func_name, type) \
	type& func_name( ) { \
      static uintptr_t offset = 0; \
      if(!offset) \
      { offset = netvar_manager::get_netvar_offset(table,  prop); } \
	  \
      return *reinterpret_cast< type* >( uintptr_t( this ) + offset ); \
    }

#define NETVAR_PTR(table, prop, func_name, type) \
	type* func_name( ) { \
      static uintptr_t offset = 0; \
      if(!offset) \
      { offset = netvar_manager::get_netvar_offset(fnv::hash( table ), fnv::hash( prop ) ); } \
	  \
      return reinterpret_cast< type* >( uintptr_t( this ) + offset ); \
    }

#define OFFSET(type, var, offset) \
	type& var() { \
		return *(type*)(uintptr_t(this) + offset); \
	} \

namespace netvar_manager {
    intptr_t get_offset(recv_table* table, const char* tableName, const char* netvarName);
    intptr_t get_netvar_offset(const char* tableName, const char* netvarName);
}