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
#include <math.h>
#include <mat4.h>

MATX(mat4f, _, 4, float, "%f")
MATX_MAT4_HELPERS(mat4f, MAT4F, _, float, sqrtf, sinf, cosf, tanf)

int main()
{
       mat4f id, tr;
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
       return 0;
}