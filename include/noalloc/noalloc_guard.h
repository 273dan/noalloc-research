#pragma once

namespace noalloc {
extern thread_local bool g_noalloc;

struct ScopedNoAlloc {
  ScopedNoAlloc() { g_noalloc = true; }
  ~ScopedNoAlloc() { g_noalloc = false; }

  // Delete copy/move to prevent leakage

  ScopedNoAlloc(const ScopedNoAlloc&) = delete;
  ScopedNoAlloc operator=(const ScopedNoAlloc&) = delete;

  ScopedNoAlloc(ScopedNoAlloc&&) = delete;
  ScopedNoAlloc operator=(ScopedNoAlloc&&) = delete;
};
}  // namespace noalloc
