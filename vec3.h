typedef struct {
    float x;
    float y;
    float z;
} vec3;

vec3 vec3new(float x, float y, float z) {
    vec3 v;
    v.x = x;
    v.y = y;
    v.z = z;
    return v;
}

//vec3 vec3
vec3 vec3vec3add(vec3 a, vec3 b) {
    return vec3new(a.x + b.x, a.y + b.y, a.z + b.z);
}

vec3 vec3vec3sub(vec3 a, vec3 b) {
    return vec3new(a.x - b.x, a.y - b.y, a.z - b.z);
}

vec3 vec3vec3mul(vec3 a, vec3 b) {
    return vec3new(a.x*b.x, a.y*b.y, a.z*b.z);
}

vec3 vec3vec3div(vec3 a, vec3 b) {
    return vec3new(a.x/b.x, a.y/b.y, a.z/b.z);
}

float vec3dot(vec3 a, vec3 b) {
    return a.x*b.x + a.y*b.y + a.z*b.z;
}

vec3 vec3vec3cross(vec3 a, vec3 b) {
    float ax = a.x;
    float ay = a.y;
    float az = a.z;
    float bx = b.x;
    float by = b.y;
    float bz = b.z;
    return vec3new(ay*bz - az*by, az*bx - ax*bz, ax*by - ay*bx);
}

//vec3 num
vec3 vec3numadd(vec3 a, float b) {
    return vec3new(a.x + b, a.y + b, a.z + b);
}

vec3 vec3numsub(vec3 a, float b) {
    return vec3new(a.x - b, a.y - b, a.z - b);
}

vec3 vec3nummul(vec3 a, float b) {
    return vec3new(a.x*b, a.y*b, a.z*b);
}

vec3 vec3numdiv(vec3 a, float b) {
    return vec3new(a.x/b, a.y/b, a.z/b);
}

//vec3
float vec3len(vec3 v) {
    float x = v.x;
    float y = v.y;
    float z = v.z;
    return sqrt(x*x + y*y + z*z);
}

vec3 vec3unit(vec3 v) {
    float x = v.x;
    float y = v.y;
    float z = v.z;
    float l = sqrt(x*x + y*y + z*z);
    return vec3new(x/l, y/l, z/l);
}
