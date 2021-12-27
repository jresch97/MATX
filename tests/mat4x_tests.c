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
#include <matx.h>
#include <mat4x.h>

#define F0 (0.0f)
#define F1 (1.0f)
#define PI (3.14159265359)

#define D2R(d)    (d * (PI / 180.0))
#define FEQ(a, b) (fabs(a - b) <= FLT_EPSILON)

MATX (MAT4F, MAT4F, mat4f, 4, float, int, int, "%f")
MAT4X(MAT4F, MAT4F, mat4f, float, sqrtf, sinf, cosf, tanf)

typedef float VEC3F[3];
typedef float VEC4F[4];

VEC3F POS   = { 1.0f, 2.0f, 3.0f };
VEC4F RIGHT = { 1.0f, 0.0f, 0.0f, 1.0f };
VEC4F UP    = { 0.0f, 1.0f, 0.0f, 1.0f };
VEC4F FWD   = { 0.0f, 0.0f, 1.0f, 1.0f };

static inline int vec4feq(VEC4F a, VEC4F b)
{
        for (int i = 0; i < 4; i++) if (!FEQ(a[i], b[i])) return 0;
        return 1;
}

static inline void vec4fabs(VEC4F out, VEC4F v)
{
        for (int i = 0; i < 4; i++) out[i] = fabs(v[i]);
}

static inline void vec4fprintf(VEC4F v)
{
        printf("%f %f %f %f\n", v[0], v[1], v[2], v[3]);
}

int main()
{
        VEC4F v;
        MAT4F id, tr, rx, ry, rz;
        float xr = D2R(90.0f), xc = cosf(xr), xs = sinf(xr);
        float yr = D2R(90.0f), yc = cosf(yr), ys = sinf(yr);
        float zr = D2R(90.0f), zc = cosf(zr), zs = sinf(zr);
        printf("============================================================\n");
        printf("= MAT4FID test\n");
        printf("============================================================\n");
        memcpy(id, MAT4FID, MAT4FSZ * sizeof(float));
        mat4fprintf(id);
        assert(id[0][0] == F1 && id[0][1] == F0 && id[0][2] == F0 && id[0][3] == F0 &&
               id[1][0] == F0 && id[1][1] == F1 && id[1][2] == F0 && id[1][3] == F0 &&
               id[2][0] == F0 && id[2][1] == F0 && id[2][2] == F1 && id[2][3] == F0 &&
               id[3][0] == F0 && id[3][1] == F0 && id[3][2] == F0 && id[3][3] == F1);
        printf("============================================================\n");
        printf("= MAT4FID passed\n");
        printf("============================================================\n");
        printf("= mat4ftransl test\n");
        printf("============================================================\n");
        mat4ftransl(tr, POS);
        mat4fprintf(tr);
        assert(tr[0][0] == F1 && tr[0][1] == F0 && tr[0][2] == F0 && tr[0][3] == POS[0] &&
               tr[1][0] == F0 && tr[1][1] == F1 && tr[1][2] == F0 && tr[1][3] == POS[1] &&
               tr[2][0] == F0 && tr[2][1] == F0 && tr[2][2] == F1 && tr[2][3] == POS[2] &&
               tr[3][0] == F0 && tr[3][1] == F0 && tr[3][2] == F0 && tr[3][3] == F1);
        printf("============================================================\n");
        printf("= mat4ftransl passed\n");
        printf("============================================================\n");
        printf("= mat4frotx test\n");
        printf("============================================================\n");
        mat4frotx(rx, xr);
        mat4fprintf(rx);
        assert(rx[0][0] == F1 && rx[0][1] ==  F0 && rx[0][2] == F0 && rx[0][3] == F0 &&
               rx[1][0] == F0 && rx[1][1] ==  xc && rx[1][2] == xs && rx[1][3] == F0 &&
               rx[2][0] == F0 && rx[2][1] == -xs && rx[2][2] == xc && rx[2][3] == F0 &&
               rx[3][0] == F0 && rx[3][1] ==  F0 && rx[3][2] == F0 && rx[3][3] == F1);
        mat4fmulv(v, rx, UP);
        vec4fabs(v, v);
        vec4fprintf(v);
        assert(vec4feq(v, FWD));
        printf("============================================================\n");
        printf("= mat4frotx passed\n");
        printf("============================================================\n");
        printf("= mat4froty test\n");
        printf("============================================================\n");
        mat4froty(ry, yr);
        mat4fprintf(ry);
        assert(ry[0][0] == yc && ry[0][1] == F0 && ry[0][2] == -ys && ry[0][3] == F0 &&
               ry[1][0] == F0 && ry[1][1] == F1 && ry[1][2] ==  F0 && ry[1][3] == F0 &&
               ry[2][0] == ys && ry[2][1] == F0 && ry[2][2] ==  yc && ry[2][3] == F0 &&
               ry[3][0] == F0 && ry[3][1] == F0 && ry[3][2] ==  F0 && ry[3][3] == F1);
        mat4fmulv(v, ry, RIGHT);
        vec4fabs(v, v);
        vec4fprintf(v);
        assert(vec4feq(v, FWD));
        printf("============================================================\n");
        printf("= mat4froty passed\n");
        printf("============================================================\n");
        printf("= mat4frotz test\n");
        printf("============================================================\n");
        mat4frotz(rz, zr);
        mat4fprintf(rz);
        assert(rz[0][0] == zc && rz[0][1] == -zs && rz[0][2] == F0 && rz[0][3] == F0 &&
               rz[1][0] == zs && rz[1][1] ==  zc && rz[1][2] == F0 && rz[1][3] == F0 &&
               rz[2][0] == F0 && rz[2][1] ==  F0 && rz[2][2] == F1 && rz[2][3] == F0 &&
               rz[3][0] == F0 && rz[3][1] ==  F0 && rz[3][2] == F0 && rz[3][3] == F1);
        mat4fmulv(v, rz, UP);
        vec4fabs(v, v);
        vec4fprintf(v);
        assert(vec4feq(v, RIGHT));
        printf("============================================================\n");
        printf("= mat4frotz passed\n");
        printf("============================================================\n");
        return 0;
}
