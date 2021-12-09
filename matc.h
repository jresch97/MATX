/**
 *
 * Author: Jared B. Resch
 *
 * This file is part of MATX.
 *
 * MATX is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * MATX is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with MATX. If not, see <https://www.gnu.org/licenses/>.
 *
 */

#ifndef MATX_MATC_H
#define MATX_MATC_H

#include "matx.h"
#include "mat4.h"

#include <math.h>

MATX(mat2f, 2, float, "%f")
MATX(mat3f, 3, float, "%f")
MATX(mat4f, 4, float, "%f")

MATX(mat2d, 2, double, "%lf")
MATX(mat3d, 3, double, "%lf")
MATX(mat4d, 4, double, "%lf")

MATX_MAT4_HELPERS(mat4f, MAT4F, float, sqrtf, tanf)
MATX_MAT4_HELPERS(mat4d, MAT4D, float, sqrt, tan)

#endif