/**
 *
 * Copyright (C) 2021 Jared B. Resch
 *
 * This file is part of MATX.
 * 
 * MATX is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 * 
 * MATX is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Affero General Public License for more details.
 * 
 * You should have received a copy of the GNU Affero General Public License
 * along with MATX. If not, see <https://www.gnu.org/licenses/>.
 *
 */

#ifndef MATX_MATX_H
#define MATX_MATX_H

#include <stdio.h>
#include <string.h>

#define MATX_EXPORT static inline
#define MATX_STDOUT stdout

#define MATX(NAME, CONST, FUN, N, T, SIZE_T, BOOL_T, FMT) \
\
typedef T NAME[N][N]; \
\
const SIZE_T CONST ## DIM = N;     \
const SIZE_T CONST ## SZ  = N * N; \
\
MATX_EXPORT void FUN ## init(NAME out, T s) \
{ \
        SIZE_T i, j;                                   \
        for (i = 0; i < N; i++) {                      \
                for (j = 0; j < N; j++) out[i][j] = s; \
        }                                              \
} \
\
MATX_EXPORT void FUN ## id(NAME out) \
{ \
        SIZE_T i, j;                                        \
        for (i = 0; i < N; i++) {                           \
                for (j = 0; j < N; j++) {                   \
                        out[i][j] = (i == j ? (T)1 : (T)0); \
                }                                           \
        }                                                   \
} \
\
MATX_EXPORT BOOL_T FUN ## eq(NAME a, NAME b) \
{ \
        SIZE_T i, j;                                              \
        for (i = 0; i < N; i++) {                                 \
                for (j = 0; j < N; j++) {                         \
                        if (a[i][j] != b[i][j]) return (BOOL_T)0; \
                }                                                 \
        }                                                         \
        return (BOOL_T)1;                                         \
} \
\
MATX_EXPORT BOOL_T FUN ## eqs(NAME m, T s) \
{ \
        SIZE_T i, j;                                        \
        for (i = 0; i < N; i++) {                           \
                for (j = 0; j < N; j++) {                   \
                        if (m[i][j] != s) return (BOOL_T)0; \
                }                                           \
        }                                                   \
        return (BOOL_T)1;                                   \
} \
\
MATX_EXPORT void FUN ## mul(NAME out, NAME a, NAME b) \
{ \
        T sum;                                            \
        NAME tmp;                                         \
        SIZE_T i, j, k;                                   \
        for (i = 0; i < N; i++) {                         \
                for (j = 0; j < N; j++) {                 \
                        sum = (T)0;                       \
                        for (k = 0; k < N; k++) {         \
                                sum += a[i][k] * b[k][j]; \
                        }                                 \
                        tmp[i][j] = sum;                  \
                }                                         \
        }                                                 \
        memcpy(out, tmp, N * N * sizeof(T));              \
} \
\
MATX_EXPORT void FUN ## mulv(T out[N], NAME m, T v[N]) \
{ \
        T tmp[N];                                              \
        SIZE_T i, j;                                           \
        for (i = 0; i < N; i++) {                              \
                T sum = (T)0;                                  \
                for (j = 0; j < N; j++) sum += m[i][j] * v[j]; \
                tmp[i] = sum;                                  \
        }                                                      \
        memcpy(out, tmp, N * sizeof(T));                       \
} \
\
MATX_EXPORT void FUN ## transp(NAME out, NAME m) \
{ \
        NAME tmp;                                            \
        SIZE_T i, j;                                         \
        for (i = 0; i < N; i++) {                            \
                for (j = 0; j < N; j++) tmp[i][j] = m[j][i]; \
        }                                                    \
        memcpy(out, tmp, N * N * sizeof(T));                 \
} \
\
MATX_EXPORT void FUN ## fprintf(FILE *f, NAME m) \
{ \
        SIZE_T i, j;                                      \
        for (i = 0; i < N; i++) {                         \
                for (j = 0; j < N; j++) {                 \
                        fprintf(f, FMT, m[i][j]);         \
                        if (j < (N - 1)) fprintf(f, " "); \
                }                                         \
                if (i < (N - 1)) fprintf(f, "\n");        \
        }                                                 \
        fprintf(f, "\n");                                 \
} \
\
MATX_EXPORT void FUN ## printf(NAME m) \
{ \
        SIZE_T i, j;                                  \
        for (i = 0; i < N; i++) {                     \
                for (j = 0; j < N; j++) {             \
                        printf(FMT, m[i][j]);         \
                        if (j < (N - 1)) printf(" "); \
                }                                     \
                if (i < (N - 1)) printf("\n");        \
        }                                             \
        printf("\n");                                 \
}

#endif
