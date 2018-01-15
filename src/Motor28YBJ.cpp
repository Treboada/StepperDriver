// Motor28YBJ.cpp
/*
 * A C/C++ asynchronous library to drive stepper motors.
 * Copyright (C) 2018 Rafa Couto <caligari@treboada.net>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published
 * by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * See LICENSE for details.
 *
 */

#include "Motor28YBJ.h"
#include <Arduino.h>

const static uint8_t step_pattern[] = {
    B00011, B00110, B01100, B01001, B00011, B00110, B01100, B01001
};

Motor28YBJ::Motor28YBJ(const Config* config)
{
    _config = config;
    _direction = DIRECTION_CW;
    _pattern_index = 0;
}

void Motor28YBJ::init()
{
    pinMode(_config->pin_in1, OUTPUT);
    pinMode(_config->pin_in2, OUTPUT);
    pinMode(_config->pin_in3, OUTPUT);
    pinMode(_config->pin_in4, OUTPUT);

    // set coils in row:
    for (int s = 1; s <= 4; s++) doStep();
}

void Motor28YBJ::doStep()
{
    _pattern_index += (_direction + 8);
    _pattern_index %= 8;
    uint8_t pattern = step_pattern[_pattern_index];

    digitalWrite(_config->pin_in1, bitRead(pattern, 0));
    digitalWrite(_config->pin_in2, bitRead(pattern, 1));
    digitalWrite(_config->pin_in3, bitRead(pattern, 2));
    digitalWrite(_config->pin_in4, bitRead(pattern, 3));
}

