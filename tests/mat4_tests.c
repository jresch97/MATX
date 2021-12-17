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

#include <assert.h>
#include <float.h>
#include <math.h>
#include <mat4.h>

#define PI                  (3.14159265359)
#define DEGS2RADS(degs)     (degs * (PI / 180.0))
#define FLTEQ(a, b)         (fabs(a - b) < FLT_EPSILON)

const float RIGHT[4]   = { 1.0f, 0.0f, 0.0f, 1.0f };
const float UP[4]      = { 0.0f, 1.0f, 0.0f, 1.0f };
const float FORWARD[4] = { 0.0f, 0.0f, 1.0f, 1.0f };

MATX(mat4f, _, 4, float, "%f")

MATX_MAT4_HELPERS(mat4f, MAT4F, _, float, sqrtf, sinf, cosf, tanf)

int main()
{
        float v[4];
        mat4f id, tr, rx, ry, rz;
        const float pos[3] = { 1.0f, 2.0f, 3.0f };
        memcpy(id, MAT4F_IDENT, 16 * sizeof(float));
        printf("================================================================================\n");
        printf("= MAT4F_IDENT test\n");
        printf("================================================================================\n");
        mat4f_printf(id);
        assert(id[0][0] == 1.0f && id[0][1] == 0.0f && id[0][2] == 0.0f && id[0][3] == 0.0f &&
               id[1][0] == 0.0f && id[1][1] == 1.0f && id[1][2] == 0.0f && id[1][3] == 0.0f &&
               id[2][0] == 0.0f && id[2][1] == 0.0f && id[2][2] == 1.0f && id[2][3] == 0.0f &&
               id[3][0] == 0.0f && id[3][1] == 0.0f && id[3][2] == 0.0f && id[3][3] == 1.0f);
        printf("================================================================================\n");
        printf("= MAT4F_IDENT passed\n");
        printf("================================================================================\n");
        printf("= mat4f_transl test\n");
        printf("================================================================================\n");
        mat4f_transl(tr, pos);
        mat4f_printf(tr);
        assert(tr[0][0] == 1.0f && tr[0][1] == 0.0f && tr[0][2] == 0.0f && tr[0][3] == 1.0f &&
               tr[1][0] == 0.0f && tr[1][1] == 1.0f && tr[1][2] == 0.0f && tr[1][3] == 2.0f &&
               tr[2][0] == 0.0f && tr[2][1] == 0.0f && tr[2][2] == 1.0f && tr[2][3] == 3.0f &&
               tr[3][0] == 0.0f && tr[3][1] == 0.0f && tr[3][2] == 0.0f && tr[3][3] == 1.0f);
        printf("================================================================================\n");
        printf("= mat4f_transl passed\n");
        printf("================================================================================\n");
        printf("= mat4f_rotx test\n");
        printf("================================================================================\n");
        float xrads = DEGS2RADS(90.0f), xcos = cosf(xrads), xsin = sinf(xrads);
        mat4f_rotx(rx, xrads);
        assert(rx[0][0] == 1.0f && rx[0][1] ==  0.0f && rx[0][2] == 0.0f && rx[0][3] == 0.0f &&
               rx[1][0] == 0.0f && rx[1][1] ==  xcos && rx[1][2] == xsin && rx[1][3] == 0.0f &&
               rx[2][0] == 0.0f && rx[2][1] == -xsin && rx[2][2] == xcos && rx[2][3] == 0.0f &&
               rx[3][0] == 0.0f && rx[3][1] ==  0.0f && rx[3][2] == 0.0f && rx[3][3] == 1.0f);
        mat4f_mulv(v, rx, UP);
        mat4f_printf(rx);
        printf("v=%f %f %f %f\n", v[0], v[1], v[2], v[3]);
        assert(FLTEQ(v[0], 0.0f) && FLTEQ(v[1], -0.0f) && FLTEQ(v[2], -1.0f) && FLTEQ(v[3], 1.0f));
        printf("================================================================================\n");
        printf("= mat4f_rotx passed\n");
        printf("================================================================================\n");
        printf("= mat4f_roty test\n");
        printf("================================================================================\n");
        float yrads = DEGS2RADS(90.0f), ycos = cosf(yrads), ysin = sinf(yrads);
        mat4f_roty(ry, yrads);
        printf("v=%f %f %f %f\n", v[0], v[1], v[2], v[3]);
        assert(ry[0][0] == ycos && ry[0][1] == 0.0f && ry[0][2] == -ysin && ry[0][3] == 0.0f &&
               ry[1][0] == 0.0f && ry[1][1] == 1.0f && ry[1][2] ==  0.0f && ry[1][3] == 0.0f &&
               ry[2][0] == ysin && ry[2][1] == 0.0f && ry[2][2] ==  ycos && ry[2][3] == 0.0f &&
               ry[3][0] == 0.0f && ry[3][1] == 0.0f && ry[3][2] ==  0.0f && ry[3][3] == 1.0f);
        mat4f_mulv(v, ry, RIGHT);
        mat4f_printf(ry);
        assert(FLTEQ(v[0], -0.0f) && FLTEQ(v[1], 0.0f) && FLTEQ(v[2], 1.0f) && FLTEQ(v[3], 1.0f));
        printf("================================================================================\n");
        printf("= mat4f_roty passed\n");
        printf("================================================================================\n");
        printf("= mat4f_rotz test\n");
        printf("================================================================================\n");
        float zrads = DEGS2RADS(90.0f), zcos = cosf(zrads), zsin = sinf(zrads);
        mat4f_rotz(rz, zrads);
        mat4f_printf(rz);
        assert(rz[0][0] == zcos && rz[0][1] == -zsin && rz[0][2] == 0.0f && rz[0][3] == 0.0f &&
               rz[1][0] == zsin && rz[1][1] ==  zcos && rz[1][2] == 0.0f && rz[1][3] == 0.0f &&
               rz[2][0] == 0.0f && rz[2][1] ==  0.0f && rz[2][2] == 1.0f && rz[2][3] == 0.0f &&
               rz[3][0] == 0.0f && rz[3][1] ==  0.0f && rz[3][2] == 0.0f && rz[3][3] == 1.0f);
        mat4f_mulv(v, rz, UP);
        printf("v=%f %f %f %f\n", v[0], v[1], v[2], v[3]);
        assert(FLTEQ(v[0], -1.0f) && FLTEQ(v[1], -0.0f) && FLTEQ(v[2], 0.0f) && FLTEQ(v[3], 1.0f));
        printf("================================================================================\n");
        printf("= mat4f_rotz passed\n");
        printf("================================================================================\n");
        return 0;
}
