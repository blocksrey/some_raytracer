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

//vector vector
vec3 vec3vec3add(vec3 a, vec3 b) {
    return vec3new(a.x + b.x, a.y + b.y, a.z + b.z);
}

vec3 vec3vec3sub(vec3 a, vec3 b) {
    return vec3new(a.x - b.x, a.y - b.y, a.z - b.z);
}

//vector number
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

//other
float vec3dot(vec3 a, vec3 b) {
    return a.x*b.x + a.y*b.y + a.z*b.z;
}

float vec3len(vec3 v) {
    return sqrt(v.x*v.x + v.y*v.y + v.z*v.z);
}

vec3 vec3unit(vec3 v) {
    float l = sqrt(v.x*v.x + v.y*v.y + v.z*v.z);
    return vec3new(v.x/l, v.y/l, v.z/l);
}

vec3 vec3cross(vec3 a, vec3 b) {
    float ax = a.x;
    float ay = a.y;
    float az = a.z;
    float bx = b.x;
    float by = b.y;
    float bz = b.z;
    return vec3new(ay*bz - by*az, az*bx - bz*ax, ax*by - bx*ay);
}
