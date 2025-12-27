#include "noalloc/noalloc_guard.h"

#include <iostream>

namespace noalloc {

thread_local bool g_noalloc{false};

} // namespace noalloc

void* operator new(std::size_t size) {
  if(noalloc::g_noalloc) {
    std::cerr << "Illegal heap allocation\n";
    std::abort();
  }
  return malloc(size);
}
