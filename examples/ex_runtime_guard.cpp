#include <print>
#include <vector>

#include "noalloc/noalloc_guard.h"

void slow_path() {
  // Stack allocation works fine...
  int x{5};

  // And so does heap allocation..
  std::vector<int> y(10);
}
void hot_path() {
  // Acquired a noalloc guard
  noalloc::ScopedNoAlloc guard{};

  // Stack allocation works fine...
  int x{5};

  // But heap allocations abort the program...
  std::vector<int> y(10);
}
int main() {
  slow_path();
  hot_path();
}
