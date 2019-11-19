typedef struct {
    float xx;
    float xy;
    float xz;

    float yx;
    float yy;
    float yz;

    float zx;
    float zy;
    float zz;
} mat3;

mat3 mat3new(float xx, float yx, float zx, float xy, float yy, float zy, float xz, float yz, float zz) {
    mat3 m;
    
    m.xx = xx;
    m.xy = xy;
    m.xz = xz;

    m.yx = yx;
    m.yy = yy;
    m.yz = yz;

    m.zx = zx;
    m.zy = zy;
    m.zz = zz;

    return m;
}

mat3 mat3trans(mat3 m) {
    return mat3new(
        m.xx, m.xy, m.xz,
        m.yx, m.yy, m.yz,
        m.zx, m.zy, m.zz
    );
}

float mat3det(mat3 m) {
    float xx = m.xx;
    float xy = m.xy;
    float xz = m.xz;

    float yx = m.yx;
    float yy = m.yy;
    float yz = m.yz;

    float zx = m.zx;
    float zy = m.zy;
    float zz = m.zz;

    return zx*(xy*yz - xz*yy) + zy*(xz*yx - xx*yz) + zz*(xx*yy - xy*yx);
}

mat3 mat3numadd(mat3 a, float b) {
    a.xx += b;
    a.xy += b;
    a.xz += b;

    a.yx += b;
    a.yy += b;
    a.yz += b;

    a.zx += b;
    a.zy += b;
    a.zz += b;

    return a;
}

mat3 mat3numsub(mat3 a, float b) {
    a.xx -= b;
    a.xy -= b;
    a.xz -= b;

    a.yx -= b;
    a.yy -= b;
    a.yz -= b;

    a.zx -= b;
    a.zy -= b;
    a.zz -= b;

    return a;
}

mat3 mat3nummul(mat3 a, float b) {
    a.xx *= b;
    a.xy *= b;
    a.xz *= b;

    a.yx *= b;
    a.yy *= b;
    a.yz *= b;

    a.zx *= b;
    a.zy *= b;
    a.zz *= b;

    return a;
}

mat3 mat3numdiv(mat3 a, float b) {
    a.xx /= b;
    a.xy /= b;
    a.xz /= b;

    a.yx /= b;
    a.yy /= b;
    a.yz /= b;

    a.zx /= b;
    a.zy /= b;
    a.zz /= b;

    return a;
}

mat3 mat3inv(mat3 a) {
    return mat3numdiv(mat3trans(a), mat3det(a));
}

vec3 mat3vec3mul(mat3 a, vec3 b) {
    float xx = a.xx;
    float xy = a.xy;
    float xz = a.xz;

    float yx = a.yx;
    float yy = a.yy;
    float yz = a.yz;

    float zx = a.zx;
    float zy = a.zy;
    float zz = a.zz;

    float x = b.x;
    float y = b.y;
    float z = b.z;

    return vec3new(x*xx + y*yx + z*zx, x*xy + y*yy + z*zy, x*xz + y*yz + z*zz);
}

mat3 mat3mat3mul(mat3 a, mat3 b) {
    float axx = a.xx;
    float axy = a.xy;
    float axz = a.xz;

    float ayx = a.yx;
    float ayy = a.yy;
    float ayz = a.yz;

    float azx = a.zx;
    float azy = a.zy;
    float azz = a.zz;

    float bxx = b.xx;
    float bxy = b.xy;
    float bxz = b.xz;

    float byx = b.yx;
    float byy = b.yy;
    float byz = b.yz;

    float bzx = b.zx;
    float bzy = b.zy;
    float bzz = b.zz;

    return mat3new(
        axx*bxx + ayx*bxy + azx*bxz, axx*byx + ayx*byy + azx*byz, axx*bzx + ayx*bzy + azx*bzz,
        axy*bxx + ayy*bxy + azy*bxz, axy*byx + ayy*byy + azy*byz, axy*bzx + ayy*bzy + azy*bzz,
        axz*bxx + ayz*bxy + azz*bxz, axz*byx + ayz*byy + azz*byz, axz*bzx + ayz*bzy + azz*bzz
    );
}

mat3 euleranglesx(float a) {
    return mat3new(1, 0, 0, 0, cos(a), -sin(a), 0, sin(a), cos(a));
}

mat3 euleranglesy(float a) {
    return mat3new(cos(a), 0, sin(a), 0, 1, 0, -sin(a), 0, cos(a));
}

mat3 euleranglesz(float a) {
    return mat3new(cos(a), -sin(a), 0, sin(a), cos(a), 0, 0, 0, 1);
}
