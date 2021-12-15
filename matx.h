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

#ifndef MATX_MATX_H
#define MATX_MATX_H

#include <stdio.h>
#include <string.h>

#define MATX_EXPORT static inline

#define MATX(NAME, DELIM, N, T, SCALAR_FMT_STR) \
\
typedef T NAME[N][N]; \
\
MATX_EXPORT void NAME ## DELIM ## init(NAME out, T val) \
{ \
        for (int i = 0; i < N; i++) { \
                for (int j = 0; j < N; j++) out[i][j] = val; \
        } \
} \
\
MATX_EXPORT void NAME ## DELIM ## ident(NAME out) \
{ \
        for (int i = 0; i < N; i++) { \
                for (int j = 0; j < N; j++) { \
                        out[i][j] = (i == j ? (T)1 : (T)0); \
                } \
        } \
} \
\
MATX_EXPORT void NAME ## DELIM ## mul(NAME out, NAME a, NAME b) \
{ \
        NAME tmp; \
        for (int i = 0; i < N; i++) { \
                for (int j = 0; j < N; j++) { \
                        T sum = (T)0; \
                        for (int k = 0; k < N; k++) { \
                                sum += a[i][k] * b[k][j]; \
                        } \
                        tmp[i][j] = sum;\
                } \
        } \
        memcpy(out, tmp, N * N * sizeof(T)); \
} \
\
MATX_EXPORT void NAME ## DELIM ## mulv(T out[N], NAME mat, T vec[N]) \
{ \
        T tmp[N]; \
        for (int i = 0; i < N; i++) { \
                T sum = (T)0; \
                for (int j = 0; j < N; j++) sum += mat[i][j] * vec[j]; \
                tmp[i] = sum; \
        } \
        memcpy(out, tmp, N * sizeof(T)); \
} \
\
MATX_EXPORT void NAME ## DELIM ## transp(NAME out, NAME mat) \
{ \
        NAME tmp; \
        for (int i = 0; i < N; i++) { \
                for (int j = 0; j < N; j++) tmp[i][j] = mat[j][i]; \
        } \
        memcpy(out, tmp, N * N * sizeof(T)); \
} \
\
MATX_EXPORT void NAME ## DELIM ## fprintf(FILE *f, NAME mat) \
{ \
        for (int i = 0; i < N; i++) { \
                for (int j = 0; j < N; j++) { \
                        fprintf(f, SCALAR_FMT_STR, mat[i][j]); \
                        if (j < (N - 1)) fprintf(f, " "); \
                } \
                if (i < (N - 1)) fprintf(f, "\n"); \
        } \
        fprintf(f, "\n"); \
} \
\
MATX_EXPORT void NAME ## DELIM ## printf(NAME mat) \
{ \
        NAME ## DELIM ## fprintf(stdout, mat); \
}

#endif