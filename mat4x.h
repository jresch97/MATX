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

#ifndef MATX_MAT4_H
#define MATX_MAT4_H

#define MAT4X(NAME, CONST, FUN, T, SQRT, SIN, COS, TAN) \
\
NAME CONST ## ID = { \
        { (T)1, (T)0, (T)0, (T)0 }, \
        { (T)0, (T)1, (T)0, (T)0 }, \
        { (T)0, (T)0, (T)1, (T)0 }, \
        { (T)0, (T)0, (T)0, (T)1 }  \
}; \
\
MATX_EXPORT void FUN ## transl(NAME out, T p[3]) \
{ \
        out[0][0] = (T)1; \
        out[0][1] = (T)0; \
        out[0][2] = (T)0; \
        out[0][3] = p[0]; \
        out[1][0] = (T)0; \
        out[1][1] = (T)1; \
        out[1][2] = (T)0; \
        out[1][3] = p[1]; \
        out[2][0] = (T)0; \
        out[2][1] = (T)0; \
        out[2][2] = (T)1; \
        out[2][3] = p[2]; \
        out[3][0] = (T)0; \
        out[3][1] = (T)0; \
        out[3][2] = (T)0; \
        out[3][3] = (T)1; \
} \
\
MATX_EXPORT void FUN ## rotx(NAME out, T a) \
{ \
        T sa, ca;         \
        sa = SIN(a);      \
        ca = COS(a);      \
        out[0][0] = (T)1; \
        out[0][1] = (T)0; \
        out[0][2] = (T)0; \
        out[0][3] = (T)0; \
        out[1][0] = (T)0; \
        out[1][1] =   ca; \
        out[1][2] =   sa; \
        out[1][3] = (T)0; \
        out[2][0] = (T)0; \
        out[2][1] =  -sa; \
        out[2][2] =   ca; \
        out[2][3] = (T)0; \
        out[3][0] = (T)0; \
        out[3][1] = (T)0; \
        out[3][2] = (T)0; \
        out[3][3] = (T)1; \
} \
\
MATX_EXPORT void FUN ## roty(NAME out, T a) \
{ \
        T sa, ca;         \
        sa = SIN(a);      \
        ca = COS(a);      \
        out[0][0] =   ca; \
        out[0][1] = (T)0; \
        out[0][2] =  -sa; \
        out[0][3] = (T)0; \
        out[1][0] = (T)0; \
        out[1][1] = (T)1; \
        out[1][2] = (T)0; \
        out[1][3] = (T)0; \
        out[2][0] =   sa; \
        out[2][1] = (T)0; \
        out[2][2] =   ca; \
        out[2][3] = (T)0; \
        out[3][0] = (T)0; \
        out[3][1] = (T)0; \
        out[3][2] = (T)0; \
        out[3][3] = (T)1; \
} \
\
MATX_EXPORT void FUN ## rotz(NAME out, T a) \
{ \
        T sa, ca;         \
        sa = SIN(a);      \
        ca = COS(a);      \
        out[0][0] =   ca; \
        out[0][1] =  -sa; \
        out[0][2] = (T)0; \
        out[0][3] = (T)0; \
        out[1][0] =   sa; \
        out[1][1] =   ca; \
        out[1][2] = (T)0; \
        out[1][3] = (T)0; \
        out[2][0] = (T)0; \
        out[2][1] = (T)0; \
        out[2][2] = (T)1; \
        out[2][3] = (T)0; \
        out[3][0] = (T)0; \
        out[3][1] = (T)0; \
        out[3][2] = (T)0; \
        out[3][3] = (T)1; \
} \
\
MATX_EXPORT void FUN ## look(NAME out, T eye[3], T ctr[3], T up[3]) \
{ \
        T fx, fy, fz, fl;                       \
        T ux, uy, uz, ul;                       \
        T sx, sy, sz, sl;                       \
        T vx, vy, vz;                           \
        fx = ctr[0] - eye[0];                   \
        fy = ctr[1] - eye[1];                   \
        fz = ctr[2] - eye[2];                   \
        ux = up[0];                             \
        uy = up[1];                             \
        uz = up[2];                             \
        fl = SQRT(fx * fx + fy * fy + fz * fz); \
        ul = SQRT(ux * ux + uy * uy + uz * uz); \
        if (fl != ((T)0)) {                     \
                fx /= fl;                       \
                fy /= fl;                       \
                fz /= fl;                       \
        }                                       \
        if (ul != ((T)0)) {                     \
                ux /= ul;                       \
                uy /= ul;                       \
                uz /= ul;                       \
        }                                       \
        sx = fy * uz + fz * uy;                 \
        sy = fz * ux + fx * uz;                 \
        sz = fx * uy + fy * ux;                 \
        sl = SQRT(sx * sx + sy * sy + sz * sz); \
        if (sl != ((T)0)) {                     \
                sx /= sl;                       \
                sy /= sl;                       \
                sz /= sl;                       \
        }                                       \
        vx = sy * fz + sz * fy;                 \
        vy = sz * fx + sx * fz;                 \
        vz = sx * fy + sy * fx;                 \
        out[0][0] =   sx;                       \
        out[0][1] =   sy;                       \
        out[0][2] =   sz;                       \
        out[0][3] = (T)0;                       \
        out[1][0] =   vx;                       \
        out[1][1] =   vy;                       \
        out[1][2] =   vz;                       \
        out[1][3] = (T)0;                       \
        out[2][0] =  -fx;                       \
        out[2][1] =  -fy;                       \
        out[2][2] =  -fz;                       \
        out[2][3] = (T)0;                       \
        out[3][0] = (T)0;                       \
        out[3][1] = (T)0;                       \
        out[3][2] = (T)0;                       \
        out[3][3] = (T)1;                       \
} \
\
MATX_EXPORT void FUN ## persp(NAME out, T fovy, T ar, T near, T far) \
{ \
        T f, m00, m22, m23;                    \
        f = (T)1 / TAN(fovy / (T)2);           \
        m00 = fovy / (ar == (T)0 ? (T)1 : ar); \
        m22 = (near + far) / (near - far);     \
        m23 = ((T)2 * far * near);             \
        out[0][0] =   m00;                     \
        out[0][1] =  (T)0;                     \
        out[0][2] =  (T)0;                     \
        out[0][3] =  (T)0;                     \
        out[1][0] =  (T)0;                     \
        out[1][1] =     f;                     \
        out[1][2] =  (T)0;                     \
        out[1][3] =  (T)0;                     \
        out[2][0] =  (T)0;                     \
        out[2][1] =  (T)0;                     \
        out[2][2] =   m22;                     \
        out[2][3] =   m23;                     \
        out[3][0] =  (T)0;                     \
        out[3][1] =  (T)0;                     \
        out[3][2] = (T)-1;                     \
        out[3][3] =  (T)0;                     \
}

#endif