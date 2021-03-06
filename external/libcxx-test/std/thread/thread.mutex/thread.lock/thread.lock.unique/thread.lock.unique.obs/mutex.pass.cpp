//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// UNSUPPORTED: libcpp-has-no-threads

// <mutex>

// template <class Mutex> class unique_lock;

// mutex_type *mutex() const;

#include <mutex>
#include <cassert>
#include "libcxx_tc_common.h"

static std::mutex m;

int tc_libcxx_thread_thread_lock_unique_obs_mutex(void)
{
    std::unique_lock<std::mutex> lk0;
    TC_ASSERT_EXPR(lk0.mutex() == nullptr);
    std::unique_lock<std::mutex> lk1(m);
    TC_ASSERT_EXPR(lk1.mutex() == &m);
    lk1.unlock();
    TC_ASSERT_EXPR(lk1.mutex() == &m);
    TC_SUCCESS_RESULT();
    return 0;
}
