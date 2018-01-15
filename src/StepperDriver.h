// StepperDriver.h
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

#ifndef _STEPPER_DRIVER_H
#define _STEPPER_DRIVER_H

#include <stdint.h>
#include "Stepper.h"

class StepperDriver {

    public:

        // constructor
        StepperDriver(Stepper* motor);

        void setStepMillis(uint32_t millis)
            { _stepMillis = millis; }

        void start(uint8_t direction);
        void stop();

        void tick(uint64_t micros);

    private:

        Stepper* _motor;

        uint32_t _stepMillis;
        uint64_t _nextStep;

};

#endif // _STEPPER_DRIVER_H


