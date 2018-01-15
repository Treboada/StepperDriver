// Motor28YBJ.h
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

#ifndef _MOTOR_28YBJ_H
#define _MOTOR_28YBJ_H

#include <stdint.h>
#include "Stepper.h"

class Motor28YBJ : public Stepper {

    public:

        // pinout definition
        typedef struct {
            int8_t pin_in1;
            int8_t pin_in2;
            int8_t pin_in3;
            int8_t pin_in4;
        } Config;

        // constructor
        Motor28YBJ(const Config* config);

        // initialization
        void init();

    protected:

        void setDirection(uint8_t direction)
            { _direction = direction; }

        void doStep();

    private:

        const Config* _config;

        uint8_t _direction;
        int8_t _pattern_index;
};

#endif // _MOTOR_28YBJ_H
