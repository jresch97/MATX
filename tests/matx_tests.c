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

#define F0 (0.0f)
#define F1 (1.0f)

#define FEQ(a, b) (fabs(a - b) <= FLT_EPSILON)

MATX(MAT4F, MAT4F, mat4f, 4, float, int, int, "%f")

typedef float VEC4F[4];

VEC4F MULVFACT = { 1.0f, 2.0f, 3.0f, 4.0f };

static inline int vec4feq(VEC4F a, VEC4F b)
{
        for (int i = 0; i < 4; i++) if (!FEQ(a[i], b[i])) return 0;
        return 1;
}

static inline void vec4fprintf(VEC4F v)
{
        printf("%f %f %f %f\n", v[0], v[1], v[2], v[3]);
}

int main()
{
        VEC4F v;
        MAT4F in, id, tr, pr;
        for (int i = 0; i < MAT4FSZ; i++) ((float*)tr)[i] = (float)(i + 1);
        printf("============================================================\n");
        printf("= MAT4FDIM test\n");
        printf("============================================================\n");
        printf("%d\n", MAT4FDIM);
        assert(MAT4FDIM == 4);
        printf("============================================================\n");
        printf("= MAT4FDIM passed\n");
        printf("============================================================\n");
        printf("= MAT4FSZ test\n");
        printf("============================================================\n");
        printf("%d\n", MAT4FSZ);
        assert(MAT4FSZ == 16);
        printf("============================================================\n");
        printf("= MAT4FSZ passed\n");
        printf("============================================================\n");
        printf("= mat4finit test\n");
        printf("============================================================\n");
        mat4finit(in, 5.0f);
        mat4fprintf(in);
        assert(mat4feqs(in, 5.0f));
        printf("============================================================\n");
        printf("= mat4finit passed\n");
        printf("============================================================\n");
        printf("= mat4fid test\n");
        printf("============================================================\n");
        mat4fid(id);
        mat4fprintf(id);
        assert(id[0][0] == F1 && id[0][1] == F0 && id[0][2] == F0 && id[0][3] == F0 &&
               id[1][0] == F0 && id[1][1] == F1 && id[1][2] == F0 && id[1][3] == F0 &&
               id[2][0] == F0 && id[2][1] == F0 && id[2][2] == F1 && id[2][3] == F0 &&
               id[3][0] == F0 && id[3][1] == F0 && id[3][2] == F0 && id[3][3] == F1);
        printf("============================================================\n");
        printf("= mat4fid passed\n");
        printf("============================================================\n");
        printf("= mat4fmul test\n");
        printf("============================================================\n");
        mat4fmul(pr, in, id);
        mat4fprintf(pr);
        assert(mat4feqs(pr, 5.0f));
        printf("============================================================\n");
        printf("= mat4fmul passed\n");
        printf("============================================================\n");
        printf("= mat4fmulv test\n");
        printf("============================================================\n");
        mat4fmulv(v, id, MULVFACT);
        vec4fprintf(v);
        assert(vec4feq(v, MULVFACT));
        printf("============================================================\n");
        printf("= mat4fmulv passed\n");
        printf("============================================================\n");
        printf("= mat4ftransp test\n");
        printf("============================================================\n");
        mat4ftransp(tr, tr);
        mat4fprintf(tr);
        assert(tr[0][0] == 1.0f && tr[0][1] == 5.0f && tr[0][2] ==  9.0f && tr[0][3] == 13.0f &&
               tr[1][0] == 2.0f && tr[1][1] == 6.0f && tr[1][2] == 10.0f && tr[1][3] == 14.0f &&
               tr[2][0] == 3.0f && tr[2][1] == 7.0f && tr[2][2] == 11.0f && tr[2][3] == 15.0f &&
               tr[3][0] == 4.0f && tr[3][1] == 8.0f && tr[3][2] == 12.0f && tr[3][3] == 16.0f);
        printf("============================================================\n");
        printf("= mat4ftransp passed\n");
        printf("============================================================\n");
        return 0;
 }