/*
 * Copyright (C) 2015-2020, Wazuh Inc.
 *
 * This program is free software; you can redistribute it
 * and/or modify it under the terms of the GNU General Public
 * License (version 2) as published by the FSF - Free Software
 * Foundation.
 */

#include "run_check.h"
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "./run_check.h"

struct state_t state;

WINBOOL wrap_SetThreadPriority (HANDLE hThread, int nPriority) {
    check_expected(hThread);
    check_expected(nPriority);
    return mock();
}

HANDLE wrap_GetCurrentThread (VOID) {
    return mock_type(HANDLE);
}

DWORD wrap_GetLastError (VOID) {
    return mock();
}

VOID wrap_Sleep (DWORD dwMilliseconds) {
    state.sleep_seconds += dwMilliseconds;
}
