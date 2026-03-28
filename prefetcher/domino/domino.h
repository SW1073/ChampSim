#ifndef PREFETCHER_NEXT_LINE_H
#define PREFETCHER_NEXT_LINE_H

#include <cstdint>
#include <vector>

#include "address.h"
#include "modules.h"

struct domino : public champsim::modules::prefetcher {
  using prefetcher::prefetcher;
  uint32_t prefetcher_cache_operate(champsim::address addr, champsim::address ip, uint8_t cache_hit, bool useful_prefetch, access_type type,
                                    uint32_t metadata_in);
  uint32_t prefetcher_cache_fill(champsim::address addr, long set, long way, uint8_t prefetch, champsim::address evicted_addr, uint32_t metadata_in);

  // void prefetcher_initialize();
  // void prefetcher_branch_operate(champsim::address ip, uint8_t branch_type, champsim::address branch_target) {}
  // void prefetcher_cycle_operate() {}
  // void prefetcher_final_stats() {}

  typedef struct {
      champsim::address addr;
  } HistoryTableEntry_t;

  typedef struct {
      HistoryTableEntry_t *ht_entry;
  } IndexTableEntry_t;

  // TO-ADD: History Table - appends every observed cache miss to its end
  //    ?CIRCULAR BUFFER?
  std::vector<HistoryTableEntry_t> historyTable;
  // TO-ADD: Index Table   - auxiliary set-associative structure that stores a pointer to every observed miss address to its last occurrence in the History Table
  //    ?HASH MAP?
  std::vector<IndexTableEntry_t> indexTable;
};

#endif
