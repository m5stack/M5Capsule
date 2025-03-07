/*
 *SPDX-FileCopyrightText: 2025 M5Stack Technology CO LTD
 *
 *SPDX-License-Identifier: MIT
 */

#include "M5Capsule.h"

using namespace m5;

M5_CAPSULE M5Capsule;

void M5_CAPSULE::begin()
{
    M5.begin();
}

void M5_CAPSULE::begin(m5::M5Unified::config_t cfg)
{
    M5.begin(cfg);
}

void M5_CAPSULE::update(void)
{
    M5.update();
}
