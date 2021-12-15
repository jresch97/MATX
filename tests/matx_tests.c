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
#include <matx.h>

MATX(mat4f, _, 4, float, "%f")

int main()
{
       mat4f in, id, tr, pr;
       float v[4] = { 1.0f, 2.0f, 3.0f, 4.0f };
       for (int i = 0; i < 16; i++) ((float*)tr)[i] = (float)(i + 1);
       printf("================================================================================\n");
       printf("= mat4f_init test\n");
       printf("================================================================================\n");
       mat4f_init(in, 5.0f);
       mat4f_printf(in);
       assert(in[0][0] == 5.0f && in[0][1] == 5.0f && in[0][2] == 5.0f && in[0][3] == 5.0f &&
              in[1][0] == 5.0f && in[1][1] == 5.0f && in[1][2] == 5.0f && in[1][3] == 5.0f &&
              in[2][0] == 5.0f && in[2][1] == 5.0f && in[2][2] == 5.0f && in[2][3] == 5.0f &&
              in[3][0] == 5.0f && in[3][1] == 5.0f && in[3][2] == 5.0f && in[3][3] == 5.0f);
       printf("================================================================================\n");
       printf("= mat4f_init passed\n");
       printf("================================================================================\n");
       printf("= mat4f_ident test\n");
       printf("================================================================================\n");
       mat4f_ident(id);
       mat4f_printf(id);
       assert(id[0][0] == 1.0f && id[0][1] == 0.0f && id[0][2] == 0.0f && id[0][3] == 0.0f &&
              id[1][0] == 0.0f && id[1][1] == 1.0f && id[1][2] == 0.0f && id[1][3] == 0.0f &&
              id[2][0] == 0.0f && id[2][1] == 0.0f && id[2][2] == 1.0f && id[2][3] == 0.0f &&
              id[3][0] == 0.0f && id[3][1] == 0.0f && id[3][2] == 0.0f && id[3][3] == 1.0f);
       printf("================================================================================\n");
       printf("= mat4f_ident passed\n");
       printf("================================================================================\n");
       printf("= mat4f_mul test\n");
       printf("================================================================================\n");
       mat4f_mul(pr, in, id);
       mat4f_printf(pr);
       assert(pr[0][0] == 5.0f && pr[0][1] == 5.0f && pr[0][2] == 5.0f && pr[0][3] == 5.0f &&
              pr[1][0] == 5.0f && pr[1][1] == 5.0f && pr[1][2] == 5.0f && pr[1][3] == 5.0f &&
              pr[2][0] == 5.0f && pr[2][1] == 5.0f && pr[2][2] == 5.0f && pr[2][3] == 5.0f &&
              pr[3][0] == 5.0f && pr[3][1] == 5.0f && pr[3][2] == 5.0f && pr[3][3] == 5.0f);
       printf("================================================================================\n");
       printf("= mat4f_mul passed\n");
       printf("================================================================================\n");
       printf("= mat4f_mulv test\n");
       printf("================================================================================\n");
       mat4f_mulv(v, id, v);
       printf("%f %f %f %f\n", v[0], v[1], v[2], v[3]);
       assert(v[0] == 1.0f && v[1] == 2.0f && v[2] == 3.0f && v[3] == 4.0f);
       printf("================================================================================\n");
       printf("= mat4f_mulv passed\n");
       printf("================================================================================\n");
       printf("= mat4f_transp test\n");
       printf("================================================================================\n");
       mat4f_transp(tr, tr);
       mat4f_printf(tr);
       assert(tr[0][0] == 1.0f && tr[0][1] == 5.0f && tr[0][2] ==  9.0f && tr[0][3] == 13.0f &&
              tr[1][0] == 2.0f && tr[1][1] == 6.0f && tr[1][2] == 10.0f && tr[1][3] == 14.0f &&
              tr[2][0] == 3.0f && tr[2][1] == 7.0f && tr[2][2] == 11.0f && tr[2][3] == 15.0f &&
              tr[3][0] == 4.0f && tr[3][1] == 8.0f && tr[3][2] == 12.0f && tr[3][3] == 16.0f);
       printf("================================================================================\n");
       printf("= mat4f_transp passed\n");
       printf("================================================================================\n");
       return 0;
 }